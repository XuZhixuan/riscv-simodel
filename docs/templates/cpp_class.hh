#pragma once

#include "common/common.hh"

namespace ${NAMESPACE_HERE}
{
    class ${CLASS_NAME}
    {
    protected:
        // member vars & funcs declaration.

    public:
        Constructor(...)
                : BaseClass(...)
        {
            // Constructor code.
        }

        ~Deconstruct() = default; // If no need to specify deconstruct func.

        // Other public member funcs.
    };
}