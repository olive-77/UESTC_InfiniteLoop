#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
string S ;
int main(){
    int t;
    while (t--){
        cin >> S;
        int n = S.size();
        string s(n * 2 + 1, '#');
        for (int i = 0; i < n; i++){
            s[i * 2 + 1] = S[i];
        }
        vector<int> d(n);
        for (int i = 0, l = 0, r = -1; i < n; i++)   //d[i]是带中心的半径长度。单个字符的回文，d=1
        {
            int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]){
                k++;
            }
            d[i] = k--;
            if (i + k > r){
                l = i - k;
                r = i + k;
            }
        }
    }
}