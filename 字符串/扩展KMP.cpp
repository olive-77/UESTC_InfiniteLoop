#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> z_function(string s)
{
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i){
        if (i <= r && z[i - l] < r - i + 1){
            z[i] = z[i - l];
        }
        else{
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
        }
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
//用于计算每个后缀与原字符串的最长公共前缀