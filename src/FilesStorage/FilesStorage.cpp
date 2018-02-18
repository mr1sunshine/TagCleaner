#include "FilesStorage.h"

#include <experimental\filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

TagCleaner::FilesStorage::FilesStorage(const std::string & path, bool recursive):
    m_path(path),
    m_recursive(recursive)
{
    for (const auto &entry : fs::directory_iterator(path))
    {
        std::cout << entry << "\n";
    }
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
            AddFileIfRegular(entry.path().string());
    }
    else
    {
        for (const auto &entry : fs::directory_iterator(path))
            AddFileIfRegular(entry.path().string());
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
