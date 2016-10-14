#include <iostream>
using namespace std;

class A{
public:
    A():a(1){
        cout << "A!" << endl;
    }

    A(int _a) : b(_a){A();};

    int a;
    int b;

};
int main() {
    A t1;
    A t2(2);

    cout << t1.a << ' ' << t1.b << ' ' << t2.a << ' ' << t2.b << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}