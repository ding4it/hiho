//
//  main.cpp
//  1037数字三角形
//
//  Created by dwj on 6/21/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
using namespace std;

inline int max(int a,int b){
    return a>b?a:b;
}


int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int arr[200][200];
    int rs[200][200] = {0};
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cin >> arr[i][j];
        }
    }
    rs[0][0] = arr[0][0];
    for(i=1;i<n;i++){
        rs[i][0] = rs[i-1][0] + arr[i][0];
        for(j=1;j<=i;j++){
            rs[i][j] = max(rs[i-1][j],rs[i-1][j-1]) + arr[i][j];
        }
    }
    int mx = -1;
    for(i=0;i<n;i++){
        mx = max(mx,rs[n-1][i]);
    }
    cout << mx << endl;
    
    
    return 0;
}
