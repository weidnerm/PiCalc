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
        myBigIntBase = new BigInts32Bit;
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

/*
TEST(FirstTestGroup, setLargePositive)
{
    myBigIntBase->setString("12345678901234567890");

    result = myBigIntBase->getString();

    STRCMP_EQUAL("12345678901234567890",result);
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
*/


TEST_GROUP(TwoValueTestGroup)
{
    BigIntBase * myBigIntBaseA;
    BigIntBase * myBigIntBaseB;
    char* result;
    char* result2;

    void setup()
    {
        myBigIntBaseA = new BigIntsBase10;
        myBigIntBaseB = new BigIntsBase10;
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

TEST(TwoValueTestGroup, addNegSmallSingleDigPBpNS)
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

TEST(TwoValueTestGroup, addNegSmallSingleDigNSpPB)
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

TEST(TwoValueTestGroup, addNegSmallSingleDigNBpPS)
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

TEST(TwoValueTestGroup, addNegSmallSingleDigPSpNB)
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



