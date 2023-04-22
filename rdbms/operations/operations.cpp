#include "../util/cell.hpp"
#include "operations.hpp"
#include "rSchema.hpp"
#include "table.hpp"
#include "../util/tuples.hpp"
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <list>

table operations::runion(table R1, table R2)
{
    table t1;
    for (auto tableRow_T1 : R1.get_rows())
    {
        for (auto tableRow_T2 : R2.get_rows())
        {
            if (tableRow_T1.toString() != tableRow_T2.toString())
                t1.add_row(tableRow_T1);
        }
    }
    for (auto tableRow_T2 : R2.get_rows())
    {
        for (auto tableRow_T1 : R1.get_rows())
        {
            if (tableRow_T2.toString() != tableRow_T1.toString())
                t1.add_row(tableRow_T2);
        }
    }
    return t1;
}

table operations::intersection(table R1, table R2)
{
    table t1;
    for (auto tableRow_T1 : R1.get_rows())
    {
        for (auto tableRow_T2 : R2.get_rows())
        {
            if (tableRow_T1.toString() == tableRow_T2.toString())
                t1.add_row(tableRow_T1);
        }
    }
    for (auto tableRow_T2 : R2.get_rows())
    {
        for (auto tableRow_T1 : R1.get_rows())
        {
            if (tableRow_T2.toString() == tableRow_T1.toString())
                t1.add_row(tableRow_T2);
        }
    }
    return t1;
}

table operations::difference(table R1, table R2)
{
    table t1;
    for (auto tableRow_T1 : R1.get_rows())
    {
        for (auto tableRow_T2 : R2.get_rows())
        {
            if (tableRow_T1.toString() != tableRow_T2.toString())
                t1.add_row(tableRow_T1);
        }
    }
    return t1;
}

table operations::projection(table R1, string P)
{
    int g;
    table t1;
    int i = R1.get_tableRSchema().get_attributes().get_num_of_elements() - 1;
    while (i >= 0)
    {
        if (R1.get_tableRSchema().get_attributes().get(i) == P)
        {
            g = i;
            break;
        }
        else
            i--;
    }
    for (auto tableRow_T1 : R1.get_rows())
    {
        t1.add_row(tuples(tableRow_T1.get(g), tableRow_T1.get(g)));
    }
    return t1;
}

table operations::selection(table R1, string A, string S)
{
    table t1;
    int itr;
    int i1 = R1.get_tableRSchema().get_attributes().get_num_of_elements() - 1;

    // 找到目标属性S
    while (i1 >= 0)
    {
        if (R1.get_tableRSchema().get_attributes().get(i1) == A)
        {
            itr = i1;
            break;
        }
        else
            i1--;
    }
    // 查找目标属性值的行
    for (auto tableRow_T1 : R1.get_rows())
    {
        // cout << tableRow_T1.get(itr)<<endl;
        if (tableRow_T1.get(itr) == S){
            t1.add_row(tableRow_T1);
        }

    }
    return t1;
}

table operations::natural_join(table table1, table table2, string id1, string id2, string A1, string A2)
{
    int g, n, id_n1, id_n2;
    table t1;
    int i = table1.get_tableRSchema().get_attributes().get_num_of_elements() - 1;
    int l = table2.get_tableRSchema().get_attributes().get_num_of_elements() - 1;
    int i1 = table1.get_tableRSchema().get_attributes().get_num_of_elements() - 1;
    int l1 = table2.get_tableRSchema().get_attributes().get_num_of_elements() - 1;
    while (i1 >= 0)
    {
        if (table1.get_tableRSchema().get_attributes().get(i1) == id1)
        {
            id_n1 = i1;
            break;
        }
        else
            i1--;
    }
    while (l1 >= 0)
    {
        if (table2.get_tableRSchema().get_attributes().get(l1) == id2)
        {
            id_n2 = l1;
            break;
        }
        else
            l1--;
    }
    while (i >= 0)
    {
        if (table1.get_tableRSchema().get_attributes().get(i) == A1)
        {
            g = i;
            break;
        }
        else
            i--;
    }
    while (l >= 0)
    {
        if (table2.get_tableRSchema().get_attributes().get(l) == A2)
        {
            n = l;
            break;
        }
        else
            l--;
    }
    for (auto tableRow_T1 : table1.get_rows())
    {
        for (auto tableRow_T2 : table2.get_rows())
        {
            if (tableRow_T1.get(id_n1) == tableRow_T2.get(id_n2))
            {

                t1.add_row(tuples(tableRow_T1.get(g), tableRow_T2.get(n)));
            }
        }
    }
    return t1;
}


table operations::copy(table R1,  string filepath){
    int g;
    // table t1;
    ifstream inFile;
    cell buff;
    inFile.open(filepath, ios::in);
    // inFile.seekg(8 , ios::beg);  // 跳过xefxbbxbf
    if(!inFile.is_open())
        cout << "Failed to open " << filepath << endl;
    
    int num_elements = R1.get_tableRSchema().get_attributes().get_num_of_elements() - 1;
    list<cell> cells;

    cout << "File is open" << filepath << endl;
    int i = num_elements;
    
    while(inFile >> buff ){
        i = num_elements;
        // cout << buff << endl;
        vector<cell> result;
        boost::trim(buff);
        boost::split(result, buff, boost::is_any_of(","));
        R1.add_row(tuples(result));
        // cout << R1.toString()<<endl;
    }
    return R1;
}
