# POO_Tema2_2
A doua tema la laboratorul de POO, tema 16 din lista (vectori de numere complexe)

Necessary files to compile and run: /main.cpp, , /vector.h

Sample input and output: /cmake-build-debug/test.in, /cmake-build-debug/test.out

Cerinte comune tuturor temelor:

	- DONE: supraincarcarea operatorilor << si >> pentru iesiri si intrari de obiecte, dupa indicatiile de mai jos, astfel incat sa fie permise (si ilustrate in program):

    - DONE: citirea de la tastatura si dintr-un fisier;

    - DONE: scrierea pe ecran sau intr-un fisier;

    - DONE: citirea informațiilor complete a n obiecte, memorarea și afisarea acestora

    - DONE: implementarea constructorului de copiere si supraincarcarea operatorului =, pentru fiecare clasa

    - DONE: supraincarcarea operatorului ==, a lui !=, si a lui < (pentru a putea compara 2 obiecte si a putea sorta un vector de obiecte folosind functia sort)

    - Template DONE: Pentru 1p in plus folositi template-uri. Pentru alt punct in plus folositi, cu sens, un design pattern singleton, iterator, observer, factory, etc. (https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns)
	
    - DONE: toate clase vor conține obligatoriu constructori de inițializare, parametrizati și de copiere, destructor, iar operatorii >>,<<,= să fie supraincarcati.
	
	- DONE: ilustrarea conceptelor de moștenire și functii virtuale (pure – unde se considera mai natural)
	
	- Accentul se pune pe mosteniri, functii virtuale. (Un design ce presupune functii virtuale pure/clase abastracte/interfete este apreciat)
	
	- Pentru fiecare 4 bucati de cod identificate ce cauzeaza memory leakuri se scad 0.5p.

Tema 2. vectori de numere complexe

	- Se dau urmatoarele clase: 
		- DONE: Complex (float re,im)
		- DONE: Vector (int dim, Complex *v).
		- DONE: Stiva : Vector - cu operatiile de adaugare și stergere modificate corespunzator.
		- DONE: Coada: Vector - cu operatiile de adaugare și stergere modificate corespunzator.

	- DONE: Clasele derivate trebuie sa contina cel puțin constructori parametrizati prin care sa se evidentieze transmiterea parametrilor catre constructorul din clasa de baza, destructor precum si metodele specifice fiecareia in parte.
