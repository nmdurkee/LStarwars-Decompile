/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x4707a0; label: FUN_004707a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004707a0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (((*(int *)(param_1 + 0x4b0) != 0) && ((*(byte *)(param_1 + 0x559) & 1) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0x4b0) + 0x14) != 0)) {
    if (param_2 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)(param_1 + 0x40);
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *param_2 = *puVar2;
        puVar2 = puVar2 + 1;
        param_2 = param_2 + 1;
      }
    }
    return param_1 + 0x70;
  }
  if (param_2 != (undefined4 *)0x0) {
    puVar2 = &DAT_00806680;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
  }
  return param_1 + 0x48c;
}

