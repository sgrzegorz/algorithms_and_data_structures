#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
traverse_a_tree(x,k){
    while(x!=NULL and k!=x->key)
    {
        if(k<x->key)
            x=x->left
        else
            x=x->right;
    }
    return x;

}
