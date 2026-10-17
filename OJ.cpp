#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void data(){
    freopen("data.in","w",stdout);
    uniform_int_distribution<int>dist(1,100);
    int t=dist(rng)%10+1;
}
int main(){
    while(1) {
        system(".\\data");
        system(".\\D < data.in > sol.txt");
        system(".\\Db < data.in > ans.txt");
        if(system("fc sol.txt ans.txt")) {
            cout<<"WRONG!\n";
            system("PAUSE");
            return 0;
        }
        cout<<"pass..\n";
    }
}

