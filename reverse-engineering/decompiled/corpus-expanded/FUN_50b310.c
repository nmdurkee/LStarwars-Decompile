/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50b310; label: FUN_0050b310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0050b310(void)

{
  if ((((DAT_00800944 != -1) && (DAT_00921d44 != 0)) &&
      (999 < (int)(&DAT_00800aa8)[(short)(&DAT_00921454)[DAT_00800944 * 0x70] * 7])) &&
     ((int)(&DAT_00800aa8)[(short)(&DAT_00921454)[DAT_00800944 * 0x70] * 7] < 0x407)) {
    return 1;
  }
  return 0;
}

