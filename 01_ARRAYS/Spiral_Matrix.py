def spiralOrder(matrix):
    # Result list to store elements in spiral order
    res = []

    while matrix:
        # Step 1: Append the first row
        res.extend(matrix.pop(0))

        # Step 2: Append the last element of each remaining row
        if matrix and matrix[0]:  # Check if matrix is not empty
            for row in matrix:
                res.append(row.pop(-1))

        # Step 3: Append the last row in reverse order
        if matrix:
            res.extend(matrix.pop(-1)[::-1])

        # Step 4: Append the first element of each remaining row in reverse order
        if matrix and matrix[0]:
            for row in reversed(matrix):
                res.append(row.pop(0))

    # Final spiral order result
    return res


matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
print(spiralOrder(matrix))  # Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
