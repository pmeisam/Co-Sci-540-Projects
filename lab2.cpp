//Meisam Poorzand,
//CO SCI 540,
//LAB 2,


#include <iostream>
#include <string>
using namespace std;

class fractions {
private:
    int numerator;
    int denominator;
    int whole;
public:
    //---------------------------------------------constructors&&destructor
    fractions();
    fractions(int , int , int );
    fractions(int , int);
    fractions(const fractions &f);
    ~fractions();
    //---------------------------------------------set functions
    void setNumerator(int);
    void setDenominator(int);
    void setWhole(int);
    void setFraction(int num, int den);
    void setFraction(int,int,int);
    //---------------------------------------------get functions
    int getNumerator() const;
    int getDenominator() const;
    int getWhole() const;
    //---------------------------------------------print functions
    void printFraction()const;
};
int main()
{
    fractions f1;
    int n, d, w;
    cout << "this program will set any numbers less than 1 in denominator to 1 and any negative number in numerator and whole number will be set to 0;\n thanks;\n";
    cout << "enter your fractions with a space in between:" << endl;
    cin >> n >> d;
    cout << "\nenter your whole number:" << endl;
    cin >> w;
    f1.setFraction ( w , n , d ) ;                          //storing numbers into fraction 1;
    fractions f2 = f1 ;                                     //creating a copy of fraction 1;
    fractions f3(5,6);
    fractions f4(1,2,3);
    /*                                                              Showing Data to User       */
    cout << "Here is your Fraction\nFraction #1:\n";
    f1.printFraction();
    cout<< "\nthe whole number is:\n"<< f1.getWhole() << "\nthe numerator is:\n"
    << f1.getNumerator() << "\nthe denominator is:\n"<< f1.getDenominator() <<endl<<endl;
    cout << "Fraction #2:\n";
    f2.printFraction();
    cout << "Fraction #3:\n";
    f3.printFraction();
    cout << "Fraction #4:\n";
    f4.printFraction();
    
    system("pause");
    return 0;
}
//----------------------------------------------------------------------------default constructor
fractions::fractions()
{
    cout << "**the default constructor is called**" << endl;
    whole=0;
    numerator=0;
    denominator=1;
}
//----------------------------------------------------------------------------copy constructor
fractions::fractions(const fractions &f)
{
    cout << "**the copy constructor is called**\n";
    numerator = f.numerator;
    denominator = f.denominator;
    whole = f.whole;
}
//---------------------------------------------------------------------------- 2 && 3 argument constructor
fractions::fractions(int w, int n, int d)
{
    cout<<"\n**the three argument constructor is called**\n";
    setFraction( w , n , d );
}
fractions::fractions(int n, int d)
{
    cout <<"\n**the two argument constructor is called**\n";
    setFraction( 0 , n , d );
}
//----------------------------------------------------------------------------destructor
fractions::~fractions()
{
    numerator = 0; denominator = 1; whole = 0;
    cout << "\n**the destructor is called**\n" << whole
    << " " << numerator << "/" <<
    denominator << endl << endl;
}
//----------------------------------------------------------------------------set functions
void fractions::setNumerator(int num)
{
    if (num >= 0)
        numerator=num;
    else
    {
        num = 0;
        cout << "\nyou have bad values, sorry\n";
    }
}
void fractions::setDenominator(int den)
{
    if (den > 0)
        denominator=den;
    else
    {
        den=0;
        cout << "\nyou have bad values, sorry\n";
    }
}
void fractions::setWhole(int whl)
{
    if (whl >= 0)
        whole= whl;
    else
    {
        whl=0;
        cout << "\nyou have bad values, sorry\n";
    }
}
void fractions::setFraction(int num, int den) { setFraction(whole,num,den);}
void fractions::setFraction( int who, int num, int den )
{
    numerator = num ;
    whole = who ;
    denominator = den ;
    if ( numerator < 0) numerator = 0 ;
    if ( denominator <= 0 ) denominator = 1 ;
    if ( whole < 0 ) whole = 0 ;
}
//----------------------------------------------------------------------------get functions
int fractions::getNumerator() const { return numerator; }
int fractions::getDenominator() const { return denominator; }
int fractions::getWhole() const { return whole; }
//----------------------------------------------------------------------------print functions
void fractions::printFraction() const{ cout << whole << " " << numerator << "/" << denominator << endl; }


/*****************************************************TEST*****************************************************
 **the default constructor is called**
 this program will set any numbers less than 1 in denominator to 1 and any negative number in numerator and whole number will be set to 0;
 thanks;
 enter your fractions with a space in between:
 12
 13
 
 enter your whole number:
 15
 **the copy constructor is called**
 
 **the two argument constructor is called**
 
 **the three argument constructor is called**
 Here is your Fraction
 Fraction #1:
 15 12/13
 
 the whole number is:
 15
 the numerator is:
 12
 the denominator is:
 13
 
 Fraction #2:
 15 12/13
 Fraction #3:
 0 5/6
 Fraction #4:
 1 2/3
 sh: pause: command not found
 
 **the destructor is called**
 0 0/1
 
 
 **the destructor is called**
 0 0/1
 
 
 **the destructor is called**
 0 0/1
 
 
 **the destructor is called**
 0 0/1
 

 
 ----------------------------------------------------------------bad values
 **the default constructor is called**
 this program will set any numbers less than 1 in denominator to 1 and any negative number in numerator and whole number will be set to 0;
 thanks;
 enter your fractions with a space in between:
 0
 0
 
 enter your whole number:
 0
 **the copy constructor is called**
 
 **the two argument constructor is called**
 
 **the three argument constructor is called**
 Here is your Fraction
 Fraction #1:
 0 0/1
 
 the whole number is:
 0
 the numerator is:
 0
 the denominator is:
 1
 
 Fraction #2:
 0 0/1
 Fraction #3:
 0 5/6
 Fraction #4:
 1 2/3
 sh: pause: command not found
 
 **the destructor is called**
 0 0/1
 
 
 **the destructor is called**
 0 0/1
 
 
 **the destructor is called**
 0 0/1
 
 
 **the destructor is called**
 0 0/1
 */



