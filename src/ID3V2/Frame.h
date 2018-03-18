#pragma once

#include <array>

namespace TagCleaner
{
    namespace ID3V2
    {
        class Frame
        {
            class Header
            {
            private:
                static constexpr size_t HEADER_FRAME_ID_POSITION = 0;
                static constexpr size_t HEADER_FRAME_ID_LENGTH = 4;
                static constexpr size_t HEADER_SIZE_POSITION = HEADER_FRAME_ID_POSITION + HEADER_FRAME_ID_LENGTH;
                static constexpr size_t HEADER_SIZE_LENGTH = 4;
                static constexpr size_t HEADER_FLAGS_POSITION = HEADER_SIZE_POSITION + HEADER_SIZE_LENGTH;
                static constexpr size_t HEADER_FLAGS_LENGTH = 2;

            public:
                static constexpr size_t HEADER_LENGTH = HEADER_FRAME_ID_LENGTH +
                                                        HEADER_SIZE_LENGTH +
                                                        HEADER_FLAGS_LENGTH;

                Header(const std::array<char, HEADER_LENGTH> header_data);
                ~Header() = default;

                Header(const Header&) = delete;
                Header(const Header&&) = delete;
                Header& operator=(const Header&) = delete;
                Header& operator=(const Header&&) = delete;

                std::string GetFrameId() const;
                std::uint32_t GetSize() const;
                std::uint16_t GetFlags() const;

            private:
                std::string m_frame_id = "";
                std::uint32_t m_size = 0;
                std::uint16_t m_flags = 0;
            };
        };
    };
};