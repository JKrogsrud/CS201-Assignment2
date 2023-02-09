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

