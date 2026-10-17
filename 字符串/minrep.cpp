#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int i,j,k,n;
void solve(){
    cin>>s;
    n=s.size(),i=0,j=1,k=0;
    while (k<=n&&i<n&&j<n)
    {
        if(s[(i+k)%n]==s[(j+k)%n]) k++;
        else {
            if(s[(i+k)%n]>s[(j+k)%n]) 
                i=i+k+1;
            else j=j+k+1;
            if(i==j) j++;
            k=0;
        }
    }
    i=min(i,j);
    for(int t=0;t<n;t++){
        cout<<s[(i+t)%n];
    }
    cout<<"\n";
}
int T;
int main(){
    cin>>T;
    while (T--)
    {
        solve();
    }
    
}