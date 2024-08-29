#include <iostream>
using namespace std;
int main () {
  int a, b;

  a = 0;
  b = 0;
  cin >> a >> b;
  cout << (a & b) << endl;
  cout << (a | b) << endl;
  cout << (a ^ b) << endl;
  return 0;
}

/*
 このプログラムでバグる理由を調べたい



以下のように出る。
:
 /usr/bin/ld: /tmp/cctjvMbT.o: warning: relocation against `_ZSt4cout' in read-only section `.text'
/usr/bin/ld: /tmp/cctjvMbT.o: in function `main':
bit_calculation.cpp:(.text+0x25): undefined reference to `std::cin'
/usr/bin/ld: bit_calculation.cpp:(.text+0x2d): undefined reference to `std::istream::operator>>(int&)'
/usr/bin/ld: bit_calculation.cpp:(.text+0x3f): undefined reference to `std::istream::operator>>(int&)'
/usr/bin/ld: bit_calculation.cpp:(.text+0x50): undefined reference to `std::cout'
/usr/bin/ld: bit_calculation.cpp:(.text+0x58): undefined reference to `std::ostream::operator<<(int)'
/usr/bin/ld: bit_calculation.cpp:(.text+0x5f): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
/usr/bin/ld: bit_calculation.cpp:(.text+0x6a): undefined reference to `std::ostream::operator<<(std::ostream& (*)(std::ostream&))'
/usr/bin/ld: bit_calculation.cpp:(.text+0x7b): undefined reference to `std::cout'
/usr/bin/ld: bit_calculation.cpp:(.text+0x83): undefined reference to `std::ostream::operator<<(int)'
/usr/bin/ld: bit_calculation.cpp:(.text+0x8a): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
/usr/bin/ld: bit_calculation.cpp:(.text+0x95): undefined reference to `std::ostream::operator<<(std::ostream& (*)(std::ostream&))'
/usr/bin/ld: bit_calculation.cpp:(.text+0xa6): undefined reference to `std::cout'
/usr/bin/ld: bit_calculation.cpp:(.text+0xae): undefined reference to `std::ostream::operator<<(int)'
/usr/bin/ld: bit_calculation.cpp:(.text+0xb5): undefined reference to `std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)'
/usr/bin/ld: bit_calculation.cpp:(.text+0xc0): undefined reference to `std::ostream::operator<<(std::ostream& (*)(std::ostream&))'
/usr/bin/ld: /tmp/cctjvMbT.o: in function `__static_initialization_and_destruction_0(int, int)':
bit_calculation.cpp:(.text+0x10b): undefined reference to `std::ios_base::Init::Init()'
/usr/bin/ld: bit_calculation.cpp:(.text+0x126): undefined reference to `std::ios_base::Init::~Init()'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
*/

