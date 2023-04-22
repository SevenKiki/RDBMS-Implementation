// Tuples 

#ifndef TUPLES_H_
#define TUPLES_H_

#include "cell.hpp"
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <list>
using namespace std;

# define MAX_ELEMENTS 10

/**
* n个属性的tuple实现
*/
class tuples 
{
private:
        int num_of_elements;
        // 存储元组所有数据的容器
        set<set<cell,cellComparator> > elements;
        vector<cell> velements;
public:
        // 默认构造函数
        tuples();
        // 构造函数
        tuples(cell elm1, cell elm2);
        tuples(cell elm1, cell elm2, cell elm3);
        tuples(cell elm1, cell elm2, cell elm3, cell elm4);
        tuples(cell elm1, cell elm2, cell elm3, cell elm4, cell elm5);
        tuples(cell elm1, cell elm2, cell elm3, cell elm4, cell elm5, cell elm6);
        tuples(cell elm1, cell elm2, cell elm3, cell elem4, cell elm5, cell elm6, cell elm7);
        tuples(cell elm1, cell elm2, cell elm3, cell elem4, cell elm5, cell elm6, cell elm7, cell elm8);
        tuples(cell elm1, cell elm2, cell elm3, cell elem4, cell elm5, cell elm6, cell elm7, cell elm8, cell elm9);
        tuples(cell elm1, cell elm2, cell elm3, cell elem4, cell elm5, cell elm6, cell elm7, cell elm8, cell elm9, cell elm10);
        tuples(std::list<cell> cells);
        tuples(std::vector<cell> cells);
        /**
        *  @brief getter 元组属性容器.
        *  @return  元组属性集合.
        */        
        set<set<cell, cellComparator> > get_elements();
        vector<cell> get_velements();
        /**
        *  @brief 从tuple中根据index找到属性
        *  @param index 需要查找的属性对应index
        *  @return  cell 给定index返回的cell
        */
        cell get(int index);
        /**
        *  @brief 一个元组的String表示
        *  @return  该元组属性的string表示
        * 
        *  将一个元组的属性用string表示，属性之间空格分开，用括号括起全部属性
        */        
        std::string toString();
        /**
        *  @brief Getter 元组的属性数
        *  @return  Int 元组的属性数.
        */
        int get_num_of_elements();
        /**
        *  @brief 判断两个元组是否相等
        *  @param tup1 左元组
        *  @param tup2 右元组
        *  @return 如果两元组包括相同的item，返回true；否则返回false
        */
        static bool isEqual(tuples tup1, tuples tup2);
};

/**
* 元组的比较方式.
*/
struct tuplesComparator {
    bool operator()(tuples lhs, tuples rhs) const{
        return lhs.toString() < rhs.toString();
        // return 1<2;
    }
};

#endif 