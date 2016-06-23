//
//  main.cpp
//  1015KMP
//
//  Created by dwj on 6/1/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;


int nxt[10005];
string par;
string ori;

void next(){
    nxt[0] = -1;
    long n = par.size();
    int q = -1,p = 0;
    while( p < n){
        if (q == -1 || par[q] == par[p]){
            p++;
            q++;
            if (p == n ||  par[p] != par[q]){
                nxt[p] = q;
            }
            else{
                nxt[p] = nxt[q];
            }
        }
        else{
            q = nxt[q];
        }
    }
}

int count(){
    int rs = 0;
    int i,j;
    long ol = ori.size();
    long pl = par.size();
    i=0;
    j=0;
    while (i<ol){
        if ( j== -1  || par[j] == ori[i]){
            i++;
            j++;
            if (j == pl){
                j = nxt[pl];
                rs ++;
            }
        }
        else{
            j = nxt[j];
        }
    }
    return rs;
}
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int i,j;
    for(i=0;i<n;i++){
        cin >> par;
        cin >> ori;
        next();
        cout << count() << endl;
    }
    return 0;
}

