"""Write a python program to store first year percentage of students in array. 
Write function for sorting array of floating point numbers in ascending order 
using quick sort and display top five scores."""

#CODE:-
def quicksort(arr, low, high):
    if low < high:
        # Partition the array
        pi = partition(arr, low, high)
        # Recursively sort elements before and after partition
        quicksort(arr, low, pi - 1)
        quicksort(arr, pi + 1, high)


def partition(arr, low, high):
    pivot = arr[high]  # Take the last element as pivot
    i = low - 1  # Index of the smaller element
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Swap elements
    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Swap pivot element
    return i + 1


def display_top_five(arr):
    n = len(arr)
    print("\nTop 5 scores are:")
    # Print top 5 scores or fewer if there are less than 5 elements
    for i in range(min(5, n)):
        print(f"{arr[n - 1 - i]:.2f}")


def main():
    # Input student percentages
    n = int(input("Enter the number of students: "))
    percentages = []
    for i in range(n):
        perc = float(input(f"Enter percentage for student {i + 1}: "))
        percentages.append(perc)

    # Sort the array using quicksort
    quicksort(percentages, 0, len(percentages) - 1)

    # Display sorted percentages
    print("\nSorted percentages in ascending order:")
    for perc in percentages:
        print(f"{perc:.2f}", end=" ")

    # Display the top 5 scores
    display_top_five(percentages)


main()
