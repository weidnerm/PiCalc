/*******************************************************************************
 *
 *             COPYRIGHT 2015 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigIntsBase10.h
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

#ifndef BIGINTSBASE10_H_
#define BIGINTSBASE10_H_

/*-------------------------- HEADER FILE INCLUDES -----------------------------*/
#include "BigIntBase.h"
#include "stdint.h"

/*------------------------------ CONSTANTS ------------------------------------*/

/*---------------------------- ENUMERATED TYPES -------------------------------*/

/*---------------------------------- MACROS -----------------------------------*/

class BigIntsBase10: public BigIntBase
{
    public:
        BigIntsBase10();
        virtual ~BigIntsBase10();
        virtual void valueOf(int); // assign an int
        virtual char* getString(); // output to a string
        virtual void setString(char * valueString);  // assign from a string
        virtual void add(BigIntBase* bigIntPtr);
        virtual void subtract(BigIntBase* bigIntPtr);
        virtual void multiply(BigIntBase* bigIntPtr);
        virtual void divide(BigIntBase* bigIntPtr);
        virtual int compareMagnitude(BigIntBase* bigIntPtr);
        virtual void assign(BigIntBase* bigIntPtr);
        virtual void pow(int power);   // base ^ int
        virtual bool equals(BigIntBase* rightVal);
        virtual bool equals(int rightVal);
        virtual void sqrt(BigIntBase* guess = 0);
//        void printBigInt(char * formatStr, BigIntsBase10 *bigIntPtr);

    protected:
        virtual void sameSignAdd(BigIntBase* bigIntPtr);
        virtual void diffSignAdd(BigIntBase* bigIntPtr);
        void swap(BigIntsBase10 ** first, BigIntsBase10 ** second);
        void trimLeadingZeros();
        void getSubArray(BigIntsBase10 * destArray, int msbIndex, int numDigits);
        void insertLeastSigDigit(int8_t digit);
    public:
        int8_t* m_value;
        uint32_t m_length;
        bool m_negative;
};

#endif /* BIGINTSBASE10_H_ */
