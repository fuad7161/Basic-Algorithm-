//Author: Fuadul Hasan(fuadul202@gmail.com)
//BSMRSTU,Gopalganj
#include<bits/stdc++.h>
using namespace std;int tc = 1;
#define happy ios::sync_with_stdio(false);
#define coding  cin.tie(0);
#define F first
#define S second
#define mp make_pair
#define ll long long
#define Pi atan(1)*4
#define pb  push_back
#define vpr vector<pr> 
#define pr pair<int, int> 
#define vi std::vector<int>
#define vll std::vector<ll>
#define YES printf("YES\n");
#define NO printf("NO\n");
#define Yes printf("Yes\n");
#define No printf("No\n");
#define all(n) n.begin(),n.end()
#define point(x) setprecision(x)
#define Test printf("Case %d: ",tc++);
#define Unique(c) (c).resize(unique(all(c))-(c).begin())
#define vout(v) for (auto z: v) cout << z << " "; cout << endl;

#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s, char c) {vector<string>v; stringstream ss(s); string x;
while (getline(ss, x, c))v.emplace_back(x); return move(v);} void err(vector<string>::iterator it) {}
template<typename T, typename... Args>void err(vector<string>::iterator it, T a, Args...args) {
cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " "; err(++it, args...);}

const int M = 1e9 + 7;
const ll  Inf = (ll)2e18 + 5;
const int N   = 101;
ll vis[N],res[N];
int a[N][N], I[N][N];

void mul(int ar[][N],int B[][N],int dim){
	/*cout<<"ar"<<endl;
	for(int i=1;i<=dim;i++){
		for(int j=1;j<=dim;j++){
			cout<<ar[i][j]<<" ";
		}cout<<endl;
	}
	cout<<"B"<<endl;
	for(int i=1;i<=dim;i++){
		for(int j=1;j<=dim;j++){
			cout<<B[i][j]<<" ";
		}cout<<endl;
	}*/

	int res[dim+1][dim+1];
	for(int i=1;i<=dim;i++){
		for(int j=1;j<=dim;j++){
			res[i][j] = 0;
			for(int k =1;k<=dim;k++){
				res[i][j]+=ar[i][k]*B[k][j];
			}
		}
	}
	for(int i=1;i<=dim;i++){
		for(int j=1;j<=dim;j++){
			ar[i][j] = res[i][j];
		}
	}
}

void power(int ar[][N],int dim,int n){
	for(int i =1;i<=dim;i++){
		for(int j=1;j<=dim;j++){
			if(i==j)I[i][j] = 1;
			else I[i][j] = 0;
		}
	}

	for(int i=1;i<=n;i++){
		mul(I,ar,dim);
	}

	for(int i=1;i<=dim;i++){
		for(int j=1;j<=dim;j++){
			ar[i][j] = I[i][j]; 
		}
	}
}


int solve() 
{
	//happy coding

	int t;
	cin>>t;
	while(t--){
		int n,dim;
		cin>>dim>>n;
		for(int i=1;i<=dim;i++){
			for(int j=1;j<=dim;j++){
				cin>>a[i][j];
			}
		}

		power(a,dim,n);
		for(int i=1;i<=dim;i++){
			for(int j=1;j<=dim;j++){
				cout<<a[i][j]<<" ";
			}cout<<endl;
		}
	}
	
	return 0;
}
int main(){
	int test = 1;
  	//scanf("%d", &test);
  	while (test--)solve();return 0;
}