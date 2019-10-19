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
	int b[n];
	int ini[n+1];
	vi  tom(n+1,0);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		ini[a[i]] = i;
	}
	int x = 0;
	for (int i = 0; i < n; ++i){
		cin >> b[i];
	}
	int j = -1;
	for (int i = 0; i < n; ++i){
		if(tom[a[i]]) continue;
		if(a[i] == b[j]){
			x++;		
		}else{
			if(j == -1) j = i;
			for (j; j < n && a[i] != b[j]; ++j){
				tom[b[j]]++;
			}
			//cout << i << ' ' << j << '\n';
			if(j == n) break;
			else x++;
		}
	}
	cout << n-x << '\n';

	return 0;
}