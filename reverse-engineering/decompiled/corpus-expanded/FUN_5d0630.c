/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0630; label: FUN_005d0630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005d0630(int param_1)

{
  if (DAT_009715a0 == 0) {
    return 0xffffffff;
  }
  return (&DAT_0096e550)[param_1];
}

