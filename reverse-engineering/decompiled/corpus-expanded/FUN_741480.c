/* Ghidra pseudocode, not original source.
 * ev_d6810b63b1adbb1cff68d70c4de6dcedf5c7ec9f8161f7a4b49c43fe0c68c9ee
 * Entry: 0x741480; label: FUN_00741480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00741480(int *param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(in_ECX + 0xc);
  do {
    if (*param_1 == *piVar2) {
      return iVar1 * 0x4d8 + 4 + in_ECX;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0x136;
  } while (iVar1 < 400);
  return 0;
}

