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
    delete root;
    delete comp;
    return -1;
}
void PrefixMatcher::insert(std::string address, int routerNumber){
    routers.push_back(std::make_pair(address, routerNumber));
    sort(routers.begin(), routers.end(),[](const auto& lhs, const auto& rhs){
        return lhs.first.length() < rhs.first.length();
    });
    return;
}

