/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5edd10; label: FUN_005edd10
 */

void FUN_005edd10(int param_1,undefined4 *param_2)

{
  FUN_005b3920(param_1,&DAT_00973708,param_2);
  FUN_005b3b30(param_1,param_1);
  *(undefined4 *)(param_1 + 0x10) = *param_2;
  *(undefined4 *)(param_1 + 0x14) = param_2[1];
  *(undefined4 *)(param_1 + 0x18) = param_2[2];
  FUN_005b3920(param_1 + 0x20,param_1,(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0x3f800000;
  return;
}

