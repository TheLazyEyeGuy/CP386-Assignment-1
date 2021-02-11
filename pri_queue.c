#include <stdlib.h>
#include <stdio.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * Insert a Node into a priority queue.
 * @param priority
 * @param data
 * @author Ryan Murari
 */
void PQ_insert(int priority, char * data) {
    //create new node n
    Node_t* n = (Node_t *) malloc(sizeof(Node_t));
    n->data = data;
    n->priority = priority;
    n->next = NULL;

    Node_ptr_t h = NULL;
    //if pq is empty or if the priority of head is greater than the node you want to insert
    if (head == NULL || head->priority < n->priority){
        n->next = head;
        head = n;
    
    }
    else{
        //going through list until you reach end of list or head priority is greater than n
        //pointer that saves head's spot just in case
        h = head;
        while (head->next != NULL && head->next->priority > n->priority){
            head = head->next;
        }
        //when you reach where you need to go reassign head->next to n
        n->next = head->next;
        head->next = n;
        head = h;
        
    }


}
/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
    if (head != NULL){
        Node_ptr_t temp = head;
        *head = *head->next;
        free(temp);
}  
    return head;  
 
 

}

/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
    return head;
}

/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
    int size = 0;
    Node_ptr_t tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next, size++)
        ;
    return size;
}


