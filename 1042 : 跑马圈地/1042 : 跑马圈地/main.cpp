//
//  main.cpp
//  1042 : 跑马圈地
//
//  Created by dwj on 6/25/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
using namespace std;

inline int max(int a, int b) {
    return a>b?a:b;
}

int main(int argc, const char * argv[]) {
    
    int N,M,L;
    int l,r,t,b;
    int rs;
    cin >> N >> M >> L;
    cin >> l >> r >> t >> b;
    if ( L >= (N+M)*2){
        rs = N*M - (r - l) * (b - t);
        cout << rs << endl;
        return 0;
    }
    if (l < M - r) {
        int temp = l;
        l = M - r;
        r = M - temp;
    }
    if (t < N - b) {
        int temp = t;
        t = N - b;
        b = N - temp;
    }
    int i,j;
    rs = 0;
    for(i=1;i<=M;i++){
        for(j=1;j<= (L/2-i) && j <= N;j++){
            if ( i <= l || j <= t ){
                rs = max(rs, i * j);
            }
            else if ( i >= r && j >= b){
                rs = max(rs, i*j - (r - l) * (b - t));
            }
            else if (l<= i && i<=r && t<=j && j <= b){
                rs = max(rs, i*j - (i-l)*(j-t));
            }
            else {
                rs = max(rs, i*j - (i-l)*(j-t));
            }
        }
    }
    cout << rs << endl;
    
    return 0;
}
