void insertatstart(node *&h, int info)
{
    node *p;
    p = new node;

    p->info = info;
    p->next = h;
    h = p;

    return;
}

void insertatend(node *h, int info)
{
    if (h == null)
    {
        return;
    }

    node *p;
    p = new node;
    p->info = info;
    p->next = null;

    node *q = h;

    while (q->next != null)
    {
        q = q->next;
    }

    q->next = p;

    return;
}

void insertAfterValue(node *h, int n, int info)
{
    if (h == null)
    {
        return;
    }

    node *p;
    p = new node;
    p->info = info;

    node *q = h;

    while (q != null && q->info != n)
    {
        q = q->next;
    }

    if (q == null)
    {
        return;
    }

    p->next = q->next;
    q->next = p;

    return;
}

void insertb4tail(node *h, int info)
{
    if (h == null)
    {
        return;
    }

    node *p;
    p = new node;
    p->info = info;

    if (h->next == null)
    {
     p->next=h;
     h=p;
     return;
    }

    node*q= h;

    while(q->next->next != null)
    {
        q=q->next;
    }

    p->next=q->next;
    q->next=p;
    return;
}

void insertatind(node* h,int info,int ind)
{
    if(h==null)
    {
        return;
    }
 node*p;
    p=new node;
    p->info=info;

    if(ind ==0)
    {
      p->next=h;
      h=p;
      return;
    }

    int i=0;
    node * q=h;
    while( i != ind-1 && q!= null)
    {
        i++;
        q=q->next;
    }

    if( q==null)
    {
        return;
    }

    p->next=q->next;
    q->next=p;

    return;
   
}