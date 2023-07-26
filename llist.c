/**
 * Linked List Library
 * 
 * @file llist.c
 * @author Jack Frater K. Buyole
 * @date July 17, 2023.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "llist.h"

/**
 * This Function, add the values of two lists together.
 * @param head: the pointer to the head of the first list
 * @param head: the pointer to the head of the second list
 * @return nothing.
*/
void add_lists(Node *list1, Node *list2)
{
    if(list1 == NULL || list2 == NULL) return;
    list1->value = list1->value + list2->value;
    add_lists(list1->next, list2->next); // continue adding ...
}

/**
 * This Function insert the value at the head..
 * @param head: the pointer to the head of the list
 * @param new_value: new value to be inserted in the list at head
*/
Node *insert_at_Head(Node *head, int new_value)
{
    Node *new_node = calloc(1,sizeof(Node));
    new_node->value = new_value;

    if(head == NULL) return new_node;
    else
    {
        new_node->next = head;
        return new_node;
    }
}

/**
 * This Function insert the value at the tail..
 * @param head: the pointer to the head of the list
 * @param new_value: new value to be inserted in the list at tail
*/
Node *insert_at_Tail(Node *head, int new_value)
{
    Node *new_node = calloc(1,sizeof(Node));
    new_node->value = new_value;

    if(head == NULL) return new_node;
    else
    {
        Node *current = head;
        while (current->next != NULL) current = current->next;/** < Here: as long as current is not equal to null, continue to the next node.*/
        current->next = new_node;

        return head; /** < we are returnig the head b/c the head is not gonna change */
        

    }
}

/**
 * Function to delete a single node or value at the head
 * @param head: the pointer to the head of the list
*/
Node *delete_at_head(Node *head)
{
    if(head == NULL) return NULL;
    else
    {
        Node *to_return = head->next;
        free(head);
        return to_return;
    }
}

/**
 * Function to delete a single node or value at the tail
 * @param head: the pointer to the head of the list
*/
Node *delete_at_tail(Node *head)
{
    // if the list is empty
    if(head == NULL) return NULL;
    // If the list has only one node
    else if( head->next == NULL)
    {
        free(head);
        return NULL;
    }
    // if the list has more than one node...
    else
    {
        Node *current = head;
        Node *prev = NULL;

        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current);

        return head;
    }
}

/**
 * This Function give you the number of how many values are stored in the list in a simple way.
 * @param head: the pointer to the head of the list
 * @return the lenght of the list.
*/
int list_lenght(Node *head)
{
    Node *current = head;
    int lenght = 0;
    while (current != NULL)
    {
        lenght++;
        current = current->next;
    }
    
    return lenght;
}

/**
 * This Function give you the number of how many values are stored in the list in a recursive way.
 * Recursive function are function that call themselves.
 * @param head: the pointer to the head of the list.
 * @return the lenght.
*/
int list_lenght_recursive_way(Node *node)
{
    if(node == NULL) return 0;
    else return 1 + list_lenght_recursive_way(node->next);
}

/**
 * This function will help us to search if a given value is within the list.
 * @param node: the pointer to the head of the list.
 * @param find_value: the pointer of the value that need checked if exist within the list.
*/

/**
 * This function check if the given value is within the list.
 * @param node: the pointer to the head of the list.
 * @param node: the pointer of the value that need to be checked if it is within the list.
 * @return the value if it is whithin the list.
*/
bool is_member(Node *node, int find_value)
{
    if(node ==  NULL) return false;
    else if(node->value == find_value) return true;
    else return is_member(node->next, find_value);
}

/**
 * This function will count how many times the value is in the list
 * @param node: the pointer to the head of the list.
 * @param find_value: the pointer to the value that need counted.
 * @return matched values.
*/
int count_matched_search(Node *node, int find_value)
{
    if(node == NULL) return 0;

    else if(node->value == find_value) return 1 + count_matched_search(node->next, find_value);
    else return count_matched_search(node->next, find_value);
}

/**
 * This function will replace the matched values with the new value that we are replacing with in the list.
 * @param node: the pointer to the head of the list.
 * @param find_value: the pointer to the value that need to be replaced
 * @param replace_value: the pointer to the new value that will replace the old one.
 * @return nothing.
*/
void replace_mathes(Node *node, int find_value, int replace_value)
{
    if(node != NULL)
    {
        if(node->value == find_value) node->value = replace_value;
        replace_mathes(node->next, find_value, replace_value);
    }
}

/**
 * The Function that delete the match value within the list
 *  @param head: the pointer to the head of the list
 *  @param delete_value: the pointer to the value that need to be deleted.
 *  @param was_deleted: the pointer to keep check if the value was deleted.
*/
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted)
{
    if(head == NULL)
    {
        was_deleted = false;
        return NULL;
    }
                                                                                             
    if (head->value == delete_value)
    {
        Node *temp = head->next;
        free(head);
        *was_deleted = true;
        return temp;
    }
                                                              
    Node *current = head->next;
    Node *prev = head;

    while (current != NULL)
    {
        if (current->value == delete_value)
        {
            prev->next = current->next;
            free(current);
            *was_deleted = true;
            return head;
        }
    }
    was_deleted = false;
    return head;
    
    
}
/**
 * This function delete given value in the list
 *  @param head: the pointer to the head of the list
 *  @param delete_value: the pointer of the value that is to be deleted from the list
 *  @param num_deleted: the pointer that give count of how many values matched and deleted.
*/
Node *efficient_delete_matches(Node *head, int delete_value, int *num_deleted)
{
    if(head == NULL) return NULL;

    Node *current, *temp, *new_head;
    current = head;
    *num_deleted = 0; 

    while (current->value == delete_value)
    {
        temp = current;
        current = current->next;
        free(temp);
        *num_deleted = *num_deleted +1;

        if(current == NULL) return NULL;
    }
    new_head = current;

    while (current->next != NULL)
    {
        if(current->next->value == delete_value)
        {
            temp = current->next;
            current->next = current->next->next;
            free(temp);

            *num_deleted = *num_deleted +1;
        }
        else current = current->next;
    }

    return new_head;
    
    
}

/**
 * The function to append nodes. This means that list2(head2) nodes will be added 
 * to list1(head1) or all nodes of list2 will added to list1.
 *  @param head1: the pointer to the head of the first list
 *  @param head2: the pointer to the head of second the list
*/
Node *append_list(Node *head1, Node *head2)
{
    if(head1 == NULL) return head2;

    Node *current = head1;

    while(current->next != NULL) current = current->next;
    current->next = head2;

    return head1;
}

/**
 * The Function that reverse the list.
 * @param head: the pointer to the head of the list
*/
Node *reverse_list(Node *head)
{
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    Node *current = head;
    Node *next_node = head->next;

    /** < setting the first node to null so it can become a tail */
    current->next = NULL;
    
    while (next_node != NULL) /** <reversing/flipping happening here! */
    {
        Node *temp = next_node->next; /** <temp node point to whatever is after the nextnode */
        next_node->next = current; /** < nextnode point back to the last node */
        current = next_node; /** < the new last one poit to newnode */
        next_node = temp;
    }
    return current;
    
}

/**
 * The Function to sort the values in the list (NB: this given example values are int values)
 * This sorting method we implimented it using bubblesort...
 * @param head: the pointer to the head of the list.
 * @return nothing.
*/
void sort_list(Node *head)
{
    if(head == NULL) return;
    if(head->next == NULL) return;

    bool swapped = false;

    do
    {
        swapped = false;

        Node *current = head;
        Node *prev = NULL;

        while (current->next != NULL)
        {
            prev = current;
            current = current->next;

            if(current != NULL)
            {
                if (current->value < prev->value)               
                {
                    int temp;
                    temp = prev->value;
                    prev->value = current->value;
                    current->value = temp;
                    swapped = true;
                }
                
            }
        }
        
    } while (swapped);      
    
}

/**
 * The function that delete duplicate values in the list.
 * @param head: the pointer to the head of the list.
 * @return nothing.
*/
void delete_duplicates(Node *head)
{
    if(head == NULL) return;
    if(head->next == NULL) return;

    Node *current1, *current2, *duplicate;
    current1 = head;

    while (current1 != NULL && current1->next != NULL)
    {
        current2 = current1;
        while (current2->next != NULL)
        {
            if (current1->value == current2->next->value)
            {
                duplicate = current2->next;
                current2->next = current2->next->next;
                free(duplicate);
            }
            else current2 = current2->next;
        }
        current1 = current1->next;
        
    }
    
}

/**
 * The Function to insert a value on given location( in the middle of value that are given)
 * @param head: the pointer to the head of the list
 * @param new_value pointer of the new value that will be inserted
 * @param after_value pointer of the location on whih the value should be inserted.
*/
Node *insert_after(Node *head, int new_value, int after_value)
{
    Node *new_node = calloc(1,sizeof(Node));
    new_node->value = new_value;

    if(head == NULL) return new_node;
    else
    {
        Node *current = head;
        while (current->next != NULL)
        {
            if (current->value == after_value)
            {
                new_node->next = current->next;
                current->next = new_node;
                return head;
            }
            else current = current->next;
            
        }
        /**< inserting at the tail if couldnt found the after value/ or if we reach the tail in short.*/
        new_node->next = current->next;
        current->next = new_node;
        return head;
    }
}

/**
 * Function to delete the whole list
 * @return nothing.
*/
Node *delete_list(Node *node)
{
    if (node != NULL)
    {
        delete_list(node->next);
        free(node);
    }
    return NULL;
}

/**
 * This function is to duplicate the list to get another list which has same values.
 * @param node: the pointer to the head of the list.
 * @return the new duplicated list..
*/
Node *duplicate_list(Node *node)
{
    if(node == NULL) return NULL;

    Node *new_node = calloc(sizeof(Node), 1);
    new_node->value = node->value;
    new_node->next = duplicate_list(node->next);

    return new_node;
}

/**
 * Function that merges two sorted lists into a single list
 * @param list1 pointer to head of the first list
 * @param list2 pointer to head of the second list.
 * @return returns the pointer of the merged list.
*/
Node *merge_sorted_lists(Node *list1, Node *list2)
{
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    Node *l1current, *l2current;
    Node *new_head, *new_current;

    l1current = list1;
    l2current = list2;

    if (l1current->value <= l2current->value)
    {
        new_head = l1current;
        l1current = l1current->next;    
    }
    else
    {
        new_head = l2current;
        l2current = l2current->next;
    }
    new_current = new_head;
    
    while (l1current != NULL && l2current != NULL)
    {
        if (l1current->value <= l2current->value)
        {
            new_current->next = l1current;
            new_current = l1current;
            l1current = l1current->next;
        }
        else
        {
            new_current->next = l2current;
            new_current = l2current;
            l2current = l2current->next;
        }
    }

    if (l1current == NULL)
    {
        new_current = l2current;
    }
    else if (l2current == NULL)
    {
        new_current = l1current;
    }
    
     return new_head;
    
    
}

/**
 * Function that print the list
 * @return nothing.
*/
void print_list(Node *head)
{
    Node *current;
    current = head;

    int i = 0;
    while (current != NULL)
    {
        printf("Node: %d = %d\n",i, current->value); /** <We are using -> bc the pointer is pointing to the struct not to the pointer itself*/
        i++;
        current = current->next;
    }
    
}
