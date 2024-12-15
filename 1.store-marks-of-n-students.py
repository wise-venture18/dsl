"""Write a Python program to store marks scored in subject Fundamental of 
Data Structure by N students in the class. Write functions to compute 
following: 
a) The average score of class 
b) Highest score and lowest score of class 
c) Count of students who were absent for the test 
d)Display mark with highest frequency"""

#CODE :
n = int(input("Enter the number of students: "))

# Initialize variables
marks = []
present_count = 0
sum_marks = 0
highest = -1
lowest = 101
absent_count = 0
frequency = {}

# Collect marks
print("Enter marks for each student (or 'AB' if absent):")
for i in range(n):
    mark = input(f"Student {i + 1}: ")
    
    if mark.upper() == 'AB':
        marks.append('AB')
        absent_count += 1
    else:
        mark = int(mark)
        marks.append(mark)
        present_count += 1
        sum_marks += mark

        # Update highest and lowest scores
        if mark > highest:
            highest = mark
        if mark < lowest:
            lowest = mark

        # Update frequency count
        if mark in frequency:
            frequency[mark] += 1
        else:
            frequency[mark] = 1

# Calculate average
if present_count > 0:
    average = sum_marks / present_count
else:
    average = 0

# Find mark with highest frequency
if frequency:
    most_frequent_mark = max(frequency, key=frequency.get)
else:
    most_frequent_mark = None

# Display results
print(f"\nAverage score of the class: {average:.2f}")
print(f"Highest score in the class: {highest}")
print(f"Lowest score in the class: {lowest}")
print(f"Number of students absent for the test: {absent_count}")
print(f"Mark with the highest frequency: {most_frequent_mark}")
