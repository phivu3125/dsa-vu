#include <iostream>
#include <math.h>
using namespace std;


//-----------------------------------
// Dinh nghia cac ham co ban cua Node
struct NODE
{
   int data;
   NODE* pNext;
};

struct List
{
   NODE* pHead;
};

NODE* CreateNode(int value)
{
    NODE* p = new NODE;
    p->data = value;
    p->pNext = NULL;
    return p;
}

List* InitLinkedList()
{
    List* list = new List;
    list->pHead = NULL;
    return list;
}

void AddLast(NODE* &pHead, NODE *p)
{
    if (pHead == NULL) {
       pHead = p;
       return;
    }
    AddLast(pHead->pNext, p);
}

NODE *PickFirst(NODE* &pHead)
{
   NODE *p = pHead;
   if (pHead != NULL)
   {
       pHead = p->pNext;
       p->pNext = NULL;
   }
   return p;
}


//----------------------------------
// Khoi tao cac ham co ban cua Queue
struct Queue
{
   NODE *pHead, *pTail;
};

Queue createQueue()
{
    Queue Q; //= new Queue;
    Q.pHead = NULL;
    Q.pTail = NULL;
    return Q;
}

bool IsEmpty(Queue Q)
{
   return (Q.pHead == NULL);
}

void Enqueue(Queue &Q, NODE *p)
{
   if (Q.pHead == NULL)
       Q.pHead = Q.pTail = p;
   else
   {
       Q.pTail->pNext = p;
       Q.pTail = p;
   }
}

int Dequeue(Queue &Q)
{
   NODE *p = Q.pHead;
   if (Q.pHead == Q.pTail)
       Q.pHead = Q.pTail = NULL;
   else if (Q.pHead != NULL)
   {
       Q.pHead = p->pNext;
       p->pNext = NULL;
   }
   int val = p->data;
   delete p;
   return val;
}


//---------------------------------------------------------
// Ham tim gia tri lon nhat trong mang de tinh so vong lap
int LargestElement(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (max < A[i]) {
            max = A[i];
        }
    }
    return max;
}



//------------------------
// Ham sap xep radix sort
void RadixSort (int A[], int n)
{
    int n_loop = log10(LargestElement(A, n)) + 1; 

    for (int i = 1; i <= n_loop; i++)
    {
        // Tao 10 queue 0->9
        Queue* Q = new Queue[10];
        for (int u = 0; u < 10; u++){
            Q[u] = createQueue();
        }


        // Xet xem chu so o vi tri thu i la so may
        // Vd: 324 thi vong for1: temp = 4 || for2: temp = 2 || for3: temp = 3
        for (int j = 0; j < n; j++)
        {
            int temp = A[j];
            int k = 1;
            while (k < i)
            {
                temp = temp / 10;
                k++;
            }
            temp = temp % 10;

            // Pick phan tu dau trong List bo vao Queue
            int val = A[j];
            switch (temp)
            {
            case 0:
                Enqueue(Q[0], CreateNode(val));
                break;
            
            case 1:
                Enqueue(Q[1], CreateNode(val));
                break;

            case 2:
                Enqueue(Q[2], CreateNode(val));
                break;

            case 3:
                Enqueue(Q[3], CreateNode(val));
                break;

            case 4:
                Enqueue(Q[4], CreateNode(val));
                break;
            
            case 5:
                Enqueue(Q[5], CreateNode(val));
                break;

            case 6:
                Enqueue(Q[6], CreateNode(val));
                break;

            case 7:
                Enqueue(Q[7], CreateNode(val));
                break;

            case 8:
                Enqueue(Q[8], CreateNode(val));
                break;

            case 9:
                Enqueue(Q[9], CreateNode(val));
                break;
            }
        }


        // Lay cac phan tu ra khoi Queue va sap lai vao List
        int k = 0;
        for (int u = 0; u < 10; u++)
        {
            while (IsEmpty(Q[u]) != true){
                A[k] = Dequeue(Q[u]);
                k++;
            }
        }
    }
}

int main ()
{
    int A[12] = {129,23,31,4,15,3,2,58,1610,98,47,136};
    int n = 12;

    RadixSort (A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}