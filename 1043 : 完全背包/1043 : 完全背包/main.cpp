//
//  main.cpp
//  1043 : 完全背包
//
//  Created by dwj on 6/24/16.
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
    cin >> n >> m;
    int i,j;
    for(i=1;i<=n;i++){
        cin >> need[i] >> val[i];
        
    }
    for(i=1;i<=n;i++){
        // 跟 01背包 唯一的区别 一个 j++ 一个 j--
        for(j=need[i];j <= m;j++){
            rs[j] = max(rs[j], rs[j-need[i]] + val[i]);
            
        }
    }
    cout << rs[m] << endl;
    return 0;
}
