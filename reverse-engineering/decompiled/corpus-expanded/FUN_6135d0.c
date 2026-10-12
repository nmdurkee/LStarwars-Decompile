/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x6135d0; label: FUN_006135d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006135d0(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int *piVar3;
  
  piVar3 = (int *)(*(int *)(param_3 + 8) + 3U & 0xfffffffc);
  *(int **)(param_3 + 8) = piVar3 + 1;
  iVar1 = FUN_00617a00();
  uVar2 = 0;
  if ((param_4 != 0) || ((uint)*(ushort *)(in_ECX + 0x10) < (uint)(iVar1 - *piVar3))) {
    uVar2 = 1;
    *piVar3 = iVar1;
  }
  return uVar2;
}

