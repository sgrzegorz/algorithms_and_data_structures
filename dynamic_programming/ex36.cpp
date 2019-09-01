#include <iostream>

using namespace std;

struct Employee{
    Employee **emp;
    int employees;
    int fun;
    int f,g;
};

void reset(Employee *boss)
{
    boss->f=-1;
    boss->g=-1;
    for(int i=0;i<boss->employees;i++)
    {
        reset(boss->emp[i]);
    }
}
int g(Employee *boss);
int f(Employee *boss);

int g(Employee *boss)
{
    //if(boss->g!=-1) return boss->g;
    boss->g=0;
    for(int i=0;i<boss->employees;i++)
    {
        boss->g+=f(boss->emp[i]);
    }
    return boss->g;
}

int f(Employee *boss)
{
    //if(boss->f!=-1) return boss->f;
    boss->f=0;
    for(int i=0;i<boss->employees;i++)
    {
        boss->f+=g(boss->emp[i]);
    }
    boss->f+=boss->fun;
    boss->f=max(boss->f,g(boss));
    return boss->f;
}

int party(Employee *boss)
{
    reset(boss);
    return f(boss);
}

Employee* x(int wartosc, int pracownicy)
{
    Employee *node=new Employee;
    node->fun=wartosc;
    node->employees=pracownicy;
    node->emp=new Employee*[pracownicy];
    return node;
}

int main()
{
   Employee *y=x(100,3);

   y->emp[0]=x(8,2);
    y->emp[1]=x(5,0);

    y->emp[2]=x(10,2);

    y->emp[0]->emp[0]=x(9,0);
    y->emp[0]->emp[1]=x(10,0);

    y->emp[2]->emp[0]=x(6,2);
    y->emp[2]->emp[1]=x(7,2);

    y->emp[2]->emp[0]->emp[0]=x(7,0);
    y->emp[2]->emp[0]->emp[1]=x(8,0);
    y->emp[2]->emp[1]->emp[0]=x(5,0);
    y->emp[2]->emp[1]->emp[1]=x(6,0);

    //========

    cout<<party(y);
    return 0;
}
