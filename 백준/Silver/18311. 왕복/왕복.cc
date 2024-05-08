#include <bits/stdc++.h>
using namespace std;
const int intmax = 2147483647;
int dx[] = { 1,0,-1,0 ,1,1,-1,-1 };
int dy[] = { 0,1,0,-1 ,1,-1,1,-1 };
#define ll long long

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N,K;
    cin>>N>>K;

    vector<ll> v(N+2,10000000);
    ll line = 0;
    for(int i=1; i<=N; i++) {
        cin >> v[i];
        line+=v[i];
    }

    int value;
    if(K<line){
        value = 0;
        while(K>=0){
            value++;
            K -= v[value];
        }

    }else{
        K-=line;
        value = N+1;
        while(K>=0){
            value--;
            K -= v[value];
        }
    }

    cout<<value;

}