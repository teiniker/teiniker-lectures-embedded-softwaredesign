#include <unity.h>
#include <stdio.h>

void setUp(void)
{
	// setup code
}

void tearDown(void)
{
	// tear down code
}

void test_A(void)
{
	TEST_ASSERT_EQUAL_HEX8(40, 40);
}

void test_B(void)
{
	TEST_ASSERT_EQUAL_HEX8(80, 90);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_A);
	RUN_TEST(test_B);
	return UNITY_END();
}

