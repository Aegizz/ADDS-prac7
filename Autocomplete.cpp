#include "Autocomplete.h"

Autocomplete::Autocomplete(TrieNode * _root){
    root=_root;
}
void Autocomplete::insert(std::string key){
    TrieNode * current = root;
    for (int i = 0; i < key.length(); i++){
        if (current->getChild(key[i]-'a')==NULL){
            TrieNode * newNode = new TrieNode();
            current->setChild(key[i] - 'a', newNode);
        }
        current = current->getChild(key[i] - 'a');

    }
    current->setWordEnd(true);

}
std::vector<std::string> Autocomplete::getSuggestions(std::string& key){
    TrieNode * current= root;
    std::vector<std::string> res;
    for (int i = 0; i < key.length(); i++){
        if (current->getChild(key[i] - 'a')==NULL){
            return res;
        }
        current = current->getChild(key[i] - 'a');
    }
    std::vector<std::string> suggestions;
    getCompletions(current, key, suggestions);
    return suggestions;

}
void Autocomplete::getCompletions(TrieNode* node, std::string prefix, std::vector<std::string>& res){
    if (node == NULL){
        return;
    }
    if (node->getWordEnd()){
        res.push_back(prefix);
    }
    for (int i = 0; i < 26; i++){
        if (node->getChild(i) != NULL){
            getCompletions(node->getChild(i), prefix + char('a'+i), res);
        }
    }
    return;
}