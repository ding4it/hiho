#include<iostream>
#include<string>
using namespace std;


struct Trie{
    int end;
    int count;
    Trie *(t[26]);
    char s[26];
};

void dfs(Trie * tree,int tag){
    if (tree == NULL){
        return;
    }
    int kkk=0;
    while (tree->t[kkk] != NULL){
        for(int i=0;i<tag*3;i++){
            cout << " ";
        }
        cout << tree->s[kkk] << " " << tree->count<< endl;
        dfs(tree->t[kkk],tag+1);
        kkk ++;
    }
}

int find(Trie * root,string s){
    Trie * tmp = root;
    int i,j,t;
    for(j=0;j<s.length();j++){
        t = 0;
        int ok = 0;
        while(tmp->t[t] != NULL ){
            if (tmp->s[t] == s[j]){
                ok = 1;
                break;
            }
            t ++;
            
        }
        if (ok){
            tmp = tmp->t[t];
        }
        else{
            return 0;
        }
    }
    return tmp->count + tmp->end;

}

int main(){
    int n,m;
    int i,j,t,ttt;
    string s;
    Trie root;
    root.count = 0;
    root.end = 0;
    for(i=0;i<26;i++){
        root.t[i] = NULL;
    }
    cin >> n;
    for(i=0;i<n;i++){
        cin >> s;
        Trie * tmp = &root;
        for(j=0;j<s.length();j++){
            t = 0;
            tmp->count ++;
            while(tmp->t[t] != NULL){
                if (tmp->s[t] == s[j]){
                    break;
                }
                t++;
            }
            if (tmp->t[t] == NULL) {
                tmp->s[t] = s[j];
                tmp->t[t] = new Trie();
                for(ttt=0;ttt<26;ttt++){
                    tmp->t[t]->t[ttt] = NULL;
                }
                tmp->t[t]->count = 0;
                tmp->t[t]->end = 0;
            }
            tmp = tmp->t[t];
        }
        tmp->end++;
        
    }
//    dfs(&root,0);
    cin >> m;
    for(i=0;i<m;i++){
        cin >> s;
        cout << find(&root,s) << endl;
    }
    
    return 0;
}

