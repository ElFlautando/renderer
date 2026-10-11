#include "Loader.hpp"
#include "Mesh.hpp"
#include "PrimitiveGeometry.hpp"
#include <filesystem>
#include <fstream>
#include <spdlog/spdlog.h>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "StringUtils.hpp"

namespace renderer::core
{

    auto Loader::load(const std::filesystem::path& file_path) -> Mesh
    {

        auto verts = std::vector<Point3f>{};
        auto tris = std::vector<Point3i>{};

        std::ifstream file(file_path.string());

        auto buffer_whitespace = std::vector<std::string_view>{};

        if (file.is_open())
        {
            auto line = std::string{};
            auto code = std::string{};
            auto data = std::string{};

            while (std::getline(file, line))
            {
                // Skip comments
                if (line[0] == '#')
                {
                    continue;
                }

                renderer::utils::split_string(line, ' ', buffer_whitespace);
                spdlog::info("splits: {}", buffer_whitespace);
            }
        }

        return Mesh(std::move(verts), std::move(tris));
    }
} // namespace renderer::core
