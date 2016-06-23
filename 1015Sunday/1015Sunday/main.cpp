/*
 
 不一定对！
 但我估计是对的。
 */
#include <iostream>
#include <cstring>
using namespace std;


string par;
string ori;

int sunday(string & des, string & src)
{
    int count = 0;
    long len_s = src.size();
    long len_d = des.size();
    long next[256] = {0};
    for (long j = 0; j < 256; ++j)
        next[j] = len_d + 1;
    for (long j = 0; j < len_d; ++j)
        next[des[j]] = len_d - j; //记录字符到最右段的最短距离+1
    //例如:des = "abcedfb"
    //next = {7 1 5 4 3 2 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8}
    int pos = 0;
    while (pos < (len_s - len_d + 1)) //末端对齐
    {
        int i = pos;
        int j;
        for (j = 0; j < len_d; ++j, ++i)
        {
            if (src[i] != des[j])
            {
                pos += next[src[pos + len_d]];
                //不等于就跳跃,跳跃是核心
                break;
            }
        }
        if ( j == len_d )
        {
            count += 1;
            pos += next[src[pos + len_d]];
        }
        
    }
    return count;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int i,j;
    for(i=0;i<n;i++){
        cin >> par;
        cin >> ori;
        cout << sunday(par, ori) << endl;
    }
    return 0;
}
