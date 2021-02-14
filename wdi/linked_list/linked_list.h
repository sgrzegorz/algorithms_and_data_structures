#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
using namespace std;

struct node
{
    int w;
    node*next;
};

void wypisz(node *f);
node *buduj(int t[],int n);


#endif // LINKEDLIST_H_INCLUDED
