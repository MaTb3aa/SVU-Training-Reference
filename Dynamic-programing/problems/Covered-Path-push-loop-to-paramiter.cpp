/***  بسم الله الرحمن ا لرحيم   ***/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define endl                         '\n'
#define Ceil(x,y)             ((x+y-1)/y)
#define sz(s)               (int)s.size()
#define RT(x)           return cout<<x,0;
#define mem(x,y)    memset(x,y,sizeof(x))
#define all(v) ((v).begin()), ((v).end())
#define watch(x) cout<<#x<<" = { "<<x<<" }\n"
#define test int t;cin>>t;while(t--)
const int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
const double PI = acos(-1), EPS = 1e-7;
const int OO = 0x3f3f3f3f, N = 2e5 + 5, mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll x, ll y) { return (!y) ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return ((x / gcd(x, y)) * y); }


void file() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}



int v1,v2,t,d;
int dp[105][10005];

int solve(int i,int lSpeed,int update){

    if(update==d+1) return -1e5;
    if(i==t)return lSpeed == v2 ? v2 : -1e5;
    int &ret=dp[i][lSpeed];
    if(~ret)return ret;

    return ret = max(solve(i,lSpeed,update+1),solve(i+1,lSpeed+update,-d)+lSpeed);

}

int main() {

    cin>>v1>>v2>>t>>d;
    memset(dp,-1,sizeof dp);
    cout<<solve(1,v1,-d);

	return 0;
}