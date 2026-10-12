/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5edd10; label: FUN_005edd10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

