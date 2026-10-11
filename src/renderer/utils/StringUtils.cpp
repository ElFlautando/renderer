#include "StringUtils.hpp"

#include <charconv>
#include <ranges>
#include <spdlog/spdlog.h>
#include <string_view>
#include <system_error>
#include <vector>

namespace renderer::utils
{
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

    auto strof(std::string_view str) -> std::optional<float>
    {
        auto res = float{};
        auto [ptr, ec] = std::from_chars(str.begin(), str.end(), res);

        if (ec == std::errc())
        {
            spdlog::error("Could not parse string to float.");
        }
        return res;
    }
} // namespace renderer::utils
