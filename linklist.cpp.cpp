#include<iostream>
#include<string>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
class NODE
{
public:
    int DATA;
    NODE *NEXT;
    NODE *PREV;
    NODE *TEMP;
    NODE(int d)
    {
        DATA=d;
        NEXT=nullptr;
        PREV = nullptr;

    }
};
class linklist
{
public:
    NODE *PTR;
    int data;
    linklist()
    {
        PTR=nullptr;
    }
    void firstpannel()
    {
        TOP:
        char c;
        system("cls");
        cout<<"================================================================================================================================================="<<"\n";
        cout<<" \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--LINKLIST--"<<"\n";
        cout<<"================================================================================================================================================="<<"\n";
        cout<<"\n\n\n\t\t\t1.Insertion \t\t2.Deletion \t\t3.Traversing \t\t4.Searching \t\t5.Types of linklist";
        cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice--";
        c=getch();
        if(c=='1')
        {
            insertion();
            getch();
        }
        else if(c=='2')
        {
            deletion();
            getch();
        }
        else if(c=='3')
        {
            travering();
            getch();
        }
        else if(c=='4')
        {
            searching();
            getch();
        }
        else if(c=='5')
        {
            types();
            getch();
        }
        cout<<"\nDo you want to continue.."<<"\n"<<"1.Press 1 else any key..\n";
        c=getch();
        if(c=='1')
            goto TOP;

}
        void insertion()
        {
            system("cls");
             cout<<"\n\n\n\t\t\t\t\t1.AtBeginning \t\t\t2.At given position \t\t\t3.At End\n";
             cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice--";
             char b;
             b=getch();

             if(b=='1')
             {
                 system("cls");
                 cout<<" \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT BEGINNING--"<<"\n";
                cout<<"\n\nEnter Node data--";
                cin>>data;
            NODE *TEMP=new NODE(data);
            if(PTR == nullptr)
            {
                PTR=TEMP;
            }
            else
            {
                TEMP->NEXT=PTR;
                PTR=TEMP;
            }
            cout<<"\nNode successfully inserted...\n";

             }
             else if(b=='2')
             {
                 system("cls");
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT GIVEN POSITION--"<<"\n";
            NODE *TEMP = PTR;
            cout<<"Enter data after which to insert--";
            int d,c=0;
            cin>>d;
            while(TEMP!=nullptr)
            {
                if(TEMP->DATA==d)
                {
                    c=1;
                    break;
                }
                TEMP=TEMP->NEXT;
            }
            if(c==1)
            {
                cout<<"Enter new node data--";
                cin>>data;
                NODE *newNode = new NODE(data);
                newNode->NEXT = TEMP->NEXT;
                TEMP->NEXT = newNode;
                cout<<"\nNode successfully inserted...\n";
            }
            else
            {
                cout<<"\nData not found.\n";
            }
             }
             else if(b=='3')
             {
                  system("cls");
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT END--"<<"\n";
            cout<<"Enter data--";
            cin>>data;
            NODE *tempnode = new NODE(data);
            if(PTR==nullptr)
            {
                PTR=tempnode;
            }
            else
            {
                NODE *TEMP=PTR;
                while(TEMP->NEXT!=nullptr)
                {
                    TEMP=TEMP->NEXT;
                }
                TEMP->NEXT=tempnode;
            }
            cout<<"\nNode successfully inserted at end...\n";
             }
        }
         void deletion()
        {
            system("cls");
             cout<<"\n\n\n\t\t\t\t\t1.AtBeginning \t\t\t2.At given position \t\t\t3.At End\n";
             cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice--";
             char b;
             b=getch();
             if(b=='1')
             {
                 system("cls");
                 cout<<" \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT BEGINNING--"<<"\n";
                 if(PTR==nullptr)
                 {
                    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tLinklist is empty..\n";
                     return;
                 }
                 else
                 {
                     NODE *TEMP=PTR;
                     PTR=PTR->NEXT;
                     delete TEMP;
                     cout<<"\nNode deleted from beginning.\n";
                 }
             }
             else if(b=='2')
             {
                 system("cls");
                 cout<<" \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT GIVEN POSTION--"<<"\n";
                    cout<<"Enter data to delete--";
                    int d;
                    cin>>d;
                     NODE *TEMP = PTR;
                    NODE *prev = nullptr;
                    while (TEMP->NEXT != nullptr) {
                        prev = TEMP;
                        TEMP = TEMP->NEXT;
                    }
                    if (prev == nullptr) {
                        delete PTR;
                        PTR = nullptr;
                    } else {
                        prev->NEXT = nullptr;
                        delete TEMP;
                    }
                    cout << "\nNode with value " << d << " deleted.\n";
                     }
             else if(b=='3')
             {
                 system("cls");
                 cout<<" \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT END--"<<"\n";
                 if(PTR==nullptr)
            {
                cout<<"\nList is empty..\n";
                return;
            }
            NODE *temp = PTR;
            NODE *prev = nullptr;
            while(temp->NEXT!=nullptr)
            {
                prev=temp;
                temp=temp->NEXT;
            }
            if(prev==nullptr)
            {
                delete PTR;
                PTR=nullptr;
            }
            else
            {
                prev->NEXT=nullptr;
                delete temp;
            }
            cout<<"\nLast node deleted.\n";
             }
        }

         void travering()
        {
            system("cls");
            cout<<" \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--TRAVERSING--"<<"\n";
            if(PTR==nullptr)
        {
            cout<<"\n\nLinklist is empty..\n";
            return;
        }
        NODE *TEMP=PTR;
        while(TEMP!=nullptr)
        {
            cout<<TEMP->DATA<<"->";
            TEMP=TEMP->NEXT;
        }
        cout<<"NULL\n";
        }
         void searching()
        {
            system("cls");
            cout<<" \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--SEARCHING--"<<"\n";
             int val, pos = 1;
        bool found = false;
        cout << "Enter value to search: ";
        cin >> val;
        NODE *temp = PTR;
        while (temp != nullptr) {
            if (temp->DATA == val) {
                cout << "Value found""\n";
                found = true;
                break;
            }
            temp = temp->NEXT;
            pos++;
        }
        if (!found) {
            cout << "Value not found in the list.\n";
        }
        }
        void types()
        {
            system("cls");
            cout<<"\n\n\n\t\t\t\t\t1.Singly Linklsit \t\t\t2.Doubly Linklist \t\t\t3.Exit\n";
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice--";
            char s;
            s=getch();
            if(s=='1')
            {
                system("cls");
                cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--SINGLY LINKLIST--"<<"\n\n\n";
                cout<<"\t\t\t\t\tA singly linked list is a linear data structure where each element (called a node) contains: \n\t\t\t\t\tData = the actual value stored.\t\tPointer (or reference) to the next node in the sequence.";
                cout<<"\t\t\t\t\t\t\t[Data | Next] -> [Data | Next] -> [Data | Next] -> NULL";
                cout<<"\n\n\n\t\t\t\t\t1.Insertion \t\t\t2.Deletion \t\t\t3.Traversing \t\t4.Exit\n";
                cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice--";
                char a;
                a=getch();
                if(a=='1')
                {
                    system("cls");
                    cout<<"\n\n\n\t\t\t\t\t1.AtBeginning \t\t\t2.At given position \t\t\t3.At End \t\t4.Exit\n";
                    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice--";
                    char c;
                    c=getch();
                    if(c=='1')
                    {
                        system("cls");
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT BEGINNING--"<<"\n";
                        cout << "Enter data: ";
                        cin >> data;
                         NODE* tempnode = new NODE(data);
                            if (tempnode == NULL) {
                                cout << "\n\nInsufficient memory";
                                return;
                            }
                            tempnode->NEXT = NULL;
                            if (PTR == NULL) {
                                PTR = tempnode;
                            } else {
                                tempnode->NEXT = PTR;
                                PTR = tempnode;
                            }
                            cout << "\n\nNode Successfully Inserted at Start...\n\n";

                    }
                            else if(c=='2') {
                            system("cls");
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT GIVEN POSITION--"<<"\n";
                            cout<<"Enter data after which to insert: ";
                            int d;
                            cin >> d;

                            cout << "Enter new node data: ";
                            cin >> data;

                            NODE *newNode = new NODE(data);
                            if (PTR == nullptr) {
                                PTR = newNode;
                                cout << "Inserted as first node.\n";
                                return;
                            }

                            NODE *TEMP = PTR;
                            while (TEMP != nullptr && TEMP->DATA != d) {
                                TEMP = TEMP->NEXT;
                            }

                            if (TEMP == nullptr) {
                                cout << "Data not found.\n";
                                delete newNode;
                            } else {
                                newNode->NEXT = TEMP->NEXT;
                                TEMP->NEXT = newNode;
                                cout << "Node inserted after " << d << "\n";
                            }
                        }
                    else if(c=='3')
                    {
                        system("cls");
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT END--"<<"\n";
                         cout << "Enter data: ";
                         cin >> data;
                         NODE* tempnode = new NODE(data);
                        if (tempnode == NULL) {
                            cout << "\n\nInsufficient memory";
                            return;
                        }
                        tempnode->NEXT = NULL;
                        if (PTR == NULL) {
                            PTR = tempnode;
                        } else {
                            NODE* temp = PTR;
                            while (temp->NEXT != NULL) {
                                temp = temp->NEXT;
                            }
                            temp->NEXT = tempnode;
        }
        cout << "\n\nNode Successfully Inserted at End...\n\n";

                    }
                    else if(c=='4')
                    {
                        types();
                        getch();
                    }
                }
        else if(a=='2')
        {
            system("cls");
            cout<<"\n\n\n\t\t\t\t\t1.AtBeginning \t\t\t2.At given position \t\t\t3.At End \t\t4.Exit\n";
                    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice--";
                    char c;
                    c=getch();
                    if(c=='1')
                    {
                        system("cls");
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT BEGINNING--"<<"\n";
                        if (PTR == NULL) {
                        cout << "\n\nLinkList is Empty..\n\n";
                        return;
                    } else {
                        NODE* tempnode = PTR;
                        PTR = PTR->NEXT;
                        delete tempnode;
                        cout << "\n\nNode Deleted from Start..\n\n";
                    }

                    }
                        else if(c=='2') {
                            system("cls");
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT GIVEN POSITION--"<<"\n";
                            if (PTR == nullptr) {
                                cout << "List is empty.\n";
                                return;
                            }

                            cout << "Enter value to delete: ";
                            int val;
                            cin >> val;

                            NODE *temp = PTR;
                            NODE *prev = nullptr;

                            while (temp != nullptr && temp->DATA != val) {
                                prev = temp;
                                temp = temp->NEXT;
                            }

                            if (temp == nullptr) {
                                cout << "Value not found!\n";
                                return;
                            }

                            if (prev == nullptr) {
                                PTR = PTR->NEXT;
                            } else {
                                prev->NEXT = temp->NEXT;
                            }

                            delete temp;
                            cout << "Node with value " << val << " deleted.\n";
                        }

                    else if(c=='3')
                    {
                        system("cls");
                        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT END--"<<"\n";
                        NODE* temp = PTR, *PREV = PTR;
                        if (PTR == NULL) {
                            cout << "\n\nLinkList is Empty..\n\n";
                            return;
                        } else if (PTR->NEXT == NULL) {
                            NODE* TN = PTR;
                            PTR = NULL;
                            delete TN;
                        } else {
                            while (temp->NEXT != NULL) {
                                PREV = temp;
                                temp = temp->NEXT;
                            }
                            PREV->NEXT = NULL;
                            delete temp;
                        }
                        cout << "\n\nNode Deleted from End..\n\n";

                    }
                    else if(c=='4')
                    {
                        types();
                        getch();
                    }
        }
        else if(a=='3')
        {
            system("cls");
            cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT TRAVERING--"<<"\n";
             cout << "\n\n";
        if (PTR == NULL) {
            cout << "\n\nLinkList is Empty...\n\n";
            return;
        }
        NODE* TEMP = PTR;
        while (TEMP != NULL) {
            cout << TEMP->DATA << " -> ";
            TEMP = TEMP->NEXT;
        }
        cout << "NULL\n\n";
    }
        else if(a=='4')
        {
            types();
            getch();
        }
            }
            else if(s=='2')
            {
                system("cls");
                cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--DOUBLY LINKLIST--"<<"\n\n\n";
                cout<<"\t\tA Doubly Linked List is a type of linked data structure where each node contains three parts:\n\n\t\t\t\t\tData = The value to store.\n\n\t\t\t\t\tPointer to the next node (next) = Points to the node that comes after.\n\n\t\t\t\t\tPointer to the previous node (prev) = Points to the node that comes before.\n\n\t\tThis allows bidirectional traversal = \n\t\tboth forward and backward through the list,unlike a singly linked list which only goes in one direction.";
                cout<<"\n\n\t\t\t\t\t\tNULL <- prev | 10 | next]  [prev | 20 | next]  [prev | 30 | next] -> NULL";
                cout<<"\n\n\n\t\t\t\t\t1.Insertion \t\t\t2.Deletion \t\t\t3.Traversing \t\t4.Exit\n";
                    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice--";
                    char d;
                    d=getch();
                    if(d=='1')
                    {
                        system("cls");
                        cout<<"\n\n\n\t\t\t\t\t1.AtBeginning \t\t\t2.At given position \t\t\t3.At End\n";
                        cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice--";
                        char c;
                        c=getch();
                        if(c=='1')
                        {
                            system("cls");
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT BEGINNING--"<<"\n";
                                cout << "Enter data: ";
                                cin >> data;
                                NODE* tempnode = new NODE(data);
                                tempnode->NEXT = PTR;
                                PTR = tempnode;
                                cout << "Node inserted at beginning.\n";
                        }
                        else if(c=='2') {
                            system("cls");
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT GIVEN POSITION--"<<"\n";
                          cout << "Enter data after which to insert: ";
                    int d;
                    cin >> d;
                    cout << "Enter new node data: ";
                    cin >> data;
                    NODE *newNode = new NODE(data);
                    NODE *TEMP = PTR;
                    while (TEMP != nullptr && TEMP->DATA != d) {
                        TEMP = TEMP->NEXT;
                    }
                    if (TEMP == nullptr) {
                        cout << "Data not found.\n";
                        delete newNode;
                    } else {
                        newNode->NEXT = TEMP->NEXT;
                        TEMP->NEXT = newNode;
                        cout << "Node inserted after " << d << ".\n";
                        }
                        }

                        else if(c=='3')
                        {
                            system("cls");
                            cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--AT END--"<<"\n";
                            cout << "Enter data: ";
                    cin >> data;
                    NODE* tempnode = new NODE(data);
                    if (PTR == nullptr) {
                        PTR = tempnode;
                    } else {
                        NODE* temp = PTR;
                        while (temp->NEXT != nullptr)
                            temp = temp->NEXT;
                        temp->NEXT = tempnode;
                    }
                    cout << "Node inserted at end.\n";

                        }
                    }
                    else if(d=='2')
                        {
                        system("cls");
                            cout<<"\n\n\n\t\t\t\t\t1.AtBeginning \t\t\t2.At given position \t\t\t3.At End \t\t4.Exit\n";
                    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter your choice--";
                    char c;
                    c=getch();
                    if(c=='1')
                    {
                        system("cls");
                    if (PTR == nullptr) {
                        cout << "\n\nDoubly Linked List is Empty..\n\n";
                        return;
                    } else {
                        NODE* tempnode = PTR;
                        PTR = PTR->NEXT;
                        if (PTR != nullptr) {
                            PTR->PREV = nullptr;
                        }
                        delete tempnode;
                        cout << "\n\nNode Deleted from Start..\n\n";
                    }
                    }
                    else if(c=='2'){
                        cout << "Enter Node Data You want to delete: ";
                        int val;
                        cin >> val;

                        if (PTR == nullptr) {
                            cout << "List is empty.\n";
                            return;
                        }

                        NODE* temp = PTR;
                        while (temp != nullptr && temp->DATA != val) {
                            temp = temp->NEXT;
                        }

                        if (temp == nullptr) {
                            cout << "Value not found.\n";
                            return;
                        }

                        if (temp->PREV != nullptr)
                            temp->PREV->NEXT = temp->NEXT;
                        else
                            PTR = temp->NEXT;

                        if (temp->NEXT != nullptr)
                            temp->NEXT->PREV = temp->PREV;

                        delete temp;
                        cout << "Node with value " << val << " deleted.\n";
                    }

                        else if(c=='3')
                        {
                            system("cls");
                            NODE* temp = PTR, *PREV = PTR;
                        if (PTR == NULL) {
                            cout << "\n\nLinkList is Empty..\n\n";
                            return;
                        } else if (PTR->NEXT == NULL) {
                            NODE* TN = PTR;
                            PTR = NULL;
                            delete TN;
                        } else {
                            while (temp->NEXT != NULL) {
                                PREV = temp;
                                temp = temp->NEXT;
                            }
                            PREV->NEXT = NULL;
                            delete temp;
                        }
                        cout << "\n\nNode Deleted from End..\n\n";

                        }
                    }
                    else if(d=='3')
                    {
                        system("cls");
                         cout << "\n\n";
                    if (PTR == NULL) {
                        cout << "\n\nLinkList is Empty...\n\n";
                        return;
                    }
                    NODE* TEMP = PTR;
                    while (TEMP != NULL) {
                        cout << TEMP->DATA << " <-> ";
                        TEMP = TEMP->NEXT;
                    }
                    cout << "NULL\n\n";

                    }
                    else if(s=='3')
                    {
                        firstpannel();
                        getch();
                    }
}
        }
};
int main()
{
     linklist l;
     l.firstpannel();
}
