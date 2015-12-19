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
        ~BigIntsBase10();
        virtual void valueOf(int); // assign an int
        virtual char* getString(); // output to a string
        virtual void setString(char * valueString);  // assign from a string
        virtual void add(BigIntBase* bigInt);
    protected:
        virtual void sameSignAdd(BigIntBase* bigInt);

    public:
        int8_t* m_value;
        uint32_t m_length;
        bool m_negative;
};

#endif /* BIGINTSBASE10_H_ */
