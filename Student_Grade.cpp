#include<bits/stdc++.h>
using namespace std;
struct student
{
    string name;
    int roll_no;
    int marks[5];
};
struct student arr[10];
int temp=0;

void add_student()
{
    struct student obj;
    cout<<"Enter Student name : "<<endl;
    cin>>obj.name;
    cout<<"Enter roll no. : "<<endl;
    cin>>obj.roll_no;
    cout<<"Enter marks of Maths, Physics, Chemistry, English and Hindi simultaneously.:"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>obj.marks[i];
    }
    arr[temp++]=obj;
}

int calculate_total(int n)
{
    int total=0;
    for(int i=0;i<5;i++)
    {
        total=total+(arr[n].marks[i]);
    }
    return total;
}

float calc_percentage(int n)
{
    float perc=(calculate_total(n)/500.0)*100;
    return perc;
}

char calc_grade(int n)
{
    char grade;
    float per=calc_percentage(n);
    if(per>=90.0)
    grade='A';
    else if(per>=80 && per<90)
    grade='B';
    else if(per>=70 && per<80)
    grade='C';
    else if(per>=60 && per<70)
    grade='D';
    else if(per>=50 && per<60)
    grade='E';
    else
    grade='F';

    return grade;
}

void display(int n)
{
    cout<<"Name of the student : "<<arr[n].name<<endl;
    cout<<"Roll no. : "<<arr[n].roll_no<<endl;
    cout<<"Marks in 5 subjects: \n\nMaths        Physics         Chem        English         Hindi\n\n";
    for(int i=0;i<5;i++)
    cout<<"  "<<arr[n].marks[i]<<"          ";
    cout<<endl;
    cout<<"Total Marks : "<<calculate_total(n)<<endl;
    cout<<"Percentage : "<<calc_percentage(n)<<endl;
    cout<<"Grade : "<<calc_grade(n);
}

void find_topper()
{
    int s=0;
    for(int i=0;i<temp;i++)
    {
        if(calc_percentage(s)<calc_percentage(i+1))
        s=i+1;
    }
    cout<<"Topper Details : \n\n";
    display(s);
}

int main()
{
    int ch,n;
    do
    {
        cout<<"MENU : \n1.Add Student \n2.View a specific student according to serial number \n3.View Topper \n4.Exit \n\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        cout<<"\n\n";
        switch(ch)
        {
            case 1:     add_student();
                        cout<<"\nStudent added successfully.\n\n";
                        break;

            case 2:     cout<<"\nEnter the serial number of student : ";
                        cin>>n;
                        cout<<"\n\n";
                        display(n-1);
                        cout<<"\n\n";
                        break;

            case 3:     find_topper();
                        cout<<"\n\n";
                        break;

            case 4:     return 0;
            
        }
    } while (ch!=4);
    
}