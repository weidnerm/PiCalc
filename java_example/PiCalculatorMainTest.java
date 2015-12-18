package com.weidnerm.pi;

import static org.junit.Assert.*;

import java.math.BigInteger;

import org.junit.Test;

public class PiCalculatorMainTest {

	@Test
	public void testBigIntSqRootNewtonFloor() {
		BigInteger testValue;
		BigInteger result;
		

		testValue = BigInteger.valueOf(10005);
		result    = PiCalculatorMain.bigIntSqRootNewtonFloor(testValue,BigInteger.ONE);
		
		assertTrue( result.equals(BigInteger.valueOf(100)) );

	
		
		testValue = BigInteger.valueOf(100050000);
		result    = PiCalculatorMain.bigIntSqRootNewtonFloor(testValue,BigInteger.ONE);
		
		assertTrue( result.equals(BigInteger.valueOf(10002)) );
		

		
		result    = PiCalculatorMain.bigIntSqRootNewtonFloor( new BigInteger("100050000000000000000000000000000000000000000000000000000000000"),BigInteger.ONE);

        assertTrue( result.equals(new BigInteger("10002499687578100594479218787635")) );
	}

	@Test
	public void testGet_six_k_factorial() 
	{
		BigInteger result = BigInteger.ONE;
		
		result = PiCalculatorMain.get_six_k_factorial(result,1);
        assertTrue( result.equals(new BigInteger("720")) );

		result = PiCalculatorMain.get_six_k_factorial(result,2);
        assertTrue( result.equals(new BigInteger("479001600")) );

		result = PiCalculatorMain.get_six_k_factorial(result,3);
        assertTrue( result.equals(new BigInteger("6402373705728000")) );
	}

	@Test
	public void testGet_three_k_factorial() 
	{
		BigInteger result = BigInteger.ONE;
		
		result = PiCalculatorMain.get_three_k_factorial(result,1);
        assertTrue( result.equals(new BigInteger("6")) );

		result = PiCalculatorMain.get_three_k_factorial(result,2);
        assertTrue( result.equals(new BigInteger("720")) );

		result = PiCalculatorMain.get_three_k_factorial(result,3);
        assertTrue( result.equals(new BigInteger("362880")) );
	}

	@Test
	public void testGet_numerator_constant() 
	{
		BigInteger result = BigInteger.valueOf(13591409L);;
		
		result = PiCalculatorMain.get_numerator_constant(result);
        assertTrue( result.equals(new BigInteger("558731543")) );

		result = PiCalculatorMain.get_numerator_constant(result);
        assertTrue( result.equals(new BigInteger("1103871677")) );

		result = PiCalculatorMain.get_numerator_constant(result);
        assertTrue( result.equals(new BigInteger("1649011811")) );
	}

	@Test
	public void testGet_k_factorial_cubed() 
	{
		BigInteger result = BigInteger.ONE;
		
		result = PiCalculatorMain.get_k_factorial_cubed(1);
        assertTrue( result.equals(new BigInteger("1")) );

		result = PiCalculatorMain.get_k_factorial_cubed(2);
        assertTrue( result.equals(new BigInteger("8")) );

		result = PiCalculatorMain.get_k_factorial_cubed(3);
        assertTrue( result.equals(new BigInteger("216")) );
	}

	@Test
	public void testGet_neg_640320_to_the_3k() 
	{
		BigInteger result = BigInteger.ONE;
		
		result = PiCalculatorMain.get_neg_640320_to_the_3k(result);
        assertTrue( result.equals(new BigInteger("-262537412640768000")) );

		result = PiCalculatorMain.get_neg_640320_to_the_3k(result);
        assertTrue( result.equals(new BigInteger("68925893036108889235415629824000000")) );

		result = PiCalculatorMain.get_neg_640320_to_the_3k(result);
        assertTrue( result.equals(new BigInteger("-18095625621654356959022098935941777779064832000000000")) );
	}

	@Test
	public void testGet_426880_sqrt_10005() 
	{
		BigInteger result       = PiCalculatorMain.get_426880_sqrt_10005(100);
        assertTrue( result.equals(new BigInteger("426986706663333958177128891606596082733208840025090828008380071788526051574575942163017999114556686013221760")) );
	}

}
