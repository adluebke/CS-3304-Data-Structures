
/*
* Class: CS 3304/section07
* Term: Fall 2016
* Name: Andrew Luebke
* Instructor: Monisha Verma
* Assignment: Lab 4
 */


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include "sequence2.h"

using namespace std;

namespace Lab_04_ALUEBKE
{
	sequence::sequence(size_type initial_capacity)
    {
        capacity = initial_capacity;
        data = new value_type[capacity];
        current_index = 0;
        used = 0;
    }

  sequence::sequence(const sequence& entry)
   {
            capacity = entry.capacity;
                data = new value_type[capacity];
                used=entry.used;
                current_index = entry.current_index;
                copy(entry.data,entry.data+used,data);
   }

    sequence::~sequence()
    {
		delete [] data;
	}


   void sequence::start( )
   {
   		current_index = 0;
   }

   void sequence::advance( )
	{
        if(is_item())
        {
			current_index++;
		}
   }

   void sequence::insert(const value_type& entry)
	{
           if(used == capacity)
           {
                capacity = (capacity*1.1) + 1 ;
                resize(capacity);
           }

           if (!is_item() )
            {
				current_index = 0;
			}

           for (int i = used; i > current_index; i--)
           {
		   		data[i] = data[i-1];
		   }

           data[current_index] = entry;
           used++;
   }


   void sequence::attach(const value_type& entry)
   {
		if(used == capacity)
        {
            capacity = (capacity*1.1) + 1 ;
            resize(capacity);
            data[current_index+1] = entry;
        }

        if(!is_item())
        {
			data[current_index]=entry;
		}

    	else
        {
            for (int i = used; i > current_index+1; i--)
            {
				data[i] = data[i-1];
			}

            data[current_index+1] = entry;
            current_index++;
        }

        ++used;
   }
   void sequence::remove_current( )
   {
        if(is_item())
        {
            for (int i = current_index; i < used; i++)
            {
				data[i] = data[i+1];
			}

			used--;
        }
   }

   void sequence::operator =(const sequence& entry)
    {
        value_type *temp_data;
        capacity = entry.capacity;
        current_index = entry.current_index;
        used = entry.used;
        temp_data = new value_type [capacity];
        copy(data,data+used,temp_data);
        delete [ ] data;
        data = temp_data;
        copy(entry.data,entry.data+used,data);
  	}

   sequence::size_type sequence::size( ) const
   {
   		return used;
   }

   bool sequence::is_item( ) const
   {
   		return current_index < used;
   }

   sequence::value_type sequence::current( ) const
   {
   		return data[current_index];
	}

    void sequence::resize(size_type new_capacity )
    {
    	if(new_capacity > used)
        {
            value_type *array_block;
            capacity = new_capacity;
            array_block = new value_type[capacity];
            copy(data,data+used,array_block);
            delete [] data;
            data = array_block;
        }
    }
}
