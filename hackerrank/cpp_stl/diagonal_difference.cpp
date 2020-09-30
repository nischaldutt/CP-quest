#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n] = {0};
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int primary = 0, secondary = 0;
    int x = sizeof(arr) / sizeof(arr[0]);
    cout<<"x ==> "<<x<<endl;
    for(int i=0;i<x;i++) {
        primary += arr[i][i];
        secondary += arr[i][x-i-1];
    }
    cout<<"primary sum = "<<primary<<endl<<"secondary sum = "<<secondary<<endl;
    cout<<abs(primary - secondary);
    return 0;
}