/*******************************************************************************
 *
 *             COPYRIGHT 2015 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigInts100M.cpp
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
#include "BigInts1B.h"

BigInts1B::BigInts1B()
{
    m_value = new int32_t[2];
    m_value[0] = 0;
    m_value[1] = 0;
    m_length = 2;
    m_negative = false;
}

BigInts1B::~BigInts1B()
{
    delete [] m_value;
}

void BigInts1B::valueOf(int inputValue)
{
    if (inputValue < 0)
    {
        m_negative = true;
        inputValue = -inputValue;
    }

    if ((inputValue >= 1000000000) && (m_length < 2))  // make sure there is room for an extra digit.
    {
        delete[] m_value;
        m_value = new int32_t[2];
    }

    int index = 0;

    while (inputValue != 0)
    {
        m_value[index] = inputValue % 1000000000;
        inputValue = inputValue / 1000000000;
        index++;
    }
    m_length = index;
}

void BigInts1B::add(BigIntBase* bigInt)
{
}

void BigInts1B::subtract(BigIntBase* bigInt)
{
}

void BigInts1B::setString(char* valueString)
{
}

char* BigInts1B::getString()
{
    char* returnVal = new char[m_length*9 + 2];   //add space terminator and negative sign
    int outIndex = 0;
    int storageIndex;
    bool foundFirstDigit = false;

    if (m_negative == true)
    {
        returnVal[outIndex] = '-';
        outIndex++;
    }

    for (storageIndex = m_length - 1; storageIndex >= 0; storageIndex--)
    {
        int32_t digitDivisor = 100000000;  // 1e8
        int32_t tempWord = m_value[storageIndex];
        int32_t tempNibble;

        while (digitDivisor != 0)
        {
            tempNibble = tempWord / digitDivisor;

            if ((tempNibble != 0) || (foundFirstDigit == true))
            {
                returnVal[outIndex++] = tempNibble + '0';
                foundFirstDigit = true;
            }
            tempWord = tempWord % digitDivisor;
            digitDivisor = digitDivisor / 10;

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
