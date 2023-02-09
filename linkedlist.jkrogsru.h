#ifndef ASSIGNMENT2_LINKEDLIST_JKROGSRU_H
#define ASSIGNMENT2_LINKEDLIST_JKROGSRU_H

#define MAXNAMELEN 127

#define BUFFLEN 256
#define TMPBUFFLEN 128

typedef struct StudentRecordStruct {
    char name[1+MAXNAMELEN];
    int id;
    struct StudentRecordStruct *next;
} StudentRecord;

/*
 * Will create a new StudentData record, fill it with supplied name and id
 * and put it into the list so that the list is maintained in ascending
 * order of id. If name is NULL or id is not positive, then leave the
 * list unchanged and return 8.
 * If there is already a record in the list for which the id matches the
 * supplied id value then return 8. Otherwise return 0.
 */
int insertEntry(StudentRecord **list, char *name, int id);

/*
 * Will remove from the list the node having specified id.
 * If there is no entry in the list with specified id value,
 * then return 8; otherwise, return 0.
 */
int deleteEntry(StudentRecord **list, int id);

/*
 * will update the name value in the list entry having specified
 * id value. If there is no record in the list with this value
 * then return 8; otherwise return 0.
 */
int modifyEntry(StudentRecord *list, char *name, int id);

/*
 * will look in the list for the record having the specified id value.
 * If no record with id exists return 8, otherwise copy name into name param
 * and return 0.
 */
int findEntry(StudentRecord *list, char *name, int id);

/*
 * will print each record in the list in order.
 * If list is empty it should print (list is empty)
 * Otherwise, it should print each record on a single line, in
 * the format: |name|44565
 */
int printList(StudentRecord *list);

#endif //ASSIGNMENT2_LINKEDLIST_JKROGSRU_H
