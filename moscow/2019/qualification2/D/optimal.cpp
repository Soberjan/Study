#include <iostream>
#include <set>
using namespace std;

int n, k, *heights;

int main()
{
    freopen("tests/02", "r", stdin);
    cin >> n >> k;
    heights = new int[n];
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    multiset<int> toMedian (heights, heights + k);
    int *medHeights = new int[n - k + 1];
    for (int i = 1; i < n - k + 1; i++){
        multiset<int>::iterator it = toMedian.begin();
        advance(it, toMedian.size() / 2);
        medHeights[i - 1] = *it;
        toMedian.erase(heights[i - 1]);
        toMedian.insert(heights[i + k - 1]);
        for (multiset<int>::iterator itt = toMedian.begin(); itt != toMedian.end(); ++itt)
            cout << *itt << " ";
        cout << *it << "\n";
    }
    for (int i = 0; i < n - k + 1; i++)
        cout << medHeights[i] << " ";

    return 0;
}
