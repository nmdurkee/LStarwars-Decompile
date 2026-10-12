/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54c030; label: FUN_0054c030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c030(int param_1,int param_2,int param_3)

{
  if ((param_1 != 0) && (DAT_00921e9c != 0)) {
    DAT_00926c44 = param_1;
    if ((param_2 < 0) || (DAT_00951360 <= param_2)) {
      param_2 = -1;
    }
    *(char *)(param_1 + 0xd) = (char)param_2;
    FUN_005b45f0(&DAT_00926bd8,DAT_00802398);
    FUN_005b4f70(&DAT_00926bd8,DAT_00926c48);
    FUN_005b5160(&DAT_00926bd8,DAT_00926c4c);
    FUN_005b4900(&DAT_00926bd8,&DAT_00802384);
    if (param_3 != 0) {
      _DAT_00921eb8 = 0;
    }
  }
  return;
}

