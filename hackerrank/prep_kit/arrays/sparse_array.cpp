#include<bits/stdc++.h>

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
    int arr[q] = {0};
    int count = 0;

    for(int i=0;i<q;i++) {
        count = 0;
        for(int j=0;j<n;j++) {
            if(queries[i] == strings[j]) {
                count++;
            }
        }
        arr[i] = count;
    }

    for(int i=0;i<q;i++) {
        cout<<arr[i]<<endl;
    }
    return 0;
}