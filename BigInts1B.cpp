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
#include "memory.h"
#include "stdio.h"

BigInts1B::BigInts1B()
{
    m_value = new int32_t[1];
    m_value[0] = 0;
    m_length = 1;
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
        m_value[0] = 0;
        m_value[1] = 0;
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

void BigInts1B::add(BigIntBase* bigIntPtr)
{
    if (m_negative == ((BigInts1B*)bigIntPtr)->m_negative)
    {
        sameSignAdd(bigIntPtr);
    }
    else
    {
        // they are different signs need to subtract
        diffSignAdd(bigIntPtr);
    }
}

void BigInts1B::subtract(BigIntBase* bigInt)
{
    // subtract by changing the sign of the second parameter then do add.  change sign back when done.
    BigInts1B * secondParm = (BigInts1B*)bigInt;
    secondParm->m_negative = (secondParm->m_negative ? false : true);  // toggle the negative flag
    add(bigInt);
    secondParm->m_negative = (secondParm->m_negative ? false : true);  // toggle the negative flag
}

int multiplier[] =
{
        1,
        10,
        100,
        1000,
        10000,
        100000,
        1000000,
        10000000,
        100000000,
};
void BigInts1B::setString(char* valueString)
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
    m_length = (length+8)/9;
    delete [] m_value;
    m_value = new int32_t[m_length];

    int index;
    for(index=0;index<m_length;index++)
    {
        m_value[index] = 0;
    }

    int outIndex;
    for (index = 0; index < length; index++)
    {
        int rawOutIndex = length - index - 1;
        outIndex = (rawOutIndex) / 9;
        int outDigit = rawOutIndex % 9;
        m_value[outIndex] += (valueString[inIndex] - '0') * multiplier[outDigit];
        inIndex++;
    }

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

void BigInts1B::sameSignAdd(BigIntBase* bigIntPtr)
{
    BigInts1B* longPtr = this;
    BigInts1B* shortPtr = (BigInts1B*)bigIntPtr;

    if ((longPtr->m_length) < (shortPtr->m_length))
    {
        swap(&longPtr,&shortPtr);
    }
    int shortestLength = shortPtr->m_length;

    int32_t * resultArray = new int32_t[longPtr->m_length+1];

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
        if (temp >= 1000000000)
        {
            temp = temp - 1000000000;
            carry = 1;
        }
        resultArray[index] = temp;
    }
    delete [] m_value;
    m_value = resultArray;
    m_length = longPtr->m_length + ((longPtr->m_length < index) ? 1 : 0);
}

void BigInts1B::diffSignAdd(BigIntBase* bigIntPtr)
{
    // the signs are different, so its a subtract.
    // take the Big one minus Small and then use the final sign of the bigger
    BigInts1B* bigPtr = this;
    BigInts1B* smallPtr = (BigInts1B*)bigIntPtr;

    // 55 - 5
    if ((bigPtr->m_length) < (smallPtr->m_length))
    {
        swap(&bigPtr, &smallPtr);
    }
    else if ((bigPtr->m_length) == (smallPtr->m_length))  // 5 - 8
    {
        if (bigPtr->m_value[bigPtr->m_length - 1] < smallPtr->m_value[smallPtr->m_length - 1])
        {
            swap(&bigPtr, &smallPtr);
        }
    }
    int shortestLength = smallPtr->m_length;
    int biggestLength  = bigPtr->m_length;

    //
    // the signs are opposite.  we can just subtract bigger from smaller
    //
    int32_t * resultArray = new int32_t[bigPtr->m_length];
    int index;
    for (index = 0; index < biggestLength; index++)  // transfer big to working area. borrows require tampering with big
    {
        resultArray[index] = bigPtr->m_value[index];
    }

    for (index = 0; index < biggestLength; index++)
    {
        int temp = 0;
        if (index < shortestLength)
        {
            temp = smallPtr->m_value[index];
        }
        if (resultArray[index] < temp)
        {
            // borrow
            resultArray[index] += 1000000000;
            resultArray[index + 1] -= 1;  // next loop will trigger a re-borrow on the next digit to eliminate the neg
        }
        resultArray[index] = resultArray[index] - temp;
    }
    delete [] m_value;
    m_value = resultArray;

    // Set the final sign to the sign of the bigger of the values.
    m_negative = bigPtr->m_negative;
    m_length = bigPtr->m_length;
}

void BigInts1B::multiply(BigIntBase* bigInt)
{
}

void BigInts1B::swap(BigInts1B** first, BigInts1B** second)
{
    BigInts1B * tempPtr;
    tempPtr = *first;
    *first = *second;
    *second = tempPtr;
}
