struct node{
    int info;
    node* prev;
    node* next;
};

void insInDlist(node *h ,int y, intx)
{
    if(h== null)
    {
     return;   
    }
node*p=h;
    while(p!= null && p->info != y)
    {
        p=p->next;
    }

    if(p==null)
    {
        return;
    }

    node *q;
    q=new node;
    q->info=x;
    q->next=p->next;
    q->prev=p;
    
if(p->next != null)
{
  p->next->prev=q;
}

p->next=q;
}