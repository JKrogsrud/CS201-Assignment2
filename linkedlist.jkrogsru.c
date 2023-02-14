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

    StudentRecord *curr = *list;

    // Check if we have an error right off the bat
    if (curr->id == newEntry->id)
    {
        printf("ERROR: Trying to enter a duplicate id.");
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
    while ( curr->next != NULL && curr->next->id < newEntry->id)
    {
        *curr = *curr->next;
        if (curr->next->id == newEntry->id)
        {
            printf("ERROR: Trying to enter a duplicate id.\n");
            return 8;
        }
    }

    newEntry->next = curr->next;
    curr->next = newEntry;
    *list = curr;

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
    }

    while (curr->next != NULL && curr->next->id != id)
    {
        *curr = *curr->next;
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