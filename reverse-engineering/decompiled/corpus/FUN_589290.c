/* Ghidra analysis pseudocode, not original source.
 * ev_4597a773e0370c09a0c234dc3483b3ea71e6a654f79adb326cefb52c3abac04d
 * Entry: 0x589290; label: FUN_00589290
 */

void FUN_00589290(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f9e70(param_1);
  if (iVar1 < 0x2711) {
    if (iVar1 < 0) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 10000;
  }
  *(short *)(DAT_00954404 + 0xee) = (short)(iVar1 / 10) * 10;
  return;
}

