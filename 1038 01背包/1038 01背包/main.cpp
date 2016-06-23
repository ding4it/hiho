//
//  main.cpp
//  1038 01背包
//
//  Created by dwj on 6/21/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
using namespace std;

inline int max(int &a, int &b){
    return a>b?a:b;
}

int need[505] = {0};
int val[505] = {0};
int rs[100005] = {0};

int main(int argc, const char * argv[]) {
    int n,m;
    cin >> n >> m;    int i,j;
    for(i=1;i<=n;i++){
        cin >> need[i] >> val[i];

    }
    for(i=1;i<=n;i++){
        for(j=m;j>=need[i];j--){
            rs[j] = max(rs[j], rs[j-need[i]] + val[i]);

        }
    }
    cout << rs[m] << endl;
    return 0;
}
