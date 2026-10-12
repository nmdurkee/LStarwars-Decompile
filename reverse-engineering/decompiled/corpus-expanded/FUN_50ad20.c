/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50ad20; label: FUN_0050ad20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050ad20(int param_1)

{
  if (*(int *)(param_1 + 100) == 0) {
    if (*(int *)(param_1 + 0x68) != 0) {
      FUN_00509ab0();
      DAT_00800940 = DAT_00800954;
    }
    return;
  }
  DAT_00800940 = DAT_00800954;
  if (*(short *)(param_1 + 10) == 1) {
    FUN_00509ab0();
    return;
  }
  DAT_00921ddc = 1;
  DAT_00921de0 = 0;
  DAT_00921de4 = 0;
  FUN_00509bc0();
  FUN_00509830(0x3f1,0,0xffffffff);
  return;
}

