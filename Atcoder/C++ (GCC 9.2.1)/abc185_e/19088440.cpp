/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn = 3e6;
const ll mod = 1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , m;
vector < ll > a;

int32_t main(){
    migmig;
	cin >> n >> m;
	ll mn = n;
	for(int i = 0 ; i < m ; i ++){
		ll x;
		cin >> x;
		a.pb(x);
	}
	a.pb(0);
	a.pb(n + 1);
	sort(a.begin() , a.end());
	m = a.size();
	for(int i = 1 ; i < m ; i ++)
		if(a[i - 1] != a[i] - 1)
			mn = min(mn , a[i] - a[i - 1] - 1);
	ll ans = 0;
	for(int i = 1 ; i < m ; i ++)
		if(a[i - 1] != a[i] - 1)
			ans = ans + (a[i] - a[i - 1] - 1 + mn - 1)/mn;
	cout << ans;
	




    return(0);
}
