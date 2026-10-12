/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x478af0; label: thunk_FUN_00574e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 thunk_FUN_00574e20(void)

{
  if ((&DAT_00921454)[DAT_00800944 * 0x70] == -1) {
    return 0xffffffff;
  }
  return (&DAT_00800aa8)[(short)(&DAT_00921454)[DAT_00800944 * 0x70] * 7];
}

