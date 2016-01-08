/*******************************************************************************
 *
 *             COPYRIGHT 2015 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigInts32Bit.cpp
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
#include "BigInts32Bit.h"

BigInts32Bit::BigInts32Bit()
{
    // TODO Auto-generated constructor stub
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/

    int index;
    m_length = 1;  // fixme
    m_value = new uint32_t[m_length];

    m_negative = false;

    for (index = 0; index < m_length; index++)
    {
        m_value[index] = 0;
    }
}

BigInts32Bit::~BigInts32Bit()
{
    // TODO Auto-generated method stub
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/
    delete [] m_value;

}

void BigInts32Bit::valueOf(int inputValue)
{
    int index = 0;

    // If its negative, set the negative tracking flag and make it positive for the loop that expects positive only.
    if (inputValue < 0)
    {
        m_negative = true;
        inputValue = -inputValue;
    }

    m_value[index] = inputValue;
    index++;
}

char* BigInts32Bit::getString()
{
    char * returnVal = new char[12];
    int outIndex = 0;
    int digit = 0;
    uint32_t value = m_value[0]; // fixme.  only handle first digit for now.
    bool foundFirstDigit = false;

    if (m_negative == true)
    {
        returnVal[outIndex] = '-';
        outIndex++;
    }

    uint32_t compareVal = 1000000000;
    while (compareVal != 0)
    {
        digit = value / compareVal;
        value = value - digit * compareVal;
        compareVal /= 10;
        if ((digit != 0) || (foundFirstDigit == true))
        {
            returnVal[outIndex++] = digit + '0';
            foundFirstDigit = true;
        }
    }

    if (foundFirstDigit ==false)
    {
        returnVal[outIndex] = '0';
        outIndex++;
    }

    returnVal[outIndex++] = 0; // null terminate.
    return returnVal;
}

void BigInts32Bit::setString(char* valueString)
{
    /*
    output = 0
    foreach digit in digits:
        output = output * base + digit
    In the reverse order, it's the following:

    output = 0
    multiplier = 1
    foreach digit in digits:
        output = output + multiplier * digit
        multiplier = multiplier * base
    */
}

void BigInts32Bit::add(BigIntBase* bigInt)
{
}

void BigInts32Bit::subtract(BigIntBase* bigInt)
{
}

void BigInts32Bit::multiply(BigIntBase* bigIntPtr)
{
}

void BigInts32Bit::divide(BigIntBase* bigIntPtr)
{
}

int BigInts32Bit::compareMagnitude(BigIntBase* bigIntPtr)
{
}

void BigInts32Bit::assign(BigIntBase* bigIntPtr)
{
}

void BigInts32Bit::pow(int power)
{
}

bool BigInts32Bit::equals(BigIntBase* rightVal)
{
}

bool BigInts32Bit::equals(int rightVal)
{
}

void BigInts32Bit::sqrt(BigIntBase* guess)
{
}

void BigInts32Bit::sameSignAdd(BigIntBase* bigIntPtr)
{
}

void BigInts32Bit::diffSignAdd(BigIntBase* bigIntPtr)
{
}

void BigInts32Bit::swap(BigInts32Bit** first, BigInts32Bit** second)
{
    BigInts32Bit * tempPtr;
    tempPtr = *first;
    *first = *second;
    *second = tempPtr;
}

void BigInts32Bit::trimLeadingZeros()
{
}

void BigInts32Bit::getSubArray(BigInts32Bit* destArray, int msbIndex, int numDigits)
{
}

//void BigInts32Bit::printBigInt(char* formatStr, BigInts32Bit* bigIntPtr)
//{
//}

void BigInts32Bit::insertLeastSigDigit(int32_t digit)
{
}
