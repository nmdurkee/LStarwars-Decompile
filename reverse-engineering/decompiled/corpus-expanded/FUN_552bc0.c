/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x552bc0; label: FUN_00552bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00552bc0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == -1) {
    return 1;
  }
  if ((param_1 == 0) && (param_1 = FUN_0055f450(), param_1 == 0)) {
    return 1;
  }
  iVar1 = *(int *)(param_1 + 0x2ac0) + param_2 * 0x10;
  if (*(char *)(iVar1 + 0xe) == '\0') {
    return 0;
  }
  uVar2 = FUN_005f33b0(iVar1,param_3);
  return uVar2;
}

