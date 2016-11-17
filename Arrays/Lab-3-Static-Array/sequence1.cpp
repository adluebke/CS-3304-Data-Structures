
/*
* Class: CS 3304/section07
* Term: Fall 2016
* Name: Andrew Luebke
* Instructor: Monisha Verma
* Assignment: Lab 3
 */


#include <iostream>
#include <cassert>
#include <cstdlib>
#include "sequence1.h"

using namespace std;

namespace Lab_03_ALUEBKE
{
    sequence::sequence ( )
    {
        current_index = 0;
        used = 0;
    }

    sequence::size_type sequence::size( ) const
    {
	return (used);
    }

    void sequence::start()
    {
        current_index = 0;
    }

    sequence::value_type sequence::current() const
    {
        return data[current_index];
    }

    void sequence::advance ( )
    {
		assert (is_item());
		current_index++;
    }

    bool sequence::is_item( ) const
    {
		return current_index < used;
    }

    void sequence::insert (const value_type& entry)
    {
		assert( size( ) < CAPACITY);
        assert( size( ) >= 0);

        if (current_index == used)
		{
			current_index = 0;
		}

		for (size_t i = used; i > current_index; --i)
		{
			data[i] = data[i-1];
		}

		data[current_index] = entry;
		++used;
		return;
    }

    void sequence::attach (const value_type& entry)
    {
	assert( size( ) < CAPACITY);
        assert( size( ) >= 0);


		if (current_index == used)
		{
			data[current_index] = entry;
			++used;
			return;
		}

		for (size_t i = used; i > current_index+1; --i)
		{
			data[i] = data[i-1];
		}

		++current_index;
		++used;
		data[current_index] = entry;
		return;
	}

    void sequence::remove_current( )
    {
		assert (is_item());
		if (current_index == (used - 1))
		{
			--used;
			return;
		}

		for (int i = current_index; i < (used - 1); ++i)
		{
			data[i] = data[i + 1];
		}
		--used;
		return;
	}

    ostream& operator <<(ostream& outs, const sequence& source)
    {
	outs << source.current() << " ";
	return outs;
    }




}
