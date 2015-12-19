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
#include "BigIntBase.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(FirstTestGroup)
{
    BigIntBase * myBigIntBase;
    char* result;

    void setup()
    {
        myBigIntBase = new BigIntsBase10;
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


