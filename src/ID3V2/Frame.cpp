#include "Frame.h"

#include "Utils\Utils.h"

TagCleaner::ID3V2::Frame::Header::Header(const std::array<char, HEADER_LENGTH> header_data)
{
    m_frame_id = std::string(header_data.begin() + HEADER_FRAME_ID_POSITION, header_data.begin() + HEADER_FRAME_ID_LENGTH);

    std::array<char, HEADER_SIZE_LENGTH> size_data;
    std::copy(header_data.begin() + HEADER_SIZE_POSITION, header_data.begin() + HEADER_SIZE_POSITION + HEADER_SIZE_LENGTH, size_data.begin());
    m_size = TagCleaner::Utils::ArrayToUint32(size_data);

    std::array<char, HEADER_FLAGS_LENGTH> flags_data;
    std::copy(header_data.begin() + HEADER_FLAGS_POSITION, header_data.begin() + HEADER_FLAGS_POSITION + HEADER_FLAGS_LENGTH, flags_data.begin());
    m_flags = TagCleaner::Utils::ArrayToUint16(flags_data);
}

std::string TagCleaner::ID3V2::Frame::Header::GetFrameId() const
{
    return m_frame_id;
}

std::uint32_t TagCleaner::ID3V2::Frame::Header::GetSize() const
{
    return m_size;
}

std::uint16_t TagCleaner::ID3V2::Frame::Header::GetFlags() const
{
    return m_flags;
}
