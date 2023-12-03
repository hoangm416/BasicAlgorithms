//C++ 
#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* head;

Node* makeNewNode(int k)
{
	Node* p = new Node();
	p->value = k;
	p->next = NULL;
	
	return p;
}

void traverse(Node *head)
{
	Node *p = head;
	while(p != NULL){
		cout << p->value << " ";
		p = p->next;
	}
}

bool search(Node* head, int k) 
{
    Node* cur = head;
    while (cur != NULL) {
        if (cur->value == k) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}


void addlast(Node *head, int k)
{
    if (!search(head, k))
    {
        Node *p = makeNewNode(k);
        if (head == NULL){
            head = p;
            return;
        }
        
        Node *cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = p;
    }
}

void addfirst(Node** head, int k) 
{
    if (!search(*head, k))
    {
        Node* p = makeNewNode(k);
        if (*head == NULL) {
            *head = p;
            return;
        }
        p->next = *head;
        *head = p;
    }
}

void addafter(Node* head, int u, int v) 
{
    if (!search(head, u))
    {
        Node* cur = head;
        while (cur != NULL) {
            if (cur->value == v) {
                Node* p = makeNewNode(u);
                p->next = cur->next;
                cur->next = p;
                break;
            }
            cur = cur->next;
        }
    }
}

void addbefore(Node** head, int u, int v) 
{
    if (*head == NULL) 
        return;
    if (!search(*head, u))
    {
        if ((*head)->value == v) {
            Node* p = makeNewNode(u);
            p->next = *head;
            *head = p;
            return;
        }
        Node* cur = *head;
        while (cur->next != NULL) {
            if (cur->next->value == v) {
                Node* p = makeNewNode(u);
                p->next = cur->next;
                cur->next = p;
                break;
            }
            cur = cur->next;
        }
    }
}

void reMove(Node** head, int k) 
{
    Node* cur = *head;
    Node* prev = NULL;
    while (cur != NULL) {
        if (cur->value == k) {
            if (prev == NULL) 
                *head = cur->next;
            else 
                prev->next = cur->next;
            
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void reverse(Node** head) 
{
    Node* prev = NULL;
    Node* cur = *head;
    Node* next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

int main() 
{ 
    Node *old, *p, *head = NULL;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p = makeNewNode(a[i]);
        if (i == 0)
            head = p;
        else
            old->next = p;
        
        old = p;
    }
    
    char query[25];
    while (cin >> query)
    {
        if (query[0] == '#')
            break;
        else if (query[3] == 'l')
        {
            int k;
            cin >> k;
            addlast(head, k);
        }
        else if (query[3] == 'f')
        {
            int k;
            cin >> k;
            addfirst(&head, k);
        }
        else if (query[3] == 'a')
        {
            int u, v;
            cin >> u >> v;
            addafter(head, u, v);
        }
        else if (query[3] == 'b')
        {
            int u, v;
            cin >> u >> v;
            addbefore(&head, u, v);
        }
        else if (query[2] == 'm')
        {
            int k;
            cin >> k;
            reMove(&head, k);
        }
        else
            reverse(&head);
            
    }
    
    traverse(head);
    return 0;
}

