#ifndef YAMKVINFOREADER_IOPTIONSPARSER_H
#define YAMKVINFOREADER_IOPTIONSPARSER_H
#include <boost/optional.hpp>

#include "AppOptions.h"

namespace options {
    class IOptionsParser {
    public:
        virtual ~IOptionsParser() = default;
    public:
        virtual boost::optional<AppOptions> Parse() = 0;
    };
} //! Options

#endif //YAMKVINFOREADER_IOPTIONSPARSER_H
