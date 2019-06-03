#include <iostream>
using namespace std;

struct Student{
    int IQ;
    float height;
    string name;

    Student operator++(){
        Student st = *this;
        st.height += 1;
        st.IQ += 1;
        *this = st;
        return *this;
    }
};

ostream& operator<<(ostream& os, Student st){
    os << st.IQ << " " << st.height << " " << st.name;
    return os;
}

bool operator==(Student lhs, Student rhs){
    return (lhs.IQ == rhs.IQ) && (lhs.height == rhs.height) && (lhs.name == rhs.name);
}
bool operator<(Student lhs, Student rhs){
    return lhs.IQ < rhs.IQ;
}
bool operator>(Student lhs, Student rhs){
    return lhs.IQ > rhs.IQ;
}




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
    cout << ++Maks;


    return 0;
}
