//**********************************************************final**************************************************************************************njgop;'
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newnode, *temp, *tail;


void create()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data ");
    scanf("%d", &newnode->data);

    newnode->prev=0;
    newnode->next=0;

    if(head==0)
    {
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
void insertAtBeginning()
{
   // struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data ");
    scanf("%d", &newnode->data);

    newnode->prev=0;
    newnode->next=0;

    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertAtEnd()
{

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data ");
    scanf("%d", &newnode->data);

    newnode->prev=0;
    newnode->next=0;

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

int getLength()
{
    int count=0;

    temp=head;
    while(temp!=0){
        count++;
        temp=temp->next;
    }
    return count;
}

void insertAtPosition()
{
    int position,i=1;
    printf("Enter position ");
    scanf("%d", &position);

    int l = getLength();

    if(position<1 || (position>(l+1))){
        printf("INVALID POSITION!!!");
    }
    else if(position==1){
        insertAtBeginning();
    }
    else if(position==(l+1)){
        insertAtEnd();
    }
    else{
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data ");
        scanf("%d", &newnode->data);

        temp=head;
        while(i<position-1){
            temp=temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void deleteFromBeginning()
{
    if(head==0){
        printf("LIST is EMPTY!");
    }
    else{
        temp=head;
        head = head->next;
        head->prev =0;
        free(temp);
    }
}

void deleteFromEnd()
{
    temp = tail;
    tail = temp->prev;
    tail->next = 0;
    free(temp);
}

void deleteFromPosition()
{
    int i=1, position;

    printf("Enter Position ");
    scanf("%d", &position);

    if(position>getLength()){
        printf("INVALID POSITION");
    }
    else if(position==1){
        deleteFromBeginning();
    }
    else if(position==getLength()){
        deleteFromEnd();
    }
    else{
        temp=head;
        while(i<position){
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        free(temp);
    }
}


void display()
{
    struct node *temp;
    temp=head;
    while(temp!=0)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void main()
{
    int ch;

    do{
        printf("Enter Choice: 1-Create NODE \n 2- Display\n 3- Insert At Beginning\n 4-Insert At End\n 5-Insert At Given Position\n 6-Delete From Beginning\n 7-Delete from End\n 8-Delete from Specific Position\n 0-To exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: insertAtBeginning();
                    break;
            case 4: insertAtEnd();
                    break;
            case 5: insertAtPosition();
                    break;
            case 6: deleteFromBeginning();
                    break;
            case 7: deleteFromEnd();
                    break;
            case 8: deleteFromPosition();
                    break;
            default: printf("INVALID CHOICE");
        }
    }while(ch!=0);
}
