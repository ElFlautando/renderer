#pragma once

#include <charconv>
#include <optional>
#include <spdlog/spdlog.h>
#include <string_view>
#include <system_error>
#include <vector>

namespace renderer::utils
{

    auto split_string(std::string_view string, char delim) -> std::vector<std::string_view>;

    void split_string(std::string_view string, char delim, std::vector<std::string_view>& out);

    template <typename T>
        requires(std::is_same_v<T, int> || std::is_same_v<T, float>)
    auto stroval(std::string_view str) -> std::optional<T>
    {
        {
            auto res = T{};
            auto [ptr, ec] = std::from_chars(str.begin(), str.end(), res);

            if (ec == std::errc())
            {
                return res;
            }
            spdlog::error("Could not parse string to float.");
            return std::nullopt;
        }
    }

    inline constexpr auto stroi = stroval<int>;
    inline constexpr auto strof = stroval<float>;

} // namespace renderer::utils
