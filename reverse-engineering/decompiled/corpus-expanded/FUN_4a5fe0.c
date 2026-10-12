/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a5fe0; label: FUN_004a5fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004a5fe0(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xc80) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_1 + 0xc84) = *(undefined4 *)(param_2 + 0x34);
  *(undefined4 *)(param_1 + 0xc88) = *(undefined4 *)(param_2 + 0x38);
  *(undefined4 *)(param_1 + 0xc8c) = *(undefined4 *)(param_2 + 0x80);
  *(undefined4 *)(param_1 + 0xc90) = *(undefined4 *)(param_2 + 0x84);
  uVar1 = *(undefined4 *)(param_2 + 0x88);
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x800;
  *(undefined4 *)(param_1 + 0xc94) = uVar1;
  *(uint *)(param_1 + 0xcc8) = ~-(uint)(DAT_00951288 != 0) & param_2;
  return 1;
}

