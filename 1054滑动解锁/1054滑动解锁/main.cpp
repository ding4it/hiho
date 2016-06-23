//
//  main.cpp
//  1054滑动解锁
//
//  Created by dwj on 6/21/16.
//  Copyright © 2016 dwj. All rights reserved.
//

#include <iostream>
using namespace std;

int con1[10] = {0};
int con2[10] = {0};
int link[10] = {0};
int visited[10] = {0};
int lines;
int existPoint = 0;
int points = 0;
int cnt = 0;
int n;

int check(int pos, int i){
    if((pos == 1 && i == 3 && visited[2] == 0) // 132
       || (pos == 4 && i == 6 && visited[5] == 0) // 465
       || (pos == 7 && i == 9 && visited[8] == 0) // 798
       || (pos == 1 && i == 7 && visited[4] == 0) // 174
       || (pos == 2 && i == 8 && visited[5] == 0) // 285
       
       || (pos == 3 && i == 9 && visited[6] == 0) // 396
       || (pos == 1 && i == 9 && visited[5] == 0) // 195
       || (pos == 3 && i == 7 && visited[5] == 0) // 375
       || (pos == 3 && i == 1 && visited[2] == 0) // 312
       || (pos == 6 && i == 4 && visited[5] == 0) // 645
       
       || (pos == 9 && i == 7 && visited[8] == 0) // 978
       || (pos == 7 && i == 1 && visited[4] == 0) // 714
       || (pos == 8 && i == 2 && visited[5] == 0) // 825
       || (pos == 9 && i == 3 && visited[6] == 0) // 936
       || (pos == 9 && i == 1 && visited[5] == 0) // 915
       
       || (pos == 7 && i == 3 && visited[5] == 0))// 735
    {
        return 0;
    }
    else{
        return 1;
    }
    
}

void dps(int pos, int prev, int start){
    //    cout << "In " << pos << endl;
    int i;
    points++;
    visited[pos] = 1;
    if(points>=4 && lines == n){
        cnt++;
    }
    if (start && link[pos] == 2){
    }
    else if(start && link[pos] == 1 && visited[con1[pos]] == 0 && check(pos, con1[pos])){
        lines++;
        
        dps(con1[pos], pos, 0);
        lines--;
    }
    else if(link[pos] == 2) {
        lines++;
        if (prev == con1[pos] && visited[con2[pos]] == 0 && check(pos, con2[pos])){
            dps(con2[pos], pos, 0);
        }
        else if( visited[con1[pos]] == 0 && check(pos, con1[pos])){
            dps(con1[pos], pos, 0);
        }
        lines--;
        
    }
    else if(link[pos] == 1 && con1[pos] != prev &&  visited[con1[pos]] == 0
            && check(pos, con1[pos])){
        lines++;
        dps(con1[pos],pos,0);
        lines--;
    }
    else{
        for(i=1;i<10;i++){
            if(visited[i] == 0){
                if(check(pos,i)) {
                    dps(i,pos,0);
                }
            }
        }
    }
    points--;
    visited[pos] = 0;
    //    cout << "Out " << pos << endl;
    
}

//
//impossible = {'13': '2',
//    '46': '5',
//    '79': '8',
//    '17': '4',
//    '28': '5',

//    '39': '6',
//    '19': '5',
//    '37': '5',
//    '31': '2',
//    '64': '5',

//    '97': '8',
//    '71': '4',
//    '82': '5',
//    '93': '6',
//    '91': '5',

//    '73': '5'}




int main(int argc, const char * argv[]) {
    int T;
    int i;
    cin >> T;
    while(T--){
        cin >> n;
        lines = 0;
        for(i=1;i<10;i++){
            con1[i] = con2[i] = visited[i] = link[i] = 0;
        }
        for(i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            if(link[a] == 0){
                con1[a] = b;
            }
            else{
                con2[a] = b;
            }
            link[a] ++;
            if(link[b] == 0){
                con1[b] = a;
            }
            else{
                con2[b] = a;
            }
            link[b]++;
        }
        existPoint = 0;
        points = 0;
        cnt = 0;
        
        for(i=1;i<10;i++){
            dps(i,-1,1);
        }
        cout << cnt << endl;
    }
    
    
    
    return 0;
}
