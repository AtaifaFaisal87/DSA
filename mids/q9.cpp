void newHead(node*& h, int x)
{
    if(h==null)
    {
        return;
    }

    node*p=h;

    while(p!=null && p->info!=x)
    {
        p=p->next;
    }

    if(p==null)
    {
        return;
    }

    while(h!=p)
    {
        node*q=h;
        h=h->next;
        delete q;
    }

    return;
}