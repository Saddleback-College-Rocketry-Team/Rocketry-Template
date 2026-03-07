/**
 * @file test_main.cpp
 * @brief file that will be to test things
 * @date 2026-03-07
 * 
 */
#include <unity.h>

void setUp(void) {
}

void tearDown(void) {
}

void test_basic_math(void) {
  TEST_ASSERT_EQUAL_INT(5, 2 + 3);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_basic_math);
  return UNITY_END();
}
