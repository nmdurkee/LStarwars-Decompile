/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56fa60; label: FUN_0056fa60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0056fa60(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
  *(uint *)(param_1 + 0x50b8) = uVar2;
  puVar1 = *(undefined4 **)(param_1 + 0x50b8);
  *(uint *)(param_1 + 0x104) = uVar2 + 0x1c;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x50b8) + 0x14) = 0x41200000;
  FUN_0056f930();
  *(undefined4 *)(*(int *)(param_1 + 0x50b8) + 0x18) = DAT_00950f60;
  FUN_0056f9f0(*(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x11c));
  if (*(short *)(*(int *)(param_1 + 0x128) + 0xde) != 0) {
    uVar2 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar2;
    **(uint **)(param_1 + 0x50b8) = uVar2;
    *(int *)(param_1 + 0x104) =
         *(int *)(param_1 + 0x104) + (uint)*(ushort *)(*(int *)(param_1 + 0x128) + 0xde) * 0x2c;
  }
  uVar2 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
  *(uint *)(param_1 + 0x104) = uVar2;
  *(uint *)(*(int *)(param_1 + 0x50b8) + 4) = uVar2;
  *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 0xb00;
  return *(undefined4 *)(param_1 + 0x50b8);
}

