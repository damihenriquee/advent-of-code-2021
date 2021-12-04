#include <bits/stdc++.h>

using namespace std;

int m[1000][5][5];
bool ja[1000][5][5];

void read_input(int c, int x){
	m[c][0][0] = x;
	for(int i=0; i<5; i++)
	for(int j=0; j<5; j++){
		if(!i && !j) j = 1;
		cin >> m[c][i][j];
	}
}

vector<int> parse_input(char s[]){
	int c = 0;
	vector<int> ret;
	char tmp[123456];
	int t = strlen(s);
	for(int i=0; i<t; i++){
		if(s[i] == ','){
			tmp[c] = '\0';
			ret.push_back(atoi(tmp));
			c = 0;
		}
		else tmp[c++] = s[i];
	}
	tmp[c] = '\0';
	ret.push_back(atoi(tmp));
	return ret;
}

bool is_completed(int c, int ii, int jj){
	bool row = true;
	bool col = true;
	for(int j=0; j<5; j++)
		row &= ja[c][ii][j];
	for(int i=0; i<5; i++)
		col &= ja[c][i][jj];
	return row || col;
}

int get_sum(int c){
	int ret = 0;
	for(int i=0; i<5; i++)
	for(int j=0; j<5; j++)
	if(!ja[c][i][j]) ret += m[c][i][j];
	return ret;
}

void solve_first(vector<int> v, int qt){
	bool won = false, first = true;
	for(int k=0; k<v.size(); k++){
		int num = v[k];
		if(won) break;
		for(int c=0; c<qt; c++){
			for(int i=0; i<5; i++)
			for(int j=0; j<5; j++){
				if(m[c][i][j] == num){
					ja[c][i][j] = true;
					won = is_completed(c, i, j);
					if(won && first) {
						first = false;
						cout << num * get_sum(c) << "\n";
					}
				}
			}
		}
	}
}

void solve_second(vector<int> v, int qt){
	bool won = false;
	set<int> s;
	int ret;
	for(int k=0; k<v.size(); k++){
		int num = v[k];
		for(int c=0; c<qt; c++){
			for(int i=0; i<5; i++)
			for(int j=0; j<5; j++){
				if(m[c][i][j] == num){
					ja[c][i][j] = true;
					won = is_completed(c, i, j);
					if(won && s.find(c) == s.end()) {
						s.insert(c);
						ret = num * get_sum(c);
					}
				}
			}
		}
	}
	cout << ret << "\n";
}

int main(){
	
	freopen("in_4.txt", "r", stdin);
	
	char s[123456];
	int x, c = 0;
	
	cin >> s;
	
	while(cin >> x) read_input(c++, x);
	
	vector<int> v = parse_input(s);
	
	solve_first(v, c);
	solve_second(v, c);
	return 0;
}
