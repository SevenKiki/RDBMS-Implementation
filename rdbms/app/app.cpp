#include "../util/cell.hpp"
#include "../operations/operations.hpp"
#include "../operations/rSchema.hpp"
#include "../operations/table.hpp"
#include "../util/tuples.hpp"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/variant.hpp>
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
    string datainput;
    vector<string> result;
    map<std::string, table> tableMap;
    map<std::string, rSchema> rschemaMap;
    system("clear");
    cout << "enter the comand separating it with a single space\n";
    do
    {
        cout << ">>  ";
        getline(cin, datainput);
        boost::trim(datainput);
        boost::split(result, datainput, boost::is_any_of(" "));
        boost::algorithm::to_lower(result[0]);

        // create table ...  or create rschema ...
        if (result[0] == "create")
        {
            if (result.size() <= 1)
            {
                cout << "error: you have to specify what you want to do\n";
            }
            else
            {
                boost::algorithm::to_lower(result[1]);
                if (result[1] == "table")
                {
                    if (result.size() <= 2)
                    {
                        cout << "error: no relational schema name\n";
                    }
                    else
                    {
                        if (result.size() <= 3)
                            cout << "error: no table name inserted\n";
                        else
                        {
                            if (rschemaMap.find(result[3]) == rschemaMap.end())
                                cout << "error: the relational schema doesnt exist\n";
                            else
                            {
                                tableMap.emplace(result[2], table(rschemaMap.at(result[3])));
                                cout << result[2] << " table created\n";
                                result.clear();
                            }
                        }
                    }
            }
            else if (result[1] == "rschema")
            {
                if (result.size() <= 2)
                {
                    cout << "error: you have to specify the name of the relational schema\n";
                }
                else if (result.size() <= 3)
                    cout << "error: yo need to insert the atribute names\n";
                else if (result.size() == 5)
                {
                    rschemaMap.emplace(result[2], rSchema(result[2], tuples(result[3], result[4])));
                    cout << result[2] << " rschema created\n";
                    result.clear();
                }
                else if (result.size() == 6){
                    rschemaMap.emplace(result[2], rSchema(result[2], tuples(result[3], result[4], result[5])));
                    cout << result[2] << " rschema created\n";
                    result.clear();
                }
                else if (result.size() == 7){
                    rschemaMap.emplace(result[2], rSchema(result[2], tuples(result[3], result[4], result[5], result[6])));
                    cout << result[2] << " rschema created\n";
                    result.clear();
                }
                else if (result.size() == 8){
                    rschemaMap.emplace(result[2], rSchema(result[2], tuples(result[3], result[4], result[5], result[6], result[7])));
                    cout << result[2] << " rschema created\n";
                    result.clear();
                }
                else if (result.size() == 9){
                    rschemaMap.emplace(result[2], rSchema(result[2], tuples(result[3], result[4], result[5], result[6], result[7], result[8])));
                    cout << result[2] << " rschema created\n";
                    result.clear();
                }
                else if (result.size() == 10){
                    rschemaMap.emplace(result[2], rSchema(result[2], tuples(result[3], result[4], result[5], result[6], result[7], result[8],  result[9])));
                    cout << result[2] << " rschema created\n";
                    result.clear();
                }
                else if (result.size() == 11){
                    rschemaMap.emplace(result[2], rSchema(result[2], tuples(result[3], result[4], result[5], result[6], result[7], result[8], result[9], result[10])));
                    cout << result[2] << " rschema created\n";
                    result.clear();
                }

            }
            else
            {
                cout << "error: unknown comand\n";
            }
        }
        }

        // insert ...
        else if (result[0] == "insert")
        {
            if (result.size() <= 1)
                cout << "error: you have to insert the table name then the row data\n";
            else
            {
                if (result.size() <= 2)
                    cout << "error: you have to insert the row data\n";
                else
                {
                    if (tableMap.find(result[1]) == tableMap.end())
                        cout << "error: the table doesnt exist\n";
                    else
                    {
                        if (result.size() >= 13) // 两个属性对应5， 三个属性对应6，十个属性对应13
                            cout << "you cant insert this amount of data in this table\n";
                        else if (result.size() == 4)
                        {
                            tableMap.at(result[1]).add_row(tuples(result[2], result[3]));
                            cout << "data inserted to " << result[1] << endl;
                        }
                        else if(result.size() == 5)
                        {
                            tableMap.at(result[1]).add_row(tuples(result[2], result[3], result[4], result[5]));
                            cout << "data inserted to " << result[1] << endl;
                        }
                        else if(result.size() == 6)
                        {
                            tableMap.at(result[1]).add_row(tuples(result[2], result[3], result[4], result[5], result[6]));
                            cout << "data inserted to " << result[1] << endl;
                        }
                        else if(result.size() == 7)
                        {
                            tableMap.at(result[1]).add_row(tuples(result[2], result[3], result[4], result[5], result[6], result[7]));
                            cout << "data inserted to " << result[1] << endl;
                        }
                        else if(result.size() == 8)
                        {
                            tableMap.at(result[1]).add_row(tuples(result[2], result[3], result[4], result[5], result[6], result[7], result[8]));
                            cout << "data inserted to " << result[1] << endl;
                        }
                        else if(result.size() == 9)
                        {
                            tableMap.at(result[1]).add_row(tuples(result[2], result[3], result[4], result[5], result[6], result[7], result[8], result[9]));
                            cout << "data inserted to " << result[1] << endl;
                        }
                        else if(result.size() == 10)
                        {
                            tableMap.at(result[1]).add_row(tuples(result[2], result[3], result[4], result[5], result[6], result[7], result[8], result[9], result[10]));
                            cout << "data inserted to " << result[1] << endl;
                        }
                    }
                }
            }
        }

        // remove row ... or remove table ...
        else if (result[0] == "remove")
        {
            boost::algorithm::to_lower(result[1]);
            if (result.size() <= 1)
                cout << "error: you have to specify what you want to remove\n";
            else if (result[1] == "row")
            {
                if (result.size() <= 2)
                    cout << "error: you have to insert the table name then the row to be removed\n";
                else
                {
                    if (result.size() <= 3)
                        cout << "error: you have to insert the row to be removed\n";
                    else
                    {
                        if (tableMap.find(result[2]) == tableMap.end())
                            cout << "error: the table doesnt exist\n";
                        else
                        {
                            tableMap.at(result[2]).remove_row(tuples(result[3], result[4]));
                            cout << "data removed from: " << result[2] << endl;
                        }
                    }
                }
            }
            else if (result[1] == "table")
            {
                if (result.size() <= 2)
                    cout << "error: you have to input the table name\n";
                else
                {
                    if (tableMap.find(result[2]) == tableMap.end())
                        cout << "error: the table doesnt exist\n";
                    else
                        {
                            tableMap.erase(result[2]);
                            cout<<result[2]<<" table removed\n";
                        }
                }
            }
            else
            {
                cout << "unknown " << result[2] << " command\n";
            }
        }

        // display ...
        else if (result[0] == "display")
        {
            if (result.size() <= 1)
                cout << "error: you have to input the table name\n";
            else
            {
                if (tableMap.find(result[1]) == tableMap.end())
                    cout << "error: the table doesnt exist\n";
                else
                {
                    cout << tableMap.at(result[1]).get_tableRSchema().toString() << "\n";
                    for (auto tableRow : tableMap.at(result[1]).get_rows())
                    {
                        cout << tableRow.toString() << "\n";
                    }
                }
            }
        }

        // database ...
        else if(result[0]=="database")
        {
            cout<<"\nRelational Schemas:";
            cout<<"\n===================\n";
            for (auto const &pair : rschemaMap)
            {
                std::cout << rschemaMap.at(pair.first).toString() << "\n\n";
            }
            cout<<"\nTables:";
            cout<<"\n=======\n";
            for (auto const &pair : tableMap)
            {
                std::cout << pair.first << "\n";
                std::cout << tableMap.at(pair.first).get_tableRSchema().toString() << "\n\n";
            }
        }
        
        //union table1 table2
        else if (result[0] == "union")
        {
            if (result.size() <= 1)
                cout << "error: insert the first table name\n";
            else
            {
                if (result.size() <= 2)
                    cout << "error: you have to input the second table name\n";
                else
                {
                    if (tableMap.find(result[1]) == tableMap.end() and tableMap.find(result[2]) == tableMap.end())
                        cout << "error: the table or tables doesnt exist\n";
                    else
                    {
                        if (tableMap.at(result[1]).get_tableRSchema().toString() == tableMap.at(result[2]).get_tableRSchema().toString())
                        {
                            cout << operations::runion(tableMap.at(result[1]), tableMap.at(result[2])).toString();
                        }
                        else
                        {
                            cout << "they are not in the same relational schema\n";
                        }
                    }
                }
            }
        }

        // intersect table1 table2
        else if (result[0] == "intersect")
        {
            if (result.size() <= 1)
                cout << "error: insert the first table name\n";
            else
            {
                if (result.size() <= 2)
                    cout << "error: you have to input the secont table name\n";
                else
                {
                    if (tableMap.find(result[1]) == tableMap.end() and tableMap.find(result[2]) == tableMap.end())
                        cout << "error: the table or tables doesnt exist\n";
                    else
                    {
                        if (tableMap.at(result[1]).get_tableRSchema().toString() == tableMap.at(result[2]).get_tableRSchema().toString())
                            cout << operations::intersection(tableMap.at(result[1]), tableMap.at(result[2])).toString();
                        else
                        {
                            cout << "they are not in the same relational schema\n";
                        }
                    }
                }
            }
        }

        //difference table1 table2 (相同rschema才能比较)
        else if (result[0] == "difference")
        {
            if (result.size() <= 1)
                cout << "error: insert the first table name\n";
            else
            {
                if (result.size() <= 2)
                    cout << "error: you have to input the secont table name\n";
                else
                {
                    if (tableMap.find(result[1]) == tableMap.end() and tableMap.find(result[2]) == tableMap.end())
                        cout << "error: the table or tables doesnt exist\n";
                    else
                    {
                        if (tableMap.at(result[1]).get_tableRSchema().toString() == tableMap.at(result[2]).get_tableRSchema().toString())
                            cout << operations::difference(tableMap.at(result[1]), tableMap.at(result[2])).toString();
                        else
                        {
                            cout << "they are not in the same relational schema\n";
                        }
                    }
                }
            }
        }

        // project table column1 column2 column...
        else if (result[0] == "project")
        {
            if (result.size() <= 1)
                cout << "error: insert the table name\n";
            else
            {
                if (result.size() <= 2)
                    cout << "error: you have to input attribute name\n";
                else
                {
                    if (tableMap.find(result[1]) == tableMap.end() and tableMap.find(result[2]) == tableMap.end())
                        cout << "error: the table or tables doesnt exist\n";
                    else
                    {
                        cout << operations::projection(tableMap.at(result[1]), result[2]).toString();
                    }
                }
            }
        }

        // revisit implementation
        else if (result[0] == "select")
        {
            if (result.size() <= 1)
                cout << "error: you have to input the table name\n";
            else
            {
                if (tableMap.find(result[1]) == tableMap.end())
                    cout << "error: the table or tables doesnt exist\n";
                else
                {
                    if (result.size() <= 2)
                        cout << "error: you have to input the attribute\n";
                    else
                    {
                        if (result.size() <= 3)
                            cout << "error: you have to input the data to be selected\n";
                        else
                            cout << operations::selection(tableMap.at(result[1]), result[2], result[3]).toString();
                    }
                }
            }
        }

        // njoin <table1 name> <table2 name> <comp1> <comp2> <joining atribute from the 1st table> <joining atribute from the second table>
        else if (result[0] == "njoin")
        {
            if (result.size() <= 1)
                cout << "error: insert the first table name\n";
            else
            {
                if (result.size() <= 2)
                    cout << "error: you have to input the second table name\n";
                else
                {
                    if (tableMap.find(result[1]) == tableMap.end() and tableMap.find(result[2]) == tableMap.end())
                        cout << "error: the table or tables doesnt exist\n";
                    else
                    {
                        if (result.size() <= 3)
                            cout << "error: you have to input the comparators\n";
                        else
                        {
                            if (result.size() <= 4)
                                cout << "error: you have to input the second comparator and the atrributes\n";
                            else
                            {
                                if (result.size() <= 5)
                                    cout << "error: you have to input the atributes\n";
                                else
                                {
                                    if (result.size() <= 6)
                                        cout << "error: you have to input the second attribute\n";
                                    else
                                    {
                                        cout << operations::natural_join(tableMap.at(result[1]), tableMap.at(result[2]), result[3], result[4], result[5], result[6]).toString();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        else if (result[0] == "copy"){
            if (result.size() <= 1)
                cout << "error: you have to input table name\n";
            else
            {
                if (result.size() <= 2)
                    cout << "error: you have to input file path\n";
                else
                {
                    if (tableMap.find(result[1]) == tableMap.end())
                        cout << "error: the table doesnt exist\n";
                    else
                    {
                        cout << operations::copy(tableMap.at(result[1]), result[2]).toString();
                    }
                }
            }
        }

        // clear
        else if (result[0] == "cls")
        {
            system("clear");
        }

        // 退出系统
        else
        {
            if (result[0] != "exit")
                cout << "unknown command\n";
        }
        result.clear();
    } while (datainput != "exit");
    return 0;
}