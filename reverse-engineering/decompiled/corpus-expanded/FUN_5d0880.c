/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0880; label: FUN_005d0880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0880(undefined4 param_1)

{
  if (DAT_009738cc < 0x10) {
    *(undefined4 *)(&DAT_0096d870 + DAT_009738cc * 4) = DAT_009738c4;
    DAT_009738cc = DAT_009738cc + 1;
    DAT_009738c4 = param_1;
    return;
  }
  DAT_009738c4 = param_1;
  return;
}

