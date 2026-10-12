/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x566da0; label: FUN_00566da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00566da0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  if ((*(int *)(param_1 + 0x50c8) != 0) && (iVar3 = *(int *)(param_1 + 0x50c0), 0 < iVar3)) {
    piVar2 = (int *)(*(int *)(param_1 + 0x50c8) + 0xa0);
    do {
      iVar1 = iVar1 + (int)*(char *)((int)piVar2 + 0x6d) * *piVar2;
      piVar2 = piVar2 + 0x45;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar1;
}

