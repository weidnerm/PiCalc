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
//        virtual void pow(int);   // base ^ int
        virtual void valueOf(int) = 0; // assign an int
        virtual void add(BigIntBase* bigIntPtr) = 0;
        virtual void subtract(BigIntBase* bigIntPtr) = 0;
        virtual void multiply(BigIntBase* bigIntPtr) = 0;
        virtual void divide(BigIntBase* bigIntPtr) = 0;
        virtual void setString(char * valueString) = 0;  // assign from a string
        virtual int compareMagnitude(BigIntBase* bigIntPtr) = 0;
        virtual char* getString() = 0; // output to a string
        virtual ~BigIntBase();
};

#endif /* BIGINTBASE_H_ */
