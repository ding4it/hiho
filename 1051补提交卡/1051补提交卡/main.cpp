//
//  main.cpp
//  1051补提交卡
//
//  Created by dwj on 6/20/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    int m,n;
    int arr[105];
    int i,j;
    while(T--){
        cin >> n >> m;
        for(i=0;i<n;i++){
            cin >> arr[i];
        }
        if ( m >= n){
            cout << 100 << endl;
        }
        else{
            int max = arr[m] - 1 > 100 - arr[n-m-1]? arr[m] - 1 : 100 - arr[n-m-1];
            for(i=m + 1;i<n;i++){
                int tmp = arr[i] - arr[i-m-1] - 1;
                if (tmp > max){
                    max = tmp;
                }
            }
            cout << max << endl;
            
        }
        
    }
    
    
    return 0;
}