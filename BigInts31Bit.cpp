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
#include "stdio.h"
#include "BigIntsBase10.h"
#include "memory.h"

#define BASE_BITS 31
#define BASE_MASK 0x7fffffff;
#define BASE (0x80000000u)

BigInts31Bit::BigInts31Bit()
{
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/

    m_value = new int32_t[1];
    m_value[0] = 0;
    m_length = 1;
    m_negative = false;
}

BigInts31Bit::~BigInts31Bit()
{
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

    m_value[0] = inputValue;

    m_length = 1;
}

void BigInts31Bit::add(BigIntBase* bigIntPtr)
{
    if (m_negative == ((BigInts31Bit*)bigIntPtr)->m_negative)
    {
        sameSignAdd(bigIntPtr);
    }
    else
    {
        // they are different signs need to subtract
        diffSignAdd(bigIntPtr);
    }
}

void BigInts31Bit::subtract(BigIntBase* bigIntPtr)
{
    // subtract by changing the sign of the second parameter then do add.  change sign back when done.
    BigInts31Bit * secondParm = (BigInts31Bit*)bigIntPtr;
    secondParm->m_negative = (secondParm->m_negative ? false : true);  // toggle the negative flag
    add(bigIntPtr);
    secondParm->m_negative = (secondParm->m_negative ? false : true);  // toggle the negative flag
}

void BigInts31Bit::multiply(BigIntBase* bigIntPtr)
{
    BigInts31Bit* A_Ptr = this;
    BigInts31Bit* B_Ptr = (BigInts31Bit*)bigIntPtr;

    int newLength = A_Ptr->m_length + B_Ptr->m_length;
    int32_t * result = new int32_t[newLength];

    int index;
    for (index = 0; index < newLength; index++)
    {
        result[index] = 0;
    }

    /*
     *   2345
     * x   11
     * ------
     *   2345
     *  2345
     * -------
     *
     */

    int Aindex, Bindex;
    int32_t carry = 0;
    for (Bindex = 0; Bindex < B_Ptr->m_length; Bindex++)
    {
        for (Aindex = 0; ((Aindex < A_Ptr->m_length)|| (carry !=0)); Aindex++)
        {
            long long tempDigit;
            long long tempA = 0;
            if (Aindex < A_Ptr->m_length)
            {
                tempA = A_Ptr->m_value[Aindex];
            }
            tempDigit = result[Bindex+Aindex] + tempA * B_Ptr->m_value[Bindex] + carry;
            carry = 0;
            if (tempDigit >= BASE )
            {
                carry = tempDigit >> BASE_BITS;
                result[Bindex + Aindex] = tempDigit & BASE_MASK;  // todo. use BASE_BITS to compute
            }
            else
            {
                result[Bindex+Aindex] = tempDigit;
            }
        }
    }

    delete [] m_value;
    m_value = result;
    m_length = newLength;
    m_negative = A_Ptr->m_negative ^ B_Ptr->m_negative;
    trimLeadingZeros();
}

void BigInts31Bit::divide(BigIntBase* bigIntPtr)
{
    int index;
    BigInts31Bit* dividend = this;
    BigInts31Bit* divisor = (BigInts31Bit*)bigIntPtr;
    int32_t * resultArray = new int32_t[m_length];

    // pre-compute various divisor products for 0-9 (and one for 10 since search loop goes one past)
    BigInts31Bit productFrag[32];  // only 30 bits of value in base 1e9
    productFrag[0].assign(divisor);
    productFrag[0].m_negative = false; // guarantee its positive.
    for (int digValIndex = 1; digValIndex < 32; digValIndex++)
    {
        productFrag[digValIndex].assign(&productFrag[digValIndex - 1]);
        productFrag[digValIndex].sameSignAdd(&productFrag[digValIndex - 1]); //sameSignAdd ignores sign bits so we can handle a negative divisor
    }

    for(index=0;index<m_length;index++)
    {
        resultArray[index] = 0;
    }

    int resultDigitIndex = dividend->m_length - divisor->m_length;   // position of digit in overall result value

    BigInts31Bit divdendFragment;

    // get a starting point for our division.  assume same num of digits as divisor.  might need one more though.
    getSubArray(&divdendFragment, m_length-1, divisor->m_length);
    if ( divdendFragment.compareMagnitude(divisor) == -1 )  // if divisor doesnt fit in fragment, tack on an extra digit.
    {
        resultDigitIndex--;
    }
    getSubArray(&divdendFragment, m_length-1, m_length-resultDigitIndex);

    // compute the overall digit 000000000-999999999 by building each subdigit.
    while (resultDigitIndex >= 0)
    {
        int dividendDigit = 0;   // full 1B digit i.e. 000000000-999999999 in value
        int subDigitMultiplier;  // values of 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1

        for (subDigitMultiplier = 31 ; subDigitMultiplier >= 0; subDigitMultiplier--)
        {
            if (divdendFragment.compareMagnitude(&productFrag[subDigitMultiplier]) > -1)
            {
                dividendDigit += (1<<subDigitMultiplier);
                divdendFragment.subtract(&productFrag[subDigitMultiplier]); // the previous loop went one too far.  back up.
            }
        }

        resultArray[resultDigitIndex] = dividendDigit;  // store the final digit.
        resultDigitIndex--;

        if (resultDigitIndex >= 0)
        {
            divdendFragment.insertLeastSigDigit(dividend->m_value[resultDigitIndex]);
        }
//        printBigInt("concatResult = %s\n", &divdendFragment);
    }

    delete [] m_value;
    m_value = resultArray;
    m_negative = divisor->m_negative ^ dividend->m_negative;   // XOR divisor sign  and  dividend sign
    trimLeadingZeros();
}

void BigInts31Bit::setString(char* valueString)
{
    int length = strlen(valueString);

    int inIndex = 0;
    if ( valueString[0] == '-' )
    {
        m_negative = true;
        inIndex++;
        length--;
    }
    else
    {
        m_negative = false;
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

    BigInts31Bit inputDigitWeight;
    BigInts31Bit inputDigitShifted;
    BigInts31Bit ten;

    inputDigitWeight.valueOf(1);
    inputDigitShifted.valueOf(1);
    valueOf(0);  // we will be cumulative value.
    ten.valueOf(10);

    for (index = 0; index < length; index++)
    {
        int rawInIndex = inIndex + length - index -1;
        int currentDigitVal = valueString[rawInIndex] - '0';
        inputDigitShifted.valueOf(currentDigitVal);
        inputDigitShifted.multiply(&inputDigitWeight);
        sameSignAdd(&inputDigitShifted);

//        printf("currentDigitVal = %d  ",currentDigitVal);
//        printBigInt("inputDigitShifted=%s   ",&inputDigitShifted);
//        printBigInt("cumulativeValue=%s   ",this);
//        if(m_length>=1) printf("m_value[1]=%d   ",m_value[1]);
//        printf("m_value[0]=%d   ",m_value[0]);
//        printBigInt("inputDigitWeight=%s\n",&inputDigitWeight);
//
        inputDigitWeight.multiply(&ten);
   }
    trimLeadingZeros();
}

int BigInts31Bit::compareMagnitude(BigIntBase* bigIntPtr)
{
    int returnVal = 0;

    BigInts31Bit* A_Ptr = this;
    BigInts31Bit* B_Ptr = (BigInts31Bit*)bigIntPtr;

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

char* BigInts31Bit::getString()
{
    char* returnVal = new char[m_length*10 + 2];   //add space terminator and negative sign
    int outIndex = 0;
    int storageIndex;
    bool foundFirstDigit = false;

    BigIntsBase10 cumulativeValue;
    cumulativeValue.valueOf(0);  // starting position
    BigIntsBase10 currentBitWeight;
    currentBitWeight.valueOf(1);  // weight of LSB

    int numBitsToProcess = 31*m_length;

    int bitIndex;
    int currentBitMask = 1;
    int currentDigitIndex = 0;
    for (bitIndex = 0; bitIndex < numBitsToProcess; bitIndex++)
    {

        if ( m_value[currentDigitIndex] & currentBitMask )
        {
            // current bit is set.  Add in the bit weight
            cumulativeValue.add(&currentBitWeight);
        }

//        printf("digit=%d;  mask=%08x;  ",currentDigitIndex , currentBitMask);
//        currentBitWeight.printBigInt("bitWeight=%s", &currentBitWeight);
//        cumulativeValue.printBigInt("   cumulativeValue=%s\n", &cumulativeValue);


        currentBitWeight.add(&currentBitWeight);  // compute new bit weighting.

        if (currentBitMask == 0x40000000)
        {
            currentBitMask = 1;
            currentDigitIndex += 1;
        }
        else
        {
            currentBitMask <<= 1;
        }
    }

    if (m_negative == true)
    {
        cumulativeValue.m_negative = true;
    }
    return cumulativeValue.getString();
}

void BigInts31Bit::assign(BigIntBase* bigIntPtr)
{
    BigInts31Bit* src_Ptr = (BigInts31Bit*)bigIntPtr;
    int sourceLength = src_Ptr->m_length;

    if (m_length < sourceLength)
    {
        // not enough room in our current area. allocate more
        delete[] m_value;
        m_value = new int32_t[src_Ptr->m_length];
    }

    memcpy(m_value, src_Ptr->m_value, sourceLength*sizeof(int32_t));
    m_length = sourceLength;
    m_negative = src_Ptr->m_negative;
}

void BigInts31Bit::pow(int exp)
{
    int numDigits = m_length * exp;
    BigInts31Bit base;
    BigInts31Bit result;

    base.assign(this);
    result.valueOf(1);  //    BigInt result = 1;
    while (exp)
    {
        if (exp & 1)
        {
            result.multiply(&base);
        }
        exp >>= 1;
        base.multiply(&base);
    }
    assign(&result);
}

bool BigInts31Bit::equals(BigIntBase* rightVal)
{
    BigInts31Bit* leftValPtr = this;
    BigInts31Bit* rightValPtr = (BigInts31Bit*)rightVal;
    bool returnVal = true;

    if (leftValPtr->m_length != rightValPtr->m_length)
    {
        returnVal = false;   // lengths dont match. cant be equal.
//        printf("length mismatch %d != %d\n",leftValPtr->m_length ,rightValPtr->m_length );
    }
    else
    {
        int index;
        for (index = 0; index < leftValPtr->m_length; index++)
        {
            if (leftValPtr->m_value[index] != rightValPtr->m_value[index])
            {
                returnVal = false;   // one of the digits didnt match.  not equal.
//                printf("digit mismatch [%d] %d != %d\n",index, leftValPtr->m_value[index] ,rightValPtr->m_value[index] );
                break;
            }
        }
    }

    if (returnVal == true)
    {
        if ((m_length != 1) || (m_value[0] != 0)) // the two are non-zero and numerically equal in absolute value. make sure signs match
        {
            if (leftValPtr->m_negative != rightValPtr->m_negative)
            {
                returnVal = false;  // signs dont match.  cant be equal.
            }
        }
    }

//    char * textPtr = leftValPtr->getString();
//    printf("leftValPtr=%s   ", textPtr);
//    delete [] textPtr;
//    textPtr = rightValPtr->getString();
//    printf("rightValPtr=%s   ", textPtr);
//    delete [] textPtr;
//    printf("returnVal=%s   ", returnVal ? "true": "false");


    return returnVal;
}

bool BigInts31Bit::equals(int rightVal)
{
    bool returnVal = false;
    uint64_t leftVal = 0;
    uint64_t rightVal64;
    int digitMultiplier = 1;
    bool negative = false;

    if (rightVal < 0)
    {
        rightVal = -rightVal;
        negative = true;
    }

    rightVal64 = rightVal;

    if (m_length <= 2)  // only deal with single digit billions at most
    {
        int index;
        for (index = 0; index < m_length; index++)
        {
            leftVal += m_value[index] * digitMultiplier;
            digitMultiplier *= 1000000000;
        }

        if (rightVal64 == leftVal)
        {
            if (m_negative == negative)
            {
                returnVal = true;
            }
        }
    }

    return returnVal;
}

void BigInts31Bit::sqrt(BigIntBase* guess)
{
    if (equals(0) || equals(1))
    {
        return; // return input;
    }

    BigInts31Bit * myGuess = new BigInts31Bit;
    BigInts31Bit * prev = new BigInts31Bit;
    BigInts31Bit * next = new BigInts31Bit;
    BigInts31Bit * two = new BigInts31Bit;
    two->valueOf(2);

    if (guess != 0)
    {
        myGuess->assign(guess);
    }
    else
    {
        int first1Pos;
        for(first1Pos=30; first1Pos>=0; first1Pos--)
        {
            if ( (unsigned int)m_value[m_length-1] > (1u<<first1Pos) )
            {
                break;
            }
        }
//        printf("m_value[m_length-1]=%08x;  first1Pos=%d; m_length=%d; totalBits=%d;  halfTotalBits=%d\n",
//                m_value[m_length-1],
//                first1Pos, m_length, (m_length-1)*31+first1Pos , ((m_length-1)*31+first1Pos)/2 );
        myGuess->valueOf(2);   // if no guess was provided, use 1
        myGuess->pow(((m_length-1)*31+first1Pos)/2);
    }

    next->assign(myGuess);  //starting value
    int loopCount = 0;

    do
    {
        //        prev = next.shiftRight(0);
        prev->assign(next);     //printBigInt("\nprev->assign(next);  = %s\n",prev);

        //        next = prev.add( input.divide(prev) );
        next->assign(this);     //printBigInt("next->assign(this);  = %s\n",next);
        next->divide(prev);     //printBigInt("next->divide(prev);  = %s\n",next);
        next->add(prev);        //printBigInt("next->add(prev);     = %s\n",next);

        //        next = next.shiftRight(1);
        next->divide(two);      //printBigInt("next->divide(two);     = %s\n",next);
        loopCount++;
        if (loopCount == 10000)
        {
            printf("Uh Oh. loopCount=%d. something seems wrong.\n", loopCount);
        }
    }
    while (prev->equals(next) == false);
//    printf("loopCount = %d\n",loopCount);

    assign(next);

    delete myGuess;
    delete prev;
    delete next;
    delete two;
}

void BigInts31Bit::sameSignAdd(BigIntBase* bigIntPtr)
{
    BigInts31Bit* longPtr = this;
    BigInts31Bit* shortPtr = (BigInts31Bit*)bigIntPtr;
    if ((longPtr->m_length) < (shortPtr->m_length))
    {
        swap(&longPtr,&shortPtr);
    }
    int shortestLength = shortPtr->m_length;
    int longestLength = longPtr->m_length;

    int32_t * resultArray = new int32_t[longPtr->m_length+1];

    // the signs match.  we can just add. (even if both negative)
    int index;
    int carry = 0;
    for (index = 0; ((index < longestLength) || (carry == 1)); index++)
    {
        unsigned int temp = 0;
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
            temp &= BASE_MASK;
            carry = 1;
        }
        resultArray[index] = temp;
    }
    delete [] m_value;
    m_value = resultArray;
    m_length = longPtr->m_length + ((longPtr->m_length < index) ? 1 : 0);
}

void BigInts31Bit::diffSignAdd(BigIntBase* bigIntPtr)
{
    // the signs are different, so its a subtract.
    // take the Big one minus Small and then use the final sign of the bigger
    BigInts31Bit* bigPtr = this;
    BigInts31Bit* smallPtr = (BigInts31Bit*)bigIntPtr;

    // we want bigger minus smaller. i.e. 55 - 5
    if ( (smallPtr->compareMagnitude(bigPtr)) == 1 )  // If A>B then swap since A is desired to be small
    {
        swap(&bigPtr, &smallPtr);
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

void BigInts31Bit::swap(BigInts31Bit** first, BigInts31Bit** second)
{
    BigInts31Bit * tempPtr;
    tempPtr = *first;
    *first = *second;
    *second = tempPtr;
}

void BigInts31Bit::trimLeadingZeros()
{
    while ((m_length != 1) && (m_value[m_length - 1] == 0))  // trim leading 0s if any
    {
        m_length--;
    }

    if ((m_length == 1) && (m_value[0] == 0))
    {
        m_negative = false;   // avoid a negative zero.
    }
}

void BigInts31Bit::getSubArray(BigInts31Bit* destArray, int msbIndex, int numDigits)
{
    if ( numDigits > destArray->m_length)  // if it wont fit, allocate more space
    {
        delete [] destArray->m_value;
        destArray->m_value = new int32_t[numDigits];
    }
    destArray->m_length = numDigits;

    int index;
    for(index=0; index<numDigits; index++)
    {
        destArray->m_value[index] = m_value[msbIndex-numDigits+index+1];
    }
}

//void BigInts31Bit::printBigInt(char* formatStr, BigInts31Bit* bigIntPtr)
//{
//    char * tempVal = bigIntPtr->getString();
//
//    printf(formatStr, tempVal);
//
//    delete[] tempVal;
//}

void BigInts31Bit::insertLeastSigDigit(int32_t digit)
{
    int32_t * newArray = new int32_t[m_length + 1];
    int index;
    for(index=0;index<m_length; index++)
    {
        newArray[index+1] = m_value[index];
    }
    newArray[0] = digit;
    m_length++;

    delete[] m_value;
    m_value = newArray;
    trimLeadingZeros();
}
