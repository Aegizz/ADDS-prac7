#ifndef Autocomplete_H
#define Autocomplete_H
#include <iostream>
#include <string>
#include <vector>
#include "TrieNode.h"
class Autocomplete{
    protected:
        TrieNode* root;
    public:
        Autocomplete();
        Autocomplete(TrieNode * _root);
        void insert(std::string key);
        std::vector<std::string> getSuggestions(std::string& key);
        void getCompletions(TrieNode* node, std::string prefix, std::vector<std::string>& res);


};
#endif