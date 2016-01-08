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
#include "stdio.h"
#include "CppUTest/CommandLineTestRunner.h"

int suiteNum = 0;
int main(int ac, char** av)
{
    int returnVal;

    printf("Running base 1e9 tests\n");
    suiteNum = 0;  // base 1e9 tests
    returnVal = CommandLineTestRunner::RunAllTests(ac, av);

    printf("Running base 10 tests\n");
    suiteNum = 1;  //
    returnVal = CommandLineTestRunner::RunAllTests(ac, av);

    printf("Running base 2^31 tests\n");
    suiteNum = 2;
    returnVal = CommandLineTestRunner::RunAllTests(ac, av);

//    printf("Running base 2^32 tests\n");
//    suiteNum = 3;
//    returnVal = CommandLineTestRunner::RunAllTests(ac, av);

    return returnVal;
}
