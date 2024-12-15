"""Write a Python program to store first year percentage of students in array. 
Write function for sorting array of floating point numbers in ascending order 
using 
a) Selection Sort 
b) Bubble sort and display top five scores"""

#CODE:-

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

# Function to perform Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:  # Compare for ascending order
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

# Function to display top five scores
def display_top_five(arr):
    sorted_arr = bubble_sort(arr)  # Sorting in ascending order
    sorted_arr.reverse()  # Reverse the list to get descending order
    print("Top Five Scores:")
    for i in range(min(5, len(sorted_arr))):
        print(sorted_arr[i])


# Main program
percentages = []
n = int(input("Enter the number of students: "))
for i in range(n):
    percentage = float(input(f"Enter percentage of student {i + 1}: "))
    percentages.append(percentage)

# Menu loop
while True:
    print("\nMenu:")
    print("1. Sort using Selection Sort (Ascending)")
    print("2. Sort using Bubble Sort (Ascending)")
    print("3. Display Top Five Scores")
    print("4. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        # Selection Sort
        sorted_percentages = selection_sort(percentages.copy())
        print("\nSorted Percentages (Selection Sort in Ascending Order):")
        print(sorted_percentages)
    elif choice == 2:
        # Bubble Sort
        sorted_percentages = bubble_sort(percentages.copy())
        print("\nSorted Percentages (Bubble Sort in Ascending Order):")
        print(sorted_percentages)
    elif choice == 3:
        # Display Top Five Scores
        display_top_five(percentages)
    elif choice == 4:
        # Exit
        print("Exiting the program.")
        break
    else:
        print("Invalid choice. Please enter a valid option.")
