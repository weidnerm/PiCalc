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

#define BASE 10

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

    delete [] m_value;
    m_value = new int8_t[10];  // big enough to hold the biggest int

    while (inputValue != 0)
    {
        m_value[index] = inputValue % BASE;
        inputValue = inputValue / BASE;
        index++;
    }
    m_length = index;
}

BigIntsBase10::BigIntsBase10()
{
    m_value = new int8_t[1];
    m_negative = false;
    m_value[0] = 0;
    m_length = 1;
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

    if ( (m_length > 1) && (m_value[m_length - 1] == 0) )   // if first value is 0, its improper
    {
        returnVal[0] = 'E';
        returnVal[1] = 0;
        return returnVal;
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

    delete [] m_value;
    m_length = length;
    m_value = new int8_t[m_length];

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
//    printBigInt("%s+", this);
//    printBigInt("%s=", (BigIntsBase10*)bigIntPtr);

    if (m_negative == ((BigIntsBase10*)bigIntPtr)->m_negative)
    {
        sameSignAdd(bigIntPtr);
    }
    else
    {
        // they are different signs need to subtract
        diffSignAdd(bigIntPtr);
    }
//    printBigInt("%s\n", this);
}

void BigIntsBase10::subtract(BigIntBase* bigInt)
{
    // subtract by changing the sign of the second parameter then do add.  change sign back when done.
    BigIntsBase10 * secondParm = (BigIntsBase10*)bigInt;
    secondParm->m_negative = (secondParm->m_negative ? false : true);  // toggle the negative flag
    add(bigInt);
    secondParm->m_negative = (secondParm->m_negative ? false : true);  // toggle the negative flag
}

void BigIntsBase10::sameSignAdd(BigIntBase* bigIntPtr)
{
    BigIntsBase10* longPtr = this;
    BigIntsBase10* shortPtr = (BigIntsBase10*)bigIntPtr;

    if ((longPtr->m_length) < (shortPtr->m_length))
    {
        swap(&longPtr,&shortPtr);
    }
    int shortestLength = shortPtr->m_length;
    int longestLength = longPtr->m_length;

    int8_t * resultArray = new int8_t[longPtr->m_length+1];

    // the signs match.  we can just add. (even if both negative)
    int index;
    int carry = 0;
    for (index = 0; ((index < longestLength) || (carry == 1)); index++)
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
        if (temp >= BASE)
        {
            temp = temp - BASE;
            carry = 1;
        }
        resultArray[index] = temp;
    }
    delete [] m_value;
    m_value = resultArray;
    m_length = longPtr->m_length + ((longPtr->m_length < index) ? 1 : 0);
}

void BigIntsBase10::diffSignAdd(BigIntBase* bigIntPtr)
{
    // the signs are different, so its a subtract.
    // take the Big one minus Small and then use the final sign of the bigger
    BigIntsBase10* bigPtr = this;
    BigIntsBase10* smallPtr = (BigIntsBase10*)bigIntPtr;

    // 55 - 5
    if ( (smallPtr->compareMagnitude(bigPtr)) == 1 )  // If A>B then swap since A is desired to be small
    {
        swap(&bigPtr, &smallPtr);
    }
    int shortestLength = smallPtr->m_length;
    int biggestLength  = bigPtr->m_length;

    //
    // the signs are opposite.  we can just subtract bigger from smaller
    //
    int8_t * resultArray = new int8_t[bigPtr->m_length];
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
            resultArray[index] += BASE;
            resultArray[index + 1] -= 1;  // next loop will trigger a re-borrow on the next digit to eliminate the neg
        }
        resultArray[index] = resultArray[index] - temp;
    }
    delete [] m_value;
    m_value = resultArray;

    // Set the final sign to the sign of the bigger of the values.
    m_negative = bigPtr->m_negative;

    m_length = bigPtr->m_length;
    trimLeadingZeros();
}

void BigIntsBase10::divide(BigIntBase* bigIntPtr)
{
    int index;
    BigIntsBase10* dividend = this;
    BigIntsBase10* divisor = (BigIntsBase10*)bigIntPtr;
    BigIntsBase10* posDivisor = new BigIntsBase10();
    posDivisor->assign(divisor);
    posDivisor->m_negative = false;  // force it to be positive.

    // pre-compute various divisor products for 0-9 (and one for 10 since search loop goes one past)
    BigIntsBase10 productFrag[11];
    productFrag[0].valueOf(0);
    for (index = 1; index < 11; index++)
    {
        productFrag[index].assign(&productFrag[index-1]);
        productFrag[index].add(posDivisor);
    }

    int8_t * resultArray = new int8_t[m_length];

    for (index = 0; index < m_length; index++)
    {
        resultArray[index] = 0;
    }

    int resultDigitIndex = dividend->m_length - divisor->m_length;
    int resultLength;

    BigIntsBase10 divdendFragment;

    getSubArray(&divdendFragment, m_length-1, divisor->m_length);

//    printBigInt("divdendFragment = %s\n", &divdendFragment);
    if ( divdendFragment.compareMagnitude(divisor) == -1 )
    {
        resultDigitIndex--;
    }
    getSubArray(&divdendFragment, m_length-1, m_length-resultDigitIndex);
//    printBigInt("divdendFragment = %s\n", &divdendFragment);

    resultLength = resultDigitIndex+1;
    while ( resultDigitIndex >= 0)
    {
        int dividendDigit = 0;
//        BigIntsBase10 productFrag;
//        productFrag.valueOf(0);
//        printBigInt("productFrag0 = %s\n", &productFrag);
        do
        {
            dividendDigit++;
//            printf("dividendDigit=%d;  ",dividendDigit);
//            productFrag.add(posDivisor);
        }
        while (( divdendFragment.compareMagnitude(&productFrag[dividendDigit]) > -1 ) && (dividendDigit <= 10 ));

//        productFrag.subtract(posDivisor);  // the previous loop went one too far.  back up.
        dividendDigit--;

//        printBigInt("productFrag = %s\n", &productFrag);
//        printf("resultArray[%d] = %d\n",resultDigitIndex,dividendDigit);


        resultArray[resultDigitIndex] = dividendDigit;  // store the final digit.
        resultDigitIndex--;

        divdendFragment.subtract(&(productFrag[dividendDigit]));
        if (resultDigitIndex >= 0)
        {
            divdendFragment.insertLeastSigDigit(dividend->m_value[resultDigitIndex]);
        }
//        printBigInt("concatResult = %s\n", &divdendFragment);


    }

//    printBigInt("Remainder = %s\n",&divdendFragment);

    delete [] m_value;
    delete posDivisor;
    m_value = resultArray;
    m_negative = divisor->m_negative ^ dividend->m_negative;   // XOR divisor sign  and  dividend sign
    trimLeadingZeros();
}

void BigIntsBase10::swap(BigIntsBase10** first, BigIntsBase10** second)
{
    BigIntsBase10 * tempPtr;
    tempPtr = *first;
    *first = *second;
    *second = tempPtr;
}

void BigIntsBase10::multiply(BigIntBase* bigInt)
{
}

// reuturns -1 if A<B;  0 if A==B;  1 if A>B
int BigIntsBase10::compareMagnitude(BigIntBase* bigIntPtr)
{
    int returnVal = 0;

    BigIntsBase10* A_Ptr = this;
    BigIntsBase10* B_Ptr = (BigIntsBase10*)bigIntPtr;

    if ((A_Ptr->m_length) < (B_Ptr->m_length))
    {
        returnVal = -1;
    }
    else if ((A_Ptr->m_length) > (B_Ptr->m_length))
    {
        returnVal = 1;
    }
    else
    {
        int index;
        for (index = m_length - 1; index >= 0; index--)
        {
            if (A_Ptr->m_value[index] < B_Ptr->m_value[index])
            {
                returnVal = -1;
                break;
            }
            else if (A_Ptr->m_value[index] > B_Ptr->m_value[index])
            {
                returnVal = 1;
                break;
            }
        }
    }

    return returnVal;
}

void BigIntsBase10::trimLeadingZeros()
{
    while ((m_length != 1) && (m_value[m_length - 1] == 0))  // trim leading 0s if any
    {
        m_length--;
    }
}

void BigIntsBase10::getSubArray(BigIntsBase10* destArray, int msbIndex, int numDigits)
{
    if ( numDigits > destArray->m_length)  // if it wont fit, allocate more space
    {
        delete [] destArray->m_value;
        destArray->m_value = new int8_t[numDigits];
    }
    destArray->m_length = numDigits;

    int index;
    for(index=0; index<numDigits; index++)
    {
        destArray->m_value[index] = m_value[msbIndex-numDigits+index+1];
    }
}

void BigIntsBase10::printBigInt(char * formatStr, BigIntsBase10* bigIntPtr)
{
    char * tempVal = bigIntPtr->getString();

    printf(formatStr, tempVal);

    delete[] tempVal;
}

void BigIntsBase10::assign(BigIntBase* bigIntPtr)
{
    BigIntsBase10* src_Ptr = (BigIntsBase10*)bigIntPtr;
    int sourceLength = src_Ptr->m_length;

    if (m_length < sourceLength)
    {
        // not enough room in our current area. allocate more
        delete[] m_value;
        m_value = new int8_t[src_Ptr->m_length];
    }

    memcpy(m_value, src_Ptr->m_value, sourceLength);
    m_length = sourceLength;
    m_negative = src_Ptr->m_negative;
}

void BigIntsBase10::insertLeastSigDigit(int8_t digit)
{
    int8_t * newArray = new int8_t[m_length + 1];
    memcpy(newArray+1, m_value, m_length);
    newArray[0] = digit;
    m_length++;

    delete[] m_value;
    m_value = newArray;
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
 *    -10  same as big-small with sign of big
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
