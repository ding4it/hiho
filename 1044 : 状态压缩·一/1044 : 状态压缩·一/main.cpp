//
//  main.cpp
//  1044 : 状态压缩·一
//
//  Created by dwj on 6/24/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[1005][1005] = {0};
int w[1005];

int countBits(int x){
    int rs = 0;
    while(x>0){
        rs += x%2;
        x = x/2;
    }
    return rs;
}

//心痛，底是2， 可以直接移位操作
int power(int base, int k){
    int rs = 1;
    while(k > 0){
        rs *= base;
        k--;
    }
    return rs;
}

inline int max(int a, int b){
    return a>b?a:b;
}

int main(int argc, const char * argv[]) {
    int N, M, Q;
    int i,j;
    cin >> N >> M >> Q;
    for(i=1;i<=N;i++){
        cin >> w[i];
    }
    int weight = power(2, M-1);
    for(i=0; i<N; i++) {
        for(j=0; j<weight; j++) {
            int bits = countBits(j);
            if(bits > Q ){
                continue;
            }
            //需要加Max, 因为 X0 跟 X1 左移一位后是一样的。
            arr[i+1][j/2] = max(arr[i+1][j/2], arr[i][j]);
            if (bits < Q) {
                arr[i+1][j/2 + weight/2] = max(arr[i+1][j/2 + weight/2],
                                                  arr[i][j] + w[i+1]);
            }
            
        }
    }
    
    int mx = arr[N][0];
    for(i=0;i<weight;i++){
        if(countBits(i) <= Q)
            mx = max(mx, arr[N][i]);
    }
    cout << mx << endl;
    
    
    
    
    
    
    
    
    return 0;
}
