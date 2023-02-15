//
// Created by Jared Krogsrud on 2/8/2023.
//

#include <stdio.h>
#include <stdlib.h>
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
    char code;
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

    lineNum = 0;

    line = fgets(buffer, BUFFLEN, fileIn);

    while (line != NULL)
    {
        lineNum += 1;
        numVarsFilled = sscanf(buffer, "%c, %[A-Za-z.' -], %d,", code, name, &id);

        if (code == 'A')
        {
            retval = insertEntry(&list, name, id);
        }
        else if (code == 'M')
        {
            retval = modifyEntry(list, name, id);
        }
        else if (code == 'D')
        {
            retval = deleteEntry(list, id);
        }
        else
        {
            printf("Code not found.");
        }

        line = fgets(buffer, BUFFLEN, fileIn);

    }
    printList(list);
}

