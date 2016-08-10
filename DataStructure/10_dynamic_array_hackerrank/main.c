/* Solution for the problem given at https://www.hackerrank.com/challenges/dynamic-array */

#include <stdio.h>
#include <stdlib.h>

typedef struct sequence_t {
    int val;
    struct sequence_t * next;
} Seq;

typedef struct list_t {
    Seq * seq;
    struct list_t * next;
} List;

Seq * append_to_sequence(Seq * seq_head, int item) {
    Seq * seq_tail;

    if(seq_head == NULL) {
        seq_head = (Seq *)(malloc(sizeof(Seq)));
        seq_head->val  = item;
        seq_head->next = NULL;
        seq_tail = seq_head;
    }

    return seq_tail;
}

List * append_to_sequence_in_list(List * list_head, int seq_no, int item) {
    List * list_tail;
    List * list_ptr;

    if(list_head == NULL) {
        list_head = (List *)(malloc(sizeof(List)));
        list_head->seq  = append_to_sequence(list_head->seq, item);
        list_head->next = NULL;
        list_tail = list_head;
    }

    return list_tail;
}

int main() {
    int N,  //-- Number of sequences
        Q;  //-- Number of queries

    List * myList = NULL;
    List * myList_head = myList;
    List * myList_tail;

    myList_tail = append_to_sequence_in_list(myList_head, 0, 9);

    printf("%d\n", myList_tail->seq->val);

    return 0;
}
