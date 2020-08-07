#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,x;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++) {
        cin>>x;
        arr.push_back(x);
    }
    int m, q;
    vector<int>::iterator index;
    cin>>m;
    while(m--) {
        cin>>q;
        index = lower_bound(arr.begin(), arr.end(), q);

        if(binary_search(arr.begin(), arr.end(), q)) {
            cout<<"Yes "<<(index - arr.begin())+1<<endl;
        }
        else {
            cout<<"No "<<(index - arr.begin())+1<<endl;
        }
    }
    return 0;
}
