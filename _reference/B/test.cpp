#include <iostream>
#include <time.h>
using namespace std;

const int NLIM = 15;
const int VLIM = 20;
int n, a[100], b[100];

int simple(){

}

int optimal(){

}

int main(){                                                   
    srand(time(0));
    for (int i = 0; i < 10000; i++){
        n = rand() % 15 + 5;
        if(simple() != optimal())
            cout << "error!";
    }
    cout << "done!";
    return 0;
}
