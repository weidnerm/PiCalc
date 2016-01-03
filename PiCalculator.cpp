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
:m_BigIntFactory(0)
{
    // TODO Auto-generated constructor stub
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/

}

PiCalculator::PiCalculator(BigIntFactory* myBigIntFactory)
{
    m_BigIntFactory        = myBigIntFactory;
    m_zero                 = m_BigIntFactory->create();
    m_one                  = m_BigIntFactory->create();
    m_three                = m_BigIntFactory->create();
    m_six                  = m_BigIntFactory->create();
    m_fiveFortyFiveMillion = m_BigIntFactory->create();
    m_neg_640320           = m_BigIntFactory->create();
    m_neg_640320_cubed     = m_BigIntFactory->create();

    m_zero ->valueOf(0);
    m_one  ->valueOf(1);
    m_three->valueOf(3);
    m_six  ->valueOf(6);
    m_fiveFortyFiveMillion->valueOf(545140134L);
    m_neg_640320      ->valueOf(-640320);
    m_neg_640320_cubed->assign(m_neg_640320);
    m_neg_640320_cubed->pow(3);

}

PiCalculator::~PiCalculator()
{
    // TODO Auto-generated method stub
    /*----------------------------- LOCAL VARIABLES ------------------------------*/

    /*---------------------------------- CODE ------------------------------------*/
    delete m_zero;
    delete m_one;
    delete m_three;
    delete m_six;
    delete m_fiveFortyFiveMillion;
    delete m_neg_640320      ;
    delete m_neg_640320_cubed;

}

/**
 *     public static BigInteger get_six_k_factorial(BigInteger previous, int k )
    {
        final BigInteger six                  = BigInteger.valueOf(6);
        final BigInteger six_k                = six.multiply(BigInteger.valueOf(k));
        final BigInteger six_k_minus_1        = six_k.subtract(BigInteger.ONE);
        final BigInteger six_k_minus_2        = six_k_minus_1.subtract(BigInteger.ONE);
        final BigInteger six_k_minus_3        = six_k_minus_2.subtract(BigInteger.ONE);
        final BigInteger six_k_minus_4        = six_k_minus_3.subtract(BigInteger.ONE);
        final BigInteger six_k_minus_5        = six_k_minus_4.subtract(BigInteger.ONE);


        final BigInteger result = previous.multiply(six_k).
                multiply(six_k_minus_1).
                multiply(six_k_minus_2).
                multiply(six_k_minus_3).
                multiply(six_k_minus_4).
                multiply(six_k_minus_5);

        return result;
    }
 *
 */
void PiCalculator::get_six_k_factorial(BigIntBase* previous, int k_val)
{
    BigIntBase *  k             = m_BigIntFactory->create();
    BigIntBase *  six_k         = m_BigIntFactory->create();
    BigIntBase *  six_k_minus_1 = m_BigIntFactory->create();
    BigIntBase *  six_k_minus_2 = m_BigIntFactory->create();
    BigIntBase *  six_k_minus_3 = m_BigIntFactory->create();
    BigIntBase *  six_k_minus_4 = m_BigIntFactory->create();
    BigIntBase *  six_k_minus_5 = m_BigIntFactory->create();

    k->valueOf(k_val);

    six_k->assign(m_six);
    six_k->multiply(k);

    six_k_minus_1->assign(six_k);
    six_k_minus_1->subtract(m_one);

    six_k_minus_2->assign(six_k_minus_1);
    six_k_minus_2->subtract(m_one);

    six_k_minus_3->assign(six_k_minus_2);
    six_k_minus_3->subtract(m_one);

    six_k_minus_4->assign(six_k_minus_3);
    six_k_minus_4->subtract(m_one);

    six_k_minus_5->assign(six_k_minus_4);
    six_k_minus_5->subtract(m_one);

    previous->multiply(six_k        );
    previous->multiply(six_k_minus_1);
    previous->multiply(six_k_minus_2);
    previous->multiply(six_k_minus_3);
    previous->multiply(six_k_minus_4);
    previous->multiply(six_k_minus_5);

    delete k             ;
    delete six_k         ;
    delete six_k_minus_1 ;
    delete six_k_minus_2 ;
    delete six_k_minus_3 ;
    delete six_k_minus_4 ;
    delete six_k_minus_5 ;
}

//    public static BigInteger get_three_k_factorial(BigInteger previous, int k )
//    {
//        final BigInteger three                  = BigInteger.valueOf(3);
//        final BigInteger three_k                = three.multiply(BigInteger.valueOf(k));
//        final BigInteger three_k_minus_1        = three_k.subtract(BigInteger.ONE);
//        final BigInteger three_k_minus_2        = three_k_minus_1.subtract(BigInteger.ONE);
//
//
//        final BigInteger result = previous.multiply(three_k).
//                multiply(three_k_minus_1).
//                multiply(three_k_minus_2);
//
//        return result;
//    }
void PiCalculator::get_three_k_factorial(BigIntBase* previous, int k_val)
{
    BigIntBase * k               = m_BigIntFactory->create();
    BigIntBase * three_k         = m_BigIntFactory->create();
    BigIntBase * three_k_minus_1 = m_BigIntFactory->create();
    BigIntBase * three_k_minus_2 = m_BigIntFactory->create();

    k->valueOf(k_val);

    three_k->assign(m_three);
    three_k->multiply(k);

    three_k_minus_1->assign(three_k);
    three_k_minus_1->subtract(m_one);

    three_k_minus_2->assign(three_k_minus_1);
    three_k_minus_2->subtract(m_one);

    previous->multiply(three_k        );
    previous->multiply(three_k_minus_1);
    previous->multiply(three_k_minus_2);

    delete k              ;
    delete three_k        ;
    delete three_k_minus_1;
    delete three_k_minus_2;

}

//    public static BigInteger get_numerator_constant(BigInteger previous )
//    {
//        final BigInteger fiveFortyFiveMillion   = BigInteger.valueOf( 545140134L );
//
//        final BigInteger result = previous.add(fiveFortyFiveMillion);
//
//        return result;
//    }
void PiCalculator::get_numerator_constant(BigIntBase* previous)
{
    previous->add(m_fiveFortyFiveMillion);
}

//    public static BigInteger get_k_factorial_cubed( int k )
//    {
//        final BigInteger k_value                = BigInteger.valueOf(k);
//        k_factorial                             = k_factorial.multiply(k_value);
//        final BigInteger k_factorial_cubed      = k_factorial.multiply(k_factorial).multiply(k_factorial);
//
//        return k_factorial_cubed;
//    }
void PiCalculator::get_k_factorial_cubed(BigIntBase* k_factorial_cubed, BigIntBase* k_factorial, int k_val)
{
    BigIntBase * k               = m_BigIntFactory->create();

    k->valueOf(k_val);

    k_factorial->multiply(k);

    k_factorial_cubed->assign(k_factorial);
    k_factorial_cubed->multiply(k_factorial);
    k_factorial_cubed->multiply(k_factorial);

    delete k;
}

//    public static BigInteger get_neg_640320_to_the_3k(BigInteger previous)
//    {
//        final BigInteger neg_640320             = BigInteger.valueOf(-640320);
//        final BigInteger neg_640320_cubed       = neg_640320.pow(3);
//
//        final BigInteger result = previous.multiply(neg_640320_cubed);
//
//        return result;
//    }
void PiCalculator::get_neg_640320_to_the_3k(BigIntBase* previous)
{
    previous->multiply(m_neg_640320_cubed);
}

//    public static BigInteger get_426880_sqrt_10005(int numDigits)
//    {
//
//        final BigInteger orig426880                   = BigInteger.valueOf(426880L);
//
//        final BigInteger orig10005                    = BigInteger.valueOf(10005L);
//        final BigInteger mySquaredPowOfTenScaleFactor = ten.pow(2*numDigits);
//        final BigInteger scaledOrig10005              = orig10005.multiply(mySquaredPowOfTenScaleFactor);
//
//        final BigInteger guessExponent                = ten.pow(numDigits-29);
//        final BigInteger guessMantissa                = new BigInteger("10002499687578100594479218787636");
//        final BigInteger guess                        = guessMantissa.multiply(guessExponent);
//
//        startSqrtTime                                 = System.currentTimeMillis();
//        final BigInteger sqrt10005                    = bigIntSqRootNewtonFloor( scaledOrig10005, guess );
//        endSqrtTime                                   = System.currentTimeMillis();
//
//        BigInteger testValue                          = sqrt10005.multiply(sqrt10005);
//
//
////      System.out.println(sqrt10005.toString());
////      System.out.println(testValue.toString());
//
//        return orig426880.multiply(sqrt10005);
//    }
void PiCalculator::get_426880_sqrt_10005(BigIntBase* result, int numDigits)
{
    BigIntBase * orig426880                   = m_BigIntFactory->create();
    BigIntBase * orig10005                    = m_BigIntFactory->create();
    BigIntBase * mySquaredPowOfTenScaleFactor = m_BigIntFactory->create();
    BigIntBase * scaledOrig10005              = m_BigIntFactory->create();
    BigIntBase * sqrt10005                    = m_BigIntFactory->create();

    //        final BigInteger orig426880                   = BigInteger.valueOf(426880L);
    //        final BigInteger orig10005                    = BigInteger.valueOf(10005L);
    orig426880->valueOf(426880L);
    orig10005->valueOf(10005L);

    //        final BigInteger mySquaredPowOfTenScaleFactor = ten.pow(2*numDigits);
    mySquaredPowOfTenScaleFactor->valueOf(10);
    mySquaredPowOfTenScaleFactor->pow(2*numDigits);

    //        final BigInteger scaledOrig10005              = orig10005.multiply(mySquaredPowOfTenScaleFactor);
    scaledOrig10005->assign(orig10005);
    scaledOrig10005->multiply(mySquaredPowOfTenScaleFactor);


    //        final BigInteger guessExponent                = ten.pow(numDigits-29);
    //        final BigInteger guessMantissa                = new BigInteger("10002499687578100594479218787636");
    //        final BigInteger guess                        = guessMantissa.multiply(guessExponent);
    //
    //        startSqrtTime                                 = System.currentTimeMillis();
    //        final BigInteger sqrt10005                    = bigIntSqRootNewtonFloor( scaledOrig10005, guess );
    sqrt10005->assign(scaledOrig10005);
    sqrt10005->sqrt();

    //        endSqrtTime                                   = System.currentTimeMillis();
    //
    //        BigInteger testValue                          = sqrt10005.multiply(sqrt10005);
    //
    //
    ////      System.out.println(sqrt10005.toString());
    ////      System.out.println(testValue.toString());
    //
    //        return orig426880.multiply(sqrt10005);
    result->assign(orig426880);
    result->multiply(sqrt10005);

    delete orig426880;
    delete orig10005;
    delete mySquaredPowOfTenScaleFactor;
    delete scaledOrig10005;
    delete sqrt10005;
}

#ifdef DITCH_ME
public class PiCalculatorMain {

    public static int numDigits = 20000;


    public static BigInteger k_factorial = BigInteger.ONE;
    public static BigInteger ten                          = BigInteger.valueOf(10L);
    public static BigInteger powerOfTenScaleFactor        = ten.pow(numDigits);
    public static BigInteger squaredPowerOfTenScaleFactor = ten.pow(2*numDigits);

    public static long startSqrtTime;
    public static long endSqrtTime;
    public static long startOverallTime;
    public static long endOverallTime;


    public static void main(String[] args)
    {
        System.out.println("Hello.");
        startOverallTime                        = System.currentTimeMillis();

        BigInteger valof_426880_sqrt_10005      = get_426880_sqrt_10005(numDigits);
        BigInteger six_k_factorial              = BigInteger.ONE;
        BigInteger numerator_constant           = BigInteger.valueOf(13591409L);
        BigInteger three_k_factorial            = BigInteger.ONE;
        BigInteger k_factorial_cubed            = BigInteger.ONE;
        BigInteger neg_640320_to_the_3k         = BigInteger.ONE;

        BigInteger series_k_sum                 = BigInteger.ZERO;

        int k = 0;

        while ( true )
        {
            if ( k>0 )
            {
                six_k_factorial        = get_six_k_factorial(six_k_factorial, k );
                three_k_factorial      = get_three_k_factorial(three_k_factorial, k );
                numerator_constant     = get_numerator_constant(numerator_constant);
                k_factorial_cubed      = get_k_factorial_cubed( k );
                neg_640320_to_the_3k   = get_neg_640320_to_the_3k(neg_640320_to_the_3k);
            }

            BigInteger series_k_scaled_numerator  = six_k_factorial.multiply(numerator_constant).multiply(powerOfTenScaleFactor);
            BigInteger series_k_denominator       = three_k_factorial.multiply(k_factorial_cubed).multiply(neg_640320_to_the_3k);

            BigInteger series_k_fraction          = series_k_scaled_numerator.divide(series_k_denominator);

            series_k_sum                          = series_k_sum.add(series_k_fraction);

            int series_k_fraction_num_digits      = series_k_fraction.toString().length();
            System.out.println("k="+k+"  series_k_fraction_num_digits="+series_k_fraction_num_digits );

            if ( series_k_fraction.equals(BigInteger.ZERO) )
            {
                break;
            }
            k++;
        }

        BigInteger scaled_Pi = valof_426880_sqrt_10005.multiply(powerOfTenScaleFactor).divide(series_k_sum);

        endOverallTime                          = System.currentTimeMillis();
        System.out.println("Complete.");

        String scaled_Pi_string                 = scaled_Pi.toString();

        String scaled_Pi_fraction_string        = scaled_Pi_string.substring(1);
        dumpString(scaled_Pi_fraction_string);

        System.out.println("Total execution time: " + (endOverallTime - startOverallTime)+" msec" );
    }


    public static void dumpString(String inputString)
    {
        int length = inputString.length();
        int charsDumped = 0;
        int charsThisLine;
        int maxCharsPerLine = 100;

        try {
            File file = new File("pi_"+numDigits+".txt");
            BufferedWriter output = new BufferedWriter(new FileWriter(file));

            output.write("3.\r\n");
            while (charsDumped < length)
            {
                charsThisLine = length - charsDumped;
                if (charsThisLine > maxCharsPerLine) {
                    charsThisLine = maxCharsPerLine;
                }

                output.write(inputString.substring(charsDumped, charsDumped
                        + charsThisLine)+"\r\n");
                charsDumped += charsThisLine;
            }
            output.close();
        } catch (IOException ex){
          // report
        } finally {
           try {} catch (Exception ex) {}
        }
    }












}
#endif // DITCH_ME
