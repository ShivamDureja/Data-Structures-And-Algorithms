#include <iostream>
#include <algorithm>

void rotate_image(int a[][4], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::reverse(a[i], a[i] + n);
    }

    //take transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i<j)
                std::swap(a[i][j], a[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int a[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Rotated matrix-" << std::endl;
    rotate_image(a, 4);
    return 0;
}