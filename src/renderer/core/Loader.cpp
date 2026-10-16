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
        buffer_whitespace.reserve(5);
        auto buffer_data = std::vector<std::string_view>{};
        buffer_data.reserve(4);

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
                // TODO : Does it make sense to move the following two lines outside of the loop? Is that even possible
                // as they are just references?
                const auto& command = buffer_whitespace[0];
                const auto data_str_vec = std::span<const std::string_view>(buffer_whitespace).subspan(1);

                // TODO :: Check if size of buffer is not too small or to large -> Error

                if (command == "v")
                {
                    parse_vertices(data_str_vec, verts);
                }
                else if (command == "vn")
                {
                    // TODO: Parse Vertex normals
                    continue;
                }
                else if (command == "f")
                {
                    parse_faces(data_str_vec, buffer_data, tris);
                }
                else if (command == "s")
                {
                    continue;
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

        spdlog::info("Parsing ended");
        return Mesh(std::move(verts), std::move(tris));
    }

    void Loader::parse_vertices(std::span<const std::string_view> verts_str, std::vector<Point3f>& verts)
    {

        // TODO : Besure that here only 3 verts exist
        // FIXME : Unsafe conversion. Check optional

        auto vert = Point3f{};
        vert.x = *renderer::utils::strof(verts_str[0]);
        vert.y = *renderer::utils::strof(verts_str[1]);
        vert.z = *renderer::utils::strof(verts_str[2]);

        verts.emplace_back(vert);
    }

    void Loader::parse_faces(std::span<const std::string_view> faces_str,
                             std::vector<std::string_view>& buffer_data,
                             std::vector<Point3i>& tris)
    {

        // for (const auto face_str : faces_str)
        // {
        //     // FIXME: There is no difference in parsing for idx/tex and idx//norm
        //     // TODO: If arr only one element then idx or 3 with idx/tex/norm other method
        //
        //     spdlog::info("Unparsed split {}", face_str);
        //     renderer::utils::split_string(face_str, '/', buffer_data);
        //     spdlog::info("Face splits face: {}", buffer_data);
        //     tris_buffer.verts[0].x = *renderer::utils::stroi(buffer_data[0]);
        //     tris_buffer.verts[1].y = *renderer::utils::stroi(buffer_data[0]);
        //     tris_buffer.verts[2].z = *renderer::utils::stroi(buffer_data[0]);
        // }
        auto tris_buffer = Point3i{};
        // buffer_data[0] refers to face index, 1 is texture index, 2 is normal index
        renderer::utils::split_string(faces_str[0], '/', buffer_data);
        tris_buffer.x = *renderer::utils::stroi(buffer_data[0]) - 1;
        renderer::utils::split_string(faces_str[1], '/', buffer_data);
        tris_buffer.y = *renderer::utils::stroi(buffer_data[0]) - 1;
        renderer::utils::split_string(faces_str[2], '/', buffer_data);
        tris_buffer.z = *renderer::utils::stroi(buffer_data[0]) - 1;
        tris.emplace_back(tris_buffer);
    }

} // namespace renderer::core
