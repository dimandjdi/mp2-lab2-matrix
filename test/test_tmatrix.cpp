#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> a(5);
    TMatrix<int> b(5);
    TMatrix<int> c(5);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = i * 5 + j;
            b[i][j] = (i * 5 + j) * 50;
        }
    c = a;
    EXPECT_EQ(c, a);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> a(5);
    TMatrix<int> b(5);
    TMatrix<int> c(5);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = i * 5 + j;
            b[i][j] = (i * 5 + j) * 50;
        }
    c = a;
    EXPECT_NE(&c, &a);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> a(5);
    EXPECT_EQ(5, a.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> a(5);
    a[0][0] = 0;
    EXPECT_EQ(0, a[0][0]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> a(5);
    ASSERT_NO_THROW(a = a);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> a(5);
    TMatrix<int> b(5);
    TMatrix<int> c(5);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = i * 5 + j;
            b[i][j] = (i * 5 + j) * 50;
        }
    EXPECT_NO_THROW(a = b);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> a(5);
    TMatrix<int> b(5);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = i * 5 + j;
        }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            b[i][j] = (i * 5 + j);
        }
    ASSERT_TRUE(a == b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> a(5);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = i * 5 + j;
        }
    ASSERT_TRUE(a == a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> a(5);
    TMatrix<int> b(6);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = i * 5 + j;
        }
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
        {
            b[i][j] = (i * 5 + j) * 50;
        }
    ASSERT_FALSE(a == b);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> a(5);
    TMatrix<int> b(5);
    TMatrix<int> c(5);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = i * 5 + j;
            b[i][j] = (i * 5 + j) * 50;
        }
    ASSERT_NO_THROW(c = a + b);
}


TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> a(5);
    TMatrix<int> b(5);
    TMatrix<int> c(5);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = i * 5 + j;
            b[i][j] = (i * 5 + j) * 50;
        }
    ASSERT_NO_THROW(c = a - b);
}

