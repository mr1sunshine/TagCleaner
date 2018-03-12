#pragma once

namespace TagCleaner
{
    class FilesStorage;

    class Processor
    {
    public:
        void ExecuteClean(const FilesStorage &files);
    };
};