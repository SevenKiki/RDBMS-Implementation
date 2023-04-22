// RDBMS 算子实现

#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include "../util/cell.hpp"
#include "rSchema.hpp"
#include "table.hpp"
#include "../util/tuples.hpp"
#include <iostream>
#include <set>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/variant.hpp>


class operations{
    public:
        /**
        *  @brief 在两表上进行union操作
        *  将两个表的数据添加到一个新表
        */  
        static table runion (table R1 ,table R2);
        /**
        *  @brief 在两个表上进行intersection操作
        *  当表中元组在两个表中都存在，将元组插入到新表中
        */ 
        static table intersection(table R1 ,table R2);
        /**
        *  @brief 在两表上进行difference操作
        *  当表中元组只存在本表，而不存在另外一个表中时，将元组插入到新表中
        */ 
        static table difference(table R1 ,table R2);
        /**
        *  @brief 在表R1中映射P对应属性值
        *  当P匹配某一个属性名时，将该属性所有值插入到新表中
        */        
        static table projection(table R1,string P);
        /**
        *  @brief 在表R1中筛选出属性A的值为S的元组
        *  当P匹配表中某一个属性名，且S匹配该属性中某一个值时，将该元组插入到新表中
        */
        static table selection(table R1 , string A , string S);
        /**
        *  @brief 自然连接两表 
        *  如果关系R1与R2具有相同的属性组B，且该属性组的值相等时的连接，结果关系的属性集合为R1的属性并上R2减去属性B的属性集合
        */
        static table natural_join(table R1 ,table R2, string id1,string id2,string A1 ,string A2);   
        /**
         * @brief 将filepath路径的文件(以.txt结尾)导入到table R1
         * @param R1 需要进行文件导入的表
         * @param filepath 文件对应的路径
         */
        static table copy(table R1, string filepath);


};

#endif  /*OPERATIONS_H_*/