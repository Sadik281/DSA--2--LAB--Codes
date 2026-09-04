// Q2 - House Robber on a Circular Street
#include <bits/stdc++.h>
using namespace std;

int robLinear(vector<int>& m, int l, int r){
    int p2=0, p1=0;
    for(int i=l;i<=r;i++){
        int cur = max(p1, p2+m[i]);
        p2=p1;
        p1=cur;
    }
    return p1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> m(n);
    for(int i=0;i<n;i++) cin >> m[i];

    if(n==1){ cout << m[0] << "\n"; return 0; }

    cout << max(robLinear(m,0,n-2), robLinear(m,1,n-1)) << "\n";
    return 0;
}