#include "FilesStorage.h"

#include <boost\algorithm\string.hpp>

#include <experimental\filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

TagCleaner::FilesStorage::FilesStorage(const std::string & path, bool recursive):
    m_path(path),
    m_recursive(recursive)
{
    AddFilesFromDirectory(path, recursive);
}

const std::vector<std::string>& TagCleaner::FilesStorage::GetFiles() const
{
    return m_files;
}

void TagCleaner::FilesStorage::AddFilesFromDirectory(const std::string & path, bool recursively)
{
    if (recursively)
    {
        for (const auto &entry : fs::recursive_directory_iterator(path))
        {
            const auto &filename = entry.path().string();
            if (FileIsMP3(filename))
                AddFileIfRegular(filename);
        }
    }
    else
    {
        for (const auto &entry : fs::directory_iterator(path))
        {
            const auto &filename = entry.path().string();
            if (FileIsMP3(filename))
                AddFileIfRegular(filename);
        }
    }
}

void TagCleaner::FilesStorage::AddFile(const std::string & file)
{
    m_files.push_back(file);
}

void TagCleaner::FilesStorage::AddFileIfRegular(const std::string & file)
{
    if (fs::is_regular_file(file))
        AddFile(file);
}

bool TagCleaner::FilesStorage::FileIsMP3(const std::string & path) const
{
    return boost::algorithm::iends_with(path, "mp3");
}
