#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[128];
typedef struct node {
  String name;
  struct node *next;
  struct node *friend; 
} LinkedNode;

int addName(LinkedNode *head, LinkedNode *newNode) {

  // I'm guessing this was meant to be directed towards Nations rather than fiends? lol
  printf("Enter nation name : ");
  scanf("%s", newNode->name);
  
  if (!strcmp(newNode->name, "-1")) {
    free(newNode);
    return 0;
  } else {
    newNode->next = head->next;
    head->next = newNode;
    return -1;
  }
}

LinkedNode *findFriend(LinkedNode *head, String name) {
  LinkedNode *dummy = head;

  while (dummy->next != NULL) {
    dummy = dummy->next;
    if (!strcmp(name, dummy->name)) {
      return dummy;
    }
  }
  return NULL;
}

void addFriend(LinkedNode *head) {
  String friendName;
  LinkedNode *friend = NULL;
  LinkedNode *dummy = head;

  while (dummy->next != NULL)
  {
    dummy = dummy->next;

    for (;;) {
      printf("Enter best ally name for %s : ", dummy->name);
      scanf("%s", friendName);

      if ((friend = (findFriend(head, friendName))) == NULL) {
        printf("Best Ally doesn't exist.\n");
      } else {
        break;
      }
    }
    dummy->friend = friend;
  }
}

void printNodes(LinkedNode *head) {
  LinkedNode *dummy;

  while (head->next != NULL) {
    dummy = head->next;
    free(head);
    head = dummy;
    printf("The best ally of %s is %s\n", head->name, head->friend->name);
  }
  free(head);
}

int main(void) {
  LinkedNode *head = (LinkedNode *)malloc(sizeof(LinkedNode));

  head->next = NULL;

  printf("Type -1 to stop adding names.\n");
  while (addName(head, malloc(sizeof(LinkedNode))))
    ;

  if (head->next == NULL) {
    printf("No Name Entered\n");
    free(head);
    return -1;
  }

  addFriend(head);

  printNodes(head);

  return (EXIT_SUCCESS);
}