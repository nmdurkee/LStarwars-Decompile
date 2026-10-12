/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x6813e0; label: FUN_006813e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006813e0(int param_1,undefined4 param_2,int param_3)

{
  DAT_02947c64 = param_1;
  DAT_02924b4c = param_1 + param_3 * 0x1c;
  DAT_02921870 = param_3;
  DAT_0292fc08 = 0;
  DAT_02947bfc = 0;
  _DAT_02947b54 = param_2;
  _DAT_00810b28 = (int)*(short *)(DAT_0292fc68 + 0x14c);
  return;
}

