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
const int N             = 2e5 + 5;
const int NN            = 1e6 + 5;

struct query{
    int l;
    int r;
    int i;
    int w;
    int lca;
};

int a[N];
vector<int>g[N];
int FT[2*N];
int S[N],T[N];
int timer = 1;
query Q[N];
#define blk  555
int fre[N];
int ans[N];
int cnt = 0;
int dis_val = 0;
map<int,int>vis; 
int L[N];
int table[N][22];
int par[N];

void dfs(int u, int pre, int dep){
    FT[timer] = u;
    S[u] = timer++;
    par[u] = pre;
    L[u] = dep;
    for(int v: g[u]){
        if(v == pre)continue;
        dfs(v,u,dep+1);
    }
    FT[timer] = u;
    T[u] = timer++;

}

void lca_init(int n){
    memset(table , -1 , sizeof table);
    for(int i=1;i<=n;i++){
        table[i][0] = par[i];
    }
    for(int j=1;j<22;j++){
        for(int i=1;i<=n;i++){
            if(table[i][j-1] != -1){
                table[i][j] = table[table[i][j-1]][j-1];
            }
        }
    }
}

int lca_query(int n, int p, int q){
    if(L[p] < L[q]){
        swap(p,q);
    }
    int log = 1;
    while(1){
        int next = log+1;
        if((1<<next) > L[p])break;
        log++;
    }
    for(int i=log;i>=0;i--){
        if(L[p] - (1<<i) >= L[q]){
            p = table[p][i];
        }
    }
    if(p == q){
        return p;
    }
    for(int i=log-1;i>=0;i--){
        if(table[p][i] != -1 and table[p][i] != table[q][i]){
            p = table[p][i];
            q = table[q][i];
        }
    }

    return par[p];
}

bool comp(query a, query b){
    if(a.l / blk != b.l / blk){
        return a.l < b.l;
    }
    if(a.l % 2 != 0){
        return a.r > b.r;
    }else{
        return a.r < b.r;
    }
}

void remove(int i){
    //error(i);
    fre[FT[i]]--;
    if(fre[FT[i]] == 1){
        if(vis[a[FT[i]]] == 0)dis_val++;
        vis[a[FT[i]]]++;
    }else if(fre[FT[i]] == 0){
        vis[a[FT[i]]]--;
        if(vis[a[FT[i]]] == 0)dis_val--;
    }
}

void add(int i){
    //error(i);
    fre[FT[i]]++;
    if(fre[FT[i]] == 2){
        vis[a[FT[i]]]--;
        if(vis[a[FT[i]]] == 0)dis_val--;
    }else if(fre[FT[i]] == 1){
        if(vis[a[FT[i]]] == 0)dis_val++;
        vis[a[FT[i]]]++;
    }
}

int solve() 
{
    
    //Test

    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }   

    int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1,-1,0);
    lca_init(n);

    for(int i=0;i<q;i++){
        cin>>x>>y;
        if(S[x] > S[y]){
            swap(x,y);
        }

        int lca = lca_query(n,x,y);
       //error(x,y,lca)
        if(x == lca){
            Q[i].l = S[x];
            Q[i].r = S[y];
            Q[i].lca = -1;
        }else{
            Q[i].l = T[x];
            Q[i].r = S[y];
            Q[i].lca = lca;
        }
        Q[i].i = i;
    }
    sort(Q,Q+q,comp);
    int curl = 1;
    int curr = 0;
    for(int i=0;i<q;i++){

        int L = Q[i].l;
        int R = Q[i].r;

        while(curr < R) add(++curr);
        while(curl < L) remove(curl++);
        while(curl > L) add(--curl);
        while(curr > R) remove(curr--);

        ans[Q[i].i] = dis_val;
        if(Q[i].lca != -1){
            if(vis[a[(Q[i].lca)]] == 0)ans[Q[i].i]+=1;
        }
    }

    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
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
