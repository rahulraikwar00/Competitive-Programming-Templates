/*
 * Deleted code is debugged code :)
 */
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define pp pair<ll,ll>
#define mp make_pair
#define PI acos(-1.0)
#define all(v) v.begin(),v.end()
#define pb push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FREV(i,a,b) for(i=a;i>=b;i--)
#define READ(a,i,n) FOR(i,0,n) { a[i] = read_ll();}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define S(n) scanf("%lld", &n)
#define INF 1e18
#define MOD 1000000007

// #ifndef ONLINE_JUDGE
// #define gc getchar
// #define pc putchar
// #else
// #define gc getchar_unlocked
// #define pc putchar_unlocked
// #endif

using namespace std;

// int read_int() {
//     char c = gc();
//     while((c < '0' || c > '9') && c != '-') c = gc();
//     int ret = 0, neg = 0;
//     if (c == '-') neg = 1, c = gc();
//     while(c >= '0' && c <= '9') {
//         ret = 10 * ret + c - 48;
//         c = gc();
//     }
//     return neg ? -ret : ret;
// }

// ll read_ll() {
//     char c = gc();
//     while((c < '0' || c > '9') && c != '-') c = gc();
//     ll ret = 0;
//     int neg = 0;
//     if (c == '-') neg = 1, c = gc();
//     while(c >= '0' && c <= '9') {
//         ret = 10 * ret + c - 48;
//         c = gc();
//     }
//     return neg ? -ret : ret;
// }

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

int main() {
	ll i,j,t,n,ans=0;
	S(n);
	vi sq, nsq, diffs;
	FOR(i,0,n) {
		S(j);
		ll sqrtn = floor(sqrt(j));
		if (sqrtn * sqrtn == j) {
			sq.pb(j);
		}
		else {
			nsq.pb(j);
		}
	}

	if (sq.size() < n / 2) {
		FOR(i,0,nsq.size()) {
			t = (ll)(sqrt(float(nsq[i])));
			diffs.pb(min(abs(t*t - nsq[i]), abs((t+1)*(t+1) - nsq[i])));
		}
		sort(all(diffs));
		FOR(i,0,n/2 - sq.size()) {
			ans += diffs[i];
		}
	}
	else {
		i = 0, j = 0;
		while (i < sq.size() and j < n / 2 - nsq.size()) {
			if (sq[i] != 0) {
				j++;
			}
			i++;
		}
		ans = j + (n/2 - nsq.size() - j) * 2;
	}
	
	printf("%lld", ans);
	return 0;
}