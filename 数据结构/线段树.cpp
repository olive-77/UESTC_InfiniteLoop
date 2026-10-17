#include<bits/stdc++.h>
using namespace std;
using ll=long long;


struct Tag {
    ll mul = 1;
    ll add = 0;
    // 可以添加 mul 等
    inline void apply(const Tag& new_tag){
        mul *= new_tag.mul;
        add = add*new_tag.mul + new_tag.add;
    }
};
struct Info {
    ll sum = 0;
    ll maxv = -LLONG_MAX;
    ll minv = LLONG_MAX;
    int len = 0;
    // 可以继续添加 min, max, gcd 等
    inline void apply(const Tag& tag){
        sum = sum * tag.mul + tag.add * len;

        maxv = maxv*tag.mul+tag.add;
        minv = minv*tag.mul+tag.add;
        if(tag.mul<=0)
            swap(maxv,minv);
    }
};
Info operator+(const Info& a, const Info& b) {
    Info res;
    res.sum = a.sum + b.sum;
    res.maxv = max(a.maxv,b.maxv);
    res.minv = min(a.minv,b.minv);
    res.len = a.len + b.len;
    return res;
}

//改上面，下面不用改(如果info加新的东西的话，build的初始化要改)

template<class Info, class Tag>
struct SegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;

    SegmentTree(int n) : n(n), info(4 * n), tag(4 * n) {}

    // 初始化（建树）
    void build(int p, int l, int r, const vector<ll>& a) {
        if (l == r) {
            info[p] = {a[l] , a[l] , a[l] , 1};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * p, l, mid, a);
        build(2 * p + 1, mid + 1, r, a);
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    // 下传标记
    void pushdown(int p) {
        info[2 * p].apply( tag[p] );
        tag[2 * p].apply(tag[p]);
        info[2 * p + 1].apply(tag[p]);
        tag[2 * p + 1].apply(tag[p]);
        tag[p] = Tag(); // 重置标记
    }

    void update(int p, int l, int r, int ql, int qr, const Tag& v) {
        if (ql <= l && r <= qr) {
            info[p].apply(v);
            tag[p].apply(v);
            return;
        }
        pushdown(p);
        int mid = (l + r) / 2;
        if (ql <= mid) update(2 * p, l, mid, ql, qr, v);
        if (qr > mid) update(2 * p + 1, mid + 1, r, ql, qr, v);
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    Info query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return info[p];
        pushdown(p);
        int mid = (l + r) / 2;
        if (qr <= mid) return query(2 * p, l, mid, ql, qr);
        if (ql > mid) return query(2 * p + 1, mid + 1, r, ql, qr);
        return query(2 * p, l, mid, ql, qr) + query(2 * p + 1, mid + 1, r, ql, qr);
    }
};
const int N=1e6+7;
int n,m,op,l,r,x;
int main(){
    cin>>n>>m;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    SegmentTree<Info,Tag> st(n);
    st.build(1,1,n,a);
    for(int i=1;i<=m;i++){
        cin>>op;
        if(op==1){//+
            cin>>l>>r>>x;
            st.update(1,1,n,l,r,{1,x});
        }
        if(op==2){
            cin>>l>>r>>x;
            st.update(1,1,n,l,r,{0,x});
        }
        if(op==3){
            cin>>l>>r>>x;
            st.update(1,1,n,l,r,{x,0});
        }
        if(op==4){
            cin>>l>>r;
            Info tmp = st.query(1,1,n,l,r);
            cout<<tmp.sum<<"\n";
        }
        if(op==5){
            cin>>l>>r;
            Info tmp = st.query(1,1,n,l,r);
            cout<<tmp.maxv<<"\n";
        }
    }
}