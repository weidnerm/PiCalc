/*******************************************************************************
 *
 *             COPYRIGHT 2016 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigInts31Bit.cpp
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
#include "BigInts31Bit.h"

#define BASE (2^31)

BigInts31Bit::BigInts31Bit()
{
    // TODO Auto-generated constructor stub
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/

    int index;
    m_length = 1;  // fixme
    m_value = new int32_t[m_length];

    m_negative = false;

    for (index = 0; index < m_length; index++)
    {
        m_value[index] = 0;
    }
}

BigInts31Bit::~BigInts31Bit()
{
    // TODO Auto-generated method stub
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/

    delete [] m_value;
}

void BigInts31Bit::valueOf(int inputValue)
{
    if (inputValue < 0)
    {
        m_negative = true;
        inputValue = -inputValue;
    }

    if ((inputValue >= BASE) && (m_length < 2))  // make sure there is room for an extra digit.
    {
        delete[] m_value;
        m_value = new int32_t[2];
        m_value[0] = 0;
        m_value[1] = 0;
    }

    int index = 0;

    do
    {
        m_value[index] = inputValue % BASE;
        inputValue = inputValue / BASE;
        index++;
    }
    while (inputValue != 0);

    m_length = index;
}

void BigInts31Bit::add(BigIntBase* bigIntPtr)
{
}

void BigInts31Bit::subtract(BigIntBase* bigIntPtr)
{
}

void BigInts31Bit::multiply(BigIntBase* bigIntPtr)
{
}

void BigInts31Bit::divide(BigIntBase* bigIntPtr)
{
}

void BigInts31Bit::setString(char* valueString)
{
}

int BigInts31Bit::compareMagnitude(BigIntBase* bigIntPtr)
{
}

char* BigInts31Bit::getString()
{
}

void BigInts31Bit::assign(BigIntBase* bigIntPtr)
{
}

void BigInts31Bit::pow(int power)
{
}

bool BigInts31Bit::equals(BigIntBase* rightVal)
{
}

bool BigInts31Bit::equals(int rightVal)
{
}

void BigInts31Bit::sqrt(BigIntBase* guess)
{
}

void BigInts31Bit::sameSignAdd(BigIntBase* bigIntPtr)
{
}

void BigInts31Bit::diffSignAdd(BigIntBase* bigIntPtr)
{
}

void BigInts31Bit::swap(BigInts31Bit** first, BigInts31Bit** second)
{
}

void BigInts31Bit::trimLeadingZeros()
{
}

void BigInts31Bit::getSubArray(BigInts31Bit* destArray, int msbIndex, int numDigits)
{
}

void BigInts31Bit::printBigInt(char* formatStr, BigInts31Bit* bigIntPtr)
{
}

void BigInts31Bit::insertLeastSigDigit(int32_t digit)
{
}
