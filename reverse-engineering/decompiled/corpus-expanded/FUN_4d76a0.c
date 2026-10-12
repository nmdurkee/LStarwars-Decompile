/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d76a0; label: FUN_004d76a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_004d76a0(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *(byte *)(*param_1 + 0x68) >> 6 & 1;
  }
  return 0;
}

