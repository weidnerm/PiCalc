#include "stdio.h"
#include "BigIntFactory1B.h"
#include "PiCalculator.h"
#include "BigIntBase.h"



int main(int argc, char** argv)
{
    int numDigits;
    int numparms;

    if ( argc != 2 )
    {
         printf("Usage: %s <numDigits>\n",argv[0]);
    }
    else
    {
        numparms = sscanf(argv[1], "%d", &numDigits);

        BigIntFactory1B * myBigIntFactory = new BigIntFactory1B;
        PiCalculator * myPiCalculator = new PiCalculator(myBigIntFactory);
        BigIntBase * myBigIntBaseA;

        myBigIntBaseA = myBigIntFactory->create();

        myPiCalculator->calc_Pi_digits(myBigIntBaseA, numDigits);
        myBigIntBaseA->printBigInt((char*)"%s\n", myBigIntBaseA);
    }
}


