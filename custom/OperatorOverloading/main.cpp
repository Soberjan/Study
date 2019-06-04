#include <iostream>
using namespace std;

struct Student{
    int IQ;
    float height;
    string name;
    Student& operator+(Student& r){
        this->height += r.height;
        this->IQ += r.IQ;
        return *this;
    }
    Student& operator=(Student& r){
        this->height = r.height;
        this->IQ = r.height;
        this->name = r.name;
        return *this;
    }
};

ostream& operator<<(ostream& os, Student& st){
    os << st.IQ << " " << st.height << " " << st.name;
    return os;
}

bool operator==(Student& l, Student& r){
    return (l.IQ == r.IQ) && (l.height == r.height) && (l.name == r.name);
}
bool operator<(Student& l, Student& r){
    return l.IQ < r.IQ;
}
bool operator>(Student& l, Student& r){
    return l.IQ > r.IQ;
}

//Student& operator+(Student& l, Student& r){
//    l.height += r.height;
//    l.IQ += r.IQ;
//    return l;
//}

int main()
{
    Student Maks;
    Maks.IQ = 99;
    Maks.height = 11.15;
    Maks.name = "Marks";

    Student Marks;
    Marks.IQ = 1115;
    Marks.height = 99.01;
    Marks.name = "Maks";
    cout << Maks << " " << Marks << "\n";

    bool x = (Maks == Marks);
    cout << x;
    x = (Maks < Marks);
    cout << x << "\n";

    Maks = Maks + Marks;
    cout << Maks;
    return 0;
}
