#include "Utils.h"

std::uint32_t TagCleaner::Utils::ArrayToUint(const std::array<char, sizeof(std::uint32_t)> array)
{
    std::uint32_t ret = 0;

    size_t i = 0;
    for (; i < sizeof(ret); ++i)
    {
        ret |= array[i];
        ret <<= 8;
    }

    ret |= array[i];
    return ret;
}
