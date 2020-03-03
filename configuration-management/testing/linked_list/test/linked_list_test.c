#include <unity.h>
#include <stdio.h>

#include <linked_list.h>

struct node *list_ptr = NULL;

void setUp(void)
{
	printf("setUp():\n");
	list_ptr = list_append(list_ptr, 1);
    list_ptr = list_append(list_ptr, 2);
    list_ptr = list_append(list_ptr, 3);
    list_ptr = list_prepend(list_ptr, 4);
 }

void tearDown(void)
{
	printf("tearDown():\n");
	list_remove_all(list_ptr);
	list_ptr = NULL;
}

void test_ListSize(void)
{
	// Exercise
	int length = list_length(list_ptr);
	
	// Verify
	TEST_ASSERT_EQUAL(4, length);
}


void test_ListElements(void)
{
	// Exercise & Verify
	TEST_ASSERT_EQUAL(4, list_get(list_ptr,0));
	TEST_ASSERT_EQUAL(1, list_get(list_ptr,1));
	TEST_ASSERT_EQUAL(2, list_get(list_ptr,2));
	TEST_ASSERT_EQUAL(3, list_get(list_ptr,3));
}


int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ListSize);
	RUN_TEST(test_ListElements);
	return UNITY_END();
}
