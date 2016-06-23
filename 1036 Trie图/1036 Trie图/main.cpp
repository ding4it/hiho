//
//  main.cpp
//  1036 Trie图
//
//  Created by dwj on 6/22/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


struct Tree{
    int isEnd;
    Tree * (key[26]);
    Tree * trie;
    Tree(){
        isEnd = 0;
        int i;
        for(i=0;i<26;i++){
            key[i] = NULL;
        }
        trie = NULL;
    }
    
};

void CalNext(Tree * root){
    queue<Tree*> q;
    int i;
    for(i=0;i<26;i++){
        if (root->key[i] != NULL) {
            root->key[i]->trie = root;
            q.push(root->key[i]);
        }
        else{
            root->key[i] = root;
        }
    }

    while(!q.empty()){
        Tree * top = q.front();
        q.pop();
        for(i=0;i<26;i++){
            if (top->key[i] == NULL){
                top->key[i] = top->trie->key[i];
            }
            else{
                top->key[i]->trie = top->trie->key[i];
                if(top->trie->key[i]->isEnd){
                    top->key[i]->isEnd = 1;
                }
                q.push(top->key[i]);
            }
        }
    }
    
}



char s[1000005];
int main(int argc, const char * argv[]) {
    int n,i;
    cin >> n;
    Tree root;
    root.trie = &root;
    for(i=0;i<n;i++){
        cin >> s;
        int pos = 0;
        Tree * top = &root;
        while(s[pos] != '\0') {
            char c = s[pos++];
            if( top->key[c - 'a'] == NULL){
                top->key[c - 'a'] = new Tree();
            }
            top = top->key[c - 'a'];
        }
        top->isEnd = 1;
    }
    
    CalNext(&root);
    
    cin >> s;
    Tree * top = &root;
    int pos = 0;
    int have = 0;
    while(s[pos] != '\0'){
        top = top->key[s[pos] - 'a'];
        if(top->isEnd){
            have = 1;
            break;
        }
        pos++;
    }
    if(have){
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
