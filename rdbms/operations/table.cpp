#include "../util/cell.hpp"
#include "rSchema.hpp"
#include "table.hpp"
#include "../util/tuples.hpp"
#include <iostream>
#include <set>


// constructor
table::table() {}

table::table(rSchema spec) 
{
    this->tableSpec = spec;
};

// getter methods
std::string table::get_table_name() 
{
    return this->tableSpec.get_name();
}
tuples table::get_attributes() 
{
    return this->tableSpec.get_attributes();
}
rSchema table::get_tableRSchema() 
{
    return this->tableSpec;
}


void table::add_row(tuples rowTuple) 
{
    this->rows.insert(rowTuple);
}

void table::remove_row(tuples rowTuple) 
{
    this->rows.erase(rowTuple);
}

std::set<tuples, tuplesComparator> table::get_rows() 
{
    return this->rows;
}

void table::set_rows(std::set<tuples, tuplesComparator> rowSet) 
{
    this->rows = rowSet;
}

std::string table::toString() 
{
    std::string info = this->get_tableRSchema().toString() + "\n";
    for (auto row : table::get_rows()) 
    {
        info += row.toString() + "\n";
    }
    return info;
}