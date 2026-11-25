void del_x(node * h,int n)
{
 if(h==null)
 {
    return;
 }   

 while(h!= null && h->info==x)
 {
    node*temp=h;
     h = h->next;
    delete temp;
 }

  if(h==null)
 {
    return;
 } 

 node*q=h;
nod*p=h->next;

while(p!=null)
{
    if(p->info==x)
    {
        q->next=p->next;
        delete p;
        p=q->next;
    }
    else{
        q=p;
        p=p->next;
    }
}

return;
}

void delatstart(node*h)
{
    if(h==null)
    {
        return;
    }

    node* p=h;
    h=h->next;
    delete p;

}

void delatend(node*h)
{
    if(h==null)
    {
        return;
    }
    if(h->next==null)
    {
        node* temp=h;
        h=null;
        delete temp;
        return;
    }

    node*p=h;
    while(p->next->next!=null)
    {
        p=p->next;
    }

    node*temp=p->next;
    delete temp;
    p->next=null;
    return;
}



void delatindex(node* h,int ind)
{
    if(h==null)
    {
        return;
    }

    if(ind==0)
    {
        node*p=h;
        h=h->next;
        delete p;
        return;
    }

    node* q=h;
    int i=0;

    while(i != ind-1 && q != null)
    {
        i++;
        q=q->next;
    }

    if(q==null || q->next==null)
    {
        return;
    }

    node* temp=q->next;
    q->next=temp->next;
    delete temp;

    return;
}
