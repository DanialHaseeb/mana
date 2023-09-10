/**
 * Competitive Programming 4
 *
 * 1.3.4.1.10
 *
 * @author Danial Haseeb
 */

class Main
{
	public static void main(String[] args)
	{
		String S = "line: a70 and z72 will be replaced, aa24 and a872 won't";
		String regex = "\\b+[a-z][0-9][0-9]\\b+";

		S.replaceAll(regex, "***");

		System.out.println(S);
	}
}
