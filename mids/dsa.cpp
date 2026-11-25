Node* forward()
{
    Node* head;
    head = NULL;

    Node *p, *q;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        p = new Node;

        cout << "ENTER INFO: ";
        cin >> p->info;

        p->next = NULL;

        if(head == NULL)
        {
            head = p;
        }
        else
        {
            q->next = p;
        }

        q = p;
    }

    return head;
}

Node* backward()
{
    Node* head;
    head = NULL;

    Node* p;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        p = new Node;

        cout << "ENTER INFO: ";
        cin >> p->info;

        p->next = head;
        head = p;
    }

    return head;
}