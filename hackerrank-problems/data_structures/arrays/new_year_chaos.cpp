#include<bits/stdc++.h>

using namespace std;

void minimumBribes(int arr[], int len) {
    int count = 0, temp = 0;
    for(int i=len-1;i>=0;i--) {
        if(i+1 != arr[i]) { 
            if(i-1 >=0 && i+1 == arr[i-1]) {
                arr[i-1] = arr[i];
                arr[i] = i+1;
                count += 1;
            }
            else if(i-2 >=0 && i+1 == arr[i-2]) {
                arr[i-2] = arr[i-1];
                arr[i-1] = arr[i]; 
                arr[i] = i+1;
                count += 2;
            }
            else {
                printf("Too chaotic\n");
                return;
            }
        }
    }
    cout<<count<<endl;
    return;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int arr[n];

        for(int i=0;i<n;i++) {
            scanf("%d", &arr[i]);
        }

        minimumBribes(arr, n);
    }
    
    return 0;
}