#include "functions.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

using namespace std;

void Menu(struct Brand *a,int n)
{
    int numOfBrand;
    int numOfUseBrand;
    char enter;
    while (true)
    {
        cout<<"Main Menu!"<<endl;
        cout<<"For Exit press 0 \n"<<endl;
        cout<<"For new Brand press 1 \n"<<endl;
        cout<<"For add new Brand to DB press 2 \n"<<endl;
        cout<<"For seen DB press 3 \n"<<endl;
        cout<<"For compare DB press 4 \n"<<endl;

        cin>>enter;
        if (enter=='0')
        {
            exit(0);
        }
        if (enter=='1')
        {
            fstream myInf;
            input(a,numOfBrand,numOfUseBrand);
            myInf.open("myInf.txt",ios::in|ios::binary);
            myInf.read((char *) a, numOfBrand*sizeof(int));
            myInf.close();
        }
        if (enter=='2')
        {
            cout<<"Enter the NUMBER of use Brand"<<endl;
            cin>>numOfUseBrand;
            input(a,numOfBrand,numOfBrand+numOfUseBrand);
            numOfBrand+=numOfUseBrand;
            fstream inform("inform.txt",ios::out|ios::binary);
            inform.write((*char)&numOfBrand,sizeof(int));
            inform.close();
        }
        if (enter=='3')
        {
            fstream fin("inform.txt",ios::in);
            fin.read((char *)&numOfBrand,sizeof(int));
            fin.close();
            cout << "DataBase:\n" << endl;
            output(a, numOfBrand);
        }
        if (enter=='4')
        {
            SortCatalog(a,numOfBrand);
        }
    }
}
void SortCatalog(struct Brand *a, const int numOfBrand)
{
    Brand *one=new Brand[20];
    typedef int (*pointer)(Brand,Brand);
    pointer *point;
    point=new pointer[3];
    point[0]=compareByName;
    point[1]=compareByNumber;
    point[2]=compareByPrice;
    cout<<"Welocom to compare Menu"<<endl;
    cout<<"For compare from NAME (A-Z) press 1"<<endl;
    cout<<"For compare from NAME (Z-A) press 2"<<endl;
    cout<<"For compare from NUMBER (0-9) press 3"<<endl;
    cout<<"For compare from NUMBER (9-0) press 4"<<endl;
    cout<<"For compare from PRICE (0-9) press 5"<<endl;
    cout<<"For compare from PRICE (9-0) press 6"<<endl;
    int enter=getch();
    if (enter=='1')
    {
        SortUp(one,numOfBrand,point[0]);
    }
    if (enter=='2')
    {
        SortDown(one,numOfBrand,point[0]);
    }
    if (enter=='3')
    {
        SortUp(one,numOfBrand,point[1]);
    }
    if (enter=='4')
    {
        SortDown(one,numOfBrand,point[1]);
    }
    if (enter=='5')
    {
        SortUp(one,numOfBrand,point[2]);
    }
    if (enter=='6')
    {
        SortDown(one,numOfBrand,point[2]);
    }
}

void input(struct Brand *a, int begin, int numOfBrand)
{
    for (int i=begin; i<begin+numOfBrand; begin++)
    {
        cout<<"Enter name"<<endl;
        cin.getline(a[i].name,20);
        cout<<"Enter number"<<endl;
        cin.getline(a[i].number,20);
        cout<<"Enter price"<<endl;
        cin.getline(a[i].price,20);
    }

}


void output(struct Brand *a, int num)
{
    for (int i=0; i<num; i++)
    {
        cout<<a[i].number<<" ";
        cout<<a[i].name<<" ";
        cout<<a[i].price<<" ";
    }
}



void repairUp(struct Brand *a, int i, int numOfBrand, int (*fptr)(Brand,Brand))
{
    int n=numOfBrand;
    int left=2*i+1;
    int right=2*i+2;
    int larg=i;
    if (left<=n&&(*fptr)(a[left],a[i])>0)
    {
        larg=left;
    }
    if (right<=n&&(*fptr)(a[i], a[left]) > 0 && (*fptr)(a[i], a[right]) < 0))
    {
        larg=right;
    }
    if (larg!=i)
    {
        int a;
        a=a[i];
        a[i]=a[larg];
        a[larg]=a;
        repairUp(a,larg,numOfBrand,(*fptr));
    }
}

void buildUp (struct Brand *a, const int numOfBrand, int (*fptr)(Brand,Brand))
{
    int n = numOfBrand;
    for( int i = n/2; i >= 0; --i)
    {
        repairUp(a, i, numOfBrand, (*fptr));
    }
}



void sortUp(struct Brand *a,const int numOfBrand,int (*fptr)(Brand,Brand))
{
    int n-numOfBrand
    int larg;
    buildUp(a, numOfBrand,(*fptr));
    for (int i=n-1; i>=1; --i)
    {
        int a;
        a=A[i];
        A[i]=A[larg];
        A[larg]=a;
        --n;
        repairUp(a,larg,numOfBrand,(*fptr));
    }
}

void repairDown(struct Brand *a, int i, int numOfBrand, int (*fptr)(Brand,Brand))
{
    int n=numOfBrand;
    int left=2*i+1;
    int right=2*i+2;
    int larg=i;
    if (left<=n&&(*fptr)(a[left],a[i])<0)
    {
        larg=left;
    }
    if (right<=n&&(*fptr)(a[i], a[left]) < 0 && (*fptr)(a[i], a[right]) < 0))
    {
        larg=right;
    }
    if (larg!=i)
    {
        int a;
        a=a[i];
        a[i]=a[larg];
        a[larg]=a;
        repairDown(a,larg,numOfBrand,(*fptr));
    }
}

void buildDown (struct Brand *a, const int numOfBrand, int (*fptr)(Brand,Brand))
{
    int n = numOfBrand;
    for( int i = n/2; i >= 0; --i)
    {
        repairDown(a, i, numOfBrand, (*fptr));
    }
}



void sortDown(struct Brand *a,const int numOfBrand,int (*fptr)(Brand,Brand))
{
    int n-numOfBrand
    int larg;
    buildDown(a, numOfBrand,(*fptr));
    for (int i=n-1; i>=1; --i)
    {
        int a;
        a=A[i];
        A[i]=A[larg];
        A[larg]=a;
        --n;
        repairDown(a,larg,numOfBrand,(*fptr));
    }
}

int compareByName(struct Brand a1, struct Brand a2)
{
    return strcmp(a1.name, a2.name);
}

int compareByNumber(struct Brand a1, struct Brand a2)
{
    return strcmp(a1.number, a2.number);
}

int compareByPrice(struct Brand a1, struct Brand a2)
{
    return strcmp(a1.price, a2.price);
}

