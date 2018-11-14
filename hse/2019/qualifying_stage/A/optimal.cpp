#include <iostream>
#include <algorithm>

using namespace std;

int n, k, x;

int optimal(){
    if (n - k >= x)
        return (n);

    int tasks_amount = n - k;
    int diff_easy = x / tasks_amount;
    int diff_hard = diff_easy + 1;
    int hard_amount = x % tasks_amount;
    if (hard_amount == 0)
        return n * diff_easy;
    int easy_amount = tasks_amount - hard_amount;

    int sum = diff_hard * hard_amount + diff_easy * easy_amount + diff_hard * k;

    return sum;
}

int main()
{
    //freopen("tests\\00", "r", stdin);
    cin >> n >> k >> x;

    cout << optimal();
    return 0;
}
