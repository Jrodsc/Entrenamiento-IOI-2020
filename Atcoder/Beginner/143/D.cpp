#include <bits/stdc++.h>
#define ll long long
#define vi vector <int>
#define vll vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>
#define F first
#define S second
#define INF 1000000000000000000
#define pi atan(1)*4
#define MOD 1000000000+7L
#define eps 0.0000006
#define MAX_V 10000
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	vi sums(1005,0);

	for (int i = 0; i < n; ++i){
		cin >> a[i];
		sums[a[i]]++;
	}

	sort(a,a+n);

	int total = 0;
	int lower;
	for (int i = n-1; i >= 0; --i){

		for (int j = i-1; j >= 0; --j){
			if(a[j]*2 < a[i]) break;
			int x = a[i]-a[j]+1;
			lower = lower_bound(a,a+n,x)-a;
			if(lower > j) continue;
			total += (j-lower);
		}
	}
	cout << total << '\n';
	return 0;
}