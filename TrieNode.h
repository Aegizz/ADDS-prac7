#ifndef TRIENODE_H
#define TRIENODE_H
#include <iostream>
#include <string>
#include <vector>
class TrieNode{
    protected:
        bool wordEnd;
        TrieNode * childNode[26];
        int routerNumber;
    public:
        TrieNode(){
            wordEnd = false;
            for (int i = 0; i < 26; i++){
                childNode[i] = NULL;
            }
            routerNumber = -1;
        };
        TrieNode * getChild(int i){
            return childNode[i];
        }
        void setChild(int i, TrieNode * node){
            childNode[i] = node;
        }
        bool getWordEnd(){
            return wordEnd;
        }
        void setWordEnd(int val){
            wordEnd = val;
        }
        void setRouterNumber(int num){
            routerNumber = num;
        }
        int getRouterNumber(){
            return routerNumber;
        }


};
#endif