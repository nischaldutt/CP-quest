#include<bits/stdc++.h>

using namespace std;

int main() {
    long n,m,l,r,k,x=0,max=0;
    cin>>n>>m;

    long* a = new long[n]();
    while(m--) {
        cin>>l>>r>>k;
        a[l-1] += k;
        a[r] -= k;
    }
    for(long i=0;i<n;i++) {
        x += a[i];
        if(max<x) max = x;
    }
    cout<<max;
    return 0;
}

