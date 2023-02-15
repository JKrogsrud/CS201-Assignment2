//
// Created by Jared Krogsrud on 2/8/2023.
//
#include <stdlib.h>
#include <string.h>
#include "stdio.h"

#include "linkedlist.jkrogsru.h"

int insertEntry(StudentRecord **list, char *name, int id)
{
    StudentRecord *newEntry = malloc(sizeof(StudentRecord));

    // Check for NULL name or non-positive id
    if (name == NULL || id <= 0)
    {
        printf("error: cannot insert a record with name NULL");
        return 8;
    }
    else if (id <= 0)
    {
        printf("error: cannot insert a record with negative id");
        return 8;
    }
    else
    {
        // Enter the fields for newEntry
        strcpy(newEntry->name, name);
        newEntry->id = id;
        newEntry->next = NULL;
    }

    // Check if list is empty
    if (*list == NULL)
    {
        *list = newEntry;
        return 0;
    }

    StudentRecord *curr;
    curr = *list;

    // Check if we have an error right off the bat
    if (curr->id == newEntry->id)
    {
        printf("Error: cannot insert %s %d; id already present");
        return 8;
    }

    // Check if the newEntry has a lower id than the head of the list
    if (curr->id > newEntry->id)
    {
        // Make the newEntry the Head of this list with next as old head
        newEntry->next = curr;
        *list = newEntry;
        return 0;
    }

    // Find the appropriate spot
    while (curr->next != NULL && curr->next->id < newEntry->id)
    {
        curr = curr->next;
    }

    // The above ran until one of the following was true:
    // 0) next id == newEntry.id
    // 1) next is NULL
    // 2) next.id > newEntry.id

    if (curr->next == NULL)
    {
        curr->next = newEntry;
    }
    else if (curr->next->id == newEntry->id)
    {
        printf("Error: cannot insert %s %d; id already present");
        return 8;
    }
    else
    {
        newEntry->next = curr->next;
        curr->next = newEntry;
    }

    return 0;
}

int deleteEntry(StudentRecord **list, int id)
{
    // Look through the list until either we get NULL or the id we need

    StudentRecord *curr = *list;

    // First check the first entry is not the one to delete
    if (curr->id == id)
    {
        // set list to the next item in list
        *list = curr->next;
        return 0;
    }

    while (curr->next != NULL && curr->next->id != id)
    {
        curr = curr->next;
    }

    // This stops if either
    /*
     * 1) The next record is NULL
     *      - This case we should return 8
     * 2) The next record is not NULL and whose id is the one we are searching for
     *      - This case we need to link curr to the record after curr->next
     *      This could happen in two ways:
     *          -curr.next.next is NULL:
     *              - We just set curr.next to NULL, return 0
     *          -curr.next is not NULL
     *              - We set curr.next to curr.next.next
     */
    if (curr->next == NULL)
    {
        printf("Error in delete: id %d not found in list", id);
        return 8;
    }
    else
    {
        if (curr->next->next == NULL)
        {
            curr->next = NULL;
            return 0;
        }
        else
        {
            curr->next = curr->next->next;
            return 0;
        }
    }
}

int modifyEntry(StudentRecord *list, char *name, int id)
{
    // Look for the given id value
    StudentRecord *curr = list;

    while (curr != NULL)
    {
        if (curr->id == id)
        {
            strcpy(curr->name, name);
            return 0;
        }
        curr = curr->next;
    }

    printf("Error in modify: id %d not found in the list", id);
    return 8;
}

int findEntry(StudentRecord *list, char *name, int id)
{
    StudentRecord  *curr = list;
    while (curr != NULL)
    {
        if (curr->id == id)
        {
            strcpy(name, curr->name);
            return 0;
        }
        curr = curr->next;
    }
    return 8;
}

int printList(StudentRecord *list)
{
    StudentRecord *curr = list;

    if (list == NULL)
    {
        printf("(list is empty)\n");
    }
    else
    {
        while (curr != NULL)
        {
            printf("|%s|%d\n", curr->name, curr->id);
            curr = curr->next;
        }
    }
    return 0;
}