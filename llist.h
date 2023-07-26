/**
* Linked List Library
*
* @file llist.h
* @author Jack Frater K. Buyole
* @date July 17, 2023
* Special thanks to Kavin Browne
*/

#include <stdbool.h>

/* A simple node in a Linked List */
typedef struct node
{
    int value; /**< Variable value that stores the integer value of the node*/
    struct node *next; /**< A pointer that point to the next node in the list */

}Node;





void print_list(Node *head);
int list_lenght(Node *head); 
int list_lenght_recursive_way(Node *node);
bool is_member(Node *node, int find_value); 
int count_matched_search(Node *node, int find_value);
void replace_mathes(Node *node, int find_value, int replace_value); 
void replace_mathes(Node *node, int find_value, int replace_value);
void sort_list(Node *head);
void delete_duplicates(Node *head);
void add_lists(Node *list1, Node *list2);

Node *insert_at_Head(Node *head, int new_value);
Node *insert_at_Tail(Node *head, int new_value);
Node *delete_at_head(Node *head);
Node *delete_at_tail(Node *head);
Node *delete_first_match(Node *head, int delete_value, bool *was_deleted);
Node *efficient_delete_matches(Node *head, int delete_value, int *num_deleted);
Node *append_list(Node *head1, Node *head2); 
Node *reverse_list(Node *head);
Node *insert_after(Node *head, int new_value, int after_value); 
Node *delete_list(Node *node);
Node *duplicate_list(Node *node);
Node *merge_sorted_lists(Node *list1, Node *list2); 