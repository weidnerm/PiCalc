/*******************************************************************************
 *
 *             COPYRIGHT 2015 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : PiCalculator.cpp
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

/*--------------------------- HEADER FILE INCLUDES ----------------------------*/
#include "PiCalculator.h"

PiCalculator::PiCalculator()
{
    // TODO Auto-generated constructor stub
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/

}

PiCalculator::~PiCalculator()
{
    // TODO Auto-generated method stub
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/

}

void PiCalculator::bigIntSqRootNewtonFloor(BigIntBase* result, BigIntBase* input, BigIntBase* guess)
{

    if (input->equals(0) || input->equals(1))
    {
        result->assign(input); // return input;
    } // end if

//    BigIntBase prev;   //    BigInteger prev;
    //    BigInteger next = guess;  //starting value
    //    int loopCount = 0;
    //
    //    do
    //    {
    //        prev = next.shiftRight(0);
    //        next = prev.add( input.divide(prev) );
    //        next = next.shiftRight(1);
    //        loopCount++;
    //
    //    }
    //    while ( prev.equals(next) == false );
    //
    //    System.out.println("loopCount = "+loopCount);
    //    return next;




    //    if (input.equals( BigInteger.ZERO) || input.equals( BigInteger.ONE) )
    //    {
    //        return input;
    //    } // end if
    //
    //    BigInteger prev;
    //    BigInteger next = guess;  //starting value
    //    int loopCount = 0;
    //
    //    do
    //    {
    //        prev = next.shiftRight(0);
    //        next = prev.add( input.divide(prev) );
    //        next = next.shiftRight(1);
    //        loopCount++;
    //
    //    }
    //    while ( prev.equals(next) == false );
    //
    //    System.out.println("loopCount = "+loopCount);
    //    return next;
}
