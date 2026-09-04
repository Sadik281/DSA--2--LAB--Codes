// Q1 - Activity Selection
#include <bits/stdc++.h>
using namespace std;

vector<int> selectActivities(vector<array<int,3>> a){
    sort(a.begin(), a.end(), [](const array<int,3>&x, const array<int,3>&y){
        return x[1] < y[1];
    });

    vector<int> res;
    int last = -1;
    for(auto &act : a){
        if(act[0] >= last){
            res.push_back(act[2]);
            last = act[1];
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<array<int,3>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    vector<int> res = selectActivities(a);

    cout << res.size() << "\n";
    for(size_t i=0;i<res.size();i++)
        cout << res[i] << (i+1<res.size() ? ' ' : '\n');

    return 0;
}