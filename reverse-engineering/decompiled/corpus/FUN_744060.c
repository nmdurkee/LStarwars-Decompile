/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x744060; label: FUN_00744060
 */

void FUN_00744060(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  if (-1 < *(short *)(param_1 + 0x1c + param_2 * 0xc)) {
    switch((*(int *)(param_1 + param_2 * 0xc + 0x20) << 4) >> 0x1c) {
    case 1:
      FUN_00741f90(param_3,param_4,param_5);
      return;
    case 2:
      FUN_00741fd0(param_3,param_4,param_5);
      return;
    case 3:
      FUN_00742010(param_3,param_4,param_5);
    }
  }
  return;
}

