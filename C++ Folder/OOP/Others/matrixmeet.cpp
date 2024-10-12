#include <iostream>
#include <vector>

// Function to compute the meet of two boolean matrices
std::vector<std::vector<bool>> meetOfMatrices(const std::vector<std::vector<bool>> &matrix1, const std::vector<std::vector<bool>> &matrix2)
{
    // Initialize the meet matrix with the same size as the input matrices
    std::vector<std::vector<bool>> meet(matrix1.size(), std::vector<bool>(matrix1[0].size()));

    // Perform the meet operation (logical AND) element-wise
    for (size_t i = 0; i < matrix1.size(); i++)
    {
        for (size_t j = 0; j < matrix1[i].size(); j++)
        {
            meet[i][j] = matrix1[i][j] && matrix2[i][j];
        }
    }

    return meet;
}

int main()
{
    // Example usage
    std::vector<std::vector<bool>> matrix1 = {{true, false, true}, {false, true, false}};
    std::vector<std::vector<bool>> matrix2 = {{true, true, false}, {false, true, true}};

    // Compute the meet of the two matrices
    std::vector<std::vector<bool>> meet = meetOfMatrices(matrix1, matrix2);

    // Print the meet matrix
    std::cout << "Meet of the matrices:" << std::endl;
    for (const auto &row : meet)
    {
        for (bool value : row)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
