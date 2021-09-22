#include <iostream>
#include "main.h"

 //#define ERROR1  
 //#define ERROR2  


int main() {
	const Point p(1.5, 3.0);
	std::cout << "Point " << p << std::endl;
	Circle circle(p, 3); 					

	Section ab(Point(0, 1), Point(-3, 5));

	Section diag1(Point(0.5, 1.0), Point(5.0, 1.0)), 
	        diag2(Point(2, 0), Point(2, 2));

	Deltoid delt1(diag1, diag2); 			

    Deltoid delt2(Point(0, 0), Point(2.5, 0), Point(2.5, 2.5), Point(0, 2.5));

	unsigned numObj = 4;
	Drawable *list[]{&circle, &ab, &delt1, &delt2};
	
	for (unsigned i = 0; i < numObj; ++i){
		std::cout << "\n*** Object " << i+1 << " ***\n";
		draw(list[i]); 
		std::cout << "Length/perimeter = " << list[i]->length() << std::endl;

		Transformable *t = dynamic_cast<Transformable*>(list[i]);
		if(t) t->shift(1.0, 1.0);
		draw(list[i]); 

		const ClosedShape *shape = dynamic_cast<const ClosedShape*>(list[i]);
		if(shape) std::cout << "Area = " << shape->area() << std::endl;
	}

	Transformable *t = &delt2;
	t->shift(2.0, 2.0);
	draw(&delt2);

	#ifdef ERROR1
	Drawable* d = t; 	// expected error "cannot convert ..."
	#endif
	#ifdef ERROR2
	Transformable* t2 = list[0]; 	//expected error "cannot convert ..."
	#endif
  return 0;
}

/* output
Point (1.5, 3)

*** Object 1 ***
Drowing a circle centered at (1.5, 3) with radius 3
Length/perimeter = 18.8496
Drowing a circle centered at (2.5, 4) with radius 3
Area = 28.2743

*** Object 2 ***
Drowing section from (0, 1) to (-3, 5)
Length/perimeter = 5
Drowing section from (1, 2) to (-2, 6)

*** Object 3 ***
Drawing a deltoid with vertices (0.5, 1), (2, 0), (5, 1), (2, 2)
Length/perimeter = 9.93011
Drawing a deltoid with vertices (1.5, 2), (3, 1), (6, 2), (3, 3)
Area = 9

*** Object 4 ***
Drawing a deltoid with vertices (0, 0), (2.5, 0), (2.5, 2.5), (0, 2.5)
Length/perimeter = 10
Drawing a deltoid with vertices (1, 1), (3.5, 1), (3.5, 3.5), (1, 3.5)
Area = 12.5
Drawing a deltoid with vertices (3, 3), (5.5, 3), (5.5, 5.5), (3, 5.5)
 */