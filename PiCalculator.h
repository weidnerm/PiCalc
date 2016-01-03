/*******************************************************************************
 *
 *             COPYRIGHT 2015 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : PiCalculator.h
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

#ifndef PICALCULATOR_H_
#define PICALCULATOR_H_

/*-------------------------- HEADER FILE INCLUDES -----------------------------*/
#include "BigIntBase.h"
#include "BigIntFactory.h"

/*------------------------------ CONSTANTS ------------------------------------*/

/*---------------------------- ENUMERATED TYPES -------------------------------*/

/*---------------------------------- MACROS -----------------------------------*/

class PiCalculator
{
    public:
        PiCalculator();
        PiCalculator(BigIntFactory * myBigIntFactory);
        virtual ~PiCalculator();

    protected:
        BigIntFactory * m_BigIntFactory;

};

#endif /* PICALCULATOR_H_ */
