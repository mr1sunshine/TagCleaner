#pragma once

#include <string>
#include <vector>

namespace TagCleaner
{
    class FilesStorage
    {
    public:
        FilesStorage(const std::string &path, bool recursive);
        ~FilesStorage() = default;

        FilesStorage(const FilesStorage &) = delete;
        FilesStorage& operator=(const FilesStorage &) = delete;

        const std::vector<std::string> &GetFiles() const;

    private:
        std::string m_path = "";
        bool m_recursive = false;

        std::vector<std::string> m_files;

        void AddFilesFromDirectory(const std::string &path, bool recursively);
        void AddFile(const std::string &file);
        void AddFileIfRegular(const std::string &file);
    };
}
