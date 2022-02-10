//
// file: package.c
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#include "miok/doublylist.h"

#include <stdlib.h>
#include <string.h>

enum
{
    failed,
    success
}; // end of local enums

//
// This is the official definition for the Amphibian Libraries
// 'DoublyListNode' type.
//
// Members:
// > [_data] is the private data member that represents the
//           data in the structure
// > [_next_ptr] is the pointer to the next node
//
typedef struct DoublyListNode
{
    char *_data;
    struct DoublyListNode *_next_ptr;
    struct DoublyListNode *_prev_ptr;
} DoublyListNode; // end of struct

//
// This is the official definition for the Amphibian Libraries
// 'DoublyListOf' type.
//
// Members:
// > _size is the number of nodes in the current list
// > _begin_ptr is the pointer to begining of the DoublyList
// > _end_ptr is the pointer to ending of the DoublyList
//
struct DoublyListOf
{
    size_t _size;
    struct DoublyListNode *_begin_ptr;
    struct DoublyListNode *_end_ptr;
}; // end of struct

//
// Should return a newly hatched data structure object if
// it pass the not nullptr test. But if it was a bad egg
// we just return nullptr.
//
// Param list:
// -> There is none to speak of at this time.
//
DoublyListOf *miok_doubly_list_create(void)
{
    DoublyListOf *new_structure = malloc(sizeof(*new_structure));
    if (!new_structure)
    {
        return NULL;
    } // end if
    new_structure->_size = 0;
    new_structure->_begin_ptr = NULL;
    new_structure->_end_ptr = NULL;

    return new_structure;
} // end of function miok_doubly_list_create

//
// Should erase the ForwardList structure if it’s not nullptr else
// do nothing.
//
// Param list:
// -> [structure_ref]: Reference pointer to your structure
//
void miok_doubly_list_erase(DoublyListOf **structure_ref)
{

    if (!*structure_ref)
    {
        return;
    } // end if

    DoublyListOf *temp_structure = *structure_ref;

    while (!miok_doubly_list_its_empty(temp_structure))
    {
        miok_doubly_list_pop(temp_structure);
    } // end while

    free(temp_structure);
    temp_structure = NULL;
    *structure_ref = NULL;
} // end of function miok_doubly_list_erase

//
// Should push a new recored into the ForwardList if the
// structure is not nullptr. Else nothing.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
// -> [data]: Your data being passed in
//
void miok_doubly_list_push(DoublyListOf *structure_ptr, const char *data)
{
    if (!structure_ptr)
    {
        return;
    } // end if

    DoublyListNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if

    temp->_data = (char *)data;
    temp->_next_ptr = NULL;
    temp->_prev_ptr = NULL;

    if (!structure_ptr->_begin_ptr)
    {
        structure_ptr->_begin_ptr = temp;
        structure_ptr->_end_ptr = temp;
    } // end if
    else
    {
        temp->_prev_ptr = structure_ptr->_end_ptr;
        structure_ptr->_end_ptr->_next_ptr = temp;
        structure_ptr->_end_ptr = temp;
    } // end else
    ++structure_ptr->_size;
} // end of function miok_doubly_list_push

//
// Should return the value stored in the removed node from
// structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
char *miok_doubly_list_pop(DoublyListOf *structure_ptr)
{
    if (!structure_ptr->_begin_ptr)
    {
        return NULL;
    } // end if

    DoublyListNode *temp = structure_ptr->_end_ptr;
    char *popped = temp->_data;
    if (temp == structure_ptr->_begin_ptr && structure_ptr->_end_ptr)
    {
        structure_ptr->_begin_ptr = NULL;
        structure_ptr->_end_ptr = NULL;
    } // end if
    else if (temp == structure_ptr->_begin_ptr)
    {
        structure_ptr->_begin_ptr->_prev_ptr = NULL;
        structure_ptr->_begin_ptr = structure_ptr->_begin_ptr->_next_ptr;
    } // end else

	else if(temp == structure_ptr->_end_ptr)
	{
		structure_ptr->_end_ptr->_prev_ptr->_next_ptr = NULL;
		structure_ptr->_end_ptr = structure_ptr->_end_ptr->_prev_ptr;
		structure_ptr->_size--;
	} // end if else
	else
	{
		temp->_prev_ptr->_next_ptr = temp->_next_ptr;
		temp->_next_ptr->_prev_ptr = temp->_prev_ptr;
		structure_ptr->_size--;
	} // end else

    --structure_ptr->_size;

    free(temp);
    return popped;
} // end of function miok_doubly_list_pop

//
// Should return the value stored in begin pointer from
// structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
char *miok_doubly_list_peek(DoublyListOf *structure_ptr)
{
    if (structure_ptr->_end_ptr)
    {
        return structure_ptr->_end_ptr->_data;
    }
    else if (structure_ptr->_begin_ptr)
    {
        return structure_ptr->_begin_ptr->_data;
    }
    return NULL;
} // end of function miok_doubly_list_peek

//
// Should return a success value if the structure is an
// empty structure.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
unsigned int miok_doubly_list_its_empty(DoublyListOf *structure_ptr)
{
    return (!structure_ptr->_begin_ptr) ? success : failed;
} // end of function miok_doubly_list_its_empty

//
// Should return a success value if the structure is not
// an empty structure.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
unsigned int miok_doubly_list_not_empty(DoublyListOf *structure_ptr)
{
    return (structure_ptr->_begin_ptr) ? success : failed;
} // end of function miok_doubly_list_not_empty
