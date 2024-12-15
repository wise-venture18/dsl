"""Write a Python program to store marks scored in subject Fundamental of 
Data Structure by N students in the class. Write functions to compute 
following: 
a) The average score of class 
b) Highest score and lowest score of class 
c) Count of students who were absent for the test 
d)Display mark with highest frequency"""

#CODE :
def Average(marks, present_count):
    sum_marks = 0
    for mark in marks:
        if isinstance(mark, int):  # Only add valid marks (not 'AB')
            sum_marks += mark
    if present_count > 0:
        return sum_marks / present_count
    return 0

def Highest(marks):
    highest = -1
    for mark in marks:
        if mark != 'AB' and mark > highest:
            highest = mark
    return highest

def Lowest(marks):
    lowest = 101
    for mark in marks:
        if mark != 'AB' and mark < lowest:
            lowest = mark
    return lowest

def Absent(marks):
    return marks.count('AB')

def HighestFrequency(marks):
    frequency = {}
    for mark in marks:
        if mark != 'AB':
            if mark in frequency:
                frequency[mark] += 1
            else:
                frequency[mark] = 1
    return frequency

# Main program to get user input and display results
n = int(input("Enter the number of students: "))

# Initialize variables
marks = []
present_count = 0

# Collect marks
print("Enter marks for each student (or 'AB' if absent):")
for i in range(n):
    mark = input(f"Student {i + 1}: ")
    
    if mark.upper() == 'AB':
        marks.append('AB')
    else:
        mark = int(mark)
        marks.append(mark)
        present_count += 1

# Call the functions
average = Average(marks, present_count)
highest_score = Highest(marks)
lowest_score = Lowest(marks)
absent_count = Absent(marks)
frequency = HighestFrequency(marks)

# Find the most frequent mark using if-else
if frequency:
    most_frequent_mark = max(frequency, key=frequency.get)
else:
    most_frequent_mark = None

# Display results
print(f"\nAverage score of the class: {average:.2f}")
print(f"Highest score in the class: {highest_score}")
print(f"Lowest score in the class: {lowest_score}")
print(f"Number of students absent for the test: {absent_count}")
if most_frequent_mark is not None:
    print(f"Mark with the highest frequency: {most_frequent_mark}")
else:
    print("Mark with the highest frequency: No marks available")
