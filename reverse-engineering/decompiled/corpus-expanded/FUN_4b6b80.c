/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b6b80; label: FUN_004b6b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004b6b80(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x1085) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  if (*(short *)(iVar1 + 0xe8) != -1) {
    FUN_00547cb0(param_1,(int)*(short *)(iVar1 + 0xe8),(float)*(byte *)(iVar1 + 0x11e));
  }
  if (((*(code **)(*(int *)(param_1 + 0x54) + 0x18) != FUN_004b5120) &&
      (*(short *)(param_1 + 0xe1c) != 0)) && ((*(uint *)(param_1 + 0xe24) & 0x2000) == 0)) {
    *(undefined2 *)(param_1 + 0xe1c) = 0;
  }
  return;
}

