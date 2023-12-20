#include "AppCore/JSHelpers.h"
#include "string"

namespace ul = ultralight;

/// Convert ul::String to std::string
/// \param string ul::string
/// \return converted std::string
std::string JSStringToString(ul::String string) {
    std::string result;

    auto utf8 = string.utf8();

    for (size_t i = 0; i < utf8.size(); ++i) {
        result += utf8[i];
    }

    return result;
}