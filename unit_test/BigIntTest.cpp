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
};

TEST(FirstTestGroup, setPostiveMediumInt123)
{
    BigIntsBase10 myBigIntsBase10;
    myBigIntsBase10.valueOf(123);

    char* result = myBigIntsBase10.getString();

    STRCMP_EQUAL("123",result);
    delete [] result;
}

TEST(FirstTestGroup, setPostiveMediumInt100)
{
    BigIntsBase10 myBigIntsBase10;
    myBigIntsBase10.valueOf(100);

    char* result = myBigIntsBase10.getString();

    STRCMP_EQUAL("100",result);
    delete [] result;
}

TEST(FirstTestGroup, setMaxPosInt)
{
    BigIntsBase10 myBigIntsBase10;
    myBigIntsBase10.valueOf(2147483647);

    char* result = myBigIntsBase10.getString();

    STRCMP_EQUAL("2147483647",result);
    delete [] result;
}

TEST(FirstTestGroup, setNegMaxInt)
{
    BigIntsBase10 myBigIntsBase10;
    myBigIntsBase10.valueOf(-2147483647);

    char* result = myBigIntsBase10.getString();

    STRCMP_EQUAL("-2147483647",result);
    delete [] result;
}

TEST(FirstTestGroup, setZero)
{
    BigIntsBase10 myBigIntsBase10;
    myBigIntsBase10.valueOf(0);

    char* result = myBigIntsBase10.getString();

    STRCMP_EQUAL("0",result);
    delete [] result;
}

TEST(FirstTestGroup, setLargePositive)
{
    BigIntsBase10 myBigIntsBase10;
    myBigIntsBase10.setString("12345678901234567890");

    char* result = myBigIntsBase10.getString();

    STRCMP_EQUAL("12345678901234567890",result);
    delete [] result;
}

TEST(FirstTestGroup, setLargeNegative)
{
    BigIntsBase10 myBigIntsBase10;
    myBigIntsBase10.setString("-21345678901234567890");

    char* result = myBigIntsBase10.getString();

    STRCMP_EQUAL("-21345678901234567890",result);
    delete [] result;
}

TEST(FirstTestGroup, setStringZero)
{
    BigIntsBase10 myBigIntsBase10;
    myBigIntsBase10.setString("0");

    char* result = myBigIntsBase10.getString();

    STRCMP_EQUAL("0",result);
    delete [] result;
}

TEST(FirstTestGroup, setString123)
{
    BigIntsBase10 myBigIntsBase10;
    myBigIntsBase10.setString("123");

    char* result = myBigIntsBase10.getString();

    STRCMP_EQUAL("123",result);
    delete [] result;
}

TEST(FirstTestGroup, setStringNeg123)
{
    BigIntsBase10 myBigIntsBase10;
    myBigIntsBase10.setString("-123");

    char* result = myBigIntsBase10.getString();

    STRCMP_EQUAL("-123",result);
    delete [] result;
}


