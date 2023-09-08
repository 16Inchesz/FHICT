#include "unity.h"
#include "encoder.h"


void setUp(void){}

void tearDown(void){}

/// @brief This test simulates different parity bits being calculated for different nibbles
/// @param  void
void TestCalculateParityBits(void){
    //assign
    uint8_t nibble1 = 0x0D;          //0b1101
    uint8_t expectedResult1 = 0x04;  //0b0100

    uint8_t nibble2 = 0x02;          //0b0010
    uint8_t expectedResult2 = 0x03;  //0b0110

    uint8_t nibble3 = 0x0A;          //0b1010
    uint8_t expectedResult3 = 0x06;  //0b0110
    
    //act
    uint8_t result1 = CalculateParity(nibble1);
    uint8_t result2 = CalculateParity(nibble2);
    uint8_t result3 = CalculateParity(nibble3);

    
    //assert
    TEST_ASSERT_EQUAL(expectedResult1, result1);
    TEST_ASSERT_EQUAL(expectedResult2, result2);
    TEST_ASSERT_EQUAL(expectedResult3, result3);
}

/// @brief This test simulates the function taking in an inputByte and encoding it into two different bytes.
/// @param  void
void TestEncodeByteFunction(void){
    //assign
    uint8_t inputByte = 0x37;   //0b00110111
    uint8_t encodedByteHigh;
    uint8_t encodedByteLow;
    bool expectedResult = true;
    uint8_t expectedEncodedByteHigh = 0x43 ;  //0b01000011
    uint8_t expectedEncodedByteLow = 0x27 ;   //0b00100111

    //act
    bool result = encodeByte(inputByte, &encodedByteHigh, &encodedByteLow);

    //assert
    TEST_ASSERT_EQUAL(expectedEncodedByteHigh, encodedByteHigh);
    TEST_ASSERT_EQUAL(expectedEncodedByteLow, encodedByteLow);
    TEST_ASSERT_EQUAL(expectedResult, result);
}

/// @brief This test simulates the function if a NULL pointer is provided.
/// @param  void
void TestNullPointer(void){
    //assign
    uint8_t inputByte = 0x37;   //0b00110111
    uint8_t encodedByteHigh;
    uint8_t encodedByteLow;
    bool expectedResult = false;

    //act
    bool result1 = encodeByte(inputByte, NULL, &encodedByteLow);    //encodedByteHigh == NULL
    bool result2 = encodeByte(inputByte, &encodedByteHigh, NULL);   //encodedByteLow == NULL
    bool result3 = encodeByte(inputByte, NULL, NULL);               //both pointers == NULL

    //assert
    TEST_ASSERT_EQUAL(expectedResult, result1);
    TEST_ASSERT_EQUAL(expectedResult, result2);
    TEST_ASSERT_EQUAL(expectedResult, result3);    
}

int main(void)
{
    UnityBegin(0);
    RUN_TEST(TestCalculateParityBits);
    RUN_TEST(TestEncodeByteFunction);
    RUN_TEST(TestNullPointer);
    return UnityEnd();
}
