//
//  main.cpp
//  1039字符相消
//
//  Created by dwj on 6/20/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int cut(char * s,char * ts){
    int len = strlen(s);
    int i=0,j=0;
    int ok = 0;
    
    while(i<len){
        if(s[i] == s[i+1]){
            i++;
            ok = 1;
            while(s[i] == s[i+1])
                i++;
        }
        if (!ok){
            ts[j++] = s[i];
        }
        ok = 0;
        i++;
    }
    ts[j] = '\0';
    strcpy(s,ts);
    return j;
}

void insert(char* ps, char* s ,int pos){
    int len = strlen(ps);
    int i;
    for(i=0;i<pos;i++){
        s[i] = ps[i];
    }
    s[pos] = 'A';
    for(i=pos;i<len;i++){
        s[i+1] = ps[i];
    }
    s[i+1] = '\0';
}

int main(){
    int n;
    cin >> n;
    int i,j;
    
    
    char s[105];
    char ps[105];
    char ts[105];

    for(i=0;i<n;i++){
        cin >> ps;
        int total = strlen(ps);
        int max = -1;
        for(j=0;j<total+1;j++){
            insert(ps,s,j);
            for (char k = 'A';k<='C';k++){
                s[j] = k;
                char news[105];
                strcpy(news,s);
                int first = cut(news,ts);
                while(1){
                    int second = cut(news,ts);
                    if (first == second){
                        break;
                    }
                    first = second;
                }
                if (total - first > max){
                    max = total - first;
                }
            }
        }
        cout << max + 1 << endl;
        
    }
    
    
    
    return 0;
}

