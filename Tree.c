#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    return ;
}

void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
    return ;
}

void preorder(struct node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    return ;
}

struct node *insert(struct node *root, int x){
    if(root == NULL){
        root = (struct node *)malloc(sizeof(struct node));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
    }
    else{
        if(root->data > x)
            root->left = insert(root->left, x);
        else
            root->right = insert(root->right, x);
    }
    return root;
}

struct node *findmax(struct node *root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node *Delete(struct node *root, int data){
    if(root == NULL)
        return;

    else if(data < root->data)
        root->left = Delete(root->left, data);

    else if(data > root->data)
        root->right = Delete(root->right, data);

    else{
        if(root->left == NULL && root->right == NULL){
            root = root->right;
            free(root);
        }
        else{
            if(root->left == NULL){
                struct node *temp = root;
                root = root->right;
                free(temp);
            }
            else if(root->right == NULL){
                struct node *temp = root;
                root = root->left;
                free(temp);
            }
            else{
                struct node *temp = findmax(root->left);
                root->data = temp->data;
                root->left = Delete(root->left, temp->data);
            }
        }
    }
    return root;
}


struct node *search(struct node *root,int x){
    if(root!=NULL){
        if(x == root->data)
            return root;

        else if(x < root->data)
            return search(root->left , x);

        else
            return search(root->right , x);
    }
    else
        return;
}

int main()
{
    struct node *root, *temp;
    int choice, value;
    root = NULL;

    while(1){
        printf("\n\n====================\n");
        printf("Press 1 for Insert in Binary Tree\n");
        printf("Press 2 for Inorder traversal of Binary Tree\n");
        printf("Press 3 for Postorder traversal of Binary Tree\n");
        printf("Press 4 for Preorder traversal of Binary Tree\n");
        printf("Press 5 for Delete\n");
        printf("Press 6 for Search\n");
        printf("Press 7 for Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

       if(choice == 1){
            printf("Enter a value: ");
            scanf("%d", &value);
            root = insert(root, value);
        }
        else if(choice == 2){
            inorder(root);
        }
        else if(choice == 3){
            postorder(root);
        }
        else if(choice == 4){
            preorder(root);
        }
        else if(choice == 5){
            printf("Enter Value for delete: ");
            scanf("%d", &value);
            Delete(root,value);
        }

        else if(choice == 6){
            printf("Enter the value for search: ");
            scanf("%d", &value);
            temp = search(root, value);
            if(temp != NULL) printf("Value Found\n");
            else printf("Not found\n");
        }

        else if(choice == 7) break;
        else printf("Wrong choice. Try Again\n");

    }
    return 0;
}
