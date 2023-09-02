import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);

		// Read the double value from the user.
		System.out.println("Enter a double value:");
		double number = scanner.nextDouble();

		// Close the scanner.
		scanner.close();

		// Echo the double with a minimum field width of 7 and 3 digits after the decimal point.
		System.out.printf("%7.3f\n", number);
	}
}
