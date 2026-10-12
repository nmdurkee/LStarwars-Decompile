/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56bff0; label: FUN_0056bff0
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

