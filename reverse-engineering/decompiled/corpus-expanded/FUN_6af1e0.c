/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6af1e0; label: FUN_006af1e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006af1e0(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 1) {
    FUN_006aef80(iVar1,param_2,param_1[1],param_1[1] + iVar1 * 4);
  }
  return;
}

