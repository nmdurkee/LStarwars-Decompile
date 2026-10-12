/* Ghidra pseudocode, not original source.
 * ev_4c4127be7d58e8981fbef62e7b9304e5f7a8f47caff33366593b2d257bcf3f12
 * Entry: 0x59ebf0; label: FUN_0059ebf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059ebf0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004f9e70(param_1);
  uVar2 = FUN_004f9e70(param_1);
  *(undefined4 *)(&DAT_00956300 + iVar1 * 4) = uVar2;
  return;
}

