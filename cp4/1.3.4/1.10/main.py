import re

def replace_special_words(string: str) -> str:
  return re.sub(r'\b[a-z]\d{2}\b', '***', string)

STRING = "a70 and z72 will be replaced, aa24 and a872 will not"

result = replace_special_words(STRING)

print(result)
