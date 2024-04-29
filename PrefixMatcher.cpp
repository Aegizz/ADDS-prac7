#include "PrefixMatcher.h"
#include <utility>
#include <algorithm>
#include <memory>
PrefixMatcher::PrefixMatcher(){
    root = new TrieNode();
}

int PrefixMatcher::selectRouter(std::string input){
    TrieNode * current = root;

    int size = input.length();
    int router = -1;

    for (int i =0; i < size && current->getChild(input[i]-'0'); i++){
        current = current->getChild(input[i] - '0');
        if (current == NULL){
            return -1;
        }
    }
    return current->getRouterNumber();

}
void PrefixMatcher::insert(std::string address, int routerNumber){
    TrieNode * current = root;
    int size = address.length();
    

    for (int i = 0; i < size; i++){
        if (current->getChild(address[i]-'0') == NULL){
            current->setChild(address[i]-'0', new TrieNode());
        }
        current = current->getChild(address[i]-'0');
    }
    current->setWordEnd(true);
    current->setRouterNumber(routerNumber);


    return;
}

