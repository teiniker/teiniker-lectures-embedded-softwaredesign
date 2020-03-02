#include <unity.h>
#include <stdio.h>

#include <compare.h>

void setUp(void)
{
	// setup code
}

void tearDown(void)
{
	// tear down code
}

void test_A_greater_B(void)
{
	// Setup
	int a = 17;
	int b = 13;
	
	// Exercise
	int result = compare(a,b);
	
	// Verify
	TEST_ASSERT_EQUAL(1, result);
}

void test_A_lessthan_B(void)
{
	// Setup
	int a = 17;
	int b = 21;
	
	// Exercise
	int result = compare(a,b);
	
	// Verify
	TEST_ASSERT_EQUAL(-1, result);
}

void test_A_equal_B(void)
{
	// Setup
	int a = 23;
	int b = 23;
	
	// Exercise
	int result = compare(a,b);
	
	// Verify
	TEST_ASSERT_EQUAL(0, result);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_A_greater_B);
	RUN_TEST(test_A_lessthan_B);
	RUN_TEST(test_A_equal_B);	
	return UNITY_END();
}

