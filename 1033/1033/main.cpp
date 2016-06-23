//
//  main.cpp
//  1033
//
//  Created by dwj on 6/2/16.
//  Copyright © 2016 dwj. All rights reserved.
// 有点不对，不知道为什么，放弃。。。。T.T
// 终于对了。
// 机智如我。

#include <iostream>
#include<cstring>
using namespace std;

long long MOD = 1000000007;
long long l,r;
int k;
struct Node{
    long long s,n;//s->sum, n-> number
    Node(long long a=0, long long b=-1):s(a),n(b){
    }
};
Node dp[20][205];
long long  base[20];
int bits[20];
int LEN;


Node dfs(int bt, int status, int limit){
//    cout << "In " << bt << " " << status << endl;
    Node t;
    t.s = t.n = 0;
    if (bt == 0){
        if(status == 100){
            t.n = 1;
        }
        return t;
    }
    long tail = limit? bits[bt]:9;
    int head = bt == LEN? 1:0;
    
    // head == 0 limit ==0 才是赋值的，有效的，才可以直接返回
    if (limit==0 && head == 0 &&  dp[bt][status].n != -1){
        return dp[bt][status];
    }
    
    int i;
    for(i=head;i<=tail;i++){
        Node tmp = dfs(bt-1,i-status+200, limit && i == tail);
        if (tmp.n > 0){
            t.n = (t.n + tmp.n) % MOD;
            t.s = (t.s + tmp.s + (((tmp.n * base[bt]) % MOD) * i) % MOD) % MOD;
          }
    }
    // head == 0 limit == 0 才可以赋值！！
    if (limit == 0 && head == 0){
        dp[bt][status] = t;
    }
//    cout << bt << " " << status << " " << t.s << " " << t.n << endl;
    return t;
}

long long count(long long x){
    if (x <= 0) return 0;
    int len = 0;
    while(x>0){
        bits[++len] = x%10;
        x /= 10;
    }
    int i;
    long long sum=0;
    for(i=1;i <= len;i++){
        //dp要重设！！！我也不知道为什么。。。。T.T
        /// 啊哈，可以不用重设了。上面赋值和直接返回dp的时候要注意！
//        memset(dp,-1,sizeof dp);
        LEN = i;
        Node kkk = dfs(i,k+100, i == len);
        sum = (sum + kkk.s) % MOD;
    }
    return sum;
}

void init(){
    int i;
    base[0] = 0;
    base[1] = 1;
    for(i=2;i<20;i++){
        base[i] = (base[i-1]*10) % MOD;
    }
}
               
int main(int argc, const char * argv[]) {
    
    // k in [-100, 100] save as k + 100 -> [0,200]
    cin >> l >> r >> k;
    init();
    long long a = count(l-1);
    long long b = count(r);
    cout << (b - a + MOD)%MOD << endl;
    
    return 0;
}
