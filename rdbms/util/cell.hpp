// Cell

#ifndef CELL_H_
#define CELL_H_
#include <set>
#include <string>
using namespace std;


/**
* 表中单个数据值的数据类型
* 保存RDMS所支持的所有预选数据类型
*/
typedef std::string cell;


struct cellComparator 
{
    bool operator()(cell lhs, cell rhs) const 
        {
            return lhs < rhs;
        }
};
#endif  /*CELL_H*/