#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,bag;
const int N = 100005;
ll dp[105][100005];

int W[N], C[N];
ll solve(int i,int rem) {
	if (i == n)return 0;
	ll& ret = dp[i][rem];
	if (~ret)return ret;
	ret = max(ret, solve(i + 1, rem));
	if(rem>=W[i])ret = max(ret, solve(i + 1, rem - W[i]) + C[i]);
	return ret;
}


int main() {
	cin >> n>>bag;
	for (int i = 0; i < n; i++)cin >> W[i] >> C[i];
	memset(dp, -1, sizeof dp);
	cout << solve(0, bag);	 
}