#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;

vector<int> prefix_function(string s)  //返回的数组，pi里面是符合的长度，不是位置。
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++){
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int main(){
    cin>>s;
    int n=s.size();
    vector<int>a(n);
    a=prefix_function(s);
}