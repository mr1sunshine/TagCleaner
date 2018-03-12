#include "Processor.h"

#include "FilesStorage\FilesStorage.h"
#include "ID3V2\Header.h"

#include <iostream>
#include <fstream>
#include <array>
#include <iterator>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

void TagCleaner::Processor::ExecuteClean(const TagCleaner::FilesStorage & files)
{
    for (const auto &file : files.GetFiles())
    {
        const auto file_size = fs::file_size(file);
        if (file_size > TagCleaner::ID3V2::Header::HEADER_LENGTH)
        {
            std::ifstream input(file, std::ios::binary);
            std::array<char, TagCleaner::ID3V2::Header::HEADER_LENGTH> header_data;

            std::copy_n(std::istreambuf_iterator<char>(input), TagCleaner::ID3V2::Header::HEADER_LENGTH, header_data.begin());

            TagCleaner::ID3V2::Header header(header_data);

            std::cout << "Header type:" << TagCleaner::ID3V2::Header::TypeToStr(header.GetType()) <<
                " ver V2 maj:" << header.GetVersion() << " min:" << header.GetRevision() <<
                " size: " << header.GetTagSize() << std::endl;
        }
    }
}
