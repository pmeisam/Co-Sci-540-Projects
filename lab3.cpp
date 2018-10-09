#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
//-----------------------------------------------------------creating a record structure
struct Record
{
    string firstName,lastName,idNumber,email;
    double GPA;
};
//-----------------------------------------------------------function to display all the records
void DisplayRecords(struct Record *records[],int n)
{
    cout<<endl<<setw(10)<<"IDNUMBER"<<setw(15)<<"FIRST NAME"<<setw(15)<<"LAST NAME"<<setw(10)<<"GPA"<<setw(10)<<"EMAIL";
    for(int i=0;i<n+1;i++)
        cout<<endl<<left<<"\t"<<records[i]->idNumber<<"\t"<<records[i]->firstName<<"\t\t\t"<<records[i]->lastName<<"\t\t\t"<<records[i]->GPA<<"\t\t"<<records[i]->email;
    cout<<endl;
}
//-----------------------------------------------------------function to sort the records and display it
void SortRecords(struct Record *records[],int n)
{
    while(true)
    {
        int option;
        cout<<"\nSorting options\n"<<"1.First name\n"<<"2.Last name\n"<<
        "3.GPA\n"<<"4.Id number\n"<<"5.Email\n"<<"6.Exit\n"<<"Enter your option: \n";
        cin>>option;                                                 //getting option from user
        switch(option)
        {
            case 1:                                                   //sorting by firstname
                for(int i=0;i<n+1;i++)
                {
                    for(int j=0;j<n+1;j++)
                    {
                        if(records[i]->firstName.compare(records[j]->firstName)<0)
                        {
                            struct Record *t;
                            t=records[i];
                            records[i]=records[j];
                            records[j]=t;
                        }
                    }
                }
                break;
            case 2:                                                    //sorting by lastname
                for(int i=0;i<n+1;i++)
                {
                    for(int j=0;j<n+1;j++)
                    {
                        if(records[i]->lastName.compare(records[j]->lastName)<0)
                        {
                            struct Record *t;
                            t=records[i];
                            records[i]=records[j];
                            records[j]=t;
                        }
                    }
                }
                break;
            case 3: //sorting by GPA
                for(int i=0;i<n+1;i++)
                {
                    for(int j=0;j<n+1;j++)
                    {
                        if(records[i]->GPA < records[j]->GPA)
                        {
                            struct Record *t;
                            t=records[i];
                            records[i]=records[j];
                            records[j]=t;
                        }
                    }
                }
                break;
            case 4:                                                      //sorting by idNumber
                for(int i=0;i<n+1;i++)
                {
                    for(int j=0;j<n+1;j++)
                    {
                        if(records[i]->idNumber.compare(records[j]->idNumber)<0)
                        {
                            struct Record *t;
                            t=records[i];
                            records[i]=records[j];
                            records[j]=t;
                        }
                    }
                }
                break;
            case 5:                                                         //sorting by email
                for(int i=0;i<n+1;i++)
                {
                    for(int j=0;j<n+1;j++)
                    {
                        if(records[i]->email.compare(records[j]->email)<0)
                        {
                            struct Record *t;
                            t=records[i];
                            records[i]=records[j];
                            records[j]=t;
                        }
                    }
                }
                break;
            case 6:
                exit(0);
            default:
                if(option<1 || option>6)                         // checking for invalid case
                    cout<<"INVALID CHOICE"<<endl;
        }
        DisplayRecords(records,n);                               //displaying sorted records
    }
}
int main()
{
    struct Record *records[10];                                 //array of pointers to structures
    int n=-1;
    ifstream infile("/Users/meisam/Desktop/CO SCI 540/lab 3/file.txt");         //openning file
    if(!infile)                                                 //checking for file existance
    {
        cout<<endl<<"Error in processing input file ";
        exit(0);
    }
    while(!infile.eof())                                         //reading the file
    {
        records[++n]=new Record();
        infile>>records[n]->firstName;
        infile>>records[n]->lastName;
        infile>>records[n]->GPA;
        infile>>records[n]->idNumber;
        infile>>records[n]->email;
    }
    while(true)
    {
        int option;
        cout<<endl<<"1. Print unsorted records\n"<<"2. Sorting the records\n"
                    <<"3. Quit\n"<<"\nEnter a choice:\n";
        cin>>option;
        switch(option)
        {
                
            case 1:DisplayRecords(records,n);               //print unsoerted records option
                break;
            case 2:SortRecords(records,n);                  //sort and display records option
                break;
            case 3:                                         //exit the program option
                exit(0);
            default:
                if(option<1 || option>3)                    // checking for invalid case
                    cout<<"INVALID CHOICE"<<endl;
        }
    }
    return 0;
}
