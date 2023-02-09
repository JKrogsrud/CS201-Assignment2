//---------------------------------------
// jdh CS201 Spring 2023
// tests for assigment #2 (linked list)
//---------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.jkrogsru.h"

//----------------------------------------------------------------------

int main() {
  StudentRecord *theList = NULL;
  int numFails = 0;
  int rc, id;
  char name[MAXNAMELEN];
  char expectedName[MAXNAMELEN];

  printf("first test insertions\n");

  strcpy(name, "Roger Federer");
  id = 12345;
  rc = insertEntry(&theList, name, id);
  if (rc == 0) {
    printf("Correct: inserted %s %d\n", name, id);
  } else {
    printf("ERROR: nonzero return code trying to insert %s %d\n", name, id);
    ++numFails;
  }
  printList(theList);
  printf("\n");

  strcpy(name, "Rafael Nadal");
  id = 12344;
  rc = insertEntry(&theList, name, id);
  if (rc == 0) {
    printf("Correct: inserted %s %d\n", name, id);
  } else {
    printf("ERROR: nonzero return code trying to insert %s %d\n", name, id);
    ++numFails;
  }
  printList(theList);
  printf("\n");

  strcpy(name, "Coco Gauff");
  id = 12346;
  rc = insertEntry(&theList, name, id);
  if (rc == 0) {
    printf("Correct: inserted %s %d\n", name, id);
  } else {
    printf("ERROR: nonzero return code trying to insert %s %d\n", name, id);
    ++numFails;
  }
  printList(theList);
  printf("\n");

  // this one should fail
  strcpy(name, "Coco VanDerWeghe");
  id = 12345;
  rc = insertEntry(&theList, name, id);
  if (rc == 0) {
    printf("ERROR: zero return code trying to insert %s %d\n", name, id);
    ++numFails;
  } else {
    printf("Correct: unable to add %s %d\n", name, id);
  }
  printf("\n");

  strcpy(name, "Frances Tiafoe");
  id = 12348;
  rc = insertEntry(&theList, name, id);
  if (rc == 0) {
    printf("Correct: inserted %s %d\n", name, id);
  } else {
    printf("ERROR: nonzero return code trying to insert %s %d\n", name, id);
    ++numFails;
  }
  printList(theList);
  printf("\n");

  strcpy(name, "Emma Raducanu");
  id = 11543;
  rc = insertEntry(&theList, name, id);
  if (rc == 0) {
    printf("Correct: inserted %s %d\n", name, id);
  } else {
    printf("ERROR: nonzero return code trying to insert %s %d\n", name, id);
    ++numFails;
  }
  printList(theList);
  printf("\n");

  // now test delete
  id = 12344;
  rc = deleteEntry(&theList, id);
  if (rc == 0) {
    printf("Correct: deleted record with id  %d\n", id);
  } else {
    printf("ERROR: nonzero return code trying to delete  %d\n", id);
    ++numFails;
  }
  printList(theList);
  printf("\n");

  id = 12346;
  rc = deleteEntry(&theList, id);
  if (rc == 0) {
    printf("Correct: deleted record with id  %d\n", id);
  } else {
    printf("ERROR: nonzero return code trying to delete %d\n", id);
    ++numFails;
  }
  printList(theList);
  printf("\n");

  id = 98723;
  rc = deleteEntry(&theList, id);
  if (rc == 0) {
    printf("ERROR: zero return code trying to delete %d\n", id);
    ++numFails;
  } else {
    printf("Correct: unable to add %d\n", id);
  }
  printf("\n");

  // test modify
  id = 12345;
  strcpy(name, "Roger V. Federer");
  rc = modifyEntry(theList, name, id);
  if (rc == 0) {
    printf("Correct: modified %s %d\n", name, id);
  } else {
    printf("ERROR: nonzero return code trying to modify %d\n", id);
    ++numFails;
  }
  printList(theList);
  printf("\n");

  id = 54278;
  strcpy(name, "Some Name");
  rc = modifyEntry(theList, name, id);
  if (rc == 0) {
    printf("ERROR: zero return code trying to modify %d\n", id);
    ++numFails;
  } else {
    printf("Correct: unable to modify %d\n", id);
  }
  printf("\n");

  // test find
  id = 12345;
  rc = findEntry(theList, name, id);
  strcpy(expectedName, "Roger V. Federer");
  if (rc == 0) {
    if ( strcmp(name, expectedName) == 0 ) {
      printf("Correct: found '%s' for id %d\n", name, id);
    } else {
      printf("ERROR: did not find expected name '%s' for id %d\n", expectedName, id);
      ++numFails;
    }
  } else {
    printf("ERROR: nonzero return code trying to find entry for id %d\n", id);
    ++numFails;
  }
  printf("\n");

  id = 83527;
  rc = findEntry(theList, name, id);
  if (rc == 0) {
    printf("ERROR: zero return code trying to find entry for %d\n", id);
    ++numFails;
  } else {
    printf("Correct: unable to find entry for %d\n", id);
  }
  printf("\n");

  if (numFails == 0) {
    printf("All tests pass!\n");
  } else {
    printf("%d tests failed\n", numFails);
  }

  return numFails;
}
