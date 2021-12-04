#include <bits/stdc++.h>

using namespace std;

void solve_first(vector<string> v){
	int one[12], zero[12];
	memset(one, 0, sizeof(one));
	memset(zero, 0, sizeof(zero));
	
	for(int i=0; i<v.size(); i++)
	for(int j=0; j<12; j++)
		if(v[i][j] == '0') zero[j]++;
		else one[j]++; 

	long long gamma = 0, epsilon = 0, f = (1 << 11);
	for(int i=0; i<12; i++){
		if(one[i] < zero[i]) epsilon += f;
		else gamma += f;
		f /= 2;
	}
	cout << gamma * epsilon << "\n";
}

vector<string> filter(vector<string> v, int pos, char num){
	vector<string> ret;
	for(int i=0; i<v.size(); i++){
		if(v[i][pos] == num) ret.push_back(v[i]);
	}
	return ret;
}

string get_last(vector<string> v, char drawBit){
	for(int i=0; i<12; i++){
		int c1 = 0, c0 = 0;
		for(int j=0; j<v.size(); j++)
			if(v[j][i] == '0') c0++;
			else c1++;
		if(drawBit == '0') swap(c0, c1);
		if(c1 > c0) v = filter(v, i, '1');
		else if(c0 > c1) v = filter(v, i, '0');
		else v = filter(v, i, drawBit);
		if(v.size() == 1) break;
	}
	return v[0];
}

void solve_second(vector<string> v){
	string oxygen = get_last(v, '1');
	string scrubber = get_last(v, '0');
	long long f = (1 << 11), o = 0, s = 0;
	for(int i=0; i<12; i++){
		if(oxygen[i] == '1') o += f;
		if(scrubber[i] == '1') s += f;
		f /= 2;
	}
	cout << o * s << "\n";
}

int main(){
	
	freopen("in_3.txt", "r", stdin);
	
	string s;
	vector<string> v;
	
	while(cin >> s) v.push_back(s);

	solve_first(v);
 	solve_second(v);

	return 0;
}
