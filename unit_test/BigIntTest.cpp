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

TEST_GROUP(FirstTestGroup)
{
    BigIntBase * myBigIntBase;
    char* result;

    void setup()
    {
        myBigIntBase = new BigInts1B;
        result = 0;  // null it out in case its not used, we can safely delete 0
    }

    void teardown()
    {
        delete myBigIntBase;
        delete [] result;
    }
};

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



TEST_GROUP(TwoValueTestGroup)
{
    BigIntBase * myBigIntBaseA;
    BigIntBase * myBigIntBaseB;
    char* result;
    char* result2;

    void setup()
    {
        myBigIntBaseA = new BigInts1B;
        myBigIntBaseB = new BigInts1B;
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







