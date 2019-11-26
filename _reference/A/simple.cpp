#include <iostream>
#include <cstring>
using namespace std;
#define X first
#define Y second
int h, w, *a, *b, *c;

inline int f(int *start, int step, int q) {
    int l = 0, m = 0;
    for (int i = 0; i < q; i++)
        if (start[i * step] == 0)
            l++;
        else
            m = max(m, l), l = 0;
    return m;
}

inline void add(int *x, int *y, int k) {
    for (int j = 0; j < w; j++)
        x[j] += k * y[j];
}

void print() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << b[i*w+j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
//    freopen("tests/02", "r", stdin);
    cin >> h >> w;
    a = new int[h*w], b = new int[h*w], c = new int[w]{};
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            a[i*w+j] = (c == 'X');
        }

    int dh = max(f(a, w, h), f(a+w-1, w, h)), dw = 0;
    for (int i = 0; i < h; i++) {
        add(c, a+i*w, 1);
        if (i - dh > 0)
            add(c, a+(i-dh-1)*w, -1);
        memcpy(b+i*w, c, w*sizeof(int));
        dw = max(dw, f(c, 1, w));
    }
//    print();
    pair<int,pair<int,int>> m = {(h+dh)*(w+dw), {h+dh, w+dw}};
    while (h+dh < w+dw) {
        dh++, dw = 0;
        for (int i = 0; i < h; i++) {
            if (i >= dh)
                add(b+i*w, b+(i-dh)*w, 1);
            dw = max(dw, f(b+i*w, 1, w));
        }
        m = min(m, {(h+dh)*(w+dw), {h+dh, w+dw}});
//        print();
    }
    cout << m.Y.X << " " << m.Y.Y;
    return 0;
}
