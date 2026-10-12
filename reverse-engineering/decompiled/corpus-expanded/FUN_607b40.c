/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x607b40; label: FUN_00607b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00607b40(int param_1,int param_2)

{
  _DAT_02854c8c = (uint)(param_1 != 0);
  FUN_006e5340(0x1c,_DAT_02854c8c);
  if (param_1 == 0) {
    FUN_006e5340();
    return;
  }
  if (param_2 == 1) {
    FUN_006e5340();
    return;
  }
  FUN_006e5340();
  return;
}

