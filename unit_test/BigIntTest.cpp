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
#include <string>
#include <iostream>

using namespace std;

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

