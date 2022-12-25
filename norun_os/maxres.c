// C++ implementation of above program.
#include <bits/stdc++.h>
using namespace std;
 
// function that calculates
// the minimum no. of resources
int Resources(int process, int need)
{
    int minResources = 0;
 
    // Condition so that deadlock
    // will not occur
    minResources = process * (need - 1) + 1;
 
    return minResources;
}
 
// Driver code
int main()
{
    int process = 3, need = 4;
 
    cout << "R >= " << Resources(process, need);
    return 0;
}
