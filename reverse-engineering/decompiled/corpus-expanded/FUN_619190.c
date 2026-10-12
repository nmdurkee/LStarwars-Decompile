/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x619190; label: FUN_00619190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00619190(int param_1)

{
  float local_4;
  
  local_4 = 0.0;
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x70) & 0x40) != 0)) {
    if (0xc0 < *(byte *)(param_1 + 0x92)) {
      local_4 = ((float)*(byte *)(param_1 + 0x93) - 128.0) * 0.01;
    }
    if (*(byte *)(param_1 + 0x92) < 0x40) {
      local_4 = (128.0 - (float)*(byte *)(param_1 + 0x93)) * -0.01;
    }
    if (0xc0 < *(byte *)(param_1 + 0x90)) {
      local_4 = ((float)*(byte *)(param_1 + 0x91) - 128.0) * 0.001;
    }
    if (*(byte *)(param_1 + 0x90) < 0x40) {
      return (float10)((128.0 - (float)*(byte *)(param_1 + 0x91)) * -0.001);
    }
  }
  return (float10)local_4;
}

