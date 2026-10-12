/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x598560; label: FUN_00598560
 */

undefined4 FUN_00598560(int param_1,int param_2)

{
  int iVar1;
  
  if (((DAT_00955fb0 != (code *)0x0) && (iVar1 = (*DAT_00955fb0)(param_1), iVar1 != 0)) &&
     ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) {
    if (param_2 == 0) {
      return 1;
    }
    if ((*(char *)(param_1 + 0x281) != '\0') && (iVar1 = FUN_005620f0(param_1), iVar1 != 0)) {
      return 1;
    }
  }
  return 0;
}

