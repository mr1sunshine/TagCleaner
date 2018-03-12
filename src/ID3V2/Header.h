#pragma once

#include <array>

namespace TagCleaner
{
    namespace ID3V2
    {
        class Header
        {
        public:

            enum class Type
            {
                ID3,
                UNKNOWN
            };

            static std::string TypeToStr(Type type);

            static constexpr size_t HEADER_TAG_FIELD_POSITION = 0;
            static constexpr size_t HEADER_TAG_FIELD_LENGTH = 3;
            static constexpr size_t HEADER_VERSION_FIELD_POSITION = HEADER_TAG_FIELD_POSITION + HEADER_TAG_FIELD_LENGTH;
            static constexpr size_t HEADER_VERSION_FIELD_LENGTH = 1;
            static constexpr size_t HEADER_REVISION_FIELD_POSITION = HEADER_VERSION_FIELD_POSITION + HEADER_VERSION_FIELD_LENGTH;
            static constexpr size_t HEADER_REVISION_FIELD_LENGTH = 1;
            static constexpr size_t HEADER_FLAGS_FIELD_POSITION = HEADER_REVISION_FIELD_POSITION + HEADER_REVISION_FIELD_LENGTH;
            static constexpr size_t HEADER_FLAGS_FIELD_LENGTH = 1;
            static constexpr size_t HEADER_SIZE_FIELD_POSITION = HEADER_FLAGS_FIELD_POSITION + HEADER_FLAGS_FIELD_LENGTH;
            static constexpr size_t HEADER_SIZE_FIELD_LENGTH = 4;
            static constexpr size_t HEADER_LENGTH = HEADER_TAG_FIELD_LENGTH +
                                                    HEADER_VERSION_FIELD_LENGTH +
                                                    HEADER_REVISION_FIELD_LENGTH +
                                                    HEADER_FLAGS_FIELD_LENGTH +
                                                    HEADER_SIZE_FIELD_LENGTH;

            Header(const std::array<char, HEADER_LENGTH> header_data);
            ~Header() = default;

            Header(const Header&) = delete;
            Header(const Header&&) = delete;
            Header& operator=(const Header&) = delete;
            Header& operator=(const Header&&) = delete;

            Type GetType() const;
            int GetVersion() const;
            int GetRevision() const;

            std::uint32_t GetTagSize() const;

        private:
            static constexpr const char *FILE_IDENTIFIER_ID3 = "ID3";

            Type m_type = Type::UNKNOWN;

            char m_version = 0;
            char m_revision = 0;
            std::uint8_t m_flags = 0;
            std::uint32_t m_size = 0;
        };
    }
}