"""Write a Python program to store second year percentage of students in array. 
Write function for sorting array of floating point numbers in ascending order 
using 
a) Insertion sort 
b) Shell Sort and display top five scores"""

#CODE:-
# Function to perform Insertion Sort
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        # Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

# Function to perform Shell Sort
def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2
    return arr

# Function to display top five scores
def display_top_five(arr):
    print("Top Five Scores:")
    for i in range(min(5, len(arr))):
        print(arr[i])

# Main program
percentages = []
n = int(input("Enter the number of students: "))
for i in range(n):
    percentage = float(input(f"Enter percentage of student {i + 1}: "))
    percentages.append(percentage)

# Menu loop
while True:
    print("\nMenu:")
    print("1. Sort using Insertion Sort (Ascending)")
    print("2. Sort using Shell Sort (Ascending)")
    print("3. Display Top Five Scores")
    print("4. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        # Insertion Sort
        sorted_percentages = insertion_sort(percentages.copy())
        print("\nSorted Percentages (Insertion Sort in Ascending Order):")
        print(sorted_percentages)
    elif choice == 2:
        # Shell Sort
        sorted_percentages = shell_sort(percentages.copy())
        print("\nSorted Percentages (Shell Sort in Ascending Order):")
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
