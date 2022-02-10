//
// file: test_cases.c
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
// USE CASE:
//
// The use case of this file is to contain the test cases needed by this
// project since its important to test once implementation against a set
// of common test cases
//
#include "miok/doublylist.h"
#include <unity.h>

DoublyListOf *list;

//
//  project setup teardown functions if needed
//
void setUp(void)
{
    list = miok_doubly_list_create();
} // end of function setUp

void tearDown(void)
{
    miok_doubly_list_erase(&list);
} // end of function tearDown


//
// list of all the test cases for this project
//
static void test_miok_doubly_list_push(void)
{
    TEST_ASSERT_NOT_NULL(list);
    miok_doubly_list_push(list, "2021");
    TEST_ASSERT_EQUAL_STRING("2021", miok_doubly_list_peek(list));

    miok_doubly_list_push(list, "2077");
    miok_doubly_list_push(list, "2010");
    TEST_ASSERT_EQUAL_STRING("2010", miok_doubly_list_peek(list));
} // end of test case

static void test_miok_doubly_list_push_with_nullptr(void)
{
    miok_doubly_list_push(NULL, "2021");
    TEST_ASSERT_EQUAL_STRING(NULL, miok_doubly_list_peek(list));

    miok_doubly_list_push(NULL, "2077");
    miok_doubly_list_push(NULL, "2021");
    TEST_ASSERT_EQUAL_STRING(NULL, miok_doubly_list_peek(list));
} // end of test case

static void test_miok_doubly_list_pop(void)
{
    TEST_ASSERT_NOT_NULL(list);
    miok_doubly_list_push(list, "red chicken");
    miok_doubly_list_push(list, "blue chicken");
    miok_doubly_list_push(list, "black chicken");
    miok_doubly_list_push(list, "green chicken");
    miok_doubly_list_push(list, "yellow chicken");

    TEST_ASSERT_EQUAL_STRING("yellow chicken", miok_doubly_list_peek(list));
    miok_doubly_list_pop(list);
    TEST_ASSERT_EQUAL_STRING("green chicken", miok_doubly_list_peek(list));
    miok_doubly_list_pop(list);
    TEST_ASSERT_EQUAL_STRING("black chicken", miok_doubly_list_peek(list));
} // end of test case

static void test_miok_doubly_list_pop_with_nullptr(void)
{
    miok_doubly_list_push(NULL, "red chicken");
    miok_doubly_list_push(NULL, "blue chicken");
    miok_doubly_list_push(NULL, "black chicken");

    TEST_ASSERT_EQUAL_STRING(NULL, miok_doubly_list_peek(list));
    miok_doubly_list_pop(list);
    TEST_ASSERT_EQUAL_STRING(NULL, miok_doubly_list_peek(list));
} // end of test case

static void test_miok_doubly_list_its_empty(void)
{
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_TRUE(miok_doubly_list_its_empty(list));
    miok_doubly_list_push(list, "red chicken");
    TEST_ASSERT_FALSE(miok_doubly_list_its_empty(list));

    TEST_ASSERT_EQUAL_STRING("red chicken", miok_doubly_list_peek(list));
} // end of test case

static void test_miok_doubly_list_its_empty_with_nullptr(void)
{
    miok_doubly_list_push(NULL, "red chicken");
    TEST_ASSERT_TRUE(miok_doubly_list_its_empty(list));

    TEST_ASSERT_EQUAL_STRING(NULL, miok_doubly_list_peek(list));
} // end of test case

static void test_miok_doubly_list_not_empty(void)
{
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_FALSE(miok_doubly_list_not_empty(list));
    miok_doubly_list_push(list, "red chicken");
    TEST_ASSERT_TRUE(miok_doubly_list_not_empty(list));

    TEST_ASSERT_EQUAL_STRING("red chicken", miok_doubly_list_peek(list));
} // end of test case

static void test_miok_doubly_list_not_empty_with_nullptr(void)
{
    miok_doubly_list_push(NULL, "red chicken");
    TEST_ASSERT_FALSE(miok_doubly_list_not_empty(list));

    TEST_ASSERT_EQUAL_STRING(NULL, miok_doubly_list_peek(list));
} // end of test case

//
//  here main is used as the test runner
//
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_miok_doubly_list_push);
    RUN_TEST(test_miok_doubly_list_pop);
    RUN_TEST(test_miok_doubly_list_its_empty);
    RUN_TEST(test_miok_doubly_list_not_empty);
    RUN_TEST(test_miok_doubly_list_push_with_nullptr);
    RUN_TEST(test_miok_doubly_list_pop_with_nullptr);
    RUN_TEST(test_miok_doubly_list_its_empty_with_nullptr);
    RUN_TEST(test_miok_doubly_list_not_empty_with_nullptr);

    return UNITY_END();
} // end of function main
