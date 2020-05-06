/*
 Celem zadania jest napisanie polimorficznej listy połączonej.
 Jej węzłami są obiekty, które mogą przechowywać różne typy.

 Lista połączona to łańcuch kolejnych węzłów, z których
 każdy posiada wskaźnik na kolejny węzeł.

 head
 _|__        ____           	  ____
|__|*| ---> |__|*| ---> ... ---> |__|*| ---> nullptr 

 Proszę stworzyć odpowiednią hierarchnię klas - węzłów.
 Proszę trochę przemyśleć, co powinno być w klasie bazowej.
 
 Następnie proszę stworzyć klasę PLinkedList, która 
 przechowuje wskażnik na początek listy. 
 Pamiętamy, że dla pustej listy jest to nullptr.
 Jej konstruktory i operatory= są "głośne".
 Listę tę można kopiować i przenosić (patrz funkcja main).

 Uwaga: 
 - tematem jest napisanie listy połączonej. Obejście
 problemu przez użycie vectora i innych kontenerów jest 
 zadaniem nie na temat.

 Tips:
 - konstruktor i operator= przenoszący są bardzo krótkie.

 */

#include "PLinkedList.h"
#include "Nodes.h"
#include <iostream>
#include <vector>

PLinkedList copyList(PLinkedList l){
  std::cout << "=== in copyList: " << l.head() << std::endl;
  return l;
}

PLinkedList createList(){
  PLinkedList tmp;
  Node * n = new NodeString("nowy");
  tmp.addFront(n);
  std::cout << "=== tmp node addr. " << tmp.head() << std::endl;
  delete n;
  return tmp;
}

int main() {
  NodeInt * n1 = new NodeInt(12);
  n1->print();
  std::cout << std::endl;
  NodeString *n2 = new NodeString("kitku");
  n2->print();

  std::cout << "\n========= Linked List =========" << std::endl;

  PLinkedList list;
  list.addFront(n1).addFront(n2).addFront(n1);
  std::cout << "list: " << list << std::endl; 
  delete n2;  // lista nadal działa

  std::cout << "=========== moving ===========" << std::endl;

  PLinkedList list2 = copyList(list);
  std::cout << "=== after moving " << list2.head() << ", " << list.head() << std::endl;
  list.addFront(n1);
  std::cout << "list: " << list << std::endl;
  std::cout << "list2: " << list2 << std::endl;
  delete n1;

  list2 = createList();
  std::cout << "=== after move assign " << list2.head() << std::endl;
}
/* wynik

12
kitku
========= Linked List =========
list: 12 -> kitku -> 12
=========== moving ===========
--- copying list: 12 -> kitku -> 12
=== in copyList: <addr1>
--- moving list: 12 -> kitku -> 12
=== after moving <addr1>, <addr2>
list: 12 -> 12 -> kitku -> 12
list2: 12 -> kitku -> 12
=== tmp node addr. <addr3>
--- move assign: nowy
=== after move assign <addr3>

 */

// W domu można jeszcze napisać operator przypisania kopiującego.
// Przykład użycia:
// list2 = list = list;
// std::cout << "list2: " << list2 << std::endl; 