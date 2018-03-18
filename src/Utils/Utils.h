#pragma once

#include <array>

namespace TagCleaner
{
    namespace Utils
    {
        std::uint32_t ArrayToUint32(const std::array<char, sizeof(std::uint32_t)> array);
        std::uint16_t ArrayToUint16(const std::array<char, sizeof(std::uint16_t)> array);
    };
};