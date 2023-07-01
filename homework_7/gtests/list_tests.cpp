#include <gtest/gtest.h>
#include <list>


// создание контейнера
TEST(list, create) {
    std::list<int> v{};
    ASSERT_TRUE(v.empty());
    v.push_back(0);
    ASSERT_FALSE(v.empty());
}

// вставка элементов в конец
TEST(list, push_back) {
    std::list<int> v{1,2,3};
    v.push_back(6);

    ASSERT_FALSE(v.back()!= 6);
}

// вставка элемента в начало
TEST(list, insert_begin) {
    std::list<int> v{ 5, 4, 3, 2, 1 };
    v.insert(v.begin(), 6);

    ASSERT_TRUE(v.front()==6);
}

// вставка элемента в середину
TEST(list, insert_middle) {
    std::list<int> v{ 5, 4, 3, 2, 1 };

    auto mid = v.begin(); 
    for(int i=0; i < (v.size()/2);++i)
    {
        ++mid;
    }
    v.emplace(mid, 6);

    auto mid2 = v.end();
    for(int i=0; i < (v.size()/2);++i)
    {
        --mid2;
    }

    ASSERT_TRUE(mid == mid2);
}

// удаление элементов из концаx
TEST(list, pop_back) {
    std::list<int> v{ 3, 2, 1 };
    v.pop_back();

    ASSERT_TRUE(v.front()==3);
    ASSERT_TRUE(v.back()==2);
    ASSERT_TRUE(v.size()==2);
}

// удаление элементов из начала
TEST(list, erase_begin) {
    std::list<int> v{ 3, 2, 1 };
    v.pop_front();

    ASSERT_TRUE(v.front()==2);
    ASSERT_TRUE(v.back()==1);
    ASSERT_TRUE(v.size()==2);
}

// удаление элементов из середины
TEST(list, erase_middle) {
    std::list<int> v{ 3, 2, 1 };
    auto iter1 = v.cbegin();
    ++iter1;
    v.erase (iter1);

    ASSERT_TRUE(v.front()==3);
    ASSERT_TRUE(v.back()==1);
    ASSERT_TRUE(v.size()==2);
}

// получение элементов из контейнера
TEST(list, get_element) {
    std::list<int> v{ 3, 2, 1 };

    ASSERT_TRUE(v.front()==3);
}

// получение размера контейнера (фактическое количество элементов)
TEST(list, get_size) {
    std::list<int> v{ 3, 2, 1 };

    ASSERT_TRUE(v.size()==3);
}

// ёмкость list больше либо равна его размеру
TEST(list, size_capacity) {
    std::list<int> v{ 3, 2, 1 };
    std::list<int> v2{ 4, 3, 2, 1 };
        
    ASSERT_LE(v.size(), v2.size());
}
