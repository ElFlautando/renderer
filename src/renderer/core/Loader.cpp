#include "Loader.hpp"
#include "Mesh.hpp"
#include "PrimitiveGeometry.hpp"
#include <filesystem>
#include <fstream>
#include <span>
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

        spdlog::info("Loader start");
        if (file.is_open())
        {

            spdlog::info("Open file");
            auto line = std::string{};

            while (std::getline(file, line))
            {
                // Skip comments
                if (line[0] == '#')
                {
                    continue;
                }

                renderer::utils::split_string(line, ' ', buffer_whitespace);
                const auto& command = buffer_whitespace[0];
                const auto& data_str_vec = std::span<std::string_view>(buffer_whitespace).subspan(1);

                // TODO :: Check if size of buffer is not too small or to large -> Error

                if (command == "v")
                {
                    parse_vertices(data_str_vec);
                }
                else if (command == "vn")
                {
                    // TODO: Parse Vertex normals
                    continue;
                }
                else if (command == "f")
                {
                    parse_faces(data_str_vec);
                }
                else
                {
                    spdlog::error("Unknown obj command: {} while parsing.", command);
                }
            }
        }
        else
        {

            spdlog::error("Failed to open file: {}", file_path.string());
        }

        return Mesh(std::move(verts), std::move(tris));
    }

    void Loader::parse_vertices(std::span<std::string_view> verts_str)
    {

        for (const auto vert_str : verts_str)
        {
            // TODO : connect to mesh
            // spdlog::info("Append vertex: {}", *renderer::utils::strof(vert_str));
        }
    }

    void Loader::parse_faces(std::span<std::string_view> faces_str)
    {

        spdlog::info(" face array: {}", faces_str);
        for (const auto face_str : faces_str)
        {
            const  auto value = *renderer::utils::strof(face_str);
            spdlog::info("Append face: {}", value);
        }
    }

} // namespace renderer::core
