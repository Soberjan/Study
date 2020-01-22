#include <iostream>
using namespace std;
#define idx(i, j) (i)*n + (j)

string s;
int n;

int *l_true, *l_numb;
int *r_true, *r_numb;
void print(int *a){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << a[idx(i,j)] << " ";
        cout << endl;
    }
    cout << endl;
}
void build_g(){
    l_true = new int[n*n]{}; l_numb = new int[n*n]{};
    for (int i = 1; i <= n; i++){
        string t = s.substr(n - i, i);
        for (int j = 0, amt = 0; j < (int)t.size(); j++)
            if (s[j] == t[j])
                l_true[idx(i-1, j)] = 1, l_numb[idx(i-1, j)] = ++amt;
            else
                l_true[idx(i-1, j)] = 0, l_numb[idx(i-1, j)] = amt;
    }

    r_true = new int[n*n]{}; r_numb = new int[n*n]{};
    for (int i = 1; i <= n; i++){
        string t = s.substr(0, i);
        int m = (int)t.size();
        for (int j = 0, amt = 0; j < m; j++)
            if (s[n-j-1] == t[m-j-1])
                r_true[idx(i-1, j)] = 1, r_numb[idx(i-1, j)] = ++amt;
            else
                r_true[idx(i-1, j)] = 0, r_numb[idx(i-1, j)] = amt;
    }
}
bool g(int i, int j, int k){
    if (k > n - (i + j))
        return 0;
    if ( (l_true[idx(n-i-1,k-1)] == 1) && (l_numb(idx(n-i-1,k-1) == k) && (r_true[idx(n-j-1,k-1)] == 1) && (r_true[idx(n-j-1,k-1] == k) )
        return 1;
    return 0;
}

int main(){
    freopen("tests/05", "r", stdin);
    cin >> s;
    n = (int)s.size();

    build_g();

    return 0;
}
