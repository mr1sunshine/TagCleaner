#pragma once

namespace TagCleaner
{
    namespace ID3V2
    {
        class Header
        {
            static constexpr size_t HEADER_TAG_FIELD_LENGTH = 3;
            static constexpr size_t HEADER_VERSION_FIELD_LENGTH = 1;
            static constexpr size_t HEADER_REVISION_FIELD_LENGTH = 1;
            static constexpr size_t HEADER_FLAGS_FIELD_LENGTH = 1;
            static constexpr size_t HEADER_SIZE_FIELD_LENGTH = 4;
            static constexpr size_t HEADER_LENGTH = HEADER_TAG_FIELD_LENGTH +
                                                    HEADER_VERSION_FIELD_LENGTH +
                                                    HEADER_REVISION_FIELD_LENGTH +
                                                    HEADER_FLAGS_FIELD_LENGTH +
                                                    HEADER_SIZE_FIELD_LENGTH;

        };
    }
}