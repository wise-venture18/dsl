"""6	B	Write Python program to store 10th class percentage of students in array. 
Write function for sorting array of floating point numbers in ascending order 
using radix sort and display top five scores	2	1,2,3,4"""


def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n  # Output array
    count = [0] * 10  # Count array for digits (0-9)

    # Store the count of occurrences in count[]
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[int(index)] += 1

    # Update count array to contain actual positions
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Build the output array
    for i in range(n - 1, -1, -1):  # Process in reverse for stable sort
        index = (arr[i] // exp) % 10
        output[count[int(index)] - 1] = arr[i]
        count[int(index)] -= 1

    # Copy output array back to arr
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    # Find the maximum number to determine the number of digits
    max_num = max(arr)

    # Perform counting sort for every digit
    exp = 1
    while max_num // exp > 0:
        counting_sort(arr, exp)
        exp *= 10

def main():
    # Take input for the number of students
    n = int(input("Enter the number of students: "))

    # Input percentages
    percentages = []
    print("Enter the percentages of students:")
    for i in range(n):
        percent = float(input(f"Student {i + 1}: "))
        percentages.append(percent)

    # Convert percentages to integers for radix sort
    scale_factor = 100  # Scaling factor to handle floating points
    scaled_percentages = []
    for percent in percentages:
        scaled_percentages.append(int(percent * scale_factor))

    # Sort the scaled array using radix sort
    radix_sort(scaled_percentages)

    # Convert sorted integers back to floating points
    sorted_percentages = []
    for value in scaled_percentages:
        sorted_percentages.append(value / scale_factor)

    # Display sorted percentages
    print("\nSorted Percentages:")
    for percent in sorted_percentages:
        print(percent)

    # Display top five scores
    top_five = sorted_percentages[-5:][::-1]  # Last 5 elements in descending order
    print("\nTop Five Scores:")
    for score in top_five:
        print(score)

# Run the program
main()
