#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *createNode(int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}
void insert(Node **head, int value)
{
  Node *newNode = createNode(value);

  if (*head == NULL || value < (*head)->data)
  {
    newNode->next = *head;
    *head = newNode;
  }
  else
  {
    Node *current = *head;

    while (current->next != NULL && current->next->data < value)
    {
      current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
  }
}

void printList(Node *head)
{
  Node *current = head;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main()
{
  Node *head = NULL;

  insert(&head, 5);
  insert(&head, 2);
  insert(&head, 8);
  insert(&head, 1);
  insert(&head, 4);

  printf("Lista ligada ordenada: ");
  printList(head);

  return 0;
}