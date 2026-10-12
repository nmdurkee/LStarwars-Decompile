/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61d810; label: FUN_0061d810
 */

void FUN_0061d810(int param_1,float param_2,int param_3,int param_4)

{
  *(float *)(param_1 + 0x50) = (param_2 - *(float *)(param_1 + 0x58)) / *(float *)(param_1 + 0x5c);
  *(float *)(param_1 + 0x54) = param_2;
  if (param_3 != 0) {
    *(undefined4 *)(param_1 + 0x60) = 0x3c;
  }
  if ((param_4 != 0) && (*(code **)(param_1 + 0x4c) != (code *)0x0)) {
    (**(code **)(param_1 + 0x4c))(0,param_1,0);
  }
  return;
}

