#include <iostream>
#include <vector>
using namespace std;
void maxPair(vector<int> vec, int k) {
    int windowSum = 0;
    int maxSum = 0;
    int maxSIndex = 0;
    for(int i = 0; i < k; i++)
    {
        maxSum+=vec[i];
    }
      
    for(int i = k; i < vec.size(); i++)
    {
        windowSum += vec[i] - vec[i-k];
        if(windowSum > maxSum)
        {
            maxSum = windowSum;
            maxSIndex = i-k+1;
        }
    }

    int ending = maxSIndex + k;

    for(int i = maxSIndex; i < ending; i++)
    {
        cout<<vec[i];
    }
}

int main() {
    vector<int> vec = {10, 5, 1, 88, 6, 10};
    maxPair(vec, 2);
}