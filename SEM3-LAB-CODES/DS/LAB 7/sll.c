#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} node;
node* ins_at_begin(node* start)
{
    node*temp=(node*)malloc(sizeof(node));
    printf("Enter the element:");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        return start;
    }
    temp->next=start;
    start=temp;
    return start;
}
node* ins_at_end(node*start)
{
    node*temp=(node*)malloc(sizeof(node));
    printf("Enter the element:");
    scanf("%d",&(temp->info));
    temp->next=NULL;
    if(start == NULL)
    {
        start=temp;
        return start;
    }
    else
    {
        node *t=start;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=temp;
    }
    return start;
}

node* ins_at_position(node* start)
{
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return start;
    }

    printf("Enter the element: ");
    scanf("%d", &temp->info);
    temp->next = NULL;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return temp;
    }
    else
    {
        node *t = start;
        printf("Enter the position you want to insert at: ");
        int pos;
        scanf("%d", &pos);

        if (pos <= 0)
        {
            printf("Invalid position.\n");
            free(temp);
            return start;
        }

        if (pos == 1)
        {
            temp->next = start;
            start = temp;
            return start;
        }

        int i;
        for (i = 1; i < pos - 1 && t->next != NULL; i++)
        {
            t = t->next;
        }

        if (i != pos - 1)
        {
            printf("Position is out of range.\n");
            free(temp);
            return start;
        }

        temp->next = t->next;
        t->next = temp;

        return start;
    }
}


node* ins_after_ele(node*start)
{
    node*temp=(node*)malloc(sizeof(node));
    node*cur;
    int ele;
    printf("Enter the element after which you want to insert:");
    scanf("%d",&ele);
    cur=start;
    if(start==NULL)
    {
        printf("List is empty");
        return start;
    }
    while(cur!=NULL&& cur->info!=ele)
        cur=cur->next;
    if(cur==NULL)
    {
        printf("Element not found.\n");
        return start;
    }
    printf("Enter the element:\n");
    scanf("%d",&temp->info);
    temp->next=NULL;
    temp->next=cur->next;
    cur->next=temp;
    return start;
}

node*ins_before_ele(node*start)
{
    node*temp=(node*)malloc(sizeof(node));
    node*cur,*prev;
    cur=start;
    prev=NULL;
    if(cur==NULL)
    {
        printf("Empty List");
        return start;
    }
    else
    {
        int ele;
        printf("Enter the element before which you want to insert:");
        scanf("%d",&ele);
        if(cur->info==ele)
        {
            printf("Enter the element:");
            scanf("%d",&temp->info);
            temp->next=cur;
            start=temp;
            return start;
        }
        while(cur!=NULL && cur->info!=ele)
        {
            prev=cur;
            cur=cur->next;
        }
        if(cur==NULL)
        {
            printf("Element not found.");
            return start;
        }
        else
        {
            printf("Enter the element:");
            scanf("%d",&temp->info);
            temp->next=prev->next;
            prev->next=temp;
            return start;
        }
    }
}

node* del_from_beg(node*start)
{
    node*t=start;
    if(start==NULL)
    {
        printf("Nothing to delete.");
        return start;
    }
    else
    {
        printf("Deleted:%d\n",t->info);
        start=start->next;
        free(t);
        return start;
    }
}
node* del_from_end(node* start) {
    node *cur, *prev;
    cur = start;

    if (cur == NULL) {
        printf("Nothing to delete.\n");
        return start;
    } else if (cur->next == NULL) {
        // Only one element in the list
        printf("Deleted:%d\n", cur->info);
        free(cur);
        start = NULL;
        return start;
    } else {
        while (cur->next != NULL) {
            prev = cur;
            cur = cur->next;
        }

        printf("Deleted:%d\n", cur->info);
        free(cur);
        prev->next = NULL;
        return start;
    }
}


node*del_alt_node(node*start)
{
    node*cur,*prev;
    prev=start;
    cur=start->next;
    if(start==NULL)
    {
        printf("Empty list.");
        return start;
    }
    while(prev!=NULL && cur!=NULL)
    {
        prev->next=cur->next;
        printf("Deleted:%d ",cur->info);
        free(cur);
        prev=prev->next;
        if(prev!=NULL)
        {
            cur=prev->next;
        }
    }
    return start;
}

node* del_user_input(node* start)
{
    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);

    if (start == NULL)
    {
        printf("Nothing to delete.\n");
        return start;
    }

    node *cur = start;
    node *prev = NULL;

    while (cur != NULL)
    {
        if (cur->info == ele)
        {
            if (prev == NULL)
            {
                start = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }

            printf("Element deleted is %d.\n", ele);
            free(cur);
            return start;
        }

        prev = cur;
        cur = cur->next;
    }

    printf("Element not found.\n");
    return start;
}


node* reverse(node* start)
{
    node* prev = NULL;
    node* current = start;
    node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
    return start;
}

node* sort(node* start)
{
    node *prev, *cur;
    int temp;
    prev = start;

    if (start == NULL)
    {
        printf("Nothing to sort\n");
        return start;
    }

    while (prev != NULL)
    {
        cur = prev->next;

        while (cur != NULL)
        {
            if (prev->info > cur->info)
            {
                temp = prev->info;
                prev->info = cur->info;
                cur->info = temp;
            }
            cur = cur->next;
        }
        prev = prev->next;
    }

    return start;
}
node* ins_sort(node* start)
{
    node* temp = (node*)malloc(sizeof(node));
    printf("Enter the element: ");
    scanf("%d", &temp->info);
    temp->next = NULL;

    if (start == NULL || temp->info < start->info)
    {
        temp->next = start;
        start = temp;
        return start;
    }
    else
    {
        node* t = start;
        while (t->next != NULL && t->next->info < temp->info)
        {
            t = t->next;
        }

        temp->next = t->next;
        t->next = temp;

        return start;
    }
}


void display(node*start)
{
    node*t=start;
    if(start==NULL)
    {
        printf("Nothing to print\n");
        return start;
    }
    while(t!=NULL)
    {
        printf("%d\t",t->info);
        t=t->next;
    }
    printf("\n");
}
int main()
{
    node*start=NULL;
    int choice;
    while(1)
    {
        printf("\nEnter choice \n1.Insert at beginning \n2.Insert at end\n3.Insert at given position\n4.Insert before an element\n5.Inset after an element\n6.Delete from beginning\n7.Delete from end\n8.Delete alternate nodes\n9.Delete based on user input\n10.Reverse\n11.Sort\n12.Insert in Sorted\n13.Display\n13.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            start=ins_at_begin(start);
            break;
        case 2:
            start=ins_at_end(start);
            break;
        case 3:
            start=ins_at_position(start);
            break;
        case 4:
            start=ins_before_ele(start);
            break;
        case 5:
            start=ins_after_ele(start);
            break;
        case 6:
            start=del_from_beg(start);
            break;
        case 7:
            start=del_from_end(start);
            break;
        case 8:
            start=del_alt_node(start);
            break;
        case 9:
            start=del_user_input(start);
            break;
        case 10:
            start=reverse(start);
            break;
        case 11:
            start=sort(start);
            break;
        case 12:
            start=ins_sort(start);
            break;
        case 13:
            display(start);
            break;
        case 14:
            exit(0);
        default:
            printf("Invalid choice");

        }
    }
    return 0;
}
