/* Ghidra pseudocode, not original source.
 * ev_12b000564e8cba1f3519ff70f1088df218803466ba65b3333f742de5377565cf
 * Entry: 0x41aef0; label: FUN_0041aef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0041aef0(int param_1)

{
  if (((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) && ((DAT_0086e4e3 & 1) != 0)) &&
      (DAT_00856980 != 0)) &&
     ((*(short *)(param_1 + 0x1064) == *(short *)(DAT_00856980 + 0x6c) ||
      (*(short *)(param_1 + 0x1064) == *(short *)(DAT_00856980 + 0x6e))))) {
    return 1;
  }
  return 0;
}

