#include <iostream>
#include <algorithm>

using namespace std;

int n, k, x;

int optimal(){
    if (n - k >= x)
        return (n);

    int diff_easy = x / (n - k);
    if (x % (n - k) == 0)
        return n * diff_easy;

    return x + k * (diff_easy + 1);
}

int main()
{
    //freopen("tests\\00", "r", stdin);
    cin >> n >> k >> x;

    cout << optimal();
    return 0;
}
