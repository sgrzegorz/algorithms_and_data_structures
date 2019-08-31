node *fixSortedList(node *first)
{
    node *p,*q;
    p=first; q=first->next;

    bool flaga=true;
    while(q->next!=NULL)
    {
        if(p->w > q->w)
        {

            p->next=q->next;
            flaga=false;
            break;
        }
        p=p->next;
        q=q->next;
    }
    if(flaga) p->next=NULL;

    p=new node;
    p->next=first;
    first=p;
    node *r=p->next;
    while(r!=NULL)
    {
        if(q->w<r->w)
        {
            p->next=q;
            q->next=r;
            return first->next;
        }
    }
    r->next=q;
    q->next=NULL;
    return first->next;


}
===========================================================