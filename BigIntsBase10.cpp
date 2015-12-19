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
#include "stdio.h"
#include "memory.h"

using namespace std;
//
//    value of 123
//         1    2    3
//       v[2] v[1]  v[0]
void BigIntsBase10::valueOf(int inputValue)
{
    int index = 0;

    // If its negative, set the negative tracking flag and make it positive for the loop that expects positive only.
    if (inputValue < 0)
    {
        m_negative = true;
        inputValue = -inputValue;
    }

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
    m_value = new int8_t[m_length];

    m_negative = false;

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
    char* returnVal = new char[m_length + 2];   //add space terminator and negative sign
    int outIndex = 0;
    int index;
    bool foundFirstDigit = false;

    if (m_negative == true)
    {
        returnVal[outIndex] = '-';
        outIndex++;
    }

    for (index = m_length - 1; index >= 0; index--)
    {
        if ((m_value[index] != 0) || (foundFirstDigit == true))
        {
            returnVal[outIndex] = m_value[index] + '0';
            outIndex++;
            foundFirstDigit = true;
        }
    }
    if (foundFirstDigit ==false)
    {
        returnVal[outIndex] = '0';
        outIndex++;
    }
    returnVal[outIndex] = 0;

    return returnVal;
}

BigIntsBase10::~BigIntsBase10()
{
    delete [] m_value;
}

// input
// [0] [1] [2] [3] [4] [5] [6]
// '1' '2' '3' 0x00

// m_value
// 0    0   0   0   0   0   0   1   2   3
// [9] [8] [7] [6] [5] [4] [3] [2] [1] [0]

void BigIntsBase10::setString(char* valueString)
{
    int length = strlen(valueString);

    int inIndex = 0;
    if ( valueString[0] == '-' )
    {
        m_negative = true;
        inIndex++;
        length--;
    }

    // if there isnt currently enough space, allocate more.
    if ( length > m_length)
    {
        m_length = length;
        delete [] m_value;
        m_value = new int8_t[m_length];
    }

    int outIndex;
    int index;
    for (index=0; index < length; index++)
    {
        outIndex = length - index - 1;
        m_value[outIndex] = valueString[inIndex] - '0';
        inIndex++;
    }

}



// 0    0   0   0   0   0   0   9   9   9
// [9] [8] [7] [6] [5] [4] [3] [2] [1] [0]

//          0   0   0   0   0   1   2   3
//         [7] [6] [5] [4] [3] [2] [1] [0]


void BigIntsBase10::add(BigIntBase* bigIntPtr)
{
    if (m_negative == ((BigIntsBase10*)bigIntPtr)->m_negative)
    {
        sameSignAdd(bigIntPtr);
    }
    else
    {
        // they are different signs need to subtract
    }
}
void BigIntsBase10::sameSignAdd(BigIntBase* bigIntPtr)
{
    BigIntsBase10* longPtr = this;
    BigIntsBase10* shortPtr = (BigIntsBase10*)bigIntPtr;

    if ((longPtr->m_length) < (shortPtr->m_length))
    {
        BigIntsBase10* tempPtr;
        tempPtr = longPtr;
        longPtr = shortPtr;
        shortPtr = tempPtr;
    }
    int shortestLength = shortPtr->m_length;

    int8_t * resultArray = new int8_t[longPtr->m_length+1];

    // the signs match.  we can just add. (even if both negative)
    int index;
    int carry = 0;
    for (index = 0; ((index < shortestLength) || (carry == 1)); index++)
    {
        int temp = 0;
        if (index < shortestLength)
        {
            temp = shortPtr->m_value[index];
        }
        if (index < longPtr->m_length)
        {
            temp = temp + longPtr->m_value[index];
        }
        temp = temp + carry;
        carry = 0;
        if (temp >= 10)
        {
            temp = temp - 10;
            carry = 1;
        }
        resultArray[index] = temp;
    }
    delete [] m_value;
    m_value = resultArray;
    m_length = longPtr->m_length + ((longPtr->m_length < index) ? 1 : 0);
}
/*
 * Same Sign Cases
 *    +10      +10      +10
 *  + +21    + +21    + +21
 *  ======   ======   ======
 *               1       31
 *
 *    -10      -10      -10
 *  + -21    + -21    + -21
 *  ======   ======   ======
 *               1      -31
 *
 *Mixed sign cases
 *    -10
 *  +  21
 *  ======
 *
 *    +10
 *  + -21
 *  ======
 *
 *
 *
 */



//power function
//
//int ipow(int base, int exp)
//{
//    int result = 1;
//    while (exp)
//    {
//        if (exp & 1)
//            result *= base;
//        exp >>= 1;
//        base *= base;
//    }
//
//    return result;
//}
