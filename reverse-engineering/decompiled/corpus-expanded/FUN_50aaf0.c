/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50aaf0; label: FUN_0050aaf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050aaf0(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_00800aa8 + (short)(&DAT_00921374)[DAT_00800944 * 0x70] * 7;
  if (*piVar1 == 0x3fb) {
    (&DAT_00800ac2)[*(short *)(param_1 + 0x14) * 0x1c] = 0;
  }
  else {
    (&DAT_00800ac2)[*(short *)(param_1 + 0x14) * 0x1c] = 1;
  }
  if ((*(int *)(param_1 + 100) != 0) || ((*(int *)(param_1 + 0x68) != 0 && (*piVar1 != 0x3fb)))) {
    DAT_00800940 = DAT_00800954;
    if (*piVar1 == 1000) {
      FUN_00509bc0();
      FUN_00509830(0x3f8,1,0xffffffff);
      return;
    }
    if (*piVar1 == 0x3fb) {
      DAT_00921d3c = 3;
      DAT_00921e5c = 0;
      FUN_00509bc0();
      return;
    }
    FUN_00509bc0();
    FUN_00509830(0x3f9,1,0xffffffff);
  }
  return;
}

