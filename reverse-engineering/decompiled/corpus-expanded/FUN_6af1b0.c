/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6af1b0; label: FUN_006af1b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006af1b0(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 1) {
    FUN_006ac310(iVar1,param_1[1],param_1[1] + iVar1 * 4);
  }
  return;
}

