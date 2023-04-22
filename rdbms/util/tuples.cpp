#include "cell.hpp"
#include "tuples.hpp"
#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;


tuples::tuples(){}

tuples::tuples(cell elm1, cell elm2) 
{
  this->num_of_elements = 2;
  set<cell, cellComparator> cells;
  cells.insert(elm1);
  this->elements.insert(cells);
  cells.insert(elm2);
  this->elements.insert(cells);

  this->velements = vector<cell> {elm1, elm2};
}


tuples::tuples(cell elm1, cell elm2, cell elm3)
{
  this->num_of_elements = 3;
  set<cell, cellComparator> cells;
  cells.insert(elm1);
  this->elements.insert(cells);
  cells.insert(elm2);
  this->elements.insert(cells);
  cells.insert(elm3);
  this->elements.insert(cells);
  this->velements = vector<cell> {elm1, elm2, elm3};
}

tuples::tuples(cell elm1, cell elm2, cell elm3, cell elm4)
{
  this->num_of_elements = 4;
  set<cell, cellComparator> cells;
  cells.insert(elm1);
  this->elements.insert(cells);
  cells.insert(elm2);
  this->elements.insert(cells);
  cells.insert(elm3);
  this->elements.insert(cells);
  cells.insert(elm4);
  this->elements.insert(cells);

  this->velements = vector<cell> {elm1, elm2, elm3, elm4};

}

tuples::tuples(cell elm1, cell elm2, cell elm3, cell elm4, cell elm5)
{
  this->num_of_elements = 5;
  set<cell, cellComparator> cells;
  cells.insert(elm1);
  this->elements.insert(cells);
  cells.insert(elm2);
  this->elements.insert(cells);
  cells.insert(elm3);
  this->elements.insert(cells);
  cells.insert(elm4);
  this->elements.insert(cells);
  cells.insert(elm5);
  this->elements.insert(cells);

  vector<cell> vcells = {elm1, elm2, elm3, elm4, elm5};
  this->velements = vcells;
}

tuples::tuples(cell elm1, cell elm2, cell elm3, cell elm4, cell elm5, cell elm6)
{
  this->num_of_elements = 6;
  set<cell, cellComparator> cells;
  cells.insert(elm1);
  this->elements.insert(cells);
  cells.insert(elm2);
  this->elements.insert(cells);
  cells.insert(elm3);
  this->elements.insert(cells);
  cells.insert(elm4);
  this->elements.insert(cells);
  cells.insert(elm5);
  this->elements.insert(cells);
  cells.insert(elm6);
  this->elements.insert(cells);
  this->velements = vector<cell> {elm1, elm2, elm3, elm4, elm5, elm6};
}

tuples::tuples(cell elm1, cell elm2, cell elm3, cell elm4, cell elm5, cell elm6, cell elm7)
{
  this->num_of_elements = 7;
  set<cell, cellComparator> cells;
  cells.insert(elm1);
  this->elements.insert(cells);
  cells.insert(elm2);
  this->elements.insert(cells);
  cells.insert(elm3);
  this->elements.insert(cells);
  cells.insert(elm4);
  this->elements.insert(cells);
  cells.insert(elm5);
  this->elements.insert(cells);
  cells.insert(elm6);
  this->elements.insert(cells);
  cells.insert(elm7);
  this->elements.insert(cells);

  this->velements = vector<cell> {elm1, elm2, elm3, elm4, elm5, elm6, elm7};
}

tuples::tuples(cell elm1, cell elm2, cell elm3, cell elm4, cell elm5, cell elm6, cell elm7, cell elm8)
{
  this->num_of_elements = 8;
  set<cell, cellComparator> cells;
  cells.insert(elm1);
  this->elements.insert(cells);
  cells.insert(elm2);
  this->elements.insert(cells);
  cells.insert(elm3);
  this->elements.insert(cells);
  cells.insert(elm4);
  this->elements.insert(cells);
  cells.insert(elm5);
  this->elements.insert(cells);
  cells.insert(elm6);
  this->elements.insert(cells);
  cells.insert(elm7);
  this->elements.insert(cells);
  cells.insert(elm8);
  this->elements.insert(cells);
  this->velements = vector<cell> {elm1, elm2, elm3, elm4, elm5, elm6, elm7, elm8};
}

tuples::tuples(cell elm1, cell elm2, cell elm3, cell elm4, cell elm5, cell elm6, cell elm7, cell elm8, cell elm9)
{
  this->num_of_elements = 9;
  set<cell, cellComparator> cells;
  cells.insert(elm1);
  this->elements.insert(cells);
  cells.insert(elm2);
  this->elements.insert(cells);
  cells.insert(elm3);
  this->elements.insert(cells);
  cells.insert(elm4);
  this->elements.insert(cells);
  cells.insert(elm5);
  this->elements.insert(cells);
  cells.insert(elm6);
  this->elements.insert(cells);
  cells.insert(elm7);
  this->elements.insert(cells);
  cells.insert(elm8);
  this->elements.insert(cells);
  cells.insert(elm9);
  this->elements.insert(cells);

    this->velements = vector<cell> {elm1, elm2, elm3, elm4, elm5, elm6, elm7, elm8, elm9};

}

tuples::tuples(cell elm1, cell elm2, cell elm3, cell elm4, cell elm5, cell elm6, cell elm7, cell elm8, cell elm9, cell elm10)
{
  this->num_of_elements = 10;
  set<cell, cellComparator> cells;
  cells.insert(elm1);
  this->elements.insert(cells);
  cells.insert(elm2);
  this->elements.insert(cells);
  cells.insert(elm3);
  this->elements.insert(cells);
  cells.insert(elm4);
  this->elements.insert(cells);
  cells.insert(elm5);
  this->elements.insert(cells);
  cells.insert(elm6);
  this->elements.insert(cells);
  cells.insert(elm7);
  this->elements.insert(cells);
  cells.insert(elm8);
  this->elements.insert(cells);
  cells.insert(elm9);
  this->elements.insert(cells);
  cells.insert(elm10);
  this->elements.insert(cells);
  this->velements = vector<cell> {elm1, elm2, elm3, elm4, elm5, elm6, elm7, elm8, elm9, elm10};

}

tuples::tuples(std::vector<cell> cells)
{
  int num = cells.size();
  int i = 1;
  if(num > MAX_ELEMENTS)
    cout << "error: the elements of tuple is too many, the max number of elements allowed is "<< MAX_ELEMENTS << endl;
  
  this->num_of_elements = num;
  if(num == 2){
    cell cell1 = cells[0];
    cell cell2 = cells[1];
    // tuples(cell1, cell2);
    this->num_of_elements = 2;
    set<cell, cellComparator> cells;
    cells.insert(cell1);
    this->elements.insert(cells);
    cells.insert(cell2);
    this->elements.insert(cells);
    this->velements = vector<cell> {cell1, cell2};
  }
  else if( num == 3){
    cell cell1 = cells[0], cell2 = cells[1], cell3 = cells[2];
    // tuples(cell1, cell2, cell3);
    this->num_of_elements = 3;
    set<cell, cellComparator> cells;
    cells.insert(cell1);
    this->elements.insert(cells);
    cells.insert(cell2);
    this->elements.insert(cells);
    cells.insert(cell3);
    this->elements.insert(cells);
    this->velements = vector<cell> {cell1, cell2, cell3};
  }
  else if( num == 4){
    cell cell1 = cells[0], cell2 = cells[1], cell3= cells[2], cell4 = cells[3];
    // tuples(cell1, cell2, cell3, cell4);
    this->num_of_elements = 4;
    set<cell, cellComparator> cells;
    cells.insert(cell1);
    this->elements.insert(cells);
    cells.insert(cell2);
    this->elements.insert(cells);
    cells.insert(cell3);
    this->elements.insert(cells);
    cells.insert(cell4);
    this->elements.insert(cells);

  this->velements = vector<cell> {cell1, cell2, cell3, cell4};
  }
  else if( num == 5){
    cell cell1 = cells[0], cell2 = cells[1], cell3= cells[2], cell4 = cells[3], cell5 = cells[4];
    // tuples(cell1, cell2, cell3, cell4, cell5);
    this->num_of_elements = 5;
    set<cell, cellComparator> cells;
    cells.insert(cell1);
    this->elements.insert(cells);
    cells.insert(cell2);
    this->elements.insert(cells);
    cells.insert(cell3);
    this->elements.insert(cells);
    cells.insert(cell4);
    this->elements.insert(cells);
    cells.insert(cell5);
    this->elements.insert(cells);
    
    cout <<"cell1 "<< cell1<<endl;

    vector<cell> vcells = {cell1, cell2, cell3, cell4, cell5};
    this->velements = vcells;
  }
  else if( num == 6){
    cell cell1 = cells[0], cell2 = cells[1], cell3= cells[2], cell4 = cells[3], cell5 = cells[4], cell6 = cells[5];
    // tuples(cell1, cell2, cell3, cell4, cell5, cell6);
    this->num_of_elements = 6;
    set<cell, cellComparator> cells;
    cells.insert(cell1);
    this->elements.insert(cells);
    cells.insert(cell2);
    this->elements.insert(cells);
    cells.insert(cell3);
    this->elements.insert(cells);
    cells.insert(cell4);
    this->elements.insert(cells);
    cells.insert(cell5);
    this->elements.insert(cells);
    cells.insert(cell6);
    this->elements.insert(cells);
    this->velements = vector<cell> {cell1, cell2, cell3, cell4, cell5, cell6};
  }
  else if( num == 7){
    cell cell1 = cells[0], cell2 = cells[1], cell3= cells[2], cell4 = cells[3], cell5 = cells[4], cell6 = cells[5], cell7 = cells[6];
    // tuples(cell1, cell2, cell3, cell4, cell5, cell6, cell7);
    this->num_of_elements = 7;
    set<cell, cellComparator> cells;
    cells.insert(cell1);
    this->elements.insert(cells);
    cells.insert(cell2);
    this->elements.insert(cells);
    cells.insert(cell3);
    this->elements.insert(cells);
    cells.insert(cell4);
    this->elements.insert(cells);
    cells.insert(cell5);
    this->elements.insert(cells);
    cells.insert(cell6);
    this->elements.insert(cells);
    cells.insert(cell7);
    this->elements.insert(cells);

    this->velements = vector<cell> {cell1, cell2, cell3, cell4, cell5, cell6, cell7};
  }
  else if( num == 8){
    cell cell1 = cells[0], cell2 = cells[1], cell3= cells[2], cell4 = cells[3], cell5 = cells[4], cell6 = cells[5], cell7 = cells[6], cell8 = cells[7];
    // tuples(cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8);
    this->num_of_elements = 8;
    set<cell, cellComparator> cells;
    cells.insert(cell1);
    this->elements.insert(cells);
    cells.insert(cell2);
    this->elements.insert(cells);
    cells.insert(cell3);
    this->elements.insert(cells);
    cells.insert(cell4);
    this->elements.insert(cells);
    cells.insert(cell5);
    this->elements.insert(cells);
    cells.insert(cell6);
    this->elements.insert(cells);
    cells.insert(cell7);
    this->elements.insert(cells);
    cells.insert(cell8);
    this->elements.insert(cells);
    this->velements = vector<cell> {cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8};
  }
  else if( num == 9){
    cell cell1 = cells[0], cell2 = cells[1], cell3= cells[2], cell4 = cells[3], cell5 = cells[4], cell6 = cells[5], cell7 = cells[6], cell8 = cells[7], cell9 = cells[8];
    // tuples(cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9);
    this->num_of_elements = 9;
    set<cell, cellComparator> cells;
    cells.insert(cell1);
    this->elements.insert(cells);
    cells.insert(cell2);
    this->elements.insert(cells);
    cells.insert(cell3);
    this->elements.insert(cells);
    cells.insert(cell4);
    this->elements.insert(cells);
    cells.insert(cell5);
    this->elements.insert(cells);
    cells.insert(cell6);
    this->elements.insert(cells);
    cells.insert(cell7);
    this->elements.insert(cells);
    cells.insert(cell8);
    this->elements.insert(cells);
    cells.insert(cell9);
    this->elements.insert(cells);

    this->velements = vector<cell> {cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9};
  }
  else if (num == 10){
    cell cell1 = cells[0], cell2 = cells[1], cell3= cells[2], cell4 = cells[3], cell5 = cells[4], cell6 = cells[5], cell7 = cells[6], cell8 = cells[7], cell9 = cells[8], cell10 = cells[9];
    // tuples(cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9, cell10);
    this->num_of_elements = 10;
  set<cell, cellComparator> cells;
  cells.insert(cell1);
  this->elements.insert(cells);
  cells.insert(cell2);
  this->elements.insert(cells);
  cells.insert(cell3);
  this->elements.insert(cells);
  cells.insert(cell4);
  this->elements.insert(cells);
  cells.insert(cell5);
  this->elements.insert(cells);
  cells.insert(cell6);
  this->elements.insert(cells);
  cells.insert(cell7);
  this->elements.insert(cells);
  cells.insert(cell8);
  this->elements.insert(cells);
  cells.insert(cell9);
  this->elements.insert(cells);
  cells.insert(cell10);
  this->elements.insert(cells);
  this->velements = vector<cell> {cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9, cell10};

  }

}
tuples::tuples(std::list<cell> cells)
{
  int num = cells.size();
  int i = 1;
  if(num > MAX_ELEMENTS)
    cout << "error: the elements of tuple is too many, the max number of elements allowed is "<< MAX_ELEMENTS << endl;

  this->num_of_elements = num;
  list<cell>::iterator itr;
  if( num == 2){
    cell cell1, cell2;
    cell1 = cells.front();
    cells.pop_front();
    cell2 = cells.front();
    cells.pop_front();

    // tuples(cell1, cell2);
    this->num_of_elements = 2;
    set<cell, cellComparator> cells;
    cells.insert(cell1);
    this->elements.insert(cells);
    cells.insert(cell2);
    this->elements.insert(cells);

    this->velements = vector<cell> {cell1, cell2};
  }
  else if( num == 3){
    cell cell1, cell2, cell3;
    cell1 = cells.front();
    cells.pop_front();
    cell2 = cells.front();
    cells.pop_front();
    cell3 = cells.front();
    cells.pop_front();

    tuples(cell1, cell2, cell3);
  }
  else if( num == 4){
    cell cell1, cell2, cell3, cell4;
    cell1 = cells.front();
    cells.pop_front();
    cell2 = cells.front();
    cells.pop_front();
    cell3 = cells.front();
    cells.pop_front();
    cell4 = cells.front();
    cells.pop_front();

    tuples(cell1, cell2, cell3, cell4);
  }
  else if( num == 5){
    cell cell1, cell2, cell3, cell4, cell5;
    cell1 = cells.front();
    cells.pop_front();
    cell2 = cells.front();
    cells.pop_front();
    cell3 = cells.front();
    cells.pop_front();
    cell4 = cells.front();
    cells.pop_front();
    cell5 = cells.front();
    cells.pop_front();

    tuples(cell1, cell2, cell3, cell4, cell5);
  }
  else if( num == 6){
    cell cell1, cell2, cell3, cell4, cell5, cell6;
    cell1 = cells.front();
    cells.pop_front();
    cell2 = cells.front();
    cells.pop_front();
    cell3 = cells.front();
    cells.pop_front();
    cell4 = cells.front();
    cells.pop_front();
    cell5 = cells.front();
    cells.pop_front();
    cell6 = cells.front();
    cells.pop_back();

    tuples(cell1, cell2, cell3, cell4, cell5, cell6);
  }
  else if( num == 7){
    cell cell1, cell2, cell3, cell4, cell5, cell6, cell7;
    cell1 = cells.front();
    cells.pop_front();
    cell2 = cells.front();
    cells.pop_front();
    cell3 = cells.front();
    cells.pop_front();
    cell4 = cells.front();
    cells.pop_front();
    cell5 = cells.front();
    cells.pop_front();
    cell6 = cells.front();
    cells.pop_back();
    cell7 = cells.front();
    cells.pop_back();

    tuples(cell1, cell2, cell3, cell4, cell5, cell6, cell7);
  }
  else if( num == 8){
    cell cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8;
    cell1 = cells.front();
    cells.pop_front();
    cell2 = cells.front();
    cells.pop_front();
    cell3 = cells.front();
    cells.pop_front();
    cell4 = cells.front();
    cells.pop_front();
    cell5 = cells.front();
    cells.pop_front();
    cell6 = cells.front();
    cells.pop_back();
    cell7 = cells.front();
    cells.pop_back();
    cell8 = cells.front();

    tuples(cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8);
  }
  else if( num == 9){
    cell cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9;
    cell1 = cells.front();
    cells.pop_front();
    cell2 = cells.front();
    cells.pop_front();
    cell3 = cells.front();
    cells.pop_front();
    cell4 = cells.front();
    cells.pop_front();
    cell5 = cells.front();
    cells.pop_front();
    cell6 = cells.front();
    cells.pop_back();
    cell7 = cells.front();
    cells.pop_back();
    cell8 = cells.front();
    cells.pop_back();
    cell9 = cells.front();
    cells.pop_back();
    tuples(cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9);
  }
  else if (num == 10){
    cell cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9, cell10;
    cell1 = cells.front();
    cells.pop_front();
    cell2 = cells.front();
    cells.pop_front();
    cell3 = cells.front();
    cells.pop_front();
    cell4 = cells.front();
    cells.pop_front();
    cell5 = cells.front();
    cells.pop_front();
    cell6 = cells.front();
    cells.pop_back();
    cell7 = cells.front();
    cells.pop_back();
    cell8 = cells.front();
    cells.pop_back();
    cell9 = cells.front();
    cells.pop_back();
    cell10 = cells.front();
    cells.pop_back();

    tuples(cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9, cell10);
  }
  else{
    cout << "error: the number of cells of tuple is not allowed." << endl;
  }
}


int tuples::get_num_of_elements(){
 return this->num_of_elements ;
}

set<set<cell, cellComparator> > tuples::get_elements()
{
  return this->elements;
}
vector<cell> tuples::get_velements()
{
  return this->velements;
}

cell tuples::get(int index) 
{
  // index 不符合规定
  if (index >= this->num_of_elements)
  {
    throw std::out_of_range ("index out of range ...");
  } 
  else{
    return this->velements[index];
  }

  /*
  //  只有一个元素，返回该元素
  else if (this->elements.size() == 1) 
  {
    return *this->elements.begin()->begin();
  }
  else if (index == 0) 
  {
    set<set<cell, cellComparator> >::iterator itr;
    for (itr = this->elements.begin(); itr != this->elements.end(); itr++) 
    {
      if (itr->size() == 1) 
      {
        return *itr->begin();
      }
    }
  }
  else //index != 0 
  {
    set<set<cell, cellComparator> >::iterator itr;
    std::set<cell, cellComparator>::iterator firstElmItr;  //index= 0 对应的set
    for (itr = this->elements.begin(); itr != this->elements.end(); itr++) 
    {
      if (itr->size() > 1) 
      {
        firstElmItr = itr->find(this->get(--index));
        if (itr->begin() == firstElmItr) 
        {
          return *(++(itr->begin()));
        }
        else 
        {
          return *itr->begin();
        }
      }
    }
  }
  */
}


std::string tuples::toString() 
{
  std::string info = "( ";
  for (int i = 0; i < this->elements.size(); i++) 
  {
    info += this->get(i) + " ";
  }
  info += ")";

  return info;
}

bool tuples::isEqual(tuples tup1, tuples tup2) 
{
  return tup1.get_velements() == tup2.get_velements();
}