/*******************************************************************************
 *
 *             COPYRIGHT 2016 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigIntFactory10.h
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

#ifndef BIGINTFACTORY10_H_
#define BIGINTFACTORY10_H_

/*-------------------------- HEADER FILE INCLUDES -----------------------------*/
#include <BigIntFactory.h>

/*------------------------------ CONSTANTS ------------------------------------*/

/*---------------------------- ENUMERATED TYPES -------------------------------*/

/*---------------------------------- MACROS -----------------------------------*/

class BigIntFactory10: public BigIntFactory
{
    public:
        BigIntFactory10();
        virtual ~BigIntFactory10();
        virtual BigIntBase * create();
};

#endif /* BIGINTFACTORY10_H_ */
