#pragma once

#include <string_view>
#include <vector>

namespace renderer::utils
{

    auto split_string(std::string_view string, char delim) -> std::vector<std::string_view>;

    void split_string(std::string_view string, char delim, std::vector<std::string_view>& out);

    auto strof(std::string_view str);

} // namespace renderer::utils
