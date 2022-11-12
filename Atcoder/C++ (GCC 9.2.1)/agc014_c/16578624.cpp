/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
vector < int > adj[maxn];
int ans;

int dfs(int v=1){
    int mx = 0;
    vector < int > vec;
    for(int u : adj[v])
        vec.pb(dfs(u));
    sort(vec.begin() , vec.end());
    reverse(vec.begin() , vec.end());
    for(int i = 0 ; i < vec.size() ; i ++) mx = max(mx ,vec[i]+ i + 1);
    return(mx);
}

int32_t main(){
    migmig
    cin >> n;
    for(int i = 2 ; i <= n;  i ++){
        int u;
        cin >> u;
        adj[u].pb(i);
    }
    cout << dfs();
    return(0);
}