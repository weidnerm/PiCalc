/*******************************************************************************
 *
 *             COPYRIGHT 2015 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : TestRunner.cpp
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
#include "TestRunner.h"

#include "CppUTest/CommandLineTestRunner.h"

int suiteNum = 0;
int main(int ac, char** av)
{
    int returnVal;

    suiteNum = 0;  // base 1e9 tests
    returnVal = CommandLineTestRunner::RunAllTests(ac, av);

    suiteNum = 1;  // base 10 tests
    returnVal = CommandLineTestRunner::RunAllTests(ac, av);

//    suiteNum = 2;  // base 2^31 tests
//    returnVal = CommandLineTestRunner::RunAllTests(ac, av);
//
//    suiteNum = 3;  // base 2^32 tests
//    returnVal = CommandLineTestRunner::RunAllTests(ac, av);

    return returnVal;
}
