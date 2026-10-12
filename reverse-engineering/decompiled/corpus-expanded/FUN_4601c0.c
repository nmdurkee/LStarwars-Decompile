/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x4601c0; label: FUN_004601c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004601c0(int param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0x40a00000;
    return;
  }
  if (*(int *)(param_1 + 0x14) == 1) {
    fVar1 = *(float *)(param_1 + 0x18);
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 != (*(float *)(param_1 + 0x1c) == param_3)) {
      FUN_004838f0(param_2);
      return;
    }
    if ((fVar1 < 0.75) && (!NAN(param_3) && 0.75 < param_3 != (param_3 == 0.75))) {
      FUN_00681f40("TrueJedi_100pc",0);
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
      return;
    }
  }
  return;
}

