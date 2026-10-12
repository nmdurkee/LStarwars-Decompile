/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c57a0; label: FUN_006c57a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c57a0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x18) == 0) {
    FUN_004f1f10(param_2,*(undefined4 *)(param_1 + 0x10));
    return;
  }
  iVar2 = *(int *)(param_1 + 0xc);
  if (((-1 < iVar2) && (iVar2 < DAT_02973ba4)) &&
     (puVar1 = (undefined4 *)(DAT_02973b8c + iVar2 * 0xc), puVar1 != (undefined4 *)0x0)) {
    FUN_004f2740(param_2,"%s %s",*puVar1,*(undefined4 *)(param_1 + 0x10));
    return;
  }
  FUN_004f1f10(param_2,*(undefined4 *)(param_1 + 0x10));
  return;
}

