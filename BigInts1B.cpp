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
            int32_t tempVal = m_value[index];

            returnVal[outIndex++] = tempVal/100000000 + '0' ; tempVal %= 100000000 ;
            returnVal[outIndex++] = tempVal/10000000  + '0' ; tempVal %= 10000000  ;
            returnVal[outIndex++] = tempVal/1000000   + '0' ; tempVal %= 1000000   ;
            returnVal[outIndex++] = tempVal/100000    + '0' ; tempVal %= 100000    ;
            returnVal[outIndex++] = tempVal/10000     + '0' ; tempVal %= 10000     ;
            returnVal[outIndex++] = tempVal/1000      + '0' ; tempVal %= 1000      ;
            returnVal[outIndex++] = tempVal/100       + '0' ; tempVal %= 100       ;
            returnVal[outIndex++] = tempVal/10        + '0' ; tempVal %= 10        ;
            returnVal[outIndex++] = tempVal           + '0' ;

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
