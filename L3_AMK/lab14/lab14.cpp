/*
  Celem zadania jest przećwiczenie szablonów klas z parametrami
  szablonu innymi niż typ.

  Stworzymy klasę symbolizującą wielkość fizyczną w jednostkach SI
  (czyli kombinacje różnych potęg kg, m oraz s). 
  Wielkości te można dodawać tylko jeśli ich jednostki są zgodne. 
  Czyli można dodać dwie liczby w m^2, ale nie można dodać np. m/s do m^2.

  Można mnożyć je bez ograniczeń, czyli np. wielkość m pomnożyć przez wielkość w s.

  Dodatkowo można dodawać/mnożyć/dzielić wielkości różnych typów (np. double i int).

  Uwaga: warunki muszą być spełnione dla dowolnych kombinacji jednostek, 
  nie tylko dla tych podanych w programie. Jeżeli program nie będzie obługiwał
  dowolnych jednostek, zadanie jest oceniane na 0 pkt.

  Uwaga: kompilacja z flagami error musi skutkować błędem: 
  "no match for ‘operator+’ (operand types are (...)"
  Brak błędu kompilacji w tym przypadku skutkuje 0 pkt za zadanie.
 */

#include <iostream>
#include "Units.h"

int main() {   
  Length<double> l1(3.2);
  Length<float> l2(4.0);
  std::cout << "lengths:\t" << l1 + l2 << std::endl;

  Area<int> S(4);
  static_assert(sizeof(S) == sizeof(int), "size wrong");
  static_assert(sizeof(Area<int>(2) + S) == sizeof(int), "summation wrong");
  std::cout <<  S + l1 * l2 << std::endl;
  std::cout << l1 * l2 + S << std::endl;
  
  Time<double> t(10);
  Velocity<double> v1 = l1 / t;
  Velocity<double> v2(20.5);
  std::cout << "velocity:\t" << v1 + v2 << std::endl;

  Acceleration<double> a = v2 / t;
  const Acceleration<float> g(9.80665);
  Weigh<int> m(10);
  std::cout << "acceleration:\t" << a + g << std::endl;
  std::cout << "gravity:\t" << m * g << std::endl;
  std::cout << "gravity:\t" << g * m << std::endl;

  // operacje na dowolnych jednostkach
  std::cout << "mass per area:\t" << m / l1 / l2 + m / S << std::endl;
  std::cout << "pressure:\t" << m * g / S + m * a / S << std::endl;
  std::cout << "volume:\t" << l1 * l1 * l2 << std::endl;

  // nie mogą się kompilować m.in.:
  #ifdef ERROR1
  l1 + l1 * l2;
  #endif
  #ifdef ERROR2
  m + m / t;
  #endif

  // część dla chętnych: co zrobić, by dało się określić na podstawie 
  // przyrostka literału, jaka to klasa?
  // auto acceleration = 10.2_ms2;
  // auto area = 1.44_m2;
  // std::cout << acceleration << ", " << area << std::endl;
}

/* wynik
lengths:	7.2 m
16.8 m^2
16.8 m^2
velocity:	20.82 m s^-1
acceleration:	11.8567 m s^-2
gravity:	98.0665 kg m s^-2
gravity:	98.0665 kg m s^-2
mass per area:	2.78125 kg m^-2
pressure:	29.6416 kg m^-1 s^-2
volume: 40.96 m^3
//poniżej wynik części dla chętnych
//10.2 m s^-2, 1.44 m^2
 */
