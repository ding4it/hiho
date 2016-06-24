//
//  main.cpp
//  1040 : 矩形判断
//
//  Created by dwj on 6/23/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    int i;
    int line[4][4];
    int visited[4];
    int a,b,c,d;
    int na,nb,nc,nd;
    while (T--) {
        for(i=0;i<4;i++){
            cin >> a >> b >> c >> d;
            line[i][0] = a;
            line[i][1] = b;
            line[i][2] = c;
            line[i][3] = d;
            visited[i] = 0;
        }
        a = line[0][0];
        b = line[0][1];
        c = line[0][2];
        d = line[0][3];
        visited[0] = 1;
        int check = 1;
        for(int p=1;p<4;p++){
            int ok = 0;
            for(i=1;i<4;i++){
                if (!visited[i] && ((line[i][0] == c && line[i][1] == d)
                                    || (line[i][2] == c && line[i][3] == d)
                                    || (line[i][0] == a && line[i][1] == b)
                                    || (line[i][2] == a && line[i][3] == b))){
                    visited[i] = 1;
                    na = line[i][0];
                    nb = line[i][1];
                    nc = line[i][2];
                    nd = line[i][3];
                    if( ((nc-na)*(c-a) + (nd-nb)*(d-b)) != 0){
                        check = 0;
                        break;
                    }
                    a = na;
                    b = nb;
                    c = nc;
                    d = nd;
                    break;
                }
            }
            if(i == 4){
                check = 0;
            }
            if (!check){
                break;
            }
        }
        if (check){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
        
    }
    
    
    
    
    return 0;
}
