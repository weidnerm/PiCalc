/*******************************************************************************
 *
 *             COPYRIGHT 2015 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigInts100M.h
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

#ifndef BIGINTS100M_H_
#define BIGINTS100M_H_

/*-------------------------- HEADER FILE INCLUDES -----------------------------*/
#include <BigIntBase.h>
#include "stdint.h"

/*------------------------------ CONSTANTS ------------------------------------*/

/*---------------------------- ENUMERATED TYPES -------------------------------*/

/*---------------------------------- MACROS -----------------------------------*/

class BigInts1B: public BigIntBase
{
    public:
        BigInts1B();
        virtual ~BigInts1B();
        virtual void valueOf(int); // assign an int
        virtual void add(BigIntBase* bigInt);
        virtual void subtract(BigIntBase* bigIntPtr);
        virtual void multiply(BigIntBase* bigInt);
        // divide
        virtual void setString(char * valueString);  // assign from a string
        virtual char* getString(); // output to a string
    protected:
        virtual void sameSignAdd(BigIntBase* bigIntPtr);
        virtual void diffSignAdd(BigIntBase* bigIntPtr);
        void swap(BigInts1B ** first, BigInts1B ** second);
    public:
        int32_t* m_value;
        uint32_t m_length;
        bool m_negative;
};

#endif /* BIGINTS100M_H_ */
