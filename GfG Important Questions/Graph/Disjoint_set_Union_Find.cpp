#include <bits/stdc++.h>
using namespace std;

int find(int par[], int x) {
    while (par[x] != x)   // traverse until reaching root
    {
        x = par[x];
    }
    return x;
}

void unionSet(int par[], int x, int z) {
    int rootX = find(par, x);
    int rootZ = find(par, z);
    if (rootX != rootZ)
    {
        par[rootX] = rootZ;   // attach one root to another
    }
}

// Driver code
int main() {
    int n = 5;  // number of elements
    int par[n];

    // initialize each node as its own parent
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }

    // Perform some unions
    unionSet(par, 0, 2);
    unionSet(par, 4, 2);
    unionSet(par, 3, 1);

    // Check if elements belong to same set
    if (find(par, 4) == find(par, 0))
        cout << "4 and 0 are in the same set\n";
    else
        cout << "4 and 0 are in different sets\n";

    if (find(par, 1) == find(par, 0))
        cout << "1 and 0 are in the same set\n";
    else
        cout << "1 and 0 are in different sets\n";

    return 0;
}