#include <stdio.h>
    #include <stdlib.h>
    
    struct node
    {
        int index;                        //Index of the node
        int data;                        //Data of the node
        struct node *nextptr;           //Address of the next node
    }*stnode;
    
    void createNodeList(int n); // function to create the list
    void displayList();         // function to display the list
    void addAfter(int index,int data);         // function to add data to a specific index in the list
    
    int main()
    {
        int n,index,data;
        printf("This program asks the user for the number of singly linked list to create then create it and give them option to put the data in each node:\n\n");
    
        printf(" Input the number of nodes : ");
        scanf("%d", &n);
        createNodeList(n);
        //addAfter(3, 19);
        printf("\n Data entered in the list : \n");
        displayList();
    
        //Task 4 adding data in-between the list
        printf("\nInput the node index to add data after: ");
        scanf("%d", &index);
        printf("Input the node data: ");
        scanf("%d", &data);
        addAfter(index, data);
    
        printf("\n List after Adding new data inbetween : \n");
        displayList();
        return 0;
    }
    void createNodeList(int n)
    {
        struct node *fnNode, *main;
        int data, i;
        stnode = (struct node *)malloc(sizeof(struct node));
    
        if(stnode == NULL) //check whether the fnnode is NULL and if so no memory allocation
        {
            printf(" Memory can not be allocated.");
        }
        else
        {
    // reads data for the node through keyboard
    
            printf(" Input data for node 1 : ");
            scanf("%d", &data);
            stnode->index = 0;
            stnode->data = data;
            stnode->nextptr = NULL; // links the address field to NULL
            main = stnode;
    // Creating n nodes and adding to linked list
            for(i=2; i<=n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode == NULL)
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
                else
                {
                    printf(" Input data for node %d : ", i);
                    scanf(" %d", &data);
    
                    fnNode->index = i - 1;
                    fnNode->data = data;      // links the num field of fnNode with num
                    fnNode->nextptr = NULL; // links the address field of fnNode with NULL
    
                    main->nextptr = fnNode; // links previous node i.e. main to the fnNode
                    main = main->nextptr;
                }
            }
        }
    }
    void displayList()
    {
        struct node *main;
        if(stnode == NULL)
        {
            printf(" List is empty.");
        }
        else
        {
            main = stnode;
            while(main != NULL)
            {
                printf("Index: %d -> %d, Current Address: %p, Next Address: %p\n", main->index,main->data,main,main->nextptr);      // prints the data of current node
                main = main->nextptr;                     // advances the position of current node
            }
        }
    }
    
    
    void addAfter(int index, int data)
    {
        struct node *fnNode, *main, *temp;
        fnNode = (struct node *)malloc(sizeof(struct node));
        temp = (struct node *)malloc(sizeof(struct node));
        temp = main;
        if(stnode == NULL)
        {
            printf(" List is empty.");
        }
        else
        {
            temp = stnode;
            int done = 0;
            while(temp != NULL)
            {
                if(done){
                    //check if the new node has been added and add 1 to the index of the rest of the nodes
                    temp->index = temp->index + 1;
                }
                if(temp->index == index){
                    fnNode->index = index;
                    fnNode->data = data;      // links the num field of fnNode with num
                    fnNode->nextptr = temp->nextptr; // links the address field of fnNode with NULL
    
                    temp->nextptr = fnNode; // links previous node i.e. main to the fnNode
                    done = 1;
                }
    
                temp = temp->nextptr;
            }
        }
    }
    
