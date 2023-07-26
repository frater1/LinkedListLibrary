#include <stdio.h>
#include <stdlib.h>
#include "llist.h"


int main()
{

    /** The Commented codes are examples if you one want to try all the functions*/
    /*
    // Inserting new value to the node at the head.
    /*list1_head = insert_at_Head(list1_head, 5);
    list1_head = insert_at_Head(list1_head, 5);
    list1_head = insert_at_Head(list1_head, 6);
    list1_head = insert_at_Head(list1_head, 7);
    list1_head = insert_at_Head(list1_head, 5);
    list1_head = insert_at_Head(list1_head, 5);
    list1_head = insert_at_Tail(list1_head, 7);
    list1_head = insert_at_Tail(list1_head, 5);*/

    // Inserting new value to the node at the tail.
   /* list1_head = insert_at_Tail(list1_head, 20);
    list1_head = insert_at_Tail(list1_head, 30);
    list1_head = insert_at_Tail(list1_head, 40);
    list1_head = insert_at_Tail(list1_head, 50);*/

   // printf("\n Before Delete\n");
    //print_list(list1_head); 
    //list1_head = delete_at_head(list1_head); // delinting at head..
    //list1_head = delete_at_tail(list1_head); // delinting at tail..

    //printf("\n After Delete\n");
   // print_list(list1_head);
    //printf("The lenght of the list is: %d\n", list_lenght(list1_head));
   // printf("Lenght using recursive function is: %d\n", list_lenght_recursive_way(list1_head));

   /*if (is_member(list1_head,15))
   printf(" 15 is within the list\n");
   else printf(" 15 is not in the list\n");*/

   //printf("We have %d 5s in our list\n", count_matched_search(list1_head,9));

   /*printf("\n List Before Replacement: \n");
       print_list(list1_head);
   printf("\n List After Replacement: \n");
      replace_mathes(list1_head,5,100);
      print_list(list1_head);*/

    /*printf("\n List Before multiple Deletion: \n");
    print_list(list1_head); 
    int num_del = 0;

    list1_head = efficient_delete_matches(list1_head,5,&num_del);

    printf("\n List After multiple Deletion: \n"); 
    print_list(list1_head); 
    printf("\n Number of 4s deleted: %d",num_del);*/

    // Adding nodes to the lists



    /*
    Node *list1 = NULL,*list2 = NULL;

    for(int i = 1; i <= 5; i++) list1 = insert_at_Tail(list1,i);
    for(int i = 6; i <= 10; i++) list2 = insert_at_Tail(list2,i);

    printf("\n List 1: \n");
    print_list(list1);

    printf("\n List 2: \n");
    print_list(list2);

    printf("\n List 1 and List 2 after appending \n");
    list1 = append_list(list1,list2);
    print_list(list1);

    printf("\n List 1 after reversing \n");
    list1 = reverse_list(list1);
    print_list(list1);*/
    
    /*Node *list1 = NULL;

    list1 = insert_at_Tail(list1,5);
    list1 = insert_at_Tail(list1,89);
    list1 = insert_at_Tail(list1,5);
    list1 = insert_at_Tail(list1,66);
    list1 = insert_at_Tail(list1,54);
    list1 = insert_at_Tail(list1,2);

    printf("List before sort: \n");
    print_list(list1);
    printf("List after sort: \n");
    sort_list(list1);
    print_list(list1);*/

   /* Node *list1 = NULL;

    list1 = insert_at_Tail(list1,5);
    list1 = insert_at_Tail(list1,5);
    list1 = insert_at_Tail(list1,5);
    list1 = insert_at_Tail(list1,6);
    list1 = insert_at_Tail(list1,4);
    list1 = insert_at_Tail(list1,2);

    printf("List before duplication delete: \n");
    print_list(list1);
    printf("List after duplication delete: \n");
    delete_duplicates(list1);
    print_list(list1);*/

    /*Node *list1 = NULL;

    list1 = insert_at_Tail(list1,5);
    list1 = insert_at_Tail(list1,1);
    list1 = insert_at_Tail(list1,3);
    list1 = insert_at_Tail(list1,6);
    list1 = insert_at_Tail(list1,4);
    list1 = insert_at_Tail(list1,2);

    printf("List before insertion: \n");
    print_list(list1);
    printf("List after  insertion: \n");
    list1 = insert_after(list1, 20,3); // inserting the value 20 after 3 in the list..
    print_list(list1);
    printf("\n List after deletion: \n");
    delete_list(list1);*/

    Node *list1 = NULL, *list2 = NULL;

    for(int i = 1; i <= 5; i++) list1 = insert_at_Head(list1,i);
    for(int i = 8; i >= 4; i--) list2 = insert_at_Head(list2,i);

    printf("List 1: \n");
    print_list(list1);
    printf("List 2: \n");
    print_list(list2);

    add_lists(list1,list2);
    printf("after added lists: \n");
    print_list(list1);


}