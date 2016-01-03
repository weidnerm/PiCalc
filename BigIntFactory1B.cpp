/*******************************************************************************
 *
 *             COPYRIGHT 2016 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigIntFactory1B.cpp
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
#include "BigIntFactory1B.h"
#include "BigInts1B.h"

BigIntFactory1B::BigIntFactory1B()
{
    // TODO Auto-generated constructor stub
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/

}

BigIntFactory1B::~BigIntFactory1B()
{
    // TODO Auto-generated method stub
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/

}

BigIntBase* BigIntFactory1B::create()
{
    return new BigInts1B;
}
