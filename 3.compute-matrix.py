"""
Write a Python program to compute following computation on matrix: 
a) Addition of two matrices  
B) Subtraction of two matrices 
c) Multiplication of two matrices  
d) Transpose of a matrix
"""

""" 
INPUT Example :- 
Matrix Operations Program
Enter the number of rows: 2
Enter the number of columns: 3

Input for Matrix 1:
Enter the elements of the matrix (2x3):
Row 1: 1 2 3
Row 2: 4 5 6

Input for Matrix 2:
Enter the elements of the matrix (2x3):
Row 1: 7 8 9
Row 2: 10 11 12
"""

#CODE:-
# Function to add two matrices
def add_matrices(matrix1, matrix2):
    rows = len(matrix1)
    cols = len(matrix1[0])
    result = []
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    return result

# Function to subtract two matrices
def subtract_matrices(matrix1, matrix2):
    rows = len(matrix1)
    cols = len(matrix1[0])
    result = []
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(matrix1[i][j] - matrix2[i][j])
        result.append(row)
    return result

# Function to multiply two matrices
def multiply_matrices(matrix1, matrix2):
    rows_matrix1 = len(matrix1)
    cols_matrix1 = len(matrix1[0])
    cols_matrix2 = len(matrix2[0])
    result = [[0] * cols_matrix2 for _ in range(rows_matrix1)]
    for i in range(rows_matrix1):
        for j in range(cols_matrix2):
            for k in range(cols_matrix1):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    return result

# Function to transpose a matrix
def transpose_matrix(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    result = [[0] * rows for _ in range(cols)]
    for i in range(rows):
        for j in range(cols):
            result[j][i] = matrix[i][j]
    return result

# Function to display a matrix
def display_matrix(matrix):
    for row in matrix:
        print(' '.join(map(str, row)))

# Function to take input for a matrix
def input_matrix(rows, cols):
    print(f"Enter the elements of the matrix ({rows}x{cols}):")
    matrix = []
    for i in range(rows):
        row = list(map(int, input(f"Row {i + 1}: ").split()))
        matrix.append(row)
    return matrix

# Main program
def main():
    print("Matrix Operations Program")
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))

    print("\nInput for Matrix 1:")
    matrix1 = input_matrix(rows, cols)
    
    print("\nInput for Matrix 2:")
    matrix2 = input_matrix(rows, cols)

    while True:
        print("\nMenu:")
        print("1. Add Matrices")
        print("2. Subtract Matrices")
        print("3. Multiply Matrices")
        print("4. Transpose Matrix 1")
        print("5. Transpose Matrix 2")
        print("6. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            print("\nResult of Addition:")
            result = add_matrices(matrix1, matrix2)
            display_matrix(result)
        elif choice == 2:
            print("\nResult of Subtraction:")
            result = subtract_matrices(matrix1, matrix2)
            display_matrix(result)
        elif choice == 3:
            print("\nResult of Multiplication:")
            result = multiply_matrices(matrix1, matrix2)
            display_matrix(result)
        elif choice == 4:
            print("\nTranspose of Matrix 1:")
            result = transpose_matrix(matrix1)
            display_matrix(result)
        elif choice == 5:
            print("\nTranspose of Matrix 2:")
            result = transpose_matrix(matrix2)
            display_matrix(result)
        elif choice == 6:
            print("Exiting the program.")
            break
        else:
            print("Invalid choice! Please select a valid option.")

# Run the program
main()
