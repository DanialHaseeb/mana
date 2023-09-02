def convert_base(number: str, source_base: int, target_base: int) -> str:
	# Convert from base X to base 10
	number_10 = int(number, source_base)

	# Convert from base 10 to base Y
	if (target_base == 10):
		return str(number_10)

	if (number_10 == 0):
		return "0"

	digits = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
	                     "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
	                     "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
	                     "U", "V", "W", "X", "Y", "Z"]

	number_y = ""

	while (number_10 != 0):
		(number_10, remainder) = divmod(number_10, target_base)
		number_y += digits[remainder]

	return number_y

# Test the function
print(convert_base("FF", 16, 10))  # Should print "255"
print(convert_base("11111111", 2, 10))  # Should print "255"
