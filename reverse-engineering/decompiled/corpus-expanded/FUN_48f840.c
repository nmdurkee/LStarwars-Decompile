/* Ghidra pseudocode, not original source.
 * ev_5eff2230042d4b302660c3ceed2c1b8d608e2d2abaeafeeac76364ea55e51798
 * Entry: 0x48f840; label: FUN_0048f840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048f840(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_3 == 0) {
    if ((DAT_0087af98 != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af98)) {
      return;
    }
    if (((DAT_0087b01c != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087b01c)) &&
       (DAT_008894bc == 0)) {
      return;
    }
  }
  if (param_1 == 0) {
    return;
  }
  if (param_3 == 0) {
    uVar2 = (uint)*(char *)(*(int *)(param_1 + 0x128) + 200);
    iVar1 = *(int *)(param_1 + 300);
    if ((iVar1 != 0) &&
       (((*(byte *)(iVar1 + 0x7a) & 4) != 0 ||
        ((iVar1 != 0 && ((*(byte *)(iVar1 + 0x7a) & 4) != 0)))))) goto LAB_0048f93f;
  }
  else {
    if (*(int *)(param_1 + 300) == 0) {
      return;
    }
    uVar2 = (uint)*(byte *)(*(int *)(param_1 + 300) + 0x7d);
  }
  FUN_00414f80(param_2);
  if (DAT_007f39e4 != 0) {
    FUN_00470e10(param_1,param_2);
  }
  FUN_00559b50(*(undefined4 *)(param_1 + 0x2ac8),param_1,uVar2);
  if (param_2 != 0) {
    FUN_0059f3b0(*(undefined4 *)(param_1 + 0x2acc),param_2 + 0x2c24);
    FUN_0048c270(*(undefined4 *)(param_1 + 0x13c),param_2,0);
  }
  FUN_005a04f0(*(undefined4 *)(param_1 + 0x2960),uVar2);
  FUN_0048a3f0(param_2);
LAB_0048f93f:
  if (param_2 != 0) {
    if (param_2 != *(int *)(param_1 + 0x130)) {
      FUN_004ef660(param_2 + 0x2d68,*(int *)(param_1 + 0x130) + 0x2d68,0xc0);
    }
    *(uint *)(param_2 + 0x2800) =
         (*(int *)(param_1 + 0x5170) * 4 ^ *(uint *)(param_2 + 0x2800)) & 4 ^
         *(uint *)(param_2 + 0x2800) | 2;
  }
  return;
}

