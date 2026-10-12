/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x574e20; label: FUN_00574e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00574e20(void)

{
  if ((&DAT_00921454)[DAT_00800944 * 0x70] == -1) {
    return 0xffffffff;
  }
  return (&DAT_00800aa8)[(short)(&DAT_00921454)[DAT_00800944 * 0x70] * 7];
}

