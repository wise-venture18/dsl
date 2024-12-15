"""Write a Python program to store marks scored in subject Fundamental of 
Data Structure by N students in the class. Write functions to compute 
following: 
a) The average score of class 
b) Highest score and lowest score of class 
c) Count of students who were absent for the test 
d)Display mark with highest frequency"""

#CODE :

n = int(input("Enter No. Of Students: "))

present, total_sum, min_score, max_score, absent = 0, 0, 101, -1, 0
marks = []

for i in range(n):
    temp = input("Enter Marks Of Student " + str(i + 1) + " or 'AB': ")
    if temp.upper() == "AB":
        marks.append("AB")
        absent += 1
    else:
        temp = int(temp)
        marks.append(temp)
        present += 1
        total_sum += temp
        if temp > max_score:
            max_score = temp
        if temp < min_score:
            min_score = temp

# Calculate average
average = total_sum / present if present > 0 else 0

# Find mark with the highest frequency
mx_f = 0
most_frequent_marks = []
for i in range(0, 101):
    f = 0
    for j in marks:
        if j != "AB" and j == i:
            f += 1
    if f > mx_f:
        mx_f = f
        most_frequent_marks = [i]
    elif f == mx_f and f > 0:
        most_frequent_marks.append(i)

# Display results
print(f"\nAverage score of the class: {average:.2f}")
print(f"Highest score in the class: {max_score}")
print(f"Lowest score in the class: {min_score}")
print(f"Number of students absent for the test: {absent}")
print(f"Mark(s) with the highest frequency: {', '.join(map(str, most_frequent_marks))}")
