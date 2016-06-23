//
//  main.cpp
//  1032
//
//  Created by dwj on 6/1/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
#include<cstring>
using namespace std;


int arr[2000005];
char s[2000005];
char ps[1000005];
int count(){
    int i,j;
    int n = strlen(ps)*2;
    int mx = 0;
    int id = 0;
    for(i=1;i<n;i++){
        if (mx > i){
            arr[i] = min(arr[2*id-i],mx-i);
        }
        else{
            arr[i] = 1;
        }
        for(; s[i+arr[i]] == s[i-arr[i]]; arr[i]++)
            ;
        if( arr[i] + i > mx )
        {
            mx = arr[i] + i;
            id = i;
        }
    }
    mx = 0;
    for(i=0;i<n;i++){
        if (arr[i] > mx){
            mx = arr[i];
        }
    }
    return mx-1;
    
}



void pre(){
    int i;
    int n = strlen(ps);
    s[0] = '$';
    s[1] = '#';
    for(i=0;i<n;i++){
        s[2*i+2] = ps[i];
        s[2*i+3] = '#';
    }
}

int main(int argc, const char * argv[]){
    int n;
    cin >> n;
    int i;
    for(i=0;i<n;i++){
        cin >> ps;
        pre();
        cout << count() << endl;
    }
    
    
    return 0;
}
