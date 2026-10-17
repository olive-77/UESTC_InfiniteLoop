#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+7;
int d[N];
int find(int x){  //d[find(x)]=d[find(y)]
    if(d[x]==x) return x;
    return d[x]=find(d[x]);
}