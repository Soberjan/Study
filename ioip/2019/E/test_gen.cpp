#include <iostream>
using namespace std;

int main(int c, char **v){
    srand(atoi(v[1]));
    int n = atoi(v[2]);
    cout << n << "\n";
    for (int i = 0; i < n - 1; i++)
        cout << rand() % (n - 1) + 1 << " " << rand() % (n - 1) + 1 << "\n";
    return 0;
}
