//Lab 1, Meisam Poorzand
#include <iostream>
#include <string>
using namespace std;

class fractions {

private:

    int numerator;
    
    int denominator;
    
    int whole;
    
public:

    void setfractions(int, int, int);
    
    void printFractions();

};

int main() {

    int n;

    int d;

    int w;

    fractions f1;

    cout << "enter your fractions with a space between:" << endl;

    cin >> n >> d;

    cout << "enter your whole number:" << endl;

    cin >> w;

    f1.setfractions(n, d, w);

    f1.printFractions();
    
}

void fractions::setfractions(int n, int d, int w) {
    
    numerator = n;
    denominator=d;
    whole=w;
    
    if (numerator < 0 || denominator <=0 || whole < 0){
        cout << "bad values\n";
    } ;
    
}

void fractions::printFractions() {
    cout <<whole;
    cout << numerator << "/" << denominator << endl;
    
    
    
}
