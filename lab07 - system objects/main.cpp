/*
  Celem zadania jest napisanie hierarchii klas opisującej składniki systemu plików.
   Składnikami tymi sa katalog (klasa Dir) i plik (klasa File), i może przydałaby się jeszcze jakaś klasa. 
   Pliki mają nazwę i rozmiar (podawany w nawiasach), katalogi nazwę i tablicę podrzędnych składników systemu plików.
   Prosze uniemożliwić dziedziczenie po klasie Dir i uzasadnić słownie w komentarzu.
   
   UWAGA:
  * Nazwy składników systemu plików proponuję przechowywać w std::string
  * Implementacja klasy Dir może opierać się o std::vector (już wszyscy powinni go znać),
    ew. tablicę ograniczoną do 20 elementów). Tablica musi być tylko jedna wspólna dla plików i katalogów.
  * Aby zapewnic wypisywanie z wcięciami, klasy te powinny posiadac metodę print z argumentem informujacym, 
    ile spacji potrzeba wypisac przed nazwa (indentacja).
  * Podczas kopiowania przydana bedzie polimorficzna metoda kopiujaca wywoływana przez copy.

 */
 
#include <iostream>
#include "Dir.h"
#include "File.h"

int main() {
  std::cout << "------- Level 1 -------\n";
  Dir *top = new Dir(".");
  Dir *home = new Dir("home");
  *top += home; // adding new dir
  Dir *stud1 = new Dir("stud1");
  *home += stud1;
  Dir *stud2 = new Dir("stud2");
  *home += stud2;  
  std::cout << const_cast<const Dir&>(*top) <<std::endl;

  std::cout << "------- Level 2 -------\n";
  *stud1 += new File("img1.jpg",2020);
  *stud1 += new File("img2.jpg");
  Dir* work = new Dir("work");
  *work += new File("main.h",150);
  *work += new File("proj.h",175);
  *stud1 += work;
  std::cout << *home <<std::endl;
  
  std::cout << "------- Level 3 -------\n";
  stud2->copy(stud1->getDir("work")); // creating copy
  if (stud1->getDir("img1.jpg")) 
    std::cout << "**** IT SHOULDN'T BE IN OUTPUT ****\n";
  stud2->copy(stud1->get("img1.jpg"));
  *work += new Dir("tmp");
  Dir *tmp = static_cast<Dir*>(work->getDir("tmp"));
  *tmp += new Dir("cpp");
  std::cout << *(stud1->getDir("work"));
  
  //deleting
  *work -= "tmp";
  *work -= "proj.h";

  *work += new File("main.cpp"); // w dir: home/stud1/work will appear new file
                                 // main.cpp, which is not in home/stud2/work 
  
  std::cout << "\n------ All folders -------" << std::endl;
  std::cout << *top;
  std::cout << "\n------- Cleaning -------" << std::endl;
  delete top;
}

/* expected output 
./main
------- Level 1 -------
. (dir)
  home (dir)
    stud1 (dir)
    stud2 (dir)

------- Level 2 -------
home (dir)
  stud1 (dir)
    img1.jpg (2020)
    img2.jpg (0)
    work (dir)
      main.h (150)
      proj.h (175)
  stud2 (dir)

------- Level 3 -------
work (dir)
  main.h (150)
  proj.h (175)
  tmp (dir)
    cpp (dir)
Destructor Dir: tmp
Destructor Dir: cpp
---Destructor File: proj.h

------ All folders -------
. (dir)
  home (dir)
    stud1 (dir)
      img1.jpg (2020)
      img2.jpg (0)
      work (dir)
        main.h (150)
        main.cpp (175)
    stud2 (dir)
      work (dir)
        main.h (150)
        proj.h (175)
      img1.jpg (2020)

------- Cleaning -------
Destructor Dir: .
Destructor Dir: home
Destructor Dir: stud1
---Destructor File: img1.jpg
---Destructor File: img2.jpg
Destructor Dir: work
---Destructor File: main.h
---Destructor File: main.cpp
Destructor Dir: stud2
Destructor Dir: work
---Destructor File: main.h
---Destructor File: proj.h
---Destructor File: img1.jpg
 */ 