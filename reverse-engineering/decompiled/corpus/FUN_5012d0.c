/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x5012d0; label: FUN_005012d0
 */

int FUN_005012d0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x60)) {
    piVar2 = (int *)(*(int *)(param_1 + 100) + 0x10);
    do {
      iVar1 = iVar1 + 1;
      if (*piVar2 == param_2) {
        return iVar1;
      }
      piVar2 = piVar2 + 8;
    } while (iVar1 < *(int *)(param_1 + 0x60));
  }
  return 0;
}

