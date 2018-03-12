#include "FilesStorage\FilesStorage.h"
#include "Processor\Processor.h"

#include <boost/program_options.hpp>

#include <iostream>
#include <string>

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    try
    {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "print usage message")
            ("path,p", po::value<std::string>(), "specify path where to do cleanup")
            ("recursively,r", "specify if search should be recursive")
            ;

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help"))
        {
            std::cout << desc << "\n";
            return 1;
        }

        const bool recursively = vm.count("recursive");
        const auto path = vm.at("path").as<std::string>();

        TagCleaner::FilesStorage files(path, recursively);

        TagCleaner::Processor processor;
        processor.ExecuteClean(files);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
    return 0;
}