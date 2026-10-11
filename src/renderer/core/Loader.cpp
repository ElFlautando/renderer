#include "Loader.hpp"
#include "Mesh.hpp"
#include "PrimitiveGeometry.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ranges>
#include <spdlog/spdlog.h>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace renderer::core
{

    void split(std::string_view string)
    {

        constexpr auto delim = ' ';
        string = "v 0.524218 0.005902 -0.307888";

        auto delim_iter = std::views::split(string, delim);

        for (const auto split : delim_iter)
        {
            std::cout << static_cast<std::string_view>(split) << "\n";
        }
    };

    auto Loader::load(const std::filesystem::path& file_path) -> Mesh
    {

        auto verts = std::vector<Point3f>{};
        auto tris = std::vector<Point3i>{};

        std::ifstream file(file_path.string());

        if (file.is_open())
        {
            auto line = std::string{};
            auto code = std::string{};
            auto data = std::string{};

            while (std::getline(file, line))
            {
                auto iss = std::istringstream(line);
                iss >> code >> data;
                spdlog::info("Code: {}", code);
            }
        }

        return Mesh(std::move(verts), std::move(tris));
    }
} // namespace renderer::core
