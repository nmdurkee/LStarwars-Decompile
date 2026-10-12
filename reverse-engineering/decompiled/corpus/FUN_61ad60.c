/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61ad60; label: FUN_0061ad60
 */

void FUN_0061ad60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float *extraout_ECX;
  
  FUN_00618000(param_2,param_3,param_4,(undefined4 *)(param_1 + 0x5c));
  *(float *)(param_1 + 0x4c) = *extraout_ECX / 360.0;
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x5c);
  return;
}

