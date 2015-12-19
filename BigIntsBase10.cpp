/*******************************************************************************
 *
 *             COPYRIGHT 2015 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigIntsBase10.cpp
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
#include <iostream>
#include "stdio.h"

using namespace std;
//
//    value of 123
//         1    2    3
//       v[2] v[1]  v[0]
void BigIntsBase10::valueOf(int inputValue)
{
    int index = 0;

    while (inputValue != 0)
    {
        m_value[index] = inputValue % 10;
        inputValue = inputValue / 10;
        index++;
    }
}

BigIntsBase10::BigIntsBase10()
{
    int index;
    m_length = 10;  // fixme

    for (index = 0; index < m_length; index++)
    {
        m_value[index] = 0;
    }
}

// m_length
// 0    0   0   0   0   0   0   1   2   3
// [9] [8] [7] [6] [5] [4] [3] [2] [1] [0]

// output
// [0] [1] [2] [3] [4] [5] [6]
// '1' '2' '3' 0x00
char* BigIntsBase10::getString()
{
    char* returnVal = new char[m_length + 1];
    int outIndex = 0;
    int index;
    bool foundFirstDigit = false;

    for (index = m_length - 1; index >= 0; index--)
    {
        if ((m_value[index] != 0) || (foundFirstDigit == true))
        {
            returnVal[outIndex] = m_value[index] + '0';
            outIndex++;
            foundFirstDigit = true;
        }
    }
    returnVal[outIndex] = 0;

    return returnVal;
}


/*
 *    +10      +10      +10
 *  + +21    + +21    + +21
 *  ======   ======   ======
 *               1       31
 *
 *    -10
 *  +  21
 *  ======
 *
 *    +10
 *  + -21
 *  ======
 *
 *    -10      -10      -10
 *  + -21    + -21    + -21
 *  ======   ======   ======
 *               1      -31
 *
 *
 */
