/**
 * Competitive Programming 4
 *
 * 1.3.4.1.11
 *
 * @author Danial Haseeb
 */

import java.math.*;

class Main
{
	public static void main(String[] args) throws Exception
	{
		BigInteger x = new BigInteger("48112959837082048697");

		String result = (x.isProbablePrime(10)) ? "Prime" : "Composite";

		System.out.println(result);
	}
}
