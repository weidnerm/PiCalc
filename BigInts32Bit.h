/*******************************************************************************
 *
 *             COPYRIGHT 2015 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigInts32Bit.h
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

#ifndef BIGINTS32BIT_H_
#define BIGINTS32BIT_H_

/*-------------------------- HEADER FILE INCLUDES -----------------------------*/
#include "BigIntBase.h"
#include "stdint.h"

/*------------------------------ CONSTANTS ------------------------------------*/

/*---------------------------- ENUMERATED TYPES -------------------------------*/

/*---------------------------------- MACROS -----------------------------------*/

class BigInts32Bit: public BigIntBase
{
    public:
        BigInts32Bit();
        virtual ~BigInts32Bit();
        virtual void valueOf(int); // assign an int
        virtual void add(BigIntBase* bigIntPtr);
        virtual void subtract(BigIntBase* bigIntPtr);
        virtual void multiply(BigIntBase* bigIntPtr);
        virtual void divide(BigIntBase* bigIntPtr);
        virtual void setString(char * valueString);  // assign from a string
        virtual int compareMagnitude(BigIntBase* bigIntPtr);
        virtual char* getString(); // output to a string
        virtual void assign(BigIntBase* bigIntPtr);
        virtual void pow(int power);   // base ^ int
        virtual bool equals(BigIntBase* rightVal);
        virtual bool equals(int rightVal);
        virtual void sqrt(BigIntBase* guess = 0);
//        void printBigInt(char * formatStr, BigInts32Bit *bigIntPtr);
    protected:
        virtual void sameSignAdd(BigIntBase* bigIntPtr);
        virtual void diffSignAdd(BigIntBase* bigIntPtr);
        void swap(BigInts32Bit ** first, BigInts32Bit ** second);
        void trimLeadingZeros();
        void getSubArray(BigInts32Bit * destArray, int msbIndex, int numDigits);
        void insertLeastSigDigit(int32_t digit);

    public:
        uint32_t* m_value;
        uint32_t m_length;
        bool m_negative;
};

#endif /* BIGINTS32BIT_H_ */
