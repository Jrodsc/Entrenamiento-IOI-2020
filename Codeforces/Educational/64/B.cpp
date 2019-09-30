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
	int t;
	cin >> t;
	string s;
	vi letras;
	for (int z = 0; z < t; ++z){
		cin >> s;
		int n = s.size();
		letras.assign(28,0);
		for (int j = 0; j < n; ++j){
			letras[s[j]-'a']++;
		}
		string temp = "";
		for (int i = 0; i < 26; i += 2){
			while(letras[i]--){
		//		cout << "dz";
				temp += (char)('a'+i);
			}
		}
		for (int i = 1; i < 26; i += 2){
			while(letras[i]--){
				temp += (char)('a'+i);
			}
		}
		bool band = false;
		for (int i = 0; i < n-1; ++i){
			if(abs(temp[i]-temp[i+1]) == 1){
				band = true;
			}
		}
		letras.assign(28,0);
		for (int j = 0; j < n; ++j){
			letras[s[j]-'a']++;
		}
		string temp1 = "";
		for (int i = 26; i >= 0; i -= 2){
			while(letras[i]){
		//		cout << "dz";
				letras[i]--;
				temp1 += (char)('a'+i);
			}
		}
		for (int i = 25; i >= 1; i -= 2){
			while(letras[i]){
				letras[i]--;
				temp1 += (char)('a'+i);
			}
		}
		bool band1 = false;
		for (int i = 0; i < n-1; ++i){
			if(abs(temp1[i]-temp1[i+1]) == 1){
				band1 = true;
			}
		}
 
		if(band && band1){
			cout << "No answer\n";
		}else if(!band){
			cout << temp << '\n';
		}else{
			cout << temp1 << '\n';
		}
	}
 
	return 0;
}