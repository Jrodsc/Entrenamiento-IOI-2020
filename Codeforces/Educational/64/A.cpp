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
	bool band = false;
	int cont = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		if(i){
			if(a[i-1] == 1){
				if(a[i] == 2){
					cont += 3;
					if(i >= 2 && a[i-2] == 3){
						cont--;
					}
				}else{
					cont += 4;
				}
			}else if(a[i-1] == 2){
				if(a[i] == 1){
					cont += 3;
				}else{
					band = true;
				}
			}else{
				if(a[i] == 1){
					cont += 4;
				}else{
					band = true;
				}
			}
		}
	}
 
	if(band){
		cout << "Infinite\n";
	}else{
		cout << "Finite\n";
		cout << cont << '\n';
	}
 
	return 0;
}