/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d58d0; label: FUN_006d58d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006d58d0(uint param_1)

{
  if ((-1 < (int)param_1) && (param_1 < 4)) {
    return 1 << ((byte)param_1 & 0x1f) & DAT_02975170;
  }
  return 0;
}

