/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d08c0; label: FUN_005d08c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d08c0(void)

{
  if (0 < DAT_009738cc) {
    DAT_009738cc = DAT_009738cc + -1;
    DAT_009738c4 = *(undefined4 *)(&DAT_0096d870 + DAT_009738cc * 4);
  }
  return;
}

