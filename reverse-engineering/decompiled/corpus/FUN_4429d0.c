/* Ghidra analysis pseudocode, not original source.
 * ev_57da142a35c0111f2a239c45d08c295619c149a30e290e5aab503b2119bb06b8
 * Entry: 0x4429d0; label: FUN_004429d0
 */

float10 FUN_004429d0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    if ((*(int *)(*piVar1 + 0xe64) != 0) && (*(char *)(*piVar1 + 0xe6b) == '\0')) {
      return (float10)0;
    }
    return (float10)1;
  }
  return (float10)-1.0;
}

