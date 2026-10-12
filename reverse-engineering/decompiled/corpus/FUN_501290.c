/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x501290; label: FUN_00501290
 */

int FUN_00501290(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    piVar2 = *(int **)(param_1 + 0xc);
    do {
      iVar1 = iVar1 + 1;
      if (*(byte *)(*piVar2 + 0x9a) == param_2) {
        return iVar1;
      }
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x10));
  }
  return 0;
}

