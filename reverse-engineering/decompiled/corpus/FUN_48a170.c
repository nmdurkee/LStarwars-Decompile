/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x48a170; label: FUN_0048a170
 */

void FUN_0048a170(int param_1)

{
  char *pcVar1;
  int iVar2;
  
  if (param_1 != 0) {
    pcVar1 = (char *)(param_1 + 0x2d68);
    iVar2 = 0xc;
    do {
      if (*pcVar1 != '\0') {
        FUN_005a8280(pcVar1,0);
      }
      pcVar1 = pcVar1 + 0x10;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

