"""Write a Python program to store marks scored in subject Fundamental of 
Data Structure by N students in the class. Write functions to compute 
following: 
a) The average score of class 
b) Highest score and lowest score of class 
c) Count of students who were absent for the test 
d)Display mark with highest frequency"""

#CODE :
def enter_marks(n, marks):
    present, absent, total_sum, min_score, max_score = 0, 0, 0, 101, -1
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
    return present, absent, total_sum, min_score, max_score


def calculate_statistics(marks):
    total_sum, min_score, max_score, present = 0, 101, -1, 0

    for m in marks:
        if m != "AB":
            total_sum += m
            present += 1
            if m > max_score:
                max_score = m
            if m < min_score:
                min_score = m

    average = total_sum / present if present > 0 else 0
    return average, min_score, max_score


def find_highest_frequency(marks):
    frequency = [0] * 101  # To store frequency of marks from 0 to 100
    for m in marks:
        if m != "AB":
            frequency[m] += 1

    max_frequency = max(frequency)  # Find the highest frequency
    most_frequent_marks = []  # Create an empty list to store the marks
    for i in range(len(frequency)):  # Loop through each index (marks) in the frequency list
        if frequency[i] == max_frequency and max_frequency > 0:  # Check if the frequency matches the max frequency
            most_frequent_marks.append(i)  # Add the mark to the list


    return most_frequent_marks, max_frequency


# Main Program
marks = []
present, absent, total_sum, min_score, max_score = 0, 0, 0, 101, -1

while True:
    print("\nMenu:")
    print("1. Enter Marks")
    print("2. Calculate Average, Highest, and Lowest Score")
    print("3. Display Number of Students Absent")
    print("4. Find Most Frequent Marks")
    print("5. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        n = int(input("Enter Number of Students: "))
        present, absent, total_sum, min_score, max_score = enter_marks(n, marks)
        print("Marks entered successfully.")

    elif choice == 2:
        average, min_score, max_score = calculate_statistics(marks)
        print(f"\nAverage score of the class: {average:.2f}")
        print(f"Highest score in the class: {max_score}")
        print(f"Lowest score in the class: {min_score}")

    elif choice == 3:
        print(f"\nNumber of students absent for the test: {absent}")

    elif choice == 4:
        most_frequent_marks, max_frequency = find_highest_frequency(marks)
        print(f"\nMark(s) with the highest frequency ({max_frequency} times): {', '.join(map(str, most_frequent_marks))}")

    elif choice == 5:
        print("Exiting the program.")
        break

    else:
        print("Invalid choice! Please select a valid option.")

