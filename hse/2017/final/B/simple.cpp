#include <iostream>
#include <algorithm>

using namespace std;
const int NLIM = 100, HLIM = 100;
int n, hmax, a[NLIM][HLIM], b[NLIM], s;

void print(){
    for (int i=0; i<hmax; i++){
        for (int j=0; j<n; j++)
            cout << a[i][j];
        cout << "\n";
        }
    }

void simple(){
    for (int i=0; i<n; i++)
        if(b[i]>hmax)
            hmax = b[i];
    s=n*hmax;

    for (int i=0; i<n; i++)
        for(int j=0; j<b[i]; j++){
            a[j][i]=1;
            s-=1;
        }

    for (int i=0; i<hmax; i++){
        for (int j=0; j<n; j++)
            if (a[i][j]==1)
                break;
            else{
                a[i][j]=2;
                s-=1;
            }

        for (int q=n-1; q>=0; q--)
            if ((a[i][q]==1)||(a[i][q]==2))
                break;
            else{
                a[i][q]=2;
                s-=1;
            }
    }
    print();
    }


int main(){
    freopen("tests\\08", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i];

    simple();

    cout << s;

    return 0;
}
