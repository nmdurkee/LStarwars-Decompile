/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56bff0; label: FUN_0056bff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056bff0(int param_1)

{
  short sVar1;
  
  *(undefined2 *)(param_1 + 0x7aa) = DAT_00804be4;
  if ((0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28)) &&
     ((sVar1 = DAT_00804cc0, DAT_00804cc0 != -1 || (sVar1 = DAT_00804be8, DAT_00804be8 != -1)))) {
    *(short *)(param_1 + 0x7aa) = sVar1;
  }
  return;
}

