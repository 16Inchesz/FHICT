#include "unity.h"
#include "decoder.h"

void setUp(void){}

void tearDown(void){}

/// @brief This test simulates different parity bits being calculated for different nibbles
/// @param  void
void TestCalculateParityBits(void){
    //assign
    uint8_t nibble1 = 0x0A;          //0b1010
    uint8_t expectedResult1 = 0x06;  //0b0110

    uint8_t nibble2 = 0x06;          //0b0110
    uint8_t expectedResult2 = 0x05;  //0b0101

    uint8_t nibble3 = 0x07;          //0b0111
    uint8_t expectedResult3 = 0x02;  //0b0010
    
    //act
    uint8_t result1 = CalculateParity(nibble1);
    uint8_t result2 = CalculateParity(nibble2);
    uint8_t result3 = CalculateParity(nibble3);

    
    //assert
    TEST_ASSERT_EQUAL(expectedResult1, result1);
    TEST_ASSERT_EQUAL(expectedResult2, result2);
    TEST_ASSERT_EQUAL(expectedResult3, result3);
}

/// @brief This test simulates the function without any interference (or interference is on bit 7).
/// @param  void
void TestDecodeByteNoInterference(void){
    //assign
    uint8_t transmittedByteHigh1 = 0x27; //0b00100111
    uint8_t transmittedByteLow1 = 0x56;  //0b01010110
    uint8_t expectedByte1 = 0x76;        //0b01110110
    bool expectedResult1 = true;
    uint8_t decodedByte1;

    //act
    bool result1 = decodeByte(transmittedByteHigh1, transmittedByteLow1, &decodedByte1);

    //assert
    TEST_ASSERT_EQUAL(expectedByte1, decodedByte1);
    TEST_ASSERT_EQUAL(expectedResult1, result1);
}

/// @brief This test simulates the function with data bit 0 being corrupted (all parity bits flipped)
/// @param  void
void TestDecodeByteWithInterference1(void){
    //assign
    uint8_t transmittedByteHigh = 0x57; //0b01010111
    uint8_t transmittedByteLow = 0x56;  //0b01010110
    uint8_t expectedByte = 0x66;        //0b01100110
    bool expectedResult = true;
    uint8_t decodedByte;

    //act
    bool result = decodeByte(transmittedByteHigh, transmittedByteLow, &decodedByte);

    //assert
    TEST_ASSERT_EQUAL(expectedByte, decodedByte);
    TEST_ASSERT_EQUAL(expectedResult, result);
}

/// @brief This test simulates the function with data bit 1 being corrupted (p0 and p1 flipped)
/// @param void
void TestDecodeByteWithInterference2(void){
    //assign
    uint8_t transmittedByteHigh = 0x17; //0b00010111
    uint8_t transmittedByteLow = 0x56;  //0b01010110
    uint8_t expectedByte = 0x56;        //0b01010110
    bool expectedResult = true;
    uint8_t decodedByte;

    //act
    bool result = decodeByte(transmittedByteHigh, transmittedByteLow, &decodedByte);

    //assert
    TEST_ASSERT_EQUAL(expectedByte, decodedByte);
    TEST_ASSERT_EQUAL(expectedResult, result);
}

/// @brief This test simulates the function with data bit 2 being corrupted (p1 and p2 flipped)
/// @param void
void TestDecodeByteWithInterference3(void){
    //assign
    uint8_t transmittedByteHigh = 0x47; //0b01000111
    uint8_t transmittedByteLow = 0x56;  //0b01010110
    uint8_t expectedByte = 0x36;        //0b00110110
    bool expectedResult = true;
    uint8_t decodedByte;

    //act
    bool result = decodeByte(transmittedByteHigh, transmittedByteLow, &decodedByte);

    //assert
    TEST_ASSERT_EQUAL(expectedByte, decodedByte);
    TEST_ASSERT_EQUAL(expectedResult, result);
}

/// @brief This test simulates the function with data bit 3 being corrupted (p0 and p2)
/// @param  void
void TestDecodeByteWithInterference4(void){
    //assign
    uint8_t transmittedByteHigh = 0x77; //0b01110111
    uint8_t transmittedByteLow = 0x56;  //0b01010110
    uint8_t expectedByte = 0xF6;        //0b11110110
    bool expectedResult = true;
    uint8_t decodedByte;

    //act
    bool result = decodeByte(transmittedByteHigh, transmittedByteLow, &decodedByte);

    //assert
    TEST_ASSERT_EQUAL(expectedByte, decodedByte);
    TEST_ASSERT_EQUAL(expectedResult, result);
}

/// @brief This test simulates the function if a NULL pointer is provided.
/// @param  void
void TestNullPointer(void){
    //assign
    uint8_t transmittedByteHigh = 0x27;  //0b00100111
    uint8_t transmittedByteLow = 0x56;   //0b01010110
    bool expectedResult = false;

    //act
    bool result = decodeByte(transmittedByteHigh, transmittedByteLow, NULL);

    //assert
    TEST_ASSERT_EQUAL(expectedResult, result);
}

int main(void)
{
    UnityBegin(0);
    RUN_TEST(TestCalculateParityBits);
    RUN_TEST(TestDecodeByteNoInterference);
    RUN_TEST(TestDecodeByteWithInterference1);
    RUN_TEST(TestDecodeByteWithInterference2);
    RUN_TEST(TestDecodeByteWithInterference3);
    RUN_TEST(TestDecodeByteWithInterference4);
    RUN_TEST(TestNullPointer);
    return UnityEnd();
}
