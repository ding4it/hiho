//
//  main.cpp
//  1082然而沼跃鱼早就看穿了一切
//
//  Created by dwj on 6/20/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;



int main(int argc, const char * argv[]) {
    long next[256];
    string perline;
    string marshtomp = "marshtomp";
    string change = "fjxmlhx";
    long mlen = marshtomp.size();
    while ( getline(cin,perline)){
        if (perline == ""){
            continue;
        }
        int len = perline.size();
        int i,j;
        for(i=0,j=0;i<len;i++){
            j = 0;
            int t = i;
            while(j< mlen && t<len && tolower(perline[t]) == marshtomp[j]){
                t++;
                j++;
            }
            if (j == mlen){
                cout << change;
                i += mlen-1;
            }
            else{
                cout << perline[i];
            }
        }
        cout << endl;
        
    }
    
    return 0;
}
