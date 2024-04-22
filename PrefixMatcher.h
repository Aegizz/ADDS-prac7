#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H
#include <string>
#include <vector>
#include "Autocomplete.h"
class PrefixMatcher{
    protected:
        std::vector<std::pair<std::string, int>> routers;
        Autocomplete * comp;
    public:
        PrefixMatcher();
        int selectRouter(std::string networkAddress);
        void insert(std::string address, int routerNumber);

};
#endif