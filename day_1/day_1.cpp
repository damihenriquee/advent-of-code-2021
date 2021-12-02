#include <bits/stdc++.h>

using namespace std;

void solve_first(vector<int> v){
	int ans = 0;
	for(int i=1; i<v.size(); i++) 
		if(v[i] > v[i-1]) ans++;
	cout << ans << "\n";
}

void solve_second(vector<int> v){
	vector<int> s;
	for(int i=2; i<v.size(); i++) 
		s.push_back(v[i] + v[i-1] + v[i-2]);
	solve_first(s);
}

int main(){
	
	freopen("in_1.txt", "r", stdin);
	
	int x;
	vector<int> v;
	
	while(cin >> x && x != EOF) v.push_back(x);
	
	solve_first(v);
	solve_second(v);

	return 0;
}
