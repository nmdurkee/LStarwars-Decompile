/* Ghidra analysis pseudocode, not original source.
 * ev_2f277248dc33480f063e4f0d474d621052bdb6108e7bcd5536ed18fa967ce013
 * Entry: 0x6f6a87; label: __startOneArgErrorHandling
 */

/* Library Function - Single Match
    __startOneArgErrorHandling
   
   Library: Visual Studio 2005 Release */

float10 __startOneArgErrorHandling(void)

{
  float10 in_ST0;
  
  __87except();
  return (float10)(double)in_ST0;
}

