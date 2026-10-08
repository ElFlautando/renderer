#include "Loader.hpp"
#include "Mesh.hpp"
#include "PrimitiveGeometry.hpp"
#include <filesystem>
#include <fstream>
#include <ranges>
#include <spdlog/spdlog.h>
#include <string>
#include <utility>
#include <vector>

namespace renderer::core
{

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
