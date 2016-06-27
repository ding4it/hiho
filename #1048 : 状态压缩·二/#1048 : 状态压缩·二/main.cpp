//
//  main.cpp
//  #1048 : 状态压缩·二
//
//  Created by dwj on 6/27/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
using namespace std;
long arr[1005][6][1025] = {0};
int N,M;
#define MOD 1000000007

long f(int i,int j, int s){

    if(i ==  (N+1) && j == 1){
        return s == 0? 1:0;
    }
    if (arr[i][j][s] >0){
        return arr[i][j][s];
    }
    int sj = s & (1 << (j-1));
    int sj1 = s & (1<< j);
    int sjm = s & 1<<(M+j-1);
    if ( sj ){
        if (j < M){
            arr[i][j][s] = f(i,j+1,s);
        }
        else{
            arr[i][j][s] = f(i+1, 1, s >> M);
        }
    }
    else{
        if ( (j == M || sj1) && (i == N || sjm ) ){
            arr[i][j][s] = 0;
        }
        else if (j < M && !sj1 && (i == N || sjm )){
            arr[i][j][s] = f(i, j, s + (1<<(j-1)) + (1<<j)  );
        }
        else if ( (j == M || sj1) && i < N && !sjm ){
            arr[i][j][s] = f(i, j, s + (1<<(j-1)) + (1<<(M+j-1)));
        }
        else if (j < M && !sj1 && i < N && !sjm){
            arr[i][j][s] = f(i, j, s + (1<<(j-1)) + (1<<j)) +
                            f(i, j, s + (1<<(j-1)) + (1<<(M+j-1)));
        }
    }
    return arr[i][j][s] % MOD;
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    cout << f(1,1,0) << endl;
    return 0;
}
