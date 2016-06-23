//
//  main.cpp
//  1094Lost in the City
//
//  Created by dwj on 6/21/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
using namespace std;

char map[205][205];
int m,n;
char pos[4][3][3];


int isEqual(int x, int y, char p[3][3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if( map[x+i][y+j] != p[i][j]){
                return 0;
            }
        }
    }
    
    return 1;
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cin >> pos[0][i][j];
        }
    }
    int t;
    for(t=1;t<4;t++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                pos[t][i][j] = pos[t-1][2-j][i];
            }
        }
    }
    for(i=0;i<n-2;i++){
        for(j=0;j<m-2;j++){
            if( isEqual(i, j, pos[0]) || isEqual(i, j, pos[1])
               || isEqual(i, j, pos[2]) || isEqual(i, j, pos[3])){
                cout << i+2 << " " << j+2 << endl;
            }
            
        }
    }
    
    
    return 0;
}
