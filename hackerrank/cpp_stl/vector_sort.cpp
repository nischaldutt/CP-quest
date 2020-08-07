#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,x;
    scanf("%d",&n);
    vector<int> arr;
    for(int i=0;i<n;i++) {
        scanf("%d",&x);
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
