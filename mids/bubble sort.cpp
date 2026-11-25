void bubblesort(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
            }
        }
    }
}

void bubblesort(int A[],int n)
{

    for(int i=0;i<n-1;i++)
    {
        bool swapped=false;
        for(int j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
                swapped=true;
            }
        }

        if(swapped==false)
        {
            return;
        }
    }
}

void selectionsort(int A[];int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            {
                min=j;
            }
        }

        swap(A[min],A[i]);
    }
}

void insertionsort(int A[],int n)
{
      for(int i=1;i<n;i++)
      {
        int key=A[i];
        int j=i-1;
        while(j>=0 && A[j]>key)
        {
            A[j+1]=A[j];
            j--;
        }

        j++;
        A[j]=key;
      }
}