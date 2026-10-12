/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0560; label: FUN_005d0560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0560(int param_1)

{
  if (((DAT_00966384 < 4) && (*(int *)(param_1 + 0x808) != 0)) && (*(int *)(param_1 + 0x824) == 0))
  {
    *(undefined4 *)(param_1 + 0x824) = 1;
    (&DAT_0096d9d0)[DAT_00966384] = param_1;
    DAT_00966384 = DAT_00966384 + 1;
    DAT_009715a0 = 0;
  }
  return;
}

