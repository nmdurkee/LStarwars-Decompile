/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bd060; label: FUN_004bd060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004bd060(int *param_1,int param_2)

{
  byte *pbVar1;
  
  if (param_1 != (int *)0x0) {
    pbVar1 = (byte *)(*param_1 + 0xa2);
    *pbVar1 = *pbVar1 ^ ((param_2 != 0) * '\x02' ^ *(byte *)(*param_1 + 0xa2)) & 2;
  }
  return;
}

