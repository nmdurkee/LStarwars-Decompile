/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50ae50; label: FUN_0050ae50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050ae50(int param_1)

{
  if (DAT_00921e5c != 0) {
    FUN_00509ab0();
  }
  if (*(int *)(param_1 + 100) != 0) {
    DAT_00800940 = DAT_00800954;
    FUN_00509ab0();
    return;
  }
  return;
}

