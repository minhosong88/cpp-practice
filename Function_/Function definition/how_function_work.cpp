#include <iostream>

using namespace std;

void func2(int &x, int y, int z) // 5. variables are on stack: x, y, z values are copied from the references.
{
  x += y + z; // 6. after execution, popped
}

int func1(int a, int b) // 4.  values are copied to a and b and result stored
{
  int result{};
  result = a + b;
  func2(result, a, b);
  return result; // 7. after execution, popped
}

int main() // 1. start at main(main at stack already)
{
  int x{10}; // 2. variables in stack
  int y{20};
  int z{};
  z = func1(x, y); // 3. push activation record for func1 (on the stack now) : variables on stack //
  cout << z << endl;

  return 0; // 8. after execution, popped
}

/*

main:
- push space for the return value
- push space for the parameters
- push the return address(space reserved for the result)
- transfer control to func1 (jmp)
------------------------------
func1:
- push the address of the previous activation record
- push any register values that will need to be restored before returning to the caller
- perform the code in func1
- restore the register value
- restore the previous acctivation record
- store any function result
- transfer control to the return address(jmp)
---------------------------------
main:
- pop the parameters
- pop the return value(clear up the stack)

*/