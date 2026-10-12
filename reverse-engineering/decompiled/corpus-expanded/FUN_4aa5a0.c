/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4aa5a0; label: FUN_004aa5a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004aa5a0(int param_1)

{
  float local_4;
  
  local_4 = _DAT_007fc164;
  if (*(char *)(param_1 + 0x280) < '\x02') {
    if (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b0dc) {
      local_4 = _DAT_007fc168;
    }
    if ((((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
        (DAT_0093d7f4 != 0)) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
      if (param_1 != DAT_0093d7f0) {
        return (float10)(local_4 - _DAT_007fc16c);
      }
      return (float10)(_DAT_007fc16c + local_4);
    }
  }
  return (float10)local_4;
}

