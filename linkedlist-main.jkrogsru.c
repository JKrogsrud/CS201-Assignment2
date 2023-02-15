//
// Created by Jared Krogsrud on 2/8/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.jkrogsru.h"

/*
 * main will open a file for which the name is specified on
 * command line; read a line from the file, check that the
 * line is valid, perform the action specified by the line,
 * and then repeat; until all lines have been read.
 *
 * Every time a file is successfully read, print a message
 * describing the action taken or error message if not successful.
 * Print an error message if an input line does not have correct format.
 *
 */

int main(int argc, char *argv[])
{
    // For file reading and scanning
    char buffer[BUFFLEN];
    char code[64];
    char name[64];
    int id;
    int lineNum;
    int numVarsFilled;
    FILE *fileIn;
    char *line;

    // For Student Records
    StudentRecord *list;
    int retval;

    if (argc < 2)
    {
        printf("error: need filename\n");
        return 8;
    }

    fileIn = fopen(argv[1], "r");
    if (fileIn == NULL)
    {
        printf("cannot open file '%s' for reading\n", argv[1]);
        return 8;
    }

    printf("reading file %s\n", argv[1]);

    lineNum = 0;
    line = fgets(buffer, BUFFLEN, fileIn);
    while (line != NULL)
    {
        lineNum += 1;
        numVarsFilled = sscanf(buffer, "%[A-Za-z.' -], %[A-Za-z.' -], %d,", code, name, &id);

        if (numVarsFilled != 3)
        {
            printf("Line %d error: not enough values; or incorrect format\n", lineNum);
        }
        else if (strcmp(code, "A") == 0)
        {
            retval = insertEntry(&list, name, id);
            if (retval == 0)
            {
                printf("Inserted: |%s|%d\n", name, id);
            }
            else
            {
                printf("Error inserting |%s|%d\n", name, id);
            }
        }
        else if (strcmp(code, "M") == 0)
        {
            retval = modifyEntry(list, name, id);
            if (retval == 0)
            {
                printf("modified: %d\n", id);
            }
            else
            {
                printf("Error modifying %d\n", id);
            }

        }
        else if (strcmp(code, "D") == 0)
        {
            retval = deleteEntry(&list, id);
            if (retval == 0)
            {
                printf("deleted: %d\n", id);
            }
            else
            {
                printf("Error deleting %d\n", id);
            }
        }
        else
        {
            printf("Instruction code not found\n");
        }

        // printf("code:%s, name:%s, id: %d\n", code, name, id);

        line = fgets(buffer, BUFFLEN, fileIn);

    }
    // printList(list);
}

