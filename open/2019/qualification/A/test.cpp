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
    for (int i = 0; i < 100000; i++){
        n = rand() % 100 + 1;
        k = rand() % n;
        x = rand() % 100;

        if(simple() != optimal())
            cout << "error!";
    }
    cout << "done!";
    return 0;
}
