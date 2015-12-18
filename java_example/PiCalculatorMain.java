package com.weidnerm.pi;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;



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
 
//	public static BigInteger bigIntSqRootFloor(BigInteger x) 
//	{
//		// square roots of 0 and 1 are trivial and
//		// y == 0 will cause a divide-by-zero exception
//		if (x.equals( BigInteger.ZERO) || x.equals( BigInteger.ONE) ) 
//		{
//			return x;
//		} // end if
//		BigInteger two = BigInteger.valueOf(2L);
//		BigInteger y;
//		int loopCount = 0;
//		// starting with y = x / 2 avoids magnitude issues with x squared
//		for (y = x.divide(two); y.compareTo(x.divide(y)) > 0; y = ((x.divide(y))
//				.add(y)).divide(two))
//			loopCount++;
//		System.out.println("loopCount = "+loopCount);
//		return y;
//	} // end bigIntSqRootFloor
	
	
	public static BigInteger bigIntSqRootNewtonFloor(BigInteger input, BigInteger guess)
	{
		if (input.equals( BigInteger.ZERO) || input.equals( BigInteger.ONE) ) 
		{
			return input;
		} // end if		
		
		BigInteger prev;
		BigInteger next = guess;  //starting value
		int loopCount = 0;
		
        do
		{
			prev = next.shiftRight(0);
			next = prev.add( input.divide(prev) );
			next = next.shiftRight(1);
			loopCount++;
					
		}
		while ( prev.equals(next) == false );
		
		System.out.println("loopCount = "+loopCount);
		return next;		
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
	
	
	public static BigInteger get_six_k_factorial(BigInteger previous, int k )
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
	
	public static BigInteger get_three_k_factorial(BigInteger previous, int k )
	{
		final BigInteger three                  = BigInteger.valueOf(3);
		final BigInteger three_k                = three.multiply(BigInteger.valueOf(k));
		final BigInteger three_k_minus_1        = three_k.subtract(BigInteger.ONE);
		final BigInteger three_k_minus_2        = three_k_minus_1.subtract(BigInteger.ONE);
		
		
		final BigInteger result = previous.multiply(three_k).
                multiply(three_k_minus_1). 
                multiply(three_k_minus_2);
		
		return result;
	}
	
	public static BigInteger get_numerator_constant(BigInteger previous )
	{
		final BigInteger fiveFortyFiveMillion   = BigInteger.valueOf( 545140134L );

		final BigInteger result = previous.add(fiveFortyFiveMillion);
		
		return result;
	}
	
	
	
	public static BigInteger get_k_factorial_cubed( int k )
	{
		final BigInteger k_value                = BigInteger.valueOf(k);
		k_factorial                             = k_factorial.multiply(k_value);
		final BigInteger k_factorial_cubed      = k_factorial.multiply(k_factorial).multiply(k_factorial);
		
		return k_factorial_cubed;
	}
	
	public static BigInteger get_neg_640320_to_the_3k(BigInteger previous)
	{
		final BigInteger neg_640320             = BigInteger.valueOf(-640320);
		final BigInteger neg_640320_cubed       = neg_640320.pow(3);

		final BigInteger result = previous.multiply(neg_640320_cubed);
		
		return result;
	}
	
	public static BigInteger get_426880_sqrt_10005(int numDigits)
	{
		
		final BigInteger orig426880                   = BigInteger.valueOf(426880L);

		final BigInteger orig10005                    = BigInteger.valueOf(10005L);
		final BigInteger mySquaredPowOfTenScaleFactor = ten.pow(2*numDigits);
		final BigInteger scaledOrig10005              = orig10005.multiply(mySquaredPowOfTenScaleFactor);
		
		final BigInteger guessExponent                = ten.pow(numDigits-29);
		final BigInteger guessMantissa                = new BigInteger("10002499687578100594479218787636");
		final BigInteger guess                        = guessMantissa.multiply(guessExponent);
		
		startSqrtTime                                 = System.currentTimeMillis();
		final BigInteger sqrt10005                    = bigIntSqRootNewtonFloor( scaledOrig10005, guess );
		endSqrtTime                                   = System.currentTimeMillis();
		
		BigInteger testValue                          = sqrt10005.multiply(sqrt10005);
		
		
//		System.out.println(sqrt10005.toString());
//		System.out.println(testValue.toString());
		
		return orig426880.multiply(sqrt10005);
	}
	
	
	
	
	
}
