/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x654ea0; label: FUN_00654ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00654ea0(int param_1,int *param_2)

{
  int iVar1;
  
  if (*param_2 == param_1) {
    iVar1 = *(int *)(param_1 + 0x5c);
    *param_2 = iVar1;
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x58) = 0;
      *(undefined4 *)(param_1 + 0x58) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      return;
    }
  }
  else if (*(int *)(param_1 + 0x58) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
    if (*(int *)(param_1 + 0x5c) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x58) = *(undefined4 *)(param_1 + 0x58);
    }
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  return;
}

