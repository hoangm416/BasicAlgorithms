//C++ 
#include <bits/stdc++.h> 
using namespace std;

struct Node{
    int id;
    Node* leftMostChild;
    Node* rightSibling;
};

Node* makeNewNode(int u)
{
    Node *p = new Node();
	p->id = u;
	p->leftMostChild = NULL;
	p->rightSibling = NULL;
	return p;
}

Node *find(Node *r, int v)
{
	if(r == NULL) return NULL;
	
	if(r->id == v) return r;
	
	Node *p = r->leftMostChild;
	while(p!=NULL){
		Node *hv = find(p,v);
		if(hv!=NULL) return hv;
		p=p->rightSibling;
	}
		
	return NULL;	
}

void insert(Node* root, int u, int v) {
    Node* parent = find(root, v);
    if (parent == NULL) {
        return;
    }
    if (find(root, u) != NULL) {
        return;
    }
    Node* child = makeNewNode(u);
    if (parent->leftMostChild == NULL) {
        parent->leftMostChild = child;
    } else {
        Node* sibling = parent->leftMostChild;
        while (sibling->rightSibling != NULL) {
            sibling = sibling->rightSibling;
        }
        sibling->rightSibling = child;
    }
}

void preOrder(Node* r)
{
    if (r == NULL) return;
    cout << r->id << " ";
    Node* p = r -> leftMostChild;
    while(p != NULL){
        preOrder(p);
        p = p -> rightSibling;
    }
}

void inOrder(Node* r)
{
    if (r == NULL) return;
    Node* p = r -> leftMostChild;
    inOrder(p);
    cout << r->id << " ";
    if (p != NULL)
        p = p -> rightSibling;
    while (p != NULL){
        inOrder(p);
        p = p -> rightSibling;
    }
    
}

void postOrder(Node* r)
{
    if (r == NULL) return;
    Node* p = r -> leftMostChild;
    while (p != NULL) {
        postOrder(p);
        p = p -> rightSibling;
    }
    cout << r->id << " ";
}


int main() 
{ 
    Node* root = NULL;
    char opera[20];
    
    while (cin >> opera)
    {
        if (opera[0] == '*')
            break;
        
        else if (opera[0] == 'M')
        {
            int g;
            cin >> g;
            root = makeNewNode(g);
        }
        else if (opera[5] == 't')
        {
            int u, v;
            cin >> u >> v;
            insert(root, u, v);
        }
        else if (opera[1] == 'r')
        {
            preOrder(root);
            cout << endl;
        }
        else if (opera[2] == 'O')
        {
            inOrder(root);
            cout << endl;
        }
        else if (opera[1] == 'o')
        {
            postOrder(root);
            cout << endl;
        }
    }
    
    return 0;
}

