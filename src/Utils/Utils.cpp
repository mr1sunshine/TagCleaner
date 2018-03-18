#include "Utils.h"

std::uint32_t TagCleaner::Utils::ArrayToUint32(const std::array<char, sizeof(std::uint32_t)> array)
{
    const std::uint32_t ret = (array[0] << 24) | (array[1] << 16) | (array[2] << 8) | (array[3]);

    return ret;
}

std::uint16_t TagCleaner::Utils::ArrayToUint16(const std::array<char, sizeof(std::uint16_t)> array)
{
    const std::uint16_t ret = (array[0] << 8) | (array[1]);

    return ret;
}
