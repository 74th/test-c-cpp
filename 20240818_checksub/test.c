#include <stdio.h>
#include <stdint.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/TestDB.h>

void test_simple_sum(void);
void test_xor_sum(void);

int main(void)
{
    CU_pSuite suite;
    CU_initialize_registry();

    suite = CU_add_suite("Test", NULL, NULL);
    CU_add_test(suite, "simple_sum", test_simple_sum);
    CU_add_test(suite, "xor_sum", test_xor_sum);

    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}

void test_simple_sum(void)
{
    uint8_t a[4] = {0x12, 0x36, 0x45, 0x78};

    uint8_t sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += a[i];
    }

    printf("sum: 0x%02x\n", sum);
    CU_ASSERT(sum == 0x05);
}

void test_xor_sum(void)
{
    uint8_t a[4] = {0x12, 0x36, 0x45, 0x78};

    uint8_t sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum ^= a[i];
    }

    // XORは別物よね
    printf("sum: 0x%02x\n", sum);
    CU_ASSERT(sum == 0x05);
}
