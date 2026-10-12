/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x5806f0; label: FUN_005806f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005806f0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_004f1ff0(param_1);
  if (iVar1 != 0) {
    iVar1 = 7;
    param_2 = param_2 + 0x4f90;
    do {
      iVar2 = FUN_004f8b10(param_1,param_2);
      if (iVar2 == 0) {
        return *(int *)(PTR_PTR_008040bc + 4) + iVar1;
      }
      iVar1 = iVar1 + -1;
      param_2 = param_2 + -0xa4;
    } while (-1 < iVar1);
    iVar1 = *(int *)(PTR_PTR_008040bc + 4) + 7;
    if (-1 < iVar1) {
      iVar2 = iVar1 * 0xa4;
      do {
        iVar3 = FUN_004f8b10(param_1,*(int *)PTR_PTR_008040bc + iVar2);
        if (iVar3 == 0) {
          return iVar1;
        }
        iVar1 = iVar1 + -1;
        iVar2 = iVar2 + -0xa4;
      } while (-1 < iVar1);
    }
  }
  return -1;
}

