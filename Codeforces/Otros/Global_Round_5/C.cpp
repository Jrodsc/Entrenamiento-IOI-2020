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
	vector<pair<ii,int> > points(n);
	vi tomados(n,0);
	for (int i = 0; i < n; ++i){
		cin >> points[i].F.F >> points[i].F.S >> points[i].S; 
	}
	vector<pair<int,ii> > prueba;
	for (int i = 0; i < n; ++i){
		for (int j = i+1; j < n; ++j){
			int s = abs(points[i].F.F-points[j].F.F);
			s += abs(points[i].F.S-points[j].F.S);
			s += abs(points[i].S-points[j].S);
			prueba.push_back({s,{i,j}});
		}
	}
	vii ans;
	int i = 0,a,b;
	bool band;
	sort(prueba.begin(),prueba.end());
	while((int)ans.size() < (n >> 1)){
		a = prueba[i].S.F;
		b = prueba[i].S.S;
		if(tomados[a] || tomados[b]){
			i++;
			continue;
		}
		band = true;
		for (int k = 0; k < n && band; ++k){
			if(tomados[k] || k == a || k == b) continue;
			if(min(points[a].F.F,points[b].F.F) <= points[k].F.F && max(points[a].F.F,points[b].F.F) >= points[k].F.F){
				if(min(points[a].F.S,points[b].F.S) <= points[k].F.S && max(points[a].F.S,points[b].F.S) >= points[k].F.S){
					if(min(points[a].S,points[b].S) <= points[k].S && max(points[a].S,points[b].S) >= points[k].S){
						band = false;
					}
				}
			}
		}
		if(band){
			ans.push_back({a+1,b+1});
			tomados[a] = tomados[b] = 1;
		}
		i++;
		i %= (int)prueba.size();
	}

	for (int i = 0; i < (int)ans.size(); ++i){
		cout << ans[i].F << ' ' << ans[i].S << '\n';
	}

	return 0;
}