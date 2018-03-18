#include "Tag.h"

#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
namespace tcid3v2 = TagCleaner::ID3V2;

TagCleaner::ID3V2::Tag::Tag(const std::string & filename):
    m_filename(filename)
{}

bool TagCleaner::ID3V2::Tag::Create()
{
    const auto file_size = fs::file_size(m_filename);
    if (file_size <= tcid3v2::Header::HEADER_LENGTH)
    {
        return false;
    }

    std::ifstream input(m_filename, std::ios::binary);
    std::array<char, tcid3v2::Header::HEADER_LENGTH> header_data;

    std::copy_n(std::istreambuf_iterator<char>(input), tcid3v2::Header::HEADER_LENGTH, header_data.begin());

    tcid3v2::Header header(header_data);

    if (header.GetType() != tcid3v2::Header::Type::ID3)
    {
        return false;
    }

    return true;
}
