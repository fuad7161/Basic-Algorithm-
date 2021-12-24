#include<bits/stdc++.h>
using namespace std;

const int N=  1e5+5;
#define ll long long
int main(){
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin>>n;

    vector<int> a(n,0);
    int blk = (int)sqrt(n)+1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> d(blk , INT_MAX);
    for(int i=0;i<n;i++){
        d[i/blk] = min(d[i/blk] , a[i]);
    }

    int q;
    cin>>q;
    while(q--){
        int x, y;
        cin>>x>>y;
        int ans = INT_MAX;
        // for(int i=x;i<=y;){
        //     if(i%blk == 0 and i+blk-1<= y){
        //         ans = min(ans , d[i/blk]);
        //         i += blk;
        //     }else{
        //         ans = min(ans , a[i]);
        //         i++;
        //     }
        // }

        int  c_l = x/blk , c_r = y/blk;
        if(c_l == c_r){
            for(int i=x;i<=y;i++){
                ans = min(ans, a[i]);
            }
        }else{
            for(int i=x;i<(c_l+1)*blk;i++){
                ans = min(ans, a[i]);
            }
            for(int i=c_l+1;i<c_r;i++){
                ans = min(ans,d[i]);
            }
            for(int i=c_r*blk;i<=y;i++){
                ans = min(ans , a[i]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
