# Conversion factors from metric to English units
conversion_factors = {
    'length': {
        'meters': {'inches': 39.3701, 'feet': 3.28084},
        'centimeters': {'inches': 0.393701},
    },
    'volume': {
        'liters': {'quarts': 1.05669},
    },
    'mass': {
        'kilograms': {'pounds': 2.20462},
        'grams': {'ounces': 0.035274},
    }
}

# Function to determine the category of a unit
def unit_category(unit):
    for category, units in conversion_factors.items():
        if unit in units:
            return category
    return None

# Function to perform the conversion
def convert(value, from_unit, to_unit):
    from_category = unit_category(from_unit)
    to_category = unit_category(to_unit)

    if from_category != to_category or from_category is None:
        return -1

    # Get the conversion factor
    factor = conversion_factors[from_category][from_unit].get(to_unit)
    if factor is None:
        return -1

    # Perform the conversion
    return value * factor

# Read the number of test cases
num_cases = int(input().strip())

# Process each test case
for _ in range(num_cases):
    words = input().strip().split()
    convert_to = words[2]
    convert_from = words[-1].removesuffix('?')
    try:
        quantity = float(words[-2])
    except ValueError:
        print(-1)
        continue

    result = convert(quantity, convert_from, convert_to)

    # Print the result
    print(result)
