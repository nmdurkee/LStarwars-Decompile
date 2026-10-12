/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f2da0; label: FUN_004f2da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char FUN_004f2da0(char param_1)

{
  if (((byte)(param_1 + 0xbfU) < 0x1a) || ((byte)(param_1 + 0x40U) < 0x20)) {
    param_1 = param_1 + ' ';
  }
  return param_1;
}

