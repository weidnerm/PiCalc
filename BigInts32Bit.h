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
        virtual char* getString(); // output to a string
        virtual void setString(char * valueString);  // assign from a string
        virtual void add(BigIntBase* bigInt);
        virtual void subtract(BigIntBase* bigInt);
    public:
        uint32_t* m_value;
        uint32_t m_length;
        bool m_negative;
};

#endif /* BIGINTS32BIT_H_ */
