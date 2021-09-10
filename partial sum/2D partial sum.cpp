//Author: Fuadul Hasan(fuadul202@gmail.com)
//BSMRSTU,Gopalganj
//#include<bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <random>
#include<iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <complex>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using namespace std;
 
//debug..........
#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s, char c) {vector<string>v; stringstream ss(s); string x;while (getline(ss, x, c))v.emplace_back(x); return move(v);} void err(vector<string>::iterator it) {}
template<typename T, typename... Args>void err(vector<string>::iterator it, T a, Args...args) {cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " "; err(++it, args...);}
 
//............ignore it..................//
#define F first
#define S second
#define Pi atan(1)*4
#define mp make_pair
#define pb  push_back
const int M    = 1e9 + 7;
#define ld  long double
#define ll  long long int
#define happy cin.tie(0);
#define point(x) cout<<fixed<<setprecision(x)
int length(string s){return (int)s.size();}
#define mem(a)  memset(a , 0 ,sizeof a)
#define memn(a) memset(a , -1 ,sizeof a)
#define coding ios::sync_with_stdio(false);
#define Unique(c) (c).resize(unique(all(c))-(c).begin())
#define vout(v) for (auto z: v) cout << z << " "; cout << endl;
 
int length(long long x){int l = 0;for(long long i=x;i;i/=10)l++;return l;}
int dx[8]= {1,0,-1,0,-1,-1,1,1};
int dy[8]= {0,1,0,-1,-1,1,-1,1}; 
 
#define rep(i,b,e)  for(__typeof(e) i = (b) ; i != (e + 1) - 2 * ((b) > (e))  ; i += 1 - 2 * ((b) > (e)))
 
long long Inv_pow(long long a,long long n){ll res = 1;while(n){if(n&1) res = ((res%M)*(a%M))%M;a = ((a%M)*(a%M))%M;n>>=1;}return res%M;}
template <typename T> vector<T> readVector(int n) {vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }
// suffix_prefix....
std::vector<ll> prefix_sum(std::vector<ll> a){int n = a.size();std::vector<ll> prf(n,0);for(int i=0;i<n;i++){
if(i == 0){prf[i] = a[i];}else{prf[i] = prf[i-1]+a[i];}}return prf;}
std::vector<ll> suffix_sum(std::vector<ll> a){int n = a.size();std::vector<ll>suf(n,0);for(int i=n-1;i>=0;i--){
if(i == n-1){suf[i] = a[i];}else{suf[i] = suf[i+1]+a[i];}}return suf;}
 
long long Lcm(long long a,long long b){return (((a)*(b)))/__gcd(a,b);}
 
#define Test cout<<"Case #"<<tc++<<": ";
int tc = 1;
 
inline void read(std::vector<int> &v){for(int i=0;i<(int)v.size();i++){cin>>(v[i]);}}
inline void readl(std::vector<ll> &v){for(int i=0;i<(int)v.size();i++){cin>>(v[i]);}}
 
template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
inline void read(int v[],int n){for(int i=0;i<n;i++){cin>>(v[i]);}}
inline void readl(ll v[],int n){for(int i=0;i<n;i++){cin>>(v[i]);}}
 
inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}
 
#define   pr     pair<int, int> 
#define   vpr     vector<pr> 
#define   vi       std::vector<int>
#define   vll      std::vector<ll>
#define   all(n) n.begin(),n.end()
 
 
const int Inf           = (int)2e9 + 5;
const ll  Lnf           = (ll)2e18 + 5;
const int N             = 5e5 + 5;
const int NN            = 1e6 + 5;
 
 
 
int solve() 
{
 
    //Test
 
    int n,m;
    cin>>n>>m;
 
    vector<vector<int>>v(n+2, vector<int> (m+2,0));
 
    int q;
    cin>>q;
    int x1,x2,y1,y2,k;
 
    while(q--){
        cin>>x1>>y1>>x2>>y2>>k;
        v[x1][y1] += k;
        v[x1][y2+1] -= k;
        v[x2+1][y1] -= k;
        v[x2+1][y2+1] += k;
    }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            v[i][j] += v[i-1][j]+v[i][j-1]-v[i-1][j-1];
        }
    }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
 
    return 0;
    //error();
}
int main(){
 
    happy coding
    int test = 1;
    //cin>>test;
    while (test--)solve();return 0;
}
 
/*
1. Everything happens for something good.
2. Don't expect anything from anyone except yourself.
3. Self discipline is the magic power that makes you unstoppable.
*/
 
/* Note:
-> when you use long long. always keep ll in integer number. like 2LL or (ll)i.
*/
