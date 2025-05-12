#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct node *createLinkedList (int size){
  int x;
  struct node *first = NULL;
  struct node *temp = NULL;
  struct node *ptr = NULL;
  for (int i = 0; i < size; i++)
    {
      printf ("Enter the data %d: ", i + 1);
      scanf ("%d", &x);
      temp = (struct node *) malloc (sizeof (struct node));
      temp->data = x;
      temp->next = NULL;
      if (first == NULL)
	{
	  first = temp;
	  ptr = temp;
	}

      else
	{
	  ptr->next = temp;
	  ptr = ptr->next;
	}
    }
  return first;
}

void display (struct node *first){
  struct node *ptr = first;
  if (first == NULL)
    {
      printf ("Linked List is empty!\n");
    }
  else
    {
      while (ptr != NULL)
	{
	  printf ("%d\t", ptr->data);
	  ptr = ptr->next;
	}
      printf ("\n");
    }
}

struct node *delete (struct node *first){
  if (first == NULL)
    {
      printf ("Linked List is empty!\n");
    }
  else
    {
      int opt;
      printf ("Enter the following from the choices to delete:\n");
      printf ("1. For first node deletion\n");
      printf ("2. For last node deletion\n");
      printf ("3. For middle node deletion\n");
      scanf ("%d", &opt);
      struct node *temp = NULL;
      switch (opt)
	{
	case 1:
	  {
	    temp = first;
	    printf ("%d deleted\n", first->data);
	    first = first->next;
	    free (temp);
	  }
	  break;
	case 2:
	  {

	    struct node *ptr = NULL;
	    struct node *prev = NULL;
	    ptr = first;
	    while (ptr->next != NULL)
	      {
		prev = ptr;
		ptr = ptr->next;
	      }
	    printf ("%d deleted\n", ptr->data);
	    prev->next = NULL;
	    free (ptr);
	  }
	  break;
	case 3:
	  {
	    int pos;
	    printf ("Enter position to delete: ");
	    scanf ("%d", &pos);
	    struct node *ptr = NULL;
	    struct node *ptr1 = NULL;
	    ptr = first;
	    for (int i = 1; i < pos - 1; i++)
	      {
		ptr = ptr->next;
	      }
	    if (ptr == NULL)
	      {
		printf ("Insufficient Node\n");
	      }
	    else
	      {
		ptr1 = ptr->next;
		ptr->next = ptr1->next;
		free (ptr1);
	      }
	  }
	  break;
	default:
	  printf ("Invalid choice\n");
	}
    }
  return first;
}

struct node *insert (struct node *first, int elem){
  struct node *temp = (struct node *) malloc (sizeof (struct node));
  temp->data = elem;
  temp->next = NULL;
  if (first == NULL)
    {

      first = temp;
    }
  else
    {
      int opt;
      printf ("Enter the following from the choices to insert:\n");
      printf ("1. For first node insertion\n");
      printf ("2. For last node insertion\n");
      printf ("3. For middle node insertion\n");
      scanf ("%d", &opt);
      switch (opt)
	{
	case 1:
	  {
	    temp->next = first;
	    first = temp;
	  }
	  break;
	case 2:
	  {
	    struct node *ptr = NULL;
	    ptr = first;
	    while (ptr->next != NULL)
	      {
		ptr = ptr->next;
	      }
	    ptr->next = temp;
	  }
	  break;
	case 3:
	  {
	    int pos;
	    printf ("Enter position to insert: ");
	    scanf ("%d", &pos);
	    struct node *ptr = NULL;
	    ptr = first;
	    int i = 2;
	    while (ptr != NULL && i != pos)
	      {
		i++;
		ptr = ptr->next;
	      }
	    if (ptr == NULL)
	      {
		printf ("Insufficient Nodes\n");
	      }
	    else
	      {
		temp->next = ptr->next;
		ptr->next = temp;
	      }
	  }

	  break;
	default:
	  printf ("Invalid choice\n");
	}
    }
  return first;
}

void search (struct node *first, int elem){
  int flag = 0;
  int i = 0;
  struct node *ptr = first;
  while (ptr != NULL)
    {
      i++;
      if (ptr->data == elem)
	{
	  printf ("Found %d at node number %d\n", elem, i);
	  flag = 1;
	  break;
	}
      ptr = ptr->next;
    }
  if (flag == 0)
    {
      printf ("%d is not found\n", elem);
    }
}

void update (struct node *first, int cur, int next){
  int flag = 0;
  struct node *ptr = NULL;
  ptr = first;
  while (ptr != NULL)
    {
      if (ptr->data == cur)
	{
	  ptr->data = next;
	  printf ("Updated %d in place of %d\n", next, cur);
	  flag = 1;
	  break;
	}
      ptr = ptr->next;
    }
  if (flag == 0)
    {
      printf ("%d is not found\n", cur);

    }
}

int main (){
  int size, opt;
  printf ("Enter the size of Linked List to create: ");
  scanf ("%d", &size);
  struct node *l1 = createLinkedList (size);
  do
    {
      printf
	("Enter the following from the choices to perform operations on Linked List:\n");

      printf ("1. For insertion\n");
      printf ("2. For deletion\n");
      printf ("3. For display\n");
      printf ("4. For update operation\n");
      printf ("5. For searching\n");
      printf ("6. To exit\n");
      scanf ("%d", &opt);
      switch (opt)
	{
	case 1:
	  {
	    int elem;
	    printf ("Enter a element to insert: ");
	    scanf ("%d", &elem);
	    l1 = insert (l1, elem);
	    display (l1);
	  }
	  break;
	case 2:
	  {
	    l1 = delete (l1);
	    display (l1);
	  }
	  break;
	case 3:
	  {
	    display (l1);
	  }
	  break;
	case 4:
	  {
	    int cur, next;
	    printf ("Enter the element to update: ");
	    scanf ("%d", &cur);
	    printf ("\nEnter the new element to insert: ");
	    scanf ("%d", &next);
	    update (l1, cur, next);

	    display (l1);
	  }
	  break;
	case 5:
	  {
	    int elem;
	    printf ("Enter the element to search: ");
	    scanf ("%d", &elem);
	    search (l1, elem);
	  }
	  break;
	case 6:
	  {
	    printf ("Exiting the program!\n");
	  }
	  break;
	default:
	  printf ("Invalid Choice\n");
	}
    }
  while (opt != 6);
  free (l1);
  return 0;
}
