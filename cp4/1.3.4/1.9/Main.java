/**
 * Competitive Programming 4
 *
 * 1.3.4.1.9
 *
 * @author Danial Haseeb
 */

import java.math.*;

class Main
{
	public static void main(String[] args)
	{
		String str = "FF";
		int X = 16;
		int Y = 10;

		System.out.println(new BigInteger(str, X).toString(Y));
	}
}
