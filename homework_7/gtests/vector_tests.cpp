#include <gtest/gtest.h>
#include <vector>

// создание контейнера
TEST(vector, create) {
    std::vector<int> v{1};

    ASSERT_TRUE(v[0]==1);
}

// вставка элементов в конец
TEST(vector, push_back) {
    std::vector<int> v{};
    v.push_back(6);

    ASSERT_FALSE(v[0]!=6);
}

// вставка элемена в начало
TEST(vector, insert_begin) {
    std::vector<int> v{ 5, 4, 3, 2, 1 };
    v.insert(v.begin(), 6);

    ASSERT_TRUE(v[0]==6);
}

//вставка элементов в середину
TEST(vector, insert_middle) {
    std::vector<int> v{ 5, 4, 3, 2, 1 };
    v.insert((v.begin() + (v.size()/2)), 6);

    ASSERT_TRUE(v[v.size()/2 - 1] == 6);
}

// удаление элементов из концаx
TEST(vector, pop_back) {
    std::vector<int> v{ 3, 2, 1 };
    v.pop_back();

    ASSERT_TRUE(v.at(0)==3);
    ASSERT_TRUE(v.at(1)==2);
    ASSERT_TRUE(v.size()==2);
}

// удаление элементов из начала
TEST(vector, erase_begin) {
    std::vector<int> v{ 3, 2, 1 };
    v.erase (v.begin());

    ASSERT_TRUE(v.at(0)==2);
    ASSERT_TRUE(v.at(1)==1);
    ASSERT_TRUE(v.size()==2);
}

// удаление элементов из середины
TEST(vector, erase_middle) {
    std::vector<int> v{ 3, 2, 1 };
    v.erase (v.begin()+v.size()/2);

    ASSERT_TRUE(v.at(0)==3);
    ASSERT_TRUE(v.at(1)==1);
    ASSERT_TRUE(v.size()==2);
}

// получение элементов из контейнера
TEST(vector, get_element) {
    std::vector<int> v{ 3, 2, 1 };

    ASSERT_TRUE(v.at(0)==3);
}

// получение размера контейнера (фактическое количество элементов)
TEST(vector, get_size) {
    std::vector<int> v{ 3, 2, 1 };

    ASSERT_TRUE(v.size()==3);
}

// ёмкость вектора больше либо равна его размеру
TEST(vector, size_capacity) {
    std::vector<int> v{ 3, 2, 1 };
    
    ASSERT_LE(v.size(), v.capacity());
}