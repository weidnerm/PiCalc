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
        virtual void get_six_k_factorial(BigIntBase * previous, int k_val );
        virtual void get_three_k_factorial(BigIntBase* previous, int k_val );
        virtual void get_numerator_constant(BigIntBase* previous);
        virtual void get_k_factorial_cubed(BigIntBase* k_factorial_cubed, BigIntBase* k_factorial, int k_val );
        virtual void get_neg_640320_to_the_3k(BigIntBase* previous);
        virtual void get_426880_sqrt_10005(BigIntBase* result, int numDigits );



    protected:
        BigIntFactory * m_BigIntFactory;
        BigIntBase * m_zero;
        BigIntBase * m_one;
        BigIntBase * m_three;
        BigIntBase * m_six;
        BigIntBase * m_fiveFortyFiveMillion;
        BigIntBase * m_neg_640320      ;
        BigIntBase * m_neg_640320_cubed;


};

#endif /* PICALCULATOR_H_ */
