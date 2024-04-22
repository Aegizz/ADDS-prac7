#include "PrefixMatcher.h"
#include <utility>
#include <algorithm>

PrefixMatcher::PrefixMatcher(){

}

int PrefixMatcher::selectRouter(std::string input){
    TrieNode * root =  new TrieNode();
    comp = new Autocomplete(root);
    comp->insert(input);
    for (int i =routers.size() - 1; i > -1 ; i--){
        if (!(comp->getSuggestions(routers[i].first)).empty()){
            return routers[i].second;
        }
    }
}
void PrefixMatcher::insert(std::string address, int routerNumber){
    routers.push_back(std::pair <std::string, int>(address, routerNumber));
    sort(routers.begin(), routers.end());
    return;
}