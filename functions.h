#ifndef FUNCTIONS_H
#define FUNCTIONS_H


struct Brand
{
    char number[10];
    char name[20];
    char price[10];
};
void Menu(struct Brand *a, const int numOfBrand);
void SortCatalog(struct Brand *a, const int numOfBrand);
void input(struct Brand *a, int begin, int numOfBrand);
void output(struct Brand *a, int num);
void repairUp(struct Brand *a, int i, int numOfBrand, int (*fptr)(Brand,Brand));
void buildUp (struct Brand *a, const int numOfBrand, int (*fptr)(Brand,Brand));
void sortUp(struct Brand *a,const int numOfBrand,int (*fptr)(Brand,Brand));
void repairDown(struct Brand *a, int i, int numOfBrand, int (*fptr)(Brand,Brand));
void buildDown (struct Brand *a, const int numOfBrand, int (*fptr)(Brand,Brand));
void sortDown(struct Brand *a,const int numOfBrand,int (*fptr)(Brand,Brand));
int compareByName(struct Brand a1, struct Brand a2);
int compareByNumber(struct Brand a1, struct Brand a2);
int compareByPrice(struct Brand a1, struct Brand a2);

#endif
