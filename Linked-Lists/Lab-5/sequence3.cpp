#include <cstdlib>  // Provides size_t
#include <iostream>
#include <cassert>
#include <algorithm>
#include "sequence3.h"
#include "node1.h"  // Provides node class

using namespace std;

namespace LAB_05_ALUEBKE
{
	sequence::sequence()
	{
		head_ptr = NULL;
		tail_ptr = NULL;
		cursor = NULL;
		precursor = NULL;
		many_nodes = 0;
	}

	sequence::sequence(const sequence& source)
	{
		/*if(source.many_nodes == 0)
		{
			list_copy(source.head_ptr, head_ptr, tail_ptr);
			cursor = NULL;
			precursor = NULL;
		}

		else if(source.many_nodes == 1)
		{
			list_copy(source.head_ptr, head_ptr, tail_ptr);
			cursor = head_ptr;
			precursor = NULL;
		}

		else
		{*/
			size_t i = 1;
			list_copy(source.head_ptr, head_ptr, tail_ptr);
			for(cursor = source.head_ptr; cursor != source.cursor; cursor = cursor->link())
			{
				i++;
			}

			cursor = list_locate(head_ptr, i);
			if(i == 1)
			{
				precursor = NULL;
			}
			else
			{
				precursor = list_locate(head_ptr, (i-1));
			}
		//}

		many_nodes = source.many_nodes;
	}

	sequence::~sequence()
	{
		list_clear(head_ptr);
		many_nodes = 0;
	}

	void sequence::start()
	{
		cursor = head_ptr;
		precursor = NULL;
	}

	void sequence::advance()
	{
		precursor = cursor;
		cursor = cursor -> link();
	}

	void sequence::insert(const value_type& entry)
	{
		if (head_ptr == NULL)
		{
			list_head_insert(head_ptr, entry);
			cursor = head_ptr;
			precursor = NULL;
			//tail_ptr = head_ptr;
		}

		else if (cursor == NULL || precursor == NULL)
        {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            precursor = NULL;
        }

		else
		{
			list_insert(precursor, entry);
			cursor = precursor -> link();
		}

		++many_nodes;
	}

	void sequence::attach(const value_type& entry)
	{
		if (head_ptr == NULL)
		{
			list_head_insert(head_ptr, entry);
			cursor = head_ptr;
			precursor = NULL;
			tail_ptr = head_ptr;
		}

		else if (cursor == NULL)
        {
            list_insert(precursor, entry);
            cursor = precursor -> link();
        }

		else
		{
			list_insert(cursor, entry);
			precursor = cursor;
			cursor = cursor -> link();
		}

		++many_nodes;
	}

	void sequence::remove_current( )
	{
		assert (is_item());

		if(cursor == head_ptr)
		{
			cursor = cursor -> link();
			list_head_remove(head_ptr);
		}

		else
		{
			cursor = cursor -> link();
			list_remove(precursor);
		}

		--many_nodes;
	}

	sequence::value_type sequence::current( ) const
	{
		assert(is_item());
		return cursor->data();
	}

	void sequence::operator =(const sequence& source)
	{
		if(this == &source)
		{
			return;
		}
		list_clear(head_ptr);
		if(source.many_nodes == 0)
		{
			list_copy(source.head_ptr, head_ptr, tail_ptr);
			cursor = NULL;
			precursor = NULL;
		}

		else if(source.cursor == source.head_ptr)
		{
			list_copy(source.head_ptr, head_ptr, tail_ptr);
			cursor = head_ptr;
			precursor = NULL;
		}

		else
		{
			size_t i = 1;
			list_copy(source.head_ptr, head_ptr, tail_ptr);
			for(cursor = source.head_ptr; cursor != source.cursor; cursor = cursor->link())
			{
				++i;
			}

			cursor = list_locate(head_ptr, i);
			if(i == 1)
			{
				precursor = NULL;
			}
			else
			{
				precursor = list_locate(head_ptr, (i-1));
			}
		}

		many_nodes = source.many_nodes;
	}
}
