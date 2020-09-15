
#include <iostream>
#include <vector>
#include <string>



// vector2string
std::string& implode(const std::vector<std::string>& elems,
                                          const std::string& delim,
                                          std::string& result)
{
    for (auto iter = elems.cbegin(); iter != elems.cend(); ++iter) {
        result += (*iter);
        if (std::next(iter) != elems.end()) {
            result += delim;
        }
    }
    return result;
}


void main() {

    
}
