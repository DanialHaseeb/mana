def evaluate_expression(expression: str) -> float:
	result = eval(expression)
	return float(result)

# Example:
expression = "3 +(8-7.5)*10/5-(2+5*7)"
result = evaluate_expression(expression)
print(result)  # Output should be -33.0
