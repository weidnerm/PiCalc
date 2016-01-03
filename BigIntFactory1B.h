/*******************************************************************************
 *
 *             COPYRIGHT 2016 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigIntFactory1B.h
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

#ifndef BIGINTFACTORY1B_H_
#define BIGINTFACTORY1B_H_

/*-------------------------- HEADER FILE INCLUDES -----------------------------*/
#include <BigIntFactory.h>

/*------------------------------ CONSTANTS ------------------------------------*/

/*---------------------------- ENUMERATED TYPES -------------------------------*/

/*---------------------------------- MACROS -----------------------------------*/

class BigIntFactory1B: public BigIntFactory
{
    public:
        BigIntFactory1B();
        virtual ~BigIntFactory1B();
        virtual BigIntBase * create();
};

#endif /* BIGINTFACTORY1B_H_ */
