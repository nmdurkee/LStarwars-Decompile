/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50aa10; label: FUN_0050aa10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050aa10(int param_1)

{
  if (*(int *)(param_1 + 0x68) != 0) {
    DAT_00800940 = DAT_00800954;
    FUN_00509bc0();
    FUN_00509830(0x3f8,1,0xffffffff);
  }
  return;
}

