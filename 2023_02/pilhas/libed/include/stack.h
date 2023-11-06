#ifndef STACK
#define STACK
#include <stdbool.h>
#include <stddef.h>

typedef struct _estatic_singly_list ESList;
typedef struct _singly_node SinglyNode, SNode;
typedef struct _singly_linked_list SinglyLinkedList, SList;
typedef struct _doubly_node DoublyNode, DNode;
typedef struct _doubly_linked_list DoublyLinkedList, DList;
typedef struct _circ_node CircNode, CNode;
typedef struct _circ_linked_list CircLinkedList, CList;

ESList *create_ESList(int capacity);
SNode *create_SNode(int val);
SList *create_SList();

DNode *create_DNode(int val);
DList *create_DList();

CNode *create_CNode(int val);
CList *create_CList();

bool ESList_is_full(const ESList *_estatic_singly_list);
bool ESList_is_empty(const ESList *estatic_slist);
bool SList_is_empty(const SList *singly_list);
bool DList_is_empty(const DList *doubly_list);
bool CList_is_empty(const CList *circ_list);

void destroy_ESList(ESList **ref_estatic_slist);
void destroy_SList(SList **ref_singly_list);
void destroy_DList(DList **ref_doubly_list);
void destroy_CList(CList **ref_circ_list);
void destroy_CList_v2(CList **ref_circ_list);
void destroy_CNode(CNode **ref_circ_node);

void append_in_ESList(ESList *estatic_slist, int val);
void add_begin_SList(SList *singly_list , int val);
void add_begin_DList(DList *doubly_list, int val);
void add_begin_CList(CList *circ_list, int val);
void add_end_CList(CList *circ_list, int val);
void add_end_SList(SList *singly_list , int val);
void add_end_DList(DList *doubly_list, int val);

void n_removeESList(ESList *estatic_slist, int n_items);
void removel_DList(DList *doubly_list, int val);
void removel_CList(CList *circ_list, int val);

void print_ESList(const ESList *estatic_slist);
void print_SList(const SList *singly_list);
void print_DList(const DList *doubly_list);
void print_inverted_DList(const DList *doubly_list);
void print_CList(const CList *circ_list);
void print_CList_v2(const CList *circ_list);
void print_inverted_CList(const CList *circ_list);
void print_inverted_CList_v2(const CList *circ_list);

ESList *concat_ESList(const ESList *estatic_slist01, const ESList *estatic_slist02);
SList *concat_SList(const SList *singly_list_01, const SList *singly_list_02);
DList *concat_DList(const DList *doubly_list_01, const DList *doubly_list_02);
CList *concat_CList(const CList *circ_list_01, const CList *circ_list_02);

#endif