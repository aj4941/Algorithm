#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int solution(vector<string> a) 
{
    int ocnt = 0, xcnt = 0;
    
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
    {
        if (a[i][j] == 'O') ocnt++;
        if (a[i][j] == 'X') xcnt++;
    }
    
    bool owin = false, xwin = false;
    
    for (int i = 0; i < 3; i++)
    {
        string tmp = "";
        for (int j = 0; j < 3; j++)
            tmp += a[i][j];
        
        if (tmp == "OOO") owin = true;
        if (tmp == "XXX") xwin = true;
    }
    
    for (int j = 0; j < 3; j++)
    {
        string tmp = "";
        for (int i = 0; i < 3; i++)
            tmp += a[i][j];
        
        if (tmp == "OOO") owin = true;
        if (tmp == "XXX") xwin = true;
    }
    
    string r1 = string("") + a[0][0] + a[1][1] + a[2][2];
    string r2 = string("") + a[2][0] + a[1][1] + a[0][2];
    
    if (r1 == "OOO") owin = true;
    if (r1 == "XXX") xwin = true;
    if (r2 == "OOO") owin = true;
    if (r2 == "XXX") xwin = true;
    
    if (owin && xwin) return 0;
    if (owin)
    {
        if (ocnt - xcnt == 1) return 1;
        else return 0;
    }
    if (xwin)
    {
        if (ocnt - xcnt == 0) return 1;
        else return 0;
    }
    if (0 <= ocnt - xcnt && ocnt - xcnt <= 1) 
        return 1;
    
    return 0;
}