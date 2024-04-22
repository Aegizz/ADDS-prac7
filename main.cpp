#include "Autocomplete.h"

int main(){
    TrieNode* root = new TrieNode();
    Autocomplete * autocomplete = new Autocomplete(root);
    std::vector<std::string> words = {"bin", "ball", "ballet"};
    for (int i = 0; i < words.size(); i++){
        autocomplete->insert(words[i]);
    }
    // Simulate user input and get suggestions
    std::string input = "b";
    std::cout << "Suggestions for \"" << input << "\": ";
    auto suggestions = autocomplete->getSuggestions(input);
    for (const auto& suggestion : suggestions) {
        std::cout << suggestion << " ";
    }
    std::cout << std::endl;

    input += "a";
    std::cout << "Suggestions for \"" << input << "\": ";
    suggestions = autocomplete->getSuggestions(input);
    for (const auto& suggestion : suggestions) {
        std::cout << suggestion << " ";
    }
    std::cout << std::endl;

    input += "l";
    std::cout << "Suggestions for \"" << input << "\": ";
    suggestions = autocomplete->getSuggestions(input);
    for (const auto& suggestion : suggestions) {
        std::cout << suggestion << " ";
    }
    std::cout << std::endl;

    input += "l";
    std::cout << "Suggestions for \"" << input << "\": ";
    suggestions = autocomplete->getSuggestions(input);
    for (const auto& suggestion : suggestions) {
        std::cout << suggestion << " ";
    }
    std::cout << std::endl;

    input += "e";
    std::cout << "Suggestions for \"" << input << "\": ";
    suggestions = autocomplete->getSuggestions(input);
    for (const auto& suggestion : suggestions) {
        std::cout << suggestion << " ";
    }
    std::cout << std::endl;
    delete root;
    return 0;
}