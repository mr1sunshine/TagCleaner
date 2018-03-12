#include "Processor.h"

#include "FilesStorage\FilesStorage.h"

#include <iostream>

void TagCleaner::Processor::ExecuteClean(const TagCleaner::FilesStorage & files)
{
    for (const auto &file : files.GetFiles())
    {
        std::cout << file << std::endl;
    }
}
