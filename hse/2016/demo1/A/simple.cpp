#include <iostream>
#include <stack>
using namespace std;

int n, a[100];

int main()
{
    //freopen("tests/03", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    stack<int> rev;
    for (int i = 0, sim = 0; (i < n) && (sim != 1); i++){
        for (int j = i, q = n - 1; j < q; j++, q--, sim = a[j] == a[q] ? 1 : 0)
            if (a[j] != a[q]){
                rev.push(a[i]);
                break;
            }
    }


    cout << rev.size() << "\n";
    while (rev.size() != 0){
        cout << rev.top() << " ";
        rev.pop();
    }
    return 0;
}
