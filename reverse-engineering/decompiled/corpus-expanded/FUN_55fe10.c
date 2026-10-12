/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55fe10; label: FUN_0055fe10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055fe10(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x128);
  *(undefined4 *)(param_1 + 0x295c) = 0;
  if ((*(byte *)(iVar1 + 100) & 8) != 0) {
    *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    uVar2 = FUN_0066b8c0(*(undefined4 *)(param_1 + 0x11c),(uint *)(param_1 + 0x104),
                         *(undefined4 *)(param_1 + 0x108),0,param_1 + 0x80,
                         *(undefined4 *)(param_1 + 0x13c),0,*(undefined2 *)(iVar1 + 0x9a),
                         *(undefined2 *)(iVar1 + 0x9a),*(undefined2 *)(iVar1 + 0x98));
    *(undefined4 *)(param_1 + 0x295c) = uVar2;
  }
  return;
}

