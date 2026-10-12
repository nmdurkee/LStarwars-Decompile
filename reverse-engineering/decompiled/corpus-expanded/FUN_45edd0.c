/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x45edd0; label: FUN_0045edd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0045edd0(int param_1,int param_2)

{
  if ((((*(byte *)(param_2 + 0xb0) & 2) == 0) &&
      (DAT_0087a1a0 = DAT_0087a1a0 + DAT_0087a18c, (*(byte *)(param_2 + 0xb0) & 0x10) != 0)) &&
     ((*(int *)(param_1 + 0x14) != 6 ||
      (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) ==
       (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18)))))) {
    FUN_005533f0(*(undefined4 *)(param_2 + 0x1c),50000,0,0);
  }
  FUN_004838f0(param_2);
  return;
}

