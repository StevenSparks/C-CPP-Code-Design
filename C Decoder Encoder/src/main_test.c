#include <unity.h>
#include <encoder.h>
#include <stdint.h>
#include <time.h>

void setUp(void)
{
     
}

void tearDown(void)
{
    
}

void test_null_ptr(){
    uint8_t* byte_ptr = 0;

    bool parity_succes = set_parity(byte_ptr);

    TEST_ASSERT_FALSE(parity_succes);
    TEST_ASSERT_NULL(byte_ptr);
}

void parity_normal_operation(){
    uint8_t byte1 = 0b1101;
    uint8_t byte2 = 0b0101;

    uint8_t expected_byte1 = 0b01001101;
    uint8_t expected_byte2 = 0b00010101;

    set_parity(&byte1);
    set_parity(&byte2);

    TEST_ASSERT_EQUAL_INT8(expected_byte1, byte1);
    TEST_ASSERT_EQUAL_INT8(expected_byte2, byte2);
}

void create_histogram(){
    int my_max = 8;
    int my_min = 0;

    srand(time(NULL));

    int bit0 = 0;
    int bit1 = 0;
    int bit2 = 0;
    int bit3 = 0;
    int bit4 = 0;
    int bit5 = 0;
    int bit6 = 0;
    int bit7 = 0;

    for(int i = 0; i < 5000; i++)
    {   
        uint8_t my_mask = (1 << (rand() % my_max + my_min));
        switch (my_mask)
        {
        case 1:
            bit0 += 1;
            break;
        case 2:
            bit1 += 1;
            break;
        case 4:
            bit2 += 1;
            break;
        case 8:
            bit3 += 1;
            break;
        case 16:
            bit4 += 1;
            break;
        case 32:
            bit5 += 1;
            break;
        case 64:
            bit6 += 1;
            break;
        case 128:
            bit7 += 1;
            break;
        }
    }
    printf("bit0 was flipped %d times\n", bit0);
    printf("bit1 was flipped %d times\n", bit1);
    printf("bit2 was flipped %d times\n", bit2);
    printf("bit3 was flipped %d times\n", bit3);
    printf("bit4 was flipped %d times\n", bit4);
    printf("bit5 was flipped %d times\n", bit5);
    printf("bit6 was flipped %d times\n", bit6);
    printf("bit7 was flipped %d times\n", bit7);
}


int main(void)
{
    create_histogram();

    UnityBegin(0);

    RUN_TEST(test_null_ptr);
    RUN_TEST(parity_normal_operation);
    
    return UnityEnd();
}
