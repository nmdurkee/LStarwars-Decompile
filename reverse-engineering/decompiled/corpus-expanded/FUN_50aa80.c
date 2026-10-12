/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50aa80; label: FUN_0050aa80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050aa80(int param_1)

{
  if (*(int *)(param_1 + 100) != 0) {
    DAT_00800940 = DAT_00800954;
    return;
  }
  if ((*(int *)(param_1 + 0x68) != 0) &&
     ((&DAT_00800aa8)[(short)(&DAT_00921374)[DAT_00800944 * 0x70] * 7] != 0x3fb)) {
    DAT_00800940 = DAT_00800954;
    FUN_00509bc0();
    FUN_00509830(0x3fa,1,0xffffffff);
  }
  return;
}

