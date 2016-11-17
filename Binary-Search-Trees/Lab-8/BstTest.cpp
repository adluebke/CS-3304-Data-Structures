#include <iostream>
#include "bst.h"
#include "node2.h"


using namespace LAB_08_ALUEBKE;
using namespace std;

typedef int data_type;

node<data_type>* head_ptr = NULL;
node<data_type>* cursor = NULL;

void feed_bst(data_type t)
{
    node<data_type>* prev = NULL;
    node<data_type>* curr = head_ptr;

    if(head_ptr == NULL)
    {
        list_head_insert(head_ptr, t);
    }
    else
    {
          while(curr != NULL)
          {
              prev = curr;
              curr = curr->link();
          }
          list_insert(prev, t);
    }

}

void print_list()
{
	node<data_type>* cursor = NULL;

	for(cursor = head_ptr; cursor != NULL; cursor=cursor->link())
	{
		cout << cursor->data() << " ";
	}
}

int main(int argc, char** argv)
{
	bst<data_type> sample;
	bool done;
	data_type answer;

	while(!done)
    {
        cout << "Please enter an integer, you can't input repeat values. Enter '999' when done: " << endl;
        cin >> answer;

        switch(answer)
        {
            case 999:
                done = true;
                break;

            default:
                sample.insert(answer);
                break;
        }

    }

    cout << endl;

    cout << "Inserting your values into a tree!" << endl;
        cout << endl;

    cout << "Passing them into a traversal function, then inserting them into a linked list." << endl;
	inorder(feed_bst, sample);
        cout << endl;

    cout << "Printing the linked list: ";
	print_list();
        cout << endl;


	return 0;
}
