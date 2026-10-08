#pragma once
#include <filesystem>

namespace renderer::core
{

    class Mesh;
    class Loader
    {
      public:
        static auto load(const std::filesystem::path& file_path) -> Mesh;

      private:
    };
} // namespace renderer::core
