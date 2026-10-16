#include "StringUtils.hpp"

#include <optional>
#include <ranges>
#include <spdlog/spdlog.h>
#include <string_view>
#include <vector>

namespace renderer::utils
{
    using std::optional;

    auto split_string(std::string_view string, char delim) -> std::vector<std::string_view>
    {
        return string | std::views::split(delim) |
               std::views::transform([](auto part) { return std::string_view{ part }; }) |
               std::views::filter([](const auto part) { return not part.empty(); }) | std::ranges::to<std::vector>();
    }

    void split_string(std::string_view string, char delim, std::vector<std::string_view>& out)
    {
        out.clear();
        for (const auto part :
             string | std::views::split(delim) | std::views::filter([](const auto part) { return not part.empty(); }))
        {

            out.emplace_back(part);
        }
    }

} // namespace renderer::utils
