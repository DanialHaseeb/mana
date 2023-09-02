from datetime import datetime

def day(date: datetime):
	days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
	return days[date.weekday()]

# Input date as yyyy-mm-dd.
date = input("Enter a date (yyyy-mm-dd): ")
format = "%Y-%m-%d"

past_date = datetime.strptime(date, format)
current_date = datetime.now()

# Calculate the day of the week and the number of days elapsed.
weekday = day(past_date)
days_elapsed = (current_date - past_date).days

print(f"The day of the week on {date} was {weekday}.")
print(f"Number of days elapsed since that day until today is {days_elapsed}.")
