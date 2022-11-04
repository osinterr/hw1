#include <gtest/gtest.h>
#include "include/Matrix.hpp"

TEST(Test1, vector1){
    double arr1[] = {1, 2, 3};
    Vector v1('l', 3, arr1);
    double arr2[] = {4, 5, 6};
    Vector v2('l', 3, arr2);

    double arr_ans[] = {5, 7, 9};
    Vector v_ans('l', 3, arr_ans);


    ASSERT_TRUE((v1+v2)==v_ans);
}

TEST(Test2, vector2){
    double arr1[] = {1, 2, 3};
    Vector v1('l', 3, arr1);
    double arr2[] = {4, 5, 6};
    Vector v2('l', 3, arr2);

    double arr_ans[] = {3, 3, 3};
    Vector v_ans('l', 3, arr_ans);


    ASSERT_TRUE((v2-v1)==v_ans);
}

TEST(Test3, vector3){
    double arr1[] = {1, 2, 3};
    Vector v1('l', 3, arr1);
    double arr2[] = {4, 5, 6};
    Vector v2('l', 3, arr2);

    double arr_ans[] = {4, 10, 18};
    Vector v_ans('l', 3, arr_ans);


    ASSERT_TRUE((v2*v1)==v_ans);
}
































TEST(Test4, matrix4){
    double arr1[] = {1, 2, 3, 4};
    Matrix m1(2, 2, arr1);
    double arr2[] = {4, 5, 6, 8};
    Matrix m2(2, 2, arr2);

    double arr_ans[] = {5, 7, 9, 12};
    Matrix m_ans(2, 2, arr_ans);


    ASSERT_TRUE((m1+m2)==m_ans);
}

TEST(Test5, matrix5){
    double arr1[] = {1, 2, 3, 4};
    Matrix m1(2, 2, arr1);
    double arr2[] = {4, 5, 6, 8};
    Matrix m2(2, 2, arr2);

    double arr_ans[] = {3, 3, 3, 4};
    Matrix m_ans(2, 2, arr_ans);


    ASSERT_TRUE((m2-m1)==m_ans);
}


TEST(Test6, matrix6){
    double arr1[] = {1, 2, 3, 4};
    Matrix m1(2, 2, arr1);
    double arr2[] = {4, 5, 6, 8};
    Matrix m2(2, 2, arr2);

    double arr_ans[] = {4, 10, 18, 32};
    Matrix m_ans(2, 2, arr_ans);


    ASSERT_TRUE((m1*m2)==m_ans);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
