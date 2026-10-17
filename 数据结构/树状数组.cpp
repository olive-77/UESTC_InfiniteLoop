#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
struct BIT{
	int n;
	T c[1000005];
	inline void modify(int x,T s){
		for(;x<=n;x+=(x&(-x))){
			c[x]+=s;
		}
	}
	inline T query(int x){
		T s=0;
		for(;x;x-=(x&(-x))){
			s+=c[x];
		}
		return s;
	}
	inline void init(int nn){
		n=nn;
		for(int i=0;i<=n;i++){
			c[i]=0;
		}
	}
};
BIT<int> c;
int main(){
    
}