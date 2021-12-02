#include <bits/stdc++.h>

using namespace std;

void solve_first(vector<pair<string, int> > v){
	int horizontal = 0, depth = 0;
	for(int i=0; i<v.size(); i++){
		string dir = v[i].first;
		int units = v[i].second;
		if(dir == "forward") horizontal += units;
		else if(dir == "up") depth -= units;
		else depth += units;
	}
	cout << horizontal * depth << "\n";
}

void solve_second(vector<pair<string, int> > v){
	int horizontal = 0, depth = 0, aim = 0;
	for(int i=0; i<v.size(); i++){
		string dir = v[i].first;
		int units = v[i].second;
		if(dir == "forward"){
			horizontal += units;
			depth += (aim * units);
		} 
		else if(dir == "up") aim -= units;
		else aim += units;
	}
	cout << horizontal * depth << "\n";
}

int main(){
	
	freopen("in_2.txt", "r", stdin);
	
	int x;
	string s;
	vector<pair<string, int> > v;
	
	while(cin >> s >> x && x != EOF) v.push_back({s, x});
	
	solve_first(v);
 	solve_second(v);

	return 0;
}
