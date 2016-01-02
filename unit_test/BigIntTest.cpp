/*******************************************************************************
 *
 *             COPYRIGHT 2015 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigIntTest.cpp
 *
 *-------------------------------- PURPOSE --------------------------------------
 *
 *
 *--------------------------- DEPENDENCY COMMENTS -------------------------------
 *
 *
 *-------------------------- PROJECT SPECIFIC DATA ------------------------------
 *
 *
 *----------------------------- REVISION HISTORY --------------------------------
 *
 * Date      Core ID   Tracking#      Description
 * --------  --------  -------------  -------------------------------------------
 *           vagrant                  Initial Creation
 *
 *******************************************************************************/

/*--------------------------- HEADER FILE INCLUDES ----------------------------*/
#include "BigIntsBase10.h"
#include "BigInts32Bit.h"
#include "BigInts1B.h"
#include "BigIntBase.h"
#include "CppUTest/TestHarness.h"
#include "stdio.h"
#include "memory.h"
#include "PiCalculator.h"

//#define CLASS_UNDER_TEST BigInts1B
#define CLASS_UNDER_TEST BigIntsBase10

#define DIVISION_TESTS

TEST_GROUP(FirstTestGroup)
{
    BigIntBase * myBigIntBase;
    char* result;

    void setup()
    {
        myBigIntBase = new CLASS_UNDER_TEST;
        result = 0;  // null it out in case its not used, we can safely delete 0
    }

    void teardown()
    {
        delete myBigIntBase;
        delete [] result;
    }
};

TEST(FirstTestGroup, setEmptyForZero)
{
    result = myBigIntBase->getString();

    STRCMP_EQUAL("0",result);
}

TEST(FirstTestGroup, setPostiveMediumInt123)
{
    myBigIntBase->valueOf(123);

    result = myBigIntBase->getString();

    STRCMP_EQUAL("123",result);
}


TEST(FirstTestGroup, setPostiveMediumInt100)
{
    myBigIntBase->valueOf(100);

    result = myBigIntBase->getString();

    STRCMP_EQUAL("100",result);
}

TEST(FirstTestGroup, setMaxPosInt)
{
    myBigIntBase->valueOf(2147483647);

    result = myBigIntBase->getString();

    STRCMP_EQUAL("2147483647",result);
}

TEST(FirstTestGroup, setNegMaxInt)
{
    myBigIntBase->valueOf(-2147483647);

    result = myBigIntBase->getString();

    STRCMP_EQUAL("-2147483647",result);
}

TEST(FirstTestGroup, setZero)
{
    myBigIntBase->valueOf(0);

    result = myBigIntBase->getString();

    STRCMP_EQUAL("0",result);
}

TEST(FirstTestGroup, setLargePositive)
{
    myBigIntBase->setString("12345678901234567890");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("12345678901234567890",result);
}
TEST(FirstTestGroup, setLargePositive21Dig)
{
    myBigIntBase->setString("123456789012345678901");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("123456789012345678901",result);
}
TEST(FirstTestGroup, setLargePositive22Dig)
{
    myBigIntBase->setString("1234567890123456789012");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("1234567890123456789012",result);
}
TEST(FirstTestGroup, setLargePositive23Dig)
{
    myBigIntBase->setString("12345678901234567890123");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("12345678901234567890123",result);
}
TEST(FirstTestGroup, setLargePositive24Dig)
{
    myBigIntBase->setString("123456789012345678901234");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("123456789012345678901234",result);
}
TEST(FirstTestGroup, setLargePositive25Dig)
{
    myBigIntBase->setString("1234567890123456789012345");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("1234567890123456789012345",result);
}
TEST(FirstTestGroup, setLargePositive26Dig)
{
    myBigIntBase->setString("12345678901234567890123456");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("12345678901234567890123456",result);
}
TEST(FirstTestGroup, setLargePositive27Dig)
{
    myBigIntBase->setString("123456789012345678901234567");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("123456789012345678901234567",result);
}
TEST(FirstTestGroup, setLargePositive28Dig)
{
    myBigIntBase->setString("1234567890123456789012345678");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("1234567890123456789012345678",result);
}
TEST(FirstTestGroup, setLargePositive29Dig)
{
    myBigIntBase->setString("12345678901234567890123456789");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("12345678901234567890123456789",result);
}

TEST(FirstTestGroup, setLargePositive30Dig0)
{
    myBigIntBase->setString("100000000000000000000000000000");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("100000000000000000000000000000",result);
}

TEST(FirstTestGroup, setLargeNegative)
{
    myBigIntBase->setString("-21345678901234567890");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("-21345678901234567890",result);
}

TEST(FirstTestGroup, setStringZero)
{
    myBigIntBase->setString("0");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("0",result);
}

TEST(FirstTestGroup, setString123)
{
    myBigIntBase->setString("123");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("123",result);
}

TEST(FirstTestGroup, setStringNeg123)
{
    myBigIntBase->setString("-123");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("-123",result);
}

TEST(FirstTestGroup, setSignChange)
{
    myBigIntBase->setString("-123");
    myBigIntBase->setString("123");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("123",result);
}



TEST_GROUP(TwoValueTestGroup)
{
    BigIntBase * myBigIntBaseA;
    BigIntBase * myBigIntBaseB;
    char* result;
    char* result2;

    void setup()
    {
        myBigIntBaseA = new CLASS_UNDER_TEST;
        myBigIntBaseB = new CLASS_UNDER_TEST;
        result = 0;  // null it out in case its not used, we can safely delete 0
        result2 = 0;  // null it out in case its not used, we can safely delete 0
    }

    void teardown()
    {
        delete myBigIntBaseA;
        delete myBigIntBaseB;
        delete [] result;
        delete [] result2;
    }
};




TEST(TwoValueTestGroup, setStringAddOneDigitNoCarry)
{
    myBigIntBaseA->setString("1");
    myBigIntBaseB->setString("2");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("3",result);
}

TEST(TwoValueTestGroup, setStringAddOneDigitCarry)
{
    myBigIntBaseA->setString("9");
    myBigIntBaseB->setString("8");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("17",result);
}

TEST(TwoValueTestGroup, setStringAddOneDigitNoCarryNeg)
{
    myBigIntBaseA->setString("-1");
    myBigIntBaseB->setString("-2");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("-3",result);
}

TEST(TwoValueTestGroup, setStringAddOneDigitCarryNeg)
{
    myBigIntBaseA->setString("-9");
    myBigIntBaseB->setString("-8");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("-17",result);
}

TEST(TwoValueTestGroup, setStringAddMoreDigitCarry)
{
    myBigIntBaseA->setString("1");
    myBigIntBaseB->setString("999999999");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("1000000000",result);
}

TEST(TwoValueTestGroup, setStringAddMoreDigitCarry8)
{
    myBigIntBaseA->setString("1");
    myBigIntBaseB->setString("99999999");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("100000000",result);
}
TEST(TwoValueTestGroup, setStringAddMoreDigitCarry9)
{
    myBigIntBaseA->setString("1");
    myBigIntBaseB->setString("999999999");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("1000000000",result);
}
TEST(TwoValueTestGroup, setStringAddMoreDigitCarry10)
{
    myBigIntBaseA->setString("1");
    myBigIntBaseB->setString("9999999999");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("10000000000",result);
}
TEST(TwoValueTestGroup, setStringAddLongDigitCarry)
{
    myBigIntBaseA->setString("89999999999999999999");
    myBigIntBaseB->setString("1");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("90000000000000000000",result);
}
TEST(TwoValueTestGroup, setStringAddLongDigitCarryShortA)
{
    myBigIntBaseA->setString("1");
    myBigIntBaseB->setString("89999999999999999999");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("90000000000000000000",result);
}

TEST(TwoValueTestGroup, setStringAddLongDigitCarryShortASpillover)
{
    myBigIntBaseA->setString("1");
    myBigIntBaseB->setString("99999999999999999999");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("100000000000000000000",result);
}

TEST(TwoValueTestGroup, setStringAddLongDigitCarryShortBSpillover)
{
    myBigIntBaseA->setString("99999999999999999999");
    myBigIntBaseB->setString("1");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("100000000000000000000",result);
}

TEST(TwoValueTestGroup, setStringAddLongDigitCarryShortASpilloverNeg)
{
    myBigIntBaseA->setString("-1");
    myBigIntBaseB->setString("-99999999999999999999");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("-100000000000000000000",result);
}

TEST(TwoValueTestGroup, setStringAddLongDigitCarryShortMaxAddNeg)
{
    myBigIntBaseA->setString("-99999999999999999999");
    myBigIntBaseB->setString("-99999999999999999999");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("-199999999999999999998",result);
}

TEST(TwoValueTestGroup, add0and37)
{
    myBigIntBaseA->setString("0");
    myBigIntBaseB->setString("37");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);

    result  = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("37",result);
    STRCMP_EQUAL("37",result2);// make sure that B didnt change
}
TEST(TwoValueTestGroup, add1and1111111111)
{
    myBigIntBaseA->setString("1");
    myBigIntBaseB->setString("1111111111");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);

    result  = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("1111111112",result);
    STRCMP_EQUAL("1111111111",result2);// make sure that B didnt change
}

TEST(TwoValueTestGroup, add0and0)
{
    myBigIntBaseA->setString("0");
    myBigIntBaseB->setString("0");

    // A = A+B
    myBigIntBaseA->subtract(myBigIntBaseB);

    result  = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("0",result);
    STRCMP_EQUAL("0",result2);// make sure that B didnt change
}








TEST(TwoValueTestGroup, setStringSubLongDigitCarryMaxNeg)
{
    myBigIntBaseA->setString("99999999999999999999");
    myBigIntBaseB->setString("-99999999999999999999");

    // A = A+B
    myBigIntBaseA->subtract(myBigIntBaseB);
    result  = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("199999999999999999998",result);
    STRCMP_EQUAL("-99999999999999999999",result2);// make sure that B didnt change
}

TEST(TwoValueTestGroup, setStringSubLongDigitCarryMaxPos)
{
    myBigIntBaseA->setString("-99999999999999999999");
    myBigIntBaseB->setString("99999999999999999999");

    // A = A+B
    myBigIntBaseA->subtract(myBigIntBaseB);
    result  = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-199999999999999999998",result);
    STRCMP_EQUAL("99999999999999999999",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedSmallSingleDigPBpNS)
{
    myBigIntBaseA->setString("5");
    myBigIntBaseB->setString("-1");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("4",result);
    STRCMP_EQUAL("-1",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedSmallSingleDigNSpPB)
{
    myBigIntBaseA->setString("-1");
    myBigIntBaseB->setString("5");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("4",result);
    STRCMP_EQUAL("5",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedSmallSingleDigNBpPS)
{
    myBigIntBaseA->setString("-5");
    myBigIntBaseB->setString("1");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-4",result);
    STRCMP_EQUAL("1",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedSmallSingleDigPSpNB)
{
    myBigIntBaseA->setString("1");
    myBigIntBaseB->setString("-5");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-4",result);
    STRCMP_EQUAL("-5",result2); // make sure that B didnt change
}




TEST(TwoValueTestGroup, addMixedMedDigPBpNS)
{
    myBigIntBaseA->setString("5000000000");
    myBigIntBaseB->setString("-1000000000");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("4000000000",result);
    STRCMP_EQUAL("-1000000000",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedMedDigNSpPB)
{
    myBigIntBaseA->setString("-1000000000");
    myBigIntBaseB->setString("5000000000");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("4000000000",result);
    STRCMP_EQUAL("5000000000",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedMedDigNBpPS)
{
    myBigIntBaseA->setString("-5000000000");
    myBigIntBaseB->setString("1000000000");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-4000000000",result);
    STRCMP_EQUAL("1000000000",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedMedDigPSpNB)
{
    myBigIntBaseA->setString("1000000000");
    myBigIntBaseB->setString("-5000000000");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-4000000000",result);
    STRCMP_EQUAL("-5000000000",result2); // make sure that B didnt change
}


TEST(TwoValueTestGroup, addMixedDiffLenDigPBpNS)
{
    myBigIntBaseA->setString("11111111111");
    myBigIntBaseB->setString("-1");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("11111111110",result);
    STRCMP_EQUAL("-1",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedDiffLenDigNSpPB)
{
    myBigIntBaseA->setString("-1");
    myBigIntBaseB->setString("11111111111");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("11111111110",result);
    STRCMP_EQUAL("11111111111",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedDiffLenDigNBpPS)
{
    myBigIntBaseA->setString("-11111111111");
    myBigIntBaseB->setString("1");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-11111111110",result);
    STRCMP_EQUAL("1",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedDiffLenDigPSpNB)
{
    myBigIntBaseA->setString("1");
    myBigIntBaseB->setString("-11111111111");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-11111111110",result);
    STRCMP_EQUAL("-11111111111",result2); // make sure that B didnt change
}




TEST(TwoValueTestGroup, addMixedMostlyCancel)
{
    myBigIntBaseA->setString("12345678901234567891");
    myBigIntBaseB->setString("-12345678901234567890");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("1",result);
    STRCMP_EQUAL("-12345678901234567890",result2); // make sure that B didnt change
}


TEST(TwoValueTestGroup, addMixedBorrow1BigLast)
{
    myBigIntBaseA->setString("-1");
    myBigIntBaseB->setString("1000000000");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("999999999",result);
    STRCMP_EQUAL("1000000000",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedBorrow2BigLast)
{
    myBigIntBaseA->setString("-1");
    myBigIntBaseB->setString("1000000000000000000");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("999999999999999999",result);
    STRCMP_EQUAL("1000000000000000000",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedBorrow3BigLast)
{
    myBigIntBaseA->setString("-1");
    myBigIntBaseB->setString("1000000000000000000000000000");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("999999999999999999999999999",result);
    STRCMP_EQUAL("1000000000000000000000000000",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedBorrow3BigFirst)
{
    myBigIntBaseA->setString("1000000000000000000000000000");
    myBigIntBaseB->setString("-1");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("999999999999999999999999999",result);
    STRCMP_EQUAL("-1",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, addMixedBorrow4BigFirst)
{
    myBigIntBaseA->setString("123451000000000000000000000000000000000000000000000000000000");
    myBigIntBaseB->setString("-1");

    // A = A+B
    myBigIntBaseA->add(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("123450999999999999999999999999999999999999999999999999999999",result);
    STRCMP_EQUAL("-1",result2); // make sure that B didnt change
}







TEST(TwoValueTestGroup, compareAshorterThanB)
{
    myBigIntBaseA->setString("8");
    myBigIntBaseB->setString("2222222222");

    int result = myBigIntBaseA->compareMagnitude(myBigIntBaseB);

    CHECK_EQUAL(-1,result);
}

TEST(TwoValueTestGroup, compareAlongerThanB)
{
    myBigIntBaseA->setString("2222222222");
    myBigIntBaseB->setString("8");

    int result = myBigIntBaseA->compareMagnitude(myBigIntBaseB);

    CHECK_EQUAL(1,result);
}

TEST(TwoValueTestGroup, compareSameLenA_lt_B)
{
    myBigIntBaseA->setString("33333333332");
    myBigIntBaseB->setString("-33333333333");

    int result = myBigIntBaseA->compareMagnitude(myBigIntBaseB);

    CHECK_EQUAL(-1,result);
}

TEST(TwoValueTestGroup, compareSameLenA_gt_B)
{
    myBigIntBaseA->setString("-33333333334");
    myBigIntBaseB->setString("33333333333");

    int result = myBigIntBaseA->compareMagnitude(myBigIntBaseB);

    CHECK_EQUAL(1,result);
}







TEST(TwoValueTestGroup, assign_sameLen)
{
    myBigIntBaseA->setString("3333333333");
    myBigIntBaseB->setString("1234567890");

    myBigIntBaseA->assign(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("1234567890",result);
    STRCMP_EQUAL("1234567890",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, assign_sameLen_oppSign)
{
    myBigIntBaseA->setString("3333333333");
    myBigIntBaseB->setString("-1234567890");

    myBigIntBaseA->assign(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-1234567890",result);
    STRCMP_EQUAL("-1234567890",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, assign_newLonger)
{
    myBigIntBaseA->setString("3333333333");
    myBigIntBaseB->setString("-12345678901234567890");

    myBigIntBaseA->assign(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-12345678901234567890",result);
    STRCMP_EQUAL("-12345678901234567890",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, assign_origLonger)
{
    myBigIntBaseA->setString("-12345678901234567890");
    myBigIntBaseB->setString("3333333333");

    myBigIntBaseA->assign(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("3333333333",result);
    STRCMP_EQUAL("3333333333",result2); // make sure that B didnt change
}





#ifdef DIVISION_TESTS

TEST(TwoValueTestGroup, divideLen1by1)
{
    myBigIntBaseA->setString("8");
    myBigIntBaseB->setString("2");

    // A = A+B
    myBigIntBaseA->divide(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("4",result);
    STRCMP_EQUAL("2",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, divideLen1by1_posXneg)
{
    myBigIntBaseA->setString("111228");
    myBigIntBaseB->setString("-199");

    // A = A+B
    myBigIntBaseA->divide(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-558",result);
    STRCMP_EQUAL("-199",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, divideLen1by1_negXpos)
{
    myBigIntBaseA->setString("-111228975896");
    myBigIntBaseB->setString("129787");

    // A = A+B
    myBigIntBaseA->divide(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-857011",result);
    STRCMP_EQUAL("129787",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, divideLen1by1_negXneg)
{
    myBigIntBaseA->setString("-975896293941");
    myBigIntBaseB->setString("-2589");

    // A = A+B
    myBigIntBaseA->divide(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("376939472",result);
    STRCMP_EQUAL("-2589",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, divideLen1260257by37)
{
    myBigIntBaseA->setString("-1260257");
    myBigIntBaseB->setString("37");

    // A = A+B
    myBigIntBaseA->divide(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-34061",result);
    STRCMP_EQUAL("37",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, divideLen1260293by37)  //remainder 36
{
    myBigIntBaseA->setString("1260293");
    myBigIntBaseB->setString("37");

    // A = A+B
    myBigIntBaseA->divide(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("34061",result);
    STRCMP_EQUAL("37",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, divideLen1219326311126352690_by_1234567890)
{
    myBigIntBaseA->setString("1219326311126352690");
    myBigIntBaseB->setString("-1234567890");

    // A = A+B
    myBigIntBaseA->divide(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-987654321",result);
    STRCMP_EQUAL("-1234567890",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, divideLen1219326311126352690_by_987654321)
{
    myBigIntBaseA->setString("1219326311126352690");
    myBigIntBaseB->setString("987654321");

    // A = A+B
    myBigIntBaseA->divide(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("1234567890",result);
    STRCMP_EQUAL("987654321",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, divide12340000_by_1234)
{
    myBigIntBaseA->setString("12340000");
    myBigIntBaseB->setString("1234");

    // A = A+B
    myBigIntBaseA->divide(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("10000",result);
    STRCMP_EQUAL("1234",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, divide12340000_by_1)
{
    myBigIntBaseA->setString("12340000");
    myBigIntBaseB->setString("1");

    // A = A+B
    myBigIntBaseA->divide(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("12340000",result);
    STRCMP_EQUAL("1",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, divide1_by_10)
{
    myBigIntBaseA->setString("1");
    myBigIntBaseB->setString("10");

    // A = A+B
    myBigIntBaseA->divide(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("0",result);
    STRCMP_EQUAL("10",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, divide10_by_200)
{
    myBigIntBaseA->setString("-10");
    myBigIntBaseB->setString("-200");

    // A = A+B
    myBigIntBaseA->divide(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("0",result);
    STRCMP_EQUAL("-200",result2); // make sure that B didnt change
}

IGNORE_TEST(TwoValueTestGroup, speedTestDivide)
{
    myBigIntBaseB->setString("987654321");
    int index;
    for(index=0;index<100000;index++)
    {
        myBigIntBaseA->setString("1219326311126352690");

        // A = A+B
        myBigIntBaseA->divide(myBigIntBaseB);
    }
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("1234567890",result);
    STRCMP_EQUAL("987654321",result2); // make sure that B didnt change
}

#endif


/*
 *  987654321
 * 1234567890
 *
 *
 *
 *
 */



TEST(TwoValueTestGroup, speedTestMultiply)
{
    myBigIntBaseB->setString("987654321");
    int index;
    for(index=0;index<1;index++)
    {
        myBigIntBaseA->setString("1234567890");

        // A = A+B
        myBigIntBaseA->multiply(myBigIntBaseB);
    }
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("1219326311126352690",result);
    STRCMP_EQUAL("987654321",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, multiply1234x2_noCarry)
{
    myBigIntBaseA->setString("1234");
    myBigIntBaseB->setString("2");

    // A = A+B
    myBigIntBaseA->multiply(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("2468",result);
    STRCMP_EQUAL("2",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, multiply2345x2)
{
    myBigIntBaseA->setString("-12345");
    myBigIntBaseB->setString("2");

    // A = A+B
    myBigIntBaseA->multiply(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-24690",result);
    STRCMP_EQUAL("2",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, multiply9999x9)
{
    myBigIntBaseA->setString("9999");
    myBigIntBaseB->setString("-9");

    // A = A+B
    myBigIntBaseA->multiply(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("-89991",result);
    STRCMP_EQUAL("-9",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, multiply6x9)
{
    myBigIntBaseA->setString("-6");
    myBigIntBaseB->setString("-9");

    // A = A+B
    myBigIntBaseA->multiply(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("54",result);
    STRCMP_EQUAL("-9",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, multiply9999x99)
{
    myBigIntBaseA->setString("9999");
    myBigIntBaseB->setString("99");

    // A = A+B
    myBigIntBaseA->multiply(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("989901",result);
    STRCMP_EQUAL("99",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, multiply9x888888)
{
    myBigIntBaseA->setString("9");
    myBigIntBaseB->setString("888888");

    // A = A+B
    myBigIntBaseA->multiply(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("7999992",result);
    STRCMP_EQUAL("888888",result2); // make sure that B didnt change
}

TEST(TwoValueTestGroup, multiply3162277660168379331998893544_sqrd)
{
    myBigIntBaseA->setString("3162277660168379331998893544");
    myBigIntBaseB->setString("3162277660168379331998893544");

    // A = A+B
    myBigIntBaseA->multiply(myBigIntBaseB);
    result = myBigIntBaseA->getString();
    result2 = myBigIntBaseB->getString();

    STRCMP_EQUAL("9999999999999999999999999997263247695355666440244879936",result);
    STRCMP_EQUAL("3162277660168379331998893544",result2); // make sure that B didnt change
}







TEST(TwoValueTestGroup, pow_10_toThe_3)
{
    myBigIntBaseA->setString("10");

    // A = A+B
    myBigIntBaseA->pow(3);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("1000",result);
}

TEST(TwoValueTestGroup, pow_10_toThe_100)
{
    myBigIntBaseA->setString("10");

    // A = A+B
    myBigIntBaseA->pow(100);
    result = myBigIntBaseA->getString();

    STRCMP_EQUAL("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",result);
}



TEST(TwoValueTestGroup, equals_int_0)
{
    myBigIntBaseA->setString("0");

    // A = A+B
    CHECK_EQUAL(true, myBigIntBaseA->equals(0) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(2147483647) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-2147483647) );

    result = myBigIntBaseA->getString();
    STRCMP_EQUAL("0",result);
}

TEST(TwoValueTestGroup, equals_int_1)
{
    myBigIntBaseA->setString("1");

    // A = A+B
    CHECK_EQUAL(false, myBigIntBaseA->equals(0) );
    CHECK_EQUAL(true, myBigIntBaseA->equals(1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(2147483647) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-2147483647) );

    result = myBigIntBaseA->getString();
    STRCMP_EQUAL("1",result);
}

TEST(TwoValueTestGroup, equals_int_minus_1)
{
    myBigIntBaseA->setString("-1");

    // A = A+B
    CHECK_EQUAL(false, myBigIntBaseA->equals(0) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1) );
    CHECK_EQUAL(true, myBigIntBaseA->equals(-1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(2147483647) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-2147483647) );

    result = myBigIntBaseA->getString();
    STRCMP_EQUAL("-1",result);
}

TEST(TwoValueTestGroup, equals_int_256)
{
    myBigIntBaseA->setString("256");

    // A = A+B
    CHECK_EQUAL(false, myBigIntBaseA->equals(0) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1) );
    CHECK_EQUAL(true, myBigIntBaseA->equals(256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(2147483647) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-2147483647) );

    result = myBigIntBaseA->getString();
    STRCMP_EQUAL("256",result);
}

TEST(TwoValueTestGroup, equals_int_2147483647)
{
    myBigIntBaseA->setString("2147483647");

    // A = A+B
    CHECK_EQUAL(false, myBigIntBaseA->equals(0) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1000000000) );
    CHECK_EQUAL(true, myBigIntBaseA->equals(2147483647) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-2147483647) );

    result = myBigIntBaseA->getString();
    STRCMP_EQUAL("2147483647",result);
}

TEST(TwoValueTestGroup, equals_int_neg_2147483647)
{
    myBigIntBaseA->setString("-2147483647");

    // A = A+B
    CHECK_EQUAL(false, myBigIntBaseA->equals(0) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(2147483647) );
    CHECK_EQUAL(true, myBigIntBaseA->equals(-2147483647) );

    result = myBigIntBaseA->getString();
    STRCMP_EQUAL("-2147483647",result);
}

TEST(TwoValueTestGroup, equals_int_1000000000000)
{
    myBigIntBaseA->setString("1000000000000");

    // A = A+B
    CHECK_EQUAL(false, myBigIntBaseA->equals(0) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(2147483647) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-2147483647) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-2147483648) );

    result = myBigIntBaseA->getString();
    STRCMP_EQUAL("1000000000000",result);
}

TEST(TwoValueTestGroup, equals_int_1234567890)
{
    myBigIntBaseA->setString("1234567890");

    // A = A+B
    CHECK_EQUAL(false, myBigIntBaseA->equals(0) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-256) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-1000000000) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(2147483647) );
    CHECK_EQUAL(false, myBigIntBaseA->equals(-2147483647) );
    CHECK_EQUAL(true, myBigIntBaseA->equals(1234567890) );

    result = myBigIntBaseA->getString();
    STRCMP_EQUAL("1234567890",result);
}






TEST(TwoValueTestGroup, equals_BigInt_1234567890000000000)
{
    myBigIntBaseA->setString("1234567890000000000");

    // A = A+B
    myBigIntBaseB->setString("0");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("1");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("-1");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("256");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("-256");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("1000000000");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("-1000000000");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("2147483647");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("-2147483647");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("1234567890000000000");
    CHECK_EQUAL(true, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("2234567890000000000");  // top digit
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("1234567890000000001");  // bottom digit
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("-1234567890000000000");  // opposite sign
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    result = myBigIntBaseA->getString();
    STRCMP_EQUAL("1234567890000000000",result);
    result2 = myBigIntBaseB->getString();
    STRCMP_EQUAL("-1234567890000000000",result2);
}

TEST(TwoValueTestGroup, equals_BigInt_0)
{
    myBigIntBaseA->setString("0");

    // A = A+B
    myBigIntBaseB->setString("0");
    CHECK_EQUAL(true, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("1");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("-1");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("256");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("-256");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("1000000000");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("-1000000000");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("2147483647");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("-2147483647");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("1234567890000000000");
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("2234567890000000000");  // top digit
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("1234567890000000001");  // bottom digit
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    myBigIntBaseB->setString("-1234567890000000000");  // opposite sign
    CHECK_EQUAL(false, myBigIntBaseA->equals(myBigIntBaseB) );

    result = myBigIntBaseA->getString();
    STRCMP_EQUAL("0",result);
    result2 = myBigIntBaseB->getString();
    STRCMP_EQUAL("-1234567890000000000",result2);
}




//
//myBigIntBaseA->setString("3162277660168379331998893544");
// myBigIntBaseB->setString("3162277660168379331998893544");
//
// // A = A+B
// myBigIntBaseA->multiply(myBigIntBaseB);
// result = myBigIntBaseA->getString();
// result2 = myBigIntBaseB->getString();
//
// STRCMP_EQUAL("9999999999999999999999999997263247695355666440244879936",result);
//
//












TEST_GROUP(PiCalcTestGroup)
{
    BigIntBase * testValue;
    BigIntBase * result;
    BigIntBase * guess;

    void setup()
    {
        testValue = new CLASS_UNDER_TEST;
        result = new CLASS_UNDER_TEST;
        guess = new CLASS_UNDER_TEST;
    }

    void teardown()
    {
        delete testValue;
        delete result;
        delete guess;
    }

    void checkAndFree(char* expectedValue, char* actualValue)
    {
        STRCMP_EQUAL(expectedValue, actualValue);
        delete [] actualValue;
    }
};


TEST(PiCalcTestGroup, testBigIntSqRootNewtonFloor)
{
    guess->valueOf(1); // seed value.

    char * resultString;

    testValue->valueOf(10005);
    PiCalculator::bigIntSqRootNewtonFloor(result, testValue, guess);

//    checkAndFree("100", result->getString());




    testValue->valueOf(100050000);

    //        result    = PiCalculatorMain.bigIntSqRootNewtonFloor(testValue,BigInteger.ONE);

//    resultString = result->getString();
//    STRCMP_EQUAL("10002", resultString);
//    delete [] resultString;
    //
    //
    //
    //        result    = PiCalculatorMain.bigIntSqRootNewtonFloor( new BigInteger("100050000000000000000000000000000000000000000000000000000000000"),BigInteger.ONE);
    //
//    resultString = result->getString();
//    STRCMP_EQUAL("10002499687578100594479218787635", resultString);
//    delete [] resultString;

}
//
//    public void testBigIntSqRootNewtonFloor() {
//        BigInteger testValue;
//        BigInteger result;
//
//
//        testValue = BigInteger.valueOf(10005);
//        result    = PiCalculatorMain.bigIntSqRootNewtonFloor(testValue,BigInteger.ONE);
//
//        assertTrue( result.equals(BigInteger.valueOf(100)) );
//
//
//
//        testValue = BigInteger.valueOf(100050000);
//        result    = PiCalculatorMain.bigIntSqRootNewtonFloor(testValue,BigInteger.ONE);
//
//        assertTrue( result.equals(BigInteger.valueOf(10002)) );
//
//
//
//        result    = PiCalculatorMain.bigIntSqRootNewtonFloor( new BigInteger("100050000000000000000000000000000000000000000000000000000000000"),BigInteger.ONE);
//
//        assertTrue( result.equals(new BigInteger("10002499687578100594479218787635")) );
//    }





