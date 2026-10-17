#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct trie
{
    int nex[N][26], cnt, exist[N], tot[N];
    void insert(string s){
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
                nex[p][c] = ++cnt;
            p = nex[p][c];
            tot[p]++;
        }
        exist[p]++;
    }

    int find(string s){
        int p = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
                return ans;
            p = nex[p][c];
            ans += exist[p];
        }
        ans += tot[p] - exist[p];
        return ans;
    }
} tr;
int main()
{

}