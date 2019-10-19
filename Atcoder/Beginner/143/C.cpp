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
	string s;
	cin >> n >> s;

	string a = "";
	a += s[0];
	for (int i = 1; i < n; ++i){
		if(s[i] == s[i-1]) continue;
		a += s[i];
	}
	cout << (int)a.size() << '\n';
	return 0;
}