#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,q,x;
    scanf("%d %d", &n, &q);
    int** outer = new int*[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&x);

        outer[i] = new int[x];

        for(int j=0;j<x;j++) {
            scanf("%d", &outer[i][j]);
        }
    }
    while(q--) {
        int i,j;
        scanf("%d %d", &i, &j);
        printf("%d\n", outer[i][j]);
    }
    return 0;
}
