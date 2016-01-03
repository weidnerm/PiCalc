/*******************************************************************************
 *
 *             COPYRIGHT 2016 MOTOROLA SOLUTIONS INC. ALL RIGHTS RESERVED.
 *                    MOTOROLA SOLUTIONS CONFIDENTIAL RESTRICTED
 *                            TEMPLATE VERSION R01.03
 *
 ********************************************************************************
 *
 *  FILE NAME : BigIntFactory10.cpp
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
#include "BigIntFactory10.h"
#include "BigIntsBase10.h"

BigIntFactory10::BigIntFactory10()
{
    // TODO Auto-generated constructor stub
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/

}

BigIntFactory10::~BigIntFactory10()
{
    // TODO Auto-generated method stub
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/

}

BigIntBase* BigIntFactory10::create()
{
    return new BigIntsBase10;
}
