/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635ad0; label: FUN_00635ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00635ad0(float param_1)

{
  if (param_1 != 0.0) {
    _DAT_0080fdec = 1.0 / param_1;
    return;
  }
  _DAT_0080fdec = 10000.0;
  return;
}

