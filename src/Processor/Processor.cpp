#include "Processor.h"

#include "FilesStorage\FilesStorage.h"
#include "ID3V2\Tag.h"

void TagCleaner::Processor::ExecuteClean(const TagCleaner::FilesStorage & files)
{
    for (const auto &file : files.GetFiles())
    {
        TagCleaner::ID3V2::Tag tag(file);

        const bool res = tag.Create();
        if (!res)
            continue;
    }
}
