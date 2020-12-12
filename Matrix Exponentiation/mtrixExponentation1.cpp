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
const int N   = 2e5 + 5;
ll vis[N],res[N];

struct Matrix{
	vector<vector<int>>mat;
	int n_rows,n_cols;
	Matrix (vector<vector<int>> values):mat(values),n_rows(values.size()),n_cols(values[0].size()){}

	static Matrix identity_matrix(int n){
		vector<vector<int>>values(n,vector<int>(n,0));
		for(int i=0;i<n;i++){
			values[i][i] = 1;
		}
		return values;
	}
	Matrix operator*(const Matrix &other) const
	{
		int n = n_rows,m=other.n_cols;
		vector<vector<int>>result(n_rows,std::vector<int> (m,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				for(int k=0;k<n_cols;k++){
					result[i][j] = (result[i][j]+mat[i][k]*1ll*other.mat[k][j])%M;
				}
			}
		}
		return Matrix(result);
	}
	/*inline bool is_square() const
	{
		return n_rows == n_cols;
	}*/
};

Matrix fast_exponentiation(Matrix m, int power){
	//assert(m.is_square());
	Matrix result = Matrix:: identity_matrix(m.n_rows);
	while(power){
		if(power&1) result = result*m;
		m = m*m;
		power >>= 1;
	}
	return result;
}


int solve() 
{
	//happy coding

	
	int n,k;
	cin>>n>>k;
	vector<vector<int>>v(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			v[i].pb(x);
		}
	}
	Matrix x(v);

	Matrix y = fast_exponentiation(x,k);


	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<y.mat[i][j]<<" ";
		}cout<<endl;
	}
	
	return 0;
}
int main(){
	int test = 1;
  	scanf("%d", &test);
  	while (test--)solve();return 0;
}