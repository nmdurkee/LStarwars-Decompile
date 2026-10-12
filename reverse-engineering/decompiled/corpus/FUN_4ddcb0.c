/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4ddcb0; label: FUN_004ddcb0
 */

undefined4 FUN_004ddcb0(void)

{
  int in_EAX;
  int in_ECX;
  
  if (in_ECX == 0) {
    if (in_EAX == 1) {
      return 3;
    }
    if (in_EAX == 2) {
      return 5;
    }
  }
  else if (in_ECX == 1) {
    if (in_EAX == 0) {
      return 3;
    }
    if (in_EAX == 2) {
      return 4;
    }
  }
  else if (in_ECX == 2) {
    if (in_EAX == 1) {
      return 4;
    }
    if (in_EAX == 0) {
      return 5;
    }
  }
  return 0xffffffff;
}

