/********************************************************
 * main.cpp - In-Memory B-Tree main program file        *
 *                                                      *
 * Author:  Dias, Samuel Pereira. 2021                  *
 *                                                      *
 * Purpose:  Demonstration of B-Tree algorithms.        *
 *                                                      *
 * Restrictions: This code can only be used in classes  *
 *    of the author's Programming Techniques (Técnicas  *
 *    de Programação/IFMG/Campus Bambuí) course, being  *
 *    forbidden to copy and modify its content.         *
 *                                                      *
 * Warning: There may be intentional bugs in the code.  *
 ********************************************************/

#include <iostream>
#include <vector>
#include "node.h"
#include "mbtree.h"

using namespace std;

int main() {
   mbtree<int, 3> tree;
   int option, k;
   vector<int> inserting = {6, 5, 9, 7, 11, 1, 2, 3, 4, 8, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20};
   vector<int> removing = {6, 7, 2, 11, 3, 4, 1, 6, 7, 9};
   node<int, 3>* n = NULL;
   bool quit = false;

   do {
      cout << "\n\nB-Tree Testing\n" << endl;
      cout << "1. Insert a integer key" << endl;
      cout << "2. Remove a integer key" << endl;
      cout << "3. Search for a key" << endl;
      cout << "4. Print the tree" << endl;
      cout << "5. Run test-cases" << endl;
      cout << "6. Quit" << endl;
      cout << "\n> ";
      cin >> option;

      switch (option) {
         case 1:
            cout << "Enter an integer value to insert: ";
            cin >> k;
            tree.insert(k);
            break;
         case 2:
            cout << "Enter an integer value to remove: ";
            cin >> k;
            tree.remove(k);
            break;
         case 3:
            cout << "Enter an integer value to search: ";
            cin >> k;
            if (tree.search(n, k) >= 0 && n == NULL) {
               cout << "The value " << k << " was found into the tree." << endl;
            } else {
               cout << "The value " << k << " wasn't found into the tree." << endl;
            }
            break;
         case 4:
            tree.print();
            break;
         case 5:
            cout << "Insertion Test-Cases" << endl;
            for (int i : inserting) {
               cout << "\nInserting key " << i << ":" << endl;
               tree.insert(i);
               tree.print();
            }

            cout << "\nRemoval Test-Cases" << endl;
            for (int i : removing) {
               cout << "\nRemoving key " << i << ":" << endl;
               tree.remove(i);
               tree.print();
            }
            break;
         case 6:
            quit = true;
            break;
         default:
            cout << "Invalid option. Please try again.\n" << endl;
            break;
      }
   } while (!quit);

   return 0;
}
