#include "loader.hh"
#include "common/lprint.hh"

namespace ELFLoader {
    ELFFile::ELFFile(const std::string &filename) {
        if (!reader.load(filename)) {
            CL_FAIL("Failed to load elf file: ", filename);
            exit(-1);
        }
    }
}