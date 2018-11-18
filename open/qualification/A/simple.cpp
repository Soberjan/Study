#include <iostream>
#include <algorithm>

using namespace std;

int n, k, x;

int simple(){
    if (n - k >= x)
        return n;
    int tasks_amount = n - k;
    int diff_easy = x / tasks_amount;
    int sum = diff_easy * tasks_amount;
    while (sum < x)
        sum += 1;
    int diff_hard = diff_easy + 1;
    if (x % tasks_amount == 0)
        for (int i = 0; i < k; i++)
            sum += diff_easy;
    else
        for (int i = 0; i < k; i++)
            sum += diff_hard;

    return sum;
}

int main()
{
    //freopen("tests\\06", "r", stdin);
    cin >> n >> k >> x;

    cout << simple();
    return 0;
}
