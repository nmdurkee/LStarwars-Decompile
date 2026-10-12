/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x4246f0; label: FUN_004246f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004246f0(undefined4 *param_1,undefined4 *param_2)

{
  if (DAT_0087b6c8 == '\0') {
    if (DAT_0087b6c9 != '\0') {
      *param_1 = 1;
      *param_2 = 1;
      return;
    }
  }
  else if (DAT_0087b6c9 == '\0') {
    *param_1 = 0;
    *param_2 = 1;
    return;
  }
  *param_1 = 0;
  *param_2 = 2;
  return;
}

