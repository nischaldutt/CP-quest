#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,x,a,b,c;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++) {
        cin>>x;
        arr.push_back(x);
    }
    cin>>a>>b>>c;
    arr.erase(arr.begin()+(a-1));
    arr.erase(arr.begin()+(b-1), arr.begin()+(c-1));
    cout<<arr.size()<<endl;
    for(vector<int>::iterator i=arr.begin();i!=arr.end();i++) {
        cout<< *i <<" ";
    }
    return 0;
}
