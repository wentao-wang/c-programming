#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cs402.h"
#include "linkedlist.h"

 int  My402ListLength(My402List* list) {
    if (list == NULL) {
        return 0;
    }
     return list -> num_members;
 }

 int  My402ListEmpty(My402List* list){
    if (list == NULL || list -> num_members == 0) {
        return TRUE;
    }
     return FALSE;
 }

//append null obj or not????
 int  My402ListAppend(My402List* list, void* obj) {
//     if (obj == NULL) {
//         return FALSE;
//     }
     My402ListElem *ele = (My402ListElem*) malloc(sizeof(My402ListElem));
     ele -> obj = obj;
     if (My402ListEmpty(list)) {
//         if (!My402ListInit(list)) {
//             return FALSE;
//         }
         list -> anchor.next = ele;
         ele -> next = &(list -> anchor);
         ele -> prev = &(list -> anchor);
         list -> anchor.prev = ele;
         list -> num_members++;
         return TRUE;
     }
     My402ListLast(list) -> next = ele;
     ele -> next = &(list -> anchor);
     ele -> prev = My402ListLast(list);
     list -> anchor.prev = ele;
     list -> num_members++;
    return TRUE;
 }

 int  My402ListPrepend(My402List* list, void* obj) {
//     if (obj == NULL) {
//         return FALSE;
//     }
    My402ListElem *ele = (My402ListElem*) malloc(sizeof(struct tagMy402ListElem));
     ele -> obj = obj;
     if (My402ListEmpty(list)) {
         if (!My402ListInit(list)) {
             return FALSE;
         }
         list -> anchor.next = ele;
         ele -> next = &(list -> anchor);
         ele -> prev = &(list -> anchor);
         list -> anchor.prev = ele;
         list -> num_members++;
         return TRUE;
     }
     My402ListFirst(list) -> prev = ele;
     ele -> next = My402ListFirst(list);
     list -> anchor.next = ele;
     ele -> prev = &(list -> anchor);
     list -> num_members++;
     return TRUE;

 }

//what if list length is one????
 void My402ListUnlink(My402List* list, My402ListElem* ele) {
     if (My402ListEmpty(list) || ele == NULL) {
         return;
     }
    if (ele -> next != NULL) {
        ele -> prev -> next = ele -> next;
    }
     if (ele -> prev != NULL) {
         ele -> next -> prev = ele -> prev;
     }


             ele -> next = NULL;
             ele -> prev = NULL;
             free(ele);
             list -> num_members--;
             return;

 }

 void My402ListUnlinkAll(My402List* list){
     if (My402ListEmpty(list)) {
         return;
     }
     My402ListElem *temp1 = NULL;
     My402ListElem *temp2 = NULL;
     for(temp1 = My402ListFirst(list); temp1 != NULL; temp1 = temp2) {
         if(temp1 == &(list ->anchor)) {
             break;
         }
         temp2 = temp1 -> next;
         temp1 -> next = NULL;
         temp1 -> prev = NULL;
         free(temp1);
     }
     My402ListInit(list);
     return;
 }

 int  My402ListInsertAfter(My402List* list, void* obj, My402ListElem* ele) {
//     if (obj == NULL) {
//         return FALSE;
//     }
     if (ele == NULL) {
        return My402ListAppend(list, obj);
    }
     if (My402ListEmpty(list)) {
         if (!My402ListInit(list)) {
             return FALSE;
         }
     }
     My402ListElem *mid = (My402ListElem*) malloc(sizeof(My402ListElem));
     mid -> obj = obj;
     mid -> next = ele -> next;
     ele -> next -> prev = mid;
     ele -> next = mid;
     mid -> prev = ele;
     list -> num_members++;
     return TRUE;
 }


 int  My402ListInsertBefore(My402List* list, void* obj, My402ListElem* ele) {
//     if (obj == NULL) {
//         return FALSE;
//     }
     if (ele == NULL) {
       return My402ListPrepend(list, obj);
    }
     if (My402ListEmpty(list)) {
         if (!My402ListInit(list)) {
             return FALSE;
         }
     }

     My402ListElem *mid = (My402ListElem*) malloc(sizeof(My402ListElem));
     mid -> obj = obj;
     mid -> next = ele;
     mid -> prev = ele -> prev;
     ele -> prev -> next = mid;
     ele -> prev = mid;
     list -> num_members++;
     return TRUE;


 }


 My402ListElem *My402ListFirst(My402List* list) {
     if (My402ListEmpty(list)) {
         return NULL;
     }

     return list -> anchor.next;

 }

 My402ListElem *My402ListLast(My402List* list) {
     if (My402ListEmpty(list)) {
         return NULL;
     }

     return list -> anchor.prev;

 }

 My402ListElem *My402ListNext(My402List* list, My402ListElem* ele) {
     if (My402ListEmpty(list) || ele == NULL || ele == My402ListLast(list)) {
         return NULL;
     }
     return ele -> next;
 }

 My402ListElem *My402ListPrev(My402List* list, My402ListElem* ele) {
     if (My402ListEmpty(list) || ele == NULL || ele == My402ListFirst(list)) {
         return NULL;
     }
     return ele -> prev;
 }

 My402ListElem *My402ListFind(My402List* list, void* obj) {
     if (My402ListEmpty(list) ) {
         return NULL;
     }
     My402ListElem *elem = NULL;
     for (elem = My402ListFirst(list); elem != NULL; elem = My402ListNext(list, elem)) {
         if (obj == elem -> obj) {
             return elem;
         }

     }
     return NULL;

 }


 int My402ListInit(My402List* list) {
    list -> anchor.obj = NULL;
     list -> anchor.next = NULL;
     list -> anchor.prev = NULL;
     list -> num_members = 0;
     return TRUE;
 }
