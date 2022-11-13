#pragma once

#include <string>

#include "elfio/elfio.hpp"

namespace ELFLoader
{
    typedef ELFIO::elfio Reader;

    /**
     * @brief ELFFile wrapper class
     */
    class ELFFile
    {
    public:
        /**
         * @brief Constructor
         *
         * @param filename name of ELF file to load
         */
        ELFFile(const std::string &filename);

    protected:
        Reader reader;
    };
}
