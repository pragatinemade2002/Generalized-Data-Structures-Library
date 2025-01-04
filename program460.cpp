#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
class DoublyLL
{
private:
    struct nodeDL<T> *First;
    int iCount;

public:
    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T> *temp = First;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |<->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> *newn = new nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> *newn = new nodeDL<T>;
    struct nodeDL<T> *temp = First;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    if (iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeDL<T> *newn = new nodeDL<T>;
        struct nodeDL<T> *temp = First;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        cout << "Linked list is empty\n";
        return;
    }

    if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeDL<T> *temp = First;
        First = First->next;
        First->prev = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (First == NULL)
    {
        cout << "Linked list is empty\n";
        return;
    }

    if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeDL<T> *temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeDL<T> *temp = First;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        struct nodeDL<T> *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        delete temp2;

        iCount--;
    }
}


/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>:: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

/////////////////////////////////////////////////////////////
//
//Singly Circular Linked List 
//
/////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

template <class T>
struct nodeSC
{
    T data;
    struct nodeSC *next;
};

template <class T>
class SinglyCL
{
private:
    nodeSC<T> *First;
    nodeSC<T> *Last;
    int CountNode;

public:
    SinglyCL();
    void Display();
    int Count();
    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPosition(T No, int pos);
};

// Constructor
template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    CountNode = 0;
}

// Display: Traverses and displays the elements of the linked list
template <class T>
void SinglyCL<T>::Display()
{
    if (First == NULL && Last == NULL) // Empty list
    {
        cout << "The list is empty." << endl;
        return;
    }

    nodeSC<T> *temp = First;

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != First);

    cout << "HEAD" << endl; // Indicate the circular nature of the list
}

// Count: Returns the number of elements in the linked list
template <class T>
int SinglyCL<T>::Count()
{
    return CountNode;
}

// InsertFirst: Inserts an element at the beginning of the linked list
template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    nodeSC<T> *newn = new nodeSC<T>; // Allocate memory for the new node

    newn->data = No;
    newn->next = NULL;

    if (First == NULL && Last == NULL) // If the list is empty
    {
        First = newn;
        Last = newn;
        Last->next = First; // Point the last node's next to the first node
    }
    else // If the list is not empty
    {
        newn->next = First; // New node points to the current first node
        First = newn;       // Update First to the new node
        Last->next = First; // Update the last node's next to maintain the circular nature
    }

    CountNode++; // Increment the count of nodes
}

// InsertLast: Inserts an element at the end of the linked list
template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    nodeSC<T> *newn = new nodeSC<T>; // Allocate memory for the new node

    newn->data = No;
    newn->next = NULL;

    if (First == NULL && Last == NULL) // If the list is empty
    {
        First = newn;
        Last = newn;
        Last->next = First; // Point the last node's next to the first node
    }
    else // If the list is not empty
    {
        Last->next = newn; // Link the last node to the new node
        Last = newn;       // Update Last to the new node
        Last->next = First; // Ensure the circular nature
    }

    CountNode++; // Increment the count of nodes
}

// InsertAtPosition: Inserts an element at a specific position in the linked list
template <class T>
void SinglyCL<T>::InsertAtPosition(T No, int pos)
{
    if (pos < 1 || pos > CountNode + 1) // Invalid position
    {
        cout << "Invalid position!" << endl;
        return;
    }

    if (pos == 1) // Insert at the beginning
    {
        InsertFirst(No);
        return;
    }
    else if (pos == CountNode + 1) // Insert at the end
    {
        InsertLast(No);
        return;
    }

    nodeSC<T> *newn = new nodeSC<T>; // Allocate memory for the new node

    newn->data = No;
    newn->next = NULL;

    nodeSC<T> *temp = First;

    // Traverse to the (pos-1)th node
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newn->next = temp->next; // Link new node to the (pos)th node
    temp->next = newn;       // Link the (pos-1)th node to the new node

    CountNode++; // Increment the count of nodes
}

// Main function to test the implementation
int main()
{
    SinglyCL<int> obj;

    obj.InsertFirst(30);
    obj.InsertFirst(20);
    obj.InsertFirst(10);

    cout << "Elements in the list: ";
    obj.Display();

    cout << "Number of elements in the list: " << obj.Count() << endl;

    return 0;
}


/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////


template <typename T>
struct node
{
    T data;
    node<T>* next;
};

template <typename T>
class Stack
{
private:
    node<T>* First;
    int iCount;

public:
    Stack();
    void Display();
    int Count();
    void Push(T No);
    T Pop();
};

// Constructor
template <typename T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

// Display function
template <typename T>
void Stack<T>::Display()
{
    cout << "Elements of stack are : \n";
    node<T>* temp = First;

    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << "\n";
}

// Count function
template <typename T>
int Stack<T>::Count()
{
    return iCount;
}

// Push function (InsertFirst)
template <typename T>
void Stack<T>::Push(T No)
{
    node<T>* newn = new node<T>; // Dynamically allocate memory for the new node

    newn->data = No;
    newn->next = First;  // Link the new node to the current First node
    First = newn;        // Update First to point to the new node
    iCount++;            // Increment the count of nodes
}

// Pop function (DeleteFirst)
template <typename T>
T Stack<T>::Pop()
{
    T iValue; 
    node<T>* temp = NULL;

    if (First == NULL)
    {
        cout << "Unable to pop the element as stack is empty\n";
        return T();  // Return a default value (e.g., 0 for int, empty string for string, etc.)
    }
    else
    {
        temp = First;  // Store the current First node in temp

        iValue = First->data;  // Get the data from the First node
        First = First->next;   // Update First to point to the next node
        delete temp;           // Deallocate the memory of the old First node

        iCount--;  // Decrement the count of nodes
    }

    return iValue;  // Return the popped value
}



/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

template <typename T>
struct node
{
    T data;
    node<T>* next;
};

template <typename T>
class Queue
{
private:
    node<T>* Front;
    node<T>* Rear;
    int iCount;

public:
    Queue();
    void Display();
    int Count();
    void EnQueue(T No);
    T DeQueue();
};

// Constructor
template <typename T>
Queue<T>::Queue()
{
    Front = NULL;
    Rear = NULL;
    iCount = 0;
}

// Display function
template <typename T>
void Queue<T>::Display()
{
    cout << "Elements of queue are : \n";
    node<T>* temp = Front;

    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << "\n";
}

// Count function
template <typename T>
int Queue<T>::Count()
{
    return iCount;
}

// EnQueue function (Insert at the rear)
template <typename T>
void Queue<T>::EnQueue(T No)
{
    node<T>* newn = new node<T>;  // Dynamically allocate memory for the new node

    newn->data = No;
    newn->next = NULL;

    if (Rear == NULL)  // If the queue is empty
    {
        Front = newn;
        Rear = newn;
    }
    else  // If the queue is not empty
    {
        Rear->next = newn;  // Link the current rear node to the new node
        Rear = newn;        // Update rear to the new node
    }

    iCount++;  // Increment the count of nodes
}

// DeQueue function (Remove from the front)
template <typename T>
T Queue<T>::DeQueue()
{
    T iValue;
    node<T>* temp = NULL;

    if (Front == NULL)  // If the queue is empty
    {
        cout << "Unable to dequeue as the queue is empty\n";
        return T();  // Return a default value (e.g., 0 for int, empty string for string, etc.)
    }
    else  // If the queue is not empty
    {
        temp = Front;  // Store the current front node in temp

        iValue = Front->data;  // Get the data from the front node
        Front = Front->next;   // Update front to point to the next node

        if (Front == NULL)  // If the queue becomes empty after dequeue
        {
            Rear = NULL;
        }

        delete temp;  // Deallocate the memory of the old front node

        iCount--;  // Decrement the count of nodes
    }

    return iValue;  // Return the dequeued value
}
///////////////////////////////////////////////////////////
//
// Code for Tree Inorder , Postorder , Preorder
//
////////////////////////////////////////////////////////

template <typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree
{
private:
    Node<T>* root;

    void inorderHelper(Node<T>* node)
    {
        if (node != nullptr)
        {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

    void preorderHelper(Node<T>* node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }

    void postorderHelper(Node<T>* node)
    {
        if (node != nullptr)
        {
            postorderHelper(node->left);
            postorderHelper(node->right);
            cout << node->data << " ";
        }
    }

    Node<T>* searchHelper(Node<T>* node, T value)
    {
        if (node == nullptr || node->data == value)
            return node;

        if (value < node->data)
            return searchHelper(node->left, value);
        
        return searchHelper(node->right, value);
    }

    Node<T>* insertHelper(Node<T>* node, T value)
    {
        if (node == nullptr)
            return new Node<T>(value);

        if (value < node->data)
            node->left = insertHelper(node->left, value);
        else if (value > node->data)
            node->right = insertHelper(node->right, value);

        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(T value)
    {
        root = insertHelper(root, value);
    }

    void inorder()
    {
        inorderHelper(root);
        cout << endl;
    }

    void preorder()
    {
        preorderHelper(root);
        cout << endl;
    }

    void postorder()
    {
        postorderHelper(root);
        cout << endl;
    }

    bool search(T value)
    {
        Node<T>* result = searchHelper(root, value);
        return result != nullptr;
    }
};


int main()
{
    // LL of integer
    cout<<"-------------- LinkdList of Integers --------------\n";

    SinglyLL<int> *iobj = new SinglyLL<int>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);
    
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->InsertAtPos(105,5);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    iobj->DeleteAtPos(5);
    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of character
    cout<<"-------------- LinkdList of Chracters --------------\n";

    SinglyLL<char> *cobj = new SinglyLL<char>();

    cobj->InsertFirst('D');
    cobj->InsertFirst('F');
    cobj->InsertFirst('R');

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->InsertLast('E');
    cobj->InsertLast('Y');
    cobj->InsertLast('U');
    
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->InsertAtPos('W',5);

    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    cobj->DeleteAtPos(5);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of float
    cout<<"-------------- LinkdList of Floats --------------\n";

    SinglyLL<float> *fobj = new SinglyLL<float>();

    fobj->InsertFirst(90.78f);
    fobj->InsertFirst(78.99f);
    fobj->InsertFirst(67.99f);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->InsertLast(45.67f);
    fobj->InsertLast(54.78f);
    fobj->InsertLast(77.89f);
    
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->InsertAtPos(88.56,5);

    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    fobj->DeleteAtPos(5);
    fobj->Display();
    iRet = fobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    // LL of double

    cout<<"-------------- LinkdList of Doubles --------------\n";

    SinglyLL<double> *dobj = new SinglyLL<double>();

    dobj->InsertFirst(90.78978);
    dobj->InsertFirst(78.99645);
    dobj->InsertFirst(67.9934);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->InsertLast(45.67867);
    dobj->InsertLast(54.78534);
    dobj->InsertLast(77.89324);
    
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->InsertAtPos(88.56987,5);

    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    dobj->DeleteAtPos(5);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Number of elemensts are : "<<iRet<<endl;

    DoublyCL<int> *idobj = new DoublyCL<int>();

    idobj->InsertFirst(51);
    idobj->InsertFirst(21);
    idobj->InsertFirst(11);
    
    idobj->InsertLast(101);
    idobj->InsertLast(111);
    idobj->InsertLast(121);
    
    idobj->Display();
    iRet = idobj->Count();

    idobj->DeleteAtPos(5);
    
    idobj->Display();
    iRet = idobj->Count();
    //
     Queue<int> intQueue;  // Queue of integers

    intQueue.EnQueue(10);
    intQueue.EnQueue(20);
    intQueue.EnQueue(30);

    intQueue.Display();

    cout << "Dequeued element: " << intQueue.DeQueue() << endl;

    intQueue.Display();

    cout << "Total elements in the queue: " << intQueue.Count() << endl;
    //

    Stack<int> intStack;  // Stack of integers

    intStack.Push(10);
    intStack.Push(20);
    intStack.Push(30);
    
    intStack.Display();
    
    cout << "Popped element: " << intStack.Pop() << endl;
    
    intStack.Display();
    
    cout << "Total elements in the stack: " << intStack.Count() << endl;

    // Stack of strings
    Stack<string> stringStack;

    stringStack.Push("Hello");
    stringStack.Push("World");
    
    stringStack.Display();
    
    cout << "Popped element: " << stringStack.Pop() << endl;
    
    stringStack.Display();
    
    cout << "Total elements in the stack: " << stringStack.Count() << endl;

    // Queue of strings
    Queue<string> stringQueue;

    stringQueue.EnQueue("Hello");
    stringQueue.EnQueue("World");

    stringQueue.Display();

    cout << "Dequeued element: " << stringQueue.DeQueue() << endl;

    stringQueue.Display();

    cout << "Total elements in the queue: " << stringQueue.Count() << endl;
    //

    return 0;
}