#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos) {
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    // clang-format off
    translate <<    1, 0, 0, -eye_pos[0],
                    0, 1, 0, -eye_pos[1],
                    0, 0, 1, -eye_pos[2],
                    0, 0, 0, 1;
    // clang-format on

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_rotation(Vector3f axis, float angle) {
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    auto nomal_axis = axis.normalized();

    auto ra = angle * MY_PI / 180;

    auto c = cos(ra);
    auto s = sin(ra);

    auto u = axis[0];
    auto v = axis[1];
    auto w = axis[2];

    // clang-format off
    model <<    u * u + (1 - u * u) * c, u * v * (1 - c) - w * s, u * w * (1 - c) + v * s, 0,
                u * v * (1 - c) + w * s, v * v + (1 - v * v) * c, v * w * (1 - c) - u * s, 0,
                u * w * (1 - c) - v * s, v * w * (1 - c) + u * s, w * w + (1 - w * w) * c, 0,
                0,                       0,                       0,                       1;
    // clang-format on

    return model;
}

#define y

Eigen::Matrix4f get_model_matrix(float rotation_angle) {
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.

    model = get_rotation(Vector3f(0, 0, 1), rotation_angle);

    return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio, float zNear, float zFar) {
    // Students will implement this function

    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.

    auto real_eye_fov = eye_fov * MY_PI / 180;

    float b = 1 / tan(real_eye_fov / 2);
    float a = b / aspect_ratio;
    float c = -1 * (zFar + zNear) / (zFar - zNear);
    float d = -1 * (2 * zNear * zFar) / (zFar - zNear);

    // clang-format off
    projection <<   a, 0, 0, 0,
                    0, b, 0, 0,
                    0, 0, c, d,
                    0, 0, -1, 0;
    // clang-format on

    return projection;
}

int main(int argc, const char **argv) {
    float       angle        = 0;
    bool        command_line = false;
    std::string filename     = "output.png";

    if(argc >= 3) {
        command_line = true;
        angle        = std::stof(argv[2]); // -r by default
        if(argc == 4) {
            filename = std::string(argv[3]);
        }
    }

    rst::rasterizer r(700, 700);

    Eigen::Vector3f eye_pos = {0, 0, 15};

    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    int key         = 0;
    int frame_count = 0;

    if(command_line) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while(key != 27) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if(key == 'a') {
            angle += 2;
        } else if(key == 'd') {
            angle -= 2;
        }
    }

    return 0;
}
