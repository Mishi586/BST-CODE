
#include <iostream>
using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int data;
    public:
    Node(int data)
    {
        this->data=data;
        right=left=NULL;
    }
    void setData(int data)
    {
        this->data=data;
    }
    int getData()
    {
        return this->data;
    }
    void setLeft(Node* left)
    {
        this->left=left;
    }
    Node* getLeft()
    {
        return this->left;
    }
    void setRight(Node* right)
    {
        this->right=right;
    }
    Node* getRight()
    {
        return this->right;
    }
};
class BST{
    Node *root;
    public:
    bool isEmpty()
    {
        return (root==NULL);
    }
    bool isFull(Node* root)
    {
        // If empty tree
    if (root == NULL)
        return true;
  
    
    if (root->left == NULL && root->right == NULL)
        return true;
  
    if ((root->left) && (root->right))
        return (isFull(root->left) && isFull(root->right));
    return false;
    }
    Node* getRoot()
    {
        return root;
    }
    Node* getLeftChild()
    {
        return root->left;
    }
    Node* getRightChild()
    {
        return root->right;
    }
    
    void add(Node* root,int val)
    {
        Node* t=root;
        Node* n=new Node(val);
        if(val<t->data)
        {
            add(t->left, val);
        }
        else
        {
            add(t->right,val);
        }
        return;
    }
    
    void VisitRoot(Node* root)
    {
        cout<<root->data;
    }
    void preOrder(Node* root)
    {
        if(root==NULL)
    {
        return;
    }
        VisitRoot(root);
        preOrder(root->left);
        preOrder(root->right);
    
    }
    bool preOrder2(Node* root,int x)
    {
        if(root==NULL)
    
      {}
      if(root->data==x){
      return true;
        VisitRoot(root);
        preOrder2(root->left,x);
        preOrder2(root->right,x);
    }
    }
    void InOrder(Node* root)
    {
        if(root==NULL)
        
            return;
            InOrder(root->left);
            VisitRoot(root);
            InOrder(root->right);
    }
    void postOrder(Node* root)
    {
        if(root==NULL)
        
            return;
            postOrder(root->left);
            postOrder(root->right);
            VisitRoot(root);
    }
    
    void print()//traversing bst
    {
       preOrder(root); 
    }
    bool doesExist(int x)
    {
        return preOrder2(root,x);
    }
    bool isLeaf(Node* root)//with no child elements
    {
        if(root->left==NULL&& root->right==NULL)
        {
            return true;
        }
        else
        return false;
    }
    bool isExternal(Node* root)//that are leaf nodes
    {
        if(isLeaf(root)==true)
        {
            return true;
        }
        else
        return false;
    }
    bool isInternal(Node* root)//Not a Leaf Nodes
    {
        return !isLeaf(root);
    }
    bool isFullParent(Node* root)
    {
        if(root->left!=NULL&&root->right!=NULL)
        {
            return true;
        }
        else
        return false;
    }
    bool isSingleParent(Node* root)
    {
        if(!isLeaf(root)&&!isFull(root))
        {
            return true;
        }
        else
        return false;
    }
    int LargestElement(Node* root)
    {
         LargestElement(root->right);
        if(root->right==NULL)
        {
            return root->data;
        }
       
    }
    int LowestElement(Node* root)
    {
        if(root->left==NULL)
        {
            return root->data;
        }
        LowestElement(root->right);
    }
    int Successor(Node* root)//smaller/least element in larger element
    {
        return LowestElement(root->right);
    }
    int preDeccessor(Node* root)//larger element in smaller element
    {
        return LargestElement(root->left);
    }
    void deleteElement(Node* root,int k)
    {
        if(root==NULL)
        return;
        if(k<root->data)
        deleteElement(root->left,k);
        else if(k>root->data)
        deleteElement(root->right,k);
        
        else
        {
            if(root->left==NULL&&root->right==NULL)
            {
                delete root;
                root=NULL;
                return;
            }
            else if(root->left==NULL)
            {
                Node* temp=root->right;
                delete root;
                root=temp;
                return;
            }
            else if(root->right==NULL)
            {
                Node* temp=root->left;
                delete root;
                root=temp;
                return;
            }
            Node* temp;
          //  temp=LowestElement(root->right);
            root->data=temp->data;
            deleteElement(root->right,temp->data);
        }
        return;
    }
};
int main() {
    BST b1;
    Node* root=NULL;
    b1.add(root,4);
    b1.add(root,5);
    b1.add(root,6);
    b1.add(root,7);
    cout<<b1.isEmpty();
    
   
}
