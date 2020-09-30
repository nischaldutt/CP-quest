#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int main() {
    int n,q;
    cin>>n;
    string strings[n];
    for(int i=0;i<n;i++) {
        cin>>strings[i];
    }
    cin>>q;
    string queries[q];
    for(int i=0;i<q;i++) {
        cin>>queries[i];
    }

    unordered_map<string, int> umap;
    vector<int> arr;
    for(string str : strings) umap[str]++;

    for(string str : queries) {
        arr.push_back(umap[str]);
    }
    for(int i=0;i<q;i++) {
        cout<<arr[i]<<endl;
    }
    return 0;
}