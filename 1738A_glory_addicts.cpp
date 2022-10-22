#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> t(n);
	rep(i, 0, n) cin >> t[i];

	vector<int> v[2];
	rep(i, 0, n) {
		int x; cin >> x;
		v[t[i]].push_back(x);
	}
	if(sz(v[0]) == 0) {
		cout << accumulate(all(v[1]), 0ll) << endl;
		return;
	}
	if(sz(v[1]) == 0) {
		cout << accumulate(all(v[0]), 0ll) << endl;
		return;
	}
	sort(v[0].rbegin(), v[0].rend());
	sort(v[1].rbegin(), v[1].rend());
	int ans = accumulate(all(v[0]), 0ll) + accumulate(all(v[1]), 0ll);;
	if(sz(v[0]) == sz(v[1])) {
		cout << ans*2-min(v[0].back(), v[1].back()) << endl;
		return;
	}
	int mn = min(sz(v[0]), sz(v[1]));
	for(int i = 0; i < mn; i++) {
		ans += v[0][i] + v[1][i];
	}
	cout << ans << endl;

}

signed main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		// cout << "Case " << i << ": ";
		solve();
	}
}


