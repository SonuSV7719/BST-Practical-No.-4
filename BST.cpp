#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int key);
};

Node::Node(int key)
{
    data = key;
    left = NULL;
    right = NULL;
}

class BST
{
    public:
    Node* root = NULL;
    Node* insert(Node* root, int key);
    void inorder(Node* root);
    void preorder(Node* root);
    void postorder(Node* root);
    void display(Node* root);
    Node* search_ele(Node* root, int key);
    Node* delete_ele(Node* root, int key);
    Node* minValueNode(Node* root);
};

Node* BST:: insert(Node* root, int key)
{
    if (root ==  NULL) return new Node(key);
    if (root->data == -1) 
    {
        root->data = key;
        return root;
    }
    if (key < root->data) 
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void BST::inorder(Node* root)
{
    if (root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void BST::preorder(Node* root)
{
    if (root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void BST::postorder(Node* root)
{
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" "; 
}

void BST::display(Node* root)
{
    if (root == NULL) return;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

Node* BST::search_ele(Node* root, int key)
{
    if (root ==  NULL || root->data == key) return  root;
    if (key < root->data) 
        return search_ele(root->left, key);
    return search_ele(root->right, key);
}

Node* BST::minValueNode(Node* root)
{
    Node* current_node = root;
    if (current_node && current_node->left != NULL)
        current_node = current_node->left;
    return current_node;
}

Node* BST::delete_ele(Node* root, int key)
{
    if (root == NULL) return root;

    //Search key on left side of tree
    if (key < root->data)
        root->left = delete_ele(root->left, key);
    //Search key on right side of tree
    else if (key > root->data)
        root->right = delete_ele(root->right, key);
    
    //if key found after traveresing then delete that node
    else
    {
        //Node with NO child
        if (root->left == NULL && root->right == NULL) return NULL;

        //Node with No child or only one child
        else if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //Node with NO children 
        //first find inorder successor 
        Node* temp = minValueNode(root->right);

        //store value of temp data to root data or copy
        root->data = temp->data;

        //delete inorder successor
        root->right = delete_ele(root->right, temp->data);
    }
    return root;
}

int main()
{
    Node* root = new Node(-1);
    BST tree;
    Node* result;
    int index;
    
    char stop = 'Y';

    do
    {
        cout<<"Which Operation you want to perform in BST: "<<endl;
        cout<<"1. Insertion\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6. Display\n7. Deletion\n8. Exit\n\nPress respective index: ";
        cin>>index;
        switch (index)
        {
        case 1:
            /* code */
            int n;
            cout<<"Enter How many element you want to enter: ";
            cin>>n;
            for (int i = 0; i<n; i++)
            {
                int key;
                cout<<"Enter Element: ";
                cin>>key;
                tree.insert(root, key);
            }
            break;

        case 2:
            /* code */
            int key;
            cout<<"Enter which element you want to search: ";
            cin>>key;
            result = tree.search_ele(root, key);
            if (result == NULL)
                cout<<key<< " Not Found!"<<endl<<endl;
            else
                cout<<key<<" Found in BST"<<endl<<endl;
            break;

        case 3:
            /* code */
            tree.inorder(root);
            cout<<endl<<endl;
            break;
        
        case 4:
            /* code */
            tree.preorder(root);
            cout<<endl<<endl;
            break;

        case 5:
            /* code */
            tree.postorder(root);
            cout<<endl<<endl;
            break;

        case 6:
            /* code */
            tree.display(root);
            cout<<endl<<endl;
            break;

        case 7:
            /* code */
            int delete_data;
            cout<<"Enter key which you want to delete: ";
            cin>>delete_data;
            root = tree.delete_ele(root, delete_data);
            cout<<delete_data<<" Deleted!!"<<endl<<endl;
            cout<<endl<<endl;
            break;

        
        case 8:
            /* code */
            stop = 'n';
            break;
        
        default:
            cout<<"You Entered wrong index. Do You want to continue press y to continue otherwise press N: ";
            cin>>stop;
            break;
        }
    } while (stop == 'Y' || stop == 'y');
    

    return 0;
}