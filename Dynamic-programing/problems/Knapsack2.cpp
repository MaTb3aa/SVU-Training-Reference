#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

void file() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int n,bag;
vector<int>we,val;
ll memo[105][100005];



ll solve(int i, int v) {
	if (i == n) {
		if(v==0)return 0;
		return 0x3f3f3f3f;
	}
	ll& ret = memo[i][v];
	if (~ret)return ret;

	return ret = min(solve(i + 1, v - val[i]) + we[i], solve(i + 1, v));
}

int main() {

	cin >> n>>bag;
	we = vector<int>(n);
	val = vector<int>(n);
	for (int i = 0; i < n; i++)cin >> we[i] >> val[i];

	memset(memo, -1,sizeof memo);

  // O(10^12)

	for (int money = 100000; money >= 0; money--) { //O(1)

		if (solve(0, money) <= bag) { cout << money; break; }
	}
		

	return 0;
}