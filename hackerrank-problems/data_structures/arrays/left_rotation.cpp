#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main() {
    int n, d, x, val=0;
    cin>>n>>d;
    vector<int> arr;
    for(int i=0;i<n;i++) {
        cin>>x;
        arr.push_back(x);
    }

    for(int i=0; i<d; i++) {
        val = arr.front();
        arr.erase(arr.begin());
        arr.push_back(val);
    }

    for(vector<int>::iterator i=arr.begin(); i!=arr.end();i++) {
        cout<< *i<<" ";
    }
    return 0;
}