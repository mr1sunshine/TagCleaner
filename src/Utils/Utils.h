#pragma once

#include <array>

namespace TagCleaner
{
    namespace Utils
    {
        std::uint32_t ArrayToUint(const std::array<char, sizeof(std::uint32_t)> array);
    };
};