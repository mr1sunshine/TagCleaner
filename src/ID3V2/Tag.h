#pragma once

#include "Header.h"

#include <string>

namespace TagCleaner
{
    namespace ID3V2
    {
        class Tag
        {
        public:
            Tag(const std::string &filename);
            ~Tag() = default;

            bool Create();
        private:
            Tag(const Tag&) = delete;
            Tag& operator=(const Tag&) = delete;
            Tag(const Tag&&) = delete;
            Tag& operator=(const Tag&&) = delete;

            std::string m_filename = "";
        };
    };
};