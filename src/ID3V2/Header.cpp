#include "Header.h"

#include "Utils\Utils.h"

#include <string>

TagCleaner::ID3V2::Header::Header(const std::array<char, HEADER_LENGTH> header_data)
{
    if (std::string(header_data.begin(), header_data.begin() + HEADER_TAG_FIELD_LENGTH) == FILE_IDENTIFIER_ID3)
        m_type = Type::ID3;

    m_version = header_data.at(HEADER_TAG_FIELD_POSITION);
    m_revision = header_data.at(HEADER_REVISION_FIELD_POSITION);

    m_flags = header_data.at(HEADER_FLAGS_FIELD_POSITION);

    std::array<char, HEADER_SIZE_FIELD_LENGTH> size_data;
    std::copy(header_data.begin() + HEADER_SIZE_FIELD_POSITION, header_data.end(), size_data.begin());
    m_size = TagCleaner::Utils::ArrayToUint(size_data);
}
