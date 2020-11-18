/* Benjamin Ferkol
 * Algorithms: linked list work
*/

#include <iostream>
#include <assert.h>
#include <algorithm>
#include "intset.h"

using namespace std;

Intset::Intset()
{
    head = NULL;
}

Intset::~Intset()
{
    while (head != NULL) remove(head->key);
}

// Return true if key is in the set
bool Intset::find(int key)
{
    for (Node *n = head; n != NULL; n = n->next)
        if (n->key == key) return true;
    return false;
}

// Inserts a new key, it is an error if key is already in the set
void Intset::insert(int key)
{
    assert (!find(key));

    // Insert at beginning of list, swap down list until
    // in correct location
    head = new Node(key, head);
    for (Node *n = head; n->next != NULL && n->next->key < n->key; n = n->next)
        swap(n->key, n->next->key);
}

// Removes a key.  It is an error if key isn't in the set
void Intset::remove(int key)
{
    assert (find(key));

    // Delete head node?
    if (head->key == key) {
        Node *to_delete = head;
        head = head->next;
        delete to_delete;
    } else {
        // Walk down list and stop one node before the one to delete
        Node *n = head;
        while (n->next->key != key) n = n->next;
        Node *to_delete = n->next;
        n->next = to_delete->next;
        delete to_delete;
    }
}

// Prints out the list
void Intset::print(void)
{
    for (Node *n = head; n != NULL; n = n->next)
        cout << n->key << "\n";
}
