//
// file: package.h
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#ifndef MIOK_DLIST_PACKAGE_H
#define MIOK_DLIST_PACKAGE_H

#ifdef __cplusplus
extern "C"
{
#endif

//
// Macros to control the visibility of functions provided by this package
//
#ifdef BUILDING_MIOK_DLIST_PACKAGE
#define MIOK_PUBLIC __attribute__((visibility("default")))
#else
#define MIOK_PUBLIC
#endif

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published package with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting c23 standard. If you wish to use a version of this library
// that targets an older version of C append "-support" at the end of the
// package name and everything should just work.
//

typedef struct DoublyListOf DoublyListOf;


MIOK_PUBLIC DoublyListOf *miok_doubly_list_create(void);
MIOK_PUBLIC void miok_doubly_list_erase(DoublyListOf **structure_ref);
MIOK_PUBLIC void miok_doubly_list_push(DoublyListOf *structure_ptr, const char *data);
MIOK_PUBLIC char *miok_doubly_list_pop(DoublyListOf *structure_ptr);
MIOK_PUBLIC char *miok_doubly_list_peek(DoublyListOf *structure_ptr);
MIOK_PUBLIC unsigned int miok_doubly_list_its_empty(DoublyListOf *structure_ptr);
MIOK_PUBLIC unsigned int miok_doubly_list_not_empty(DoublyListOf *structure_ptr);

#ifdef __cplusplus
}
#endif

#endif // end of MIOK_PACKAGE_H
