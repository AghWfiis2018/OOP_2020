// Proszę napisać klasę Vector3d, reprezentującą wektor 3-wymiarowy.
// ma on możliwość dostępu do swoich komponentów przez operator[].

// Proszę także napisać klasę Matrix3d, która reprezentuje macierz.
// Matrix3D składa się z  Vector3d'ów.
// Domyślny konstruktor wypełnia je zerami.
// Możliwe są także operacje matematyczne wektorów i macierzy.

// W Matrix3d możliwy jest dostęp do elementów jak w tablicy 2-wymiarowej:
// Matrix3d matrix;
// matrix[i][j] = 10;
// Co trzeba zwrócić?

// Uwagi:
// - Proszę tam gdzie to możliwe, unikać copy-paste'a! 
// - Jak oszczędzić sobie wysiłku przy mnożeniu macierzy przez wektor?

// Skończone zadanie proszę spakować i wysłać na UPEL, np.
// tar -czvf lab02.tar.gz lab02

#include <iostream>
#include "Matrix3d.h"
#include "Vector3d.h"

int main() {
	Vector3d v1(3., 1.5, 2.);	
	const Vector3d v2(4, 2.);

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	std::cout << "v1 * v2: " << v1 * v2 << std::endl;
	std::cout << std::endl;

	v1[1] = 10;
	std::cout << "Po zmianie v1[2]: " << std::endl;
	std::cout << "v3: " << v1 << std::endl;
	std::cout << "v1 * 2: " << v1 * 2 << std::endl;
	std::cout << "2 * v1: " << 2 * v1 << std::endl;
	std::cout << std::endl;

	const Matrix3d m1(v1, v2, v2);
	Matrix3d m2;

	std::cout << "m1: " << std::endl;
	std::cout << m1 << std::endl;
	std::cout << "m2: " << std::endl;
	std::cout << m2 << std::endl;

	m2[0][0] = 100;
	std::cout << "Po zmianie m2[0][0]: " << std::endl;
	std::cout << m2 << std::endl;

	std::cout << "m1 * v2: " << std::endl;
	std::cout << m1 * v2 << std::endl; 
}
/* wyniki

v1: [ 3 1.5 2 ]
v2: [ 4 2 0 ]
v1 * v2: 15

Po zmianie v1[2]: 
v3: [ 3 10 2 ]
v1 * 2: [ 6 20 4 ]
2 * v1: [ 6 20 4 ]

m1: 
[ 3 10 2 ]
[ 4 2 0 ]
[ 4 2 0 ]

m2: 
[ 0 0 0 ]
[ 0 0 0 ]
[ 0 0 0 ]

Po zmianie m2[0][0]: 
[ 100 0 0 ]
[ 0 0 0 ]
[ 0 0 0 ]

m1 * v2: 
[ 32 20 20 ]

*/