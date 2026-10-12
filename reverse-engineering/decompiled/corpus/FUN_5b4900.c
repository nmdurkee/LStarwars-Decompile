/* Ghidra analysis pseudocode, not original source.
 * ev_6ec8aea645f94e3276e7ac0037e639f8d50e0230e3ad74bacc489d09a6610266
 * Entry: 0x5b4900; label: FUN_005b4900
 */

void FUN_005b4900(int param_1,float *param_2)

{
  *(float *)(param_1 + 0x30) = *param_2 + *(float *)(param_1 + 0x30);
  *(float *)(param_1 + 0x34) = param_2[1] + *(float *)(param_1 + 0x34);
  *(float *)(param_1 + 0x38) = param_2[2] + *(float *)(param_1 + 0x38);
  return;
}

