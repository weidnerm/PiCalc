/*******************************************************************************
 *
 *             COPYRIGHT 2015 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigIntBase.h
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

#ifndef BIGINTBASE_H_
#define BIGINTBASE_H_

/*-------------------------- HEADER FILE INCLUDES -----------------------------*/

/*------------------------------ CONSTANTS ------------------------------------*/

/*---------------------------- ENUMERATED TYPES -------------------------------*/

/*---------------------------------- MACROS -----------------------------------*/

class BigIntBase
{
    public:
        BigIntBase();
        virtual void valueOf(int) = 0; // assign an int
        virtual void add(BigIntBase* bigIntPtr) = 0;
        virtual void subtract(BigIntBase* bigIntPtr) = 0;
        virtual void multiply(BigIntBase* bigIntPtr) = 0;
        virtual void divide(BigIntBase* bigIntPtr) = 0;
        virtual void setString(char * valueString) = 0;  // assign from a string
        virtual int compareMagnitude(BigIntBase* bigIntPtr) = 0;
        virtual char* getString() = 0; // output to a string
        virtual void assign(BigIntBase* bigIntPtr) = 0;
        virtual ~BigIntBase();
        virtual void pow(int power) = 0;   // base ^ int
        virtual bool equals(BigIntBase* rightVal) = 0;
        virtual bool equals(int rightVal) = 0;
        virtual void sqrt(BigIntBase* guess = 0) = 0;
};

#endif /* BIGINTBASE_H_ */
