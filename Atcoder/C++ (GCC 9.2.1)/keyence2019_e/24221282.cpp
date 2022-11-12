#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , d , a[maxn];
bool mark[maxn];
ll ans;
priority_queue < pii , vector < pii > , greater < pii > > pq;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] , pq.push({a[i] , i});
	while(pq.size()){
		auto [dasdasd , v] = pq.top();
		pq.pop();
		if(v > 1 and !mark[v]){
			ans += d * 1ll + a[v] + a[v - 1];
			if(d + a[v] < a[v - 1]){
				a[v - 1] = d + a[v];
				pq.push({a[v - 1] , v - 1});
			}
			mark[v] = 1;
		}
		if(v < n and !mark[v + 1]){
			ans += d * 1ll + a[v] + a[v + 1];
			if(d + a[v] < a[v + 1]){
				a[v + 1] = d + a[v];
				pq.push({a[v + 1] , v + 1});
			}
			mark[v + 1] = 1;
		}
	}
	cout << ans;
	return(0);
}