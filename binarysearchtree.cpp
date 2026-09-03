#include <iostream>
using namespace std;
struct node {
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

// Insert function
void insert(struct node *root, struct node *newnode) {
    if (newnode->data < root->data) {
        if (root->left == NULL)
            root->left = newnode;
        else
            insert(root->left, newnode);
    }
    else {
        if (root->right == NULL)
            root->right = newnode;
        else
            insert(root->right, newnode);
    }
}

// Create + insert together
void create(int value) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->left = newnode->right = NULL;

    if (root == NULL)
        root = newnode;
    else
        insert(root, newnode);   // insertion in else
}

// Inorder traversal
void inorder(struct node *temp) {
    if (temp != NULL) {
        inorder(temp->left);
        cout<< temp->data;
        inorder(temp->right);
    }
}

void preorder(struct node *temp) {
    if (temp != NULL) {
        
        cout <<temp->data;
        preorder(temp->left);

        preorder(temp->right);
    }
}

void postorder(struct node *temp) {
    if (temp != NULL) {
    postorder(temp->left);

        postorder(temp->right);
        cout <<temp->data;

    }
}
struct node* findMin(struct node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;
        
        
return root;

}







struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;

    // Search node
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // Node found
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    
    
            

    cout<<"DELETION COMPLETED\n";
    return root;
            
    
}




// Main
int main() {
    int choice, value;

    while (1) {
        cout<<"\\n1. Insert\\n2. inorder \\ n3.preorder  \\n4.postorder \\n5.findMin \\ n6.deletion\\ n7. Exit\\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                create(value);   // directly call create
                break;

            case 2:
                cout<<"BST: ";
                inorder(root);
                cout<<"\\n";
                break;

                case 3: 
                cout<<"BST : ";
                preorder(root);
                cout<<"\\n";

                break;

                case 4: 
            cout<<"BST : ";
                postorder(root);
                cout<<"\\n";

                break;


            


                case 5: 
                findMin(root);
                break;
                
                case 6:
                cout<<"Enter value to delete: ";
                cin>>value;
                root = deleteNode(root, value);
                break;
                


            case 7:
                exit(0);

            default:
                cout<<"Invalid choice\\n";
        }
    }
    
}







