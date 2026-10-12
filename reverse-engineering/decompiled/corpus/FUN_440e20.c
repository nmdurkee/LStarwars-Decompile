/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x440e20; label: FUN_00440e20
 */

float10 FUN_00440e20(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    iVar2 = FUN_0043adb0(piVar1);
    if (iVar2 != 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

