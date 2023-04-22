// Relational table implementation -*- C++ -*-

#ifndef TABLE_H_
#define TABLE_H_
#include "rSchema.hpp"
#include "../util/tuples.hpp"
#include <iostream>
#include <set>


/**
* rdbms表的抽象类
*/
class table
{
private:
        /* data */
        rSchema tableSpec;  // 该表对应的relational schema 
        std::set<tuples, tuplesComparator> rows;    // 该表的tuples容器
public:
        // 默认构造函数
        table();
        // 构造函数
        table(rSchema spec);
        /**
        *  @brief Getter  表名
        *  @return 表名 String.
        */
        std::string get_table_name();

        /**
        *  @brief Getter 数据列（属性）
        *  @return tuple of table attributes.
        */  
        tuples get_attributes();

        /**
        *  @brief Getter 表模式.
        *  @return 表模式.
        */
        rSchema get_tableRSchema();

        /**
        *  @brief 给定列名，返回表中某一列的所有数据
        *  @param 某一列的属性名
        *  @return set of cell 某一列的所有数据
        */
        std::set<cell, cellComparator> get_column(std::string attribName);

        /**
        *  @brief 在表中插入一行数据
        *  @param 待插入数据
        */
        void add_row(tuples rowTuple);

        /**
        *  @brief 从表中删除一行数据
        *  @param 从表中要删除的数据行
        */
        void remove_row(tuples rowTuple);

        /**
        *  @brief 返回表中所有数据
        *  @return set of tuples 表中每一行数据
        */
        std::set<tuples, tuplesComparator> get_rows();

        /**
        *  @brief Setter 表中数据，方便一次性设定表值，而不需要每一次都调用add_row
        *  @param rowSet Set of tuples of data to be added in to the table
        */
        void set_rows(std::set<tuples, tuplesComparator> rowSet);
        /**
        *  @brief 返回表
        *  @return 表的元数据，以及表数据S
        */
        std::string toString();
};


struct tableComparator 
{
    bool operator()(table lhs, table rhs) 
    {
        return lhs.get_table_name() < rhs.get_table_name();
    }
};
#endif  /*TABLE_H_*/