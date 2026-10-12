/* Ghidra analysis pseudocode, not original source.
 * ev_2f277248dc33480f063e4f0d474d621052bdb6108e7bcd5536ed18fa967ce013
 * Entry: 0x6f690c; label: FUN_006f690c
 */

undefined4 FUN_006f690c(void)

{
  uint in_EAX;
  
  if ((in_EAX & 0x80000) != 0) {
    return 7;
  }
  return 1;
}

