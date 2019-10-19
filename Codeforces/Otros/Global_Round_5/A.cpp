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
	int sum = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		sum += (a[i]/2);
	}
    for (int i = 0; i < n; ++i){
    	if(sum < 0){
    		if(a[i] > 0 && (a[i] & 1 )){
    			a[i]++;
    			sum++;
    		}
    	}else if(sum > 0){
    		if(a[i] < 0 && (a[i]%2 != 0)){
    			a[i]--;
    			sum--;
    		}
    	}
//    	cout << a[i] << '\n';
    	a[i] /= 2;
    }

    for (int i = 0; i < n; ++i){
    	cout << a[i] << '\n';
    }

//    cout << sum << '\n';


	return 0;
}