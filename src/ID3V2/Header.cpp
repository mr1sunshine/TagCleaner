#include "Header.h"

#include "Utils\Utils.h"

#include <string>

std::string TagCleaner::ID3V2::Header::TypeToStr(Type type)
{
    std::string ret;
    switch (type)
    {
        case Type::ID3:
        {
            ret = "ID3";
            break;
        }

        case Type::UNKNOWN:
        {
            ret = "UNKNOWN";
            break;
        }
    }

    return ret;
}

TagCleaner::ID3V2::Header::Header(const std::array<char, HEADER_LENGTH> header_data)
{
    if (std::string(header_data.begin(), header_data.begin() + HEADER_TAG_FIELD_LENGTH) == FILE_IDENTIFIER_ID3)
        m_type = Type::ID3;

    m_version = header_data.at(HEADER_VERSION_FIELD_POSITION);
    m_revision = header_data.at(HEADER_REVISION_FIELD_POSITION);

    m_flags = header_data.at(HEADER_FLAGS_FIELD_POSITION);

    std::array<char, HEADER_SIZE_FIELD_LENGTH> size_data;
    std::copy(header_data.begin() + HEADER_SIZE_FIELD_POSITION, header_data.end(), size_data.begin());
    m_size = TagCleaner::Utils::ArrayToUint(size_data) & 0x3FFFFFFF;
}

TagCleaner::ID3V2::Header::Type TagCleaner::ID3V2::Header::GetType() const
{
    return m_type;
}

int TagCleaner::ID3V2::Header::GetVersion() const
{
    return m_version;
}

int TagCleaner::ID3V2::Header::GetRevision() const
{
    return m_revision;
}

std::uint32_t TagCleaner::ID3V2::Header::GetTagSize() const
{
    return m_size;
}
