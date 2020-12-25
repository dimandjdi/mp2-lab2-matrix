#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
    TVector<int> v(10);
    TVector<int> v1(10);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i;
        v1[i] = 10 - i;
    }
    v1 = v;
    EXPECT_EQ(v[0], v1[0]);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> v(10);
    for (int i = 0; i < 10; ++i)
        v[i] = i;
    TVector<int> v1(v);
    v1 = v;
    EXPECT_NE(&v1, &v);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
    TVector<int> v(10);
    ASSERT_ANY_THROW(v[-1] = 0);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> v(10);
    ASSERT_ANY_THROW(v[9999999999] = 0);
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> v(10);
    ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> v(10);
    TVector<int> v1(10);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i;
        v1[i] = 10 - i;
    }
    ASSERT_NO_THROW(v = v1);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TVector<int> v(10);
    TVector<int> v1(11);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i;
        v1[i] = 10 - i;
    }
    v1[10] = 0;
    v = v1;
    EXPECT_EQ(11, v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> v(10);
    TVector<int> v1(11);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i;
        v1[i] = 10 - i;
    }
    v1[10] = 0;
    ASSERT_NO_THROW(v = v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> v(10);
    TVector<int> v1(10);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i;
        v1[i] = i;
    }
    ASSERT_TRUE(v == v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> v(10);
    TVector<int> v1(10);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i;
        v1[i] = i;
    }
    ASSERT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> v(10);
    TVector<int> v1(11);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i;
        v1[i] = i;
    }
    v1[10] = 0;
    ASSERT_FALSE(v == v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector<int> v(10);
    TVector<int> v1(10);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i;
        v1[i] = i;
    }
    ASSERT_NO_THROW(v + 3);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector<int> v(10);
    TVector<int> v1(10);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i;
        v1[i] = i;
    }
    ASSERT_NO_THROW(v - 3);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> v(10);
    TVector<int> v1(10);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i*2;
        v1[i] = i;
    }
    ASSERT_NO_THROW(v + v1);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> v(10);
    TVector<int> v1(11);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i*2;
        v1[i] = i;
    }
    v1[10] = 0;
    ASSERT_NO_THROW(v + v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> v(10);
    TVector<int> v1(10);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i * 10;
        v1[i] = i;
    }
    ASSERT_NO_THROW(v - v1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> v(10);
    TVector<int> v1(11);
    for (int i = 0; i < 10; ++i)
    {
        v[i] = i*10;
        v1[i] = i;
    }
    v1[10] = 0;
    ASSERT_NO_THROW(v - v1);
}


