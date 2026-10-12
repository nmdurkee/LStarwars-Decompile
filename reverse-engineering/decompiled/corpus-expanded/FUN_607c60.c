/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x607c60; label: FUN_00607c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00607c60(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  DAT_02854cfc = DAT_0080e268 / 0x18;
  iVar1 = DAT_02854cfc * 0x18;
  piVar2 = &DAT_02854b8c;
  DAT_02854cf8 = iVar1;
  do {
    *piVar2 = *param_1;
    *param_1 = *param_1 + iVar1;
    piVar2 = piVar2 + 1;
  } while (piVar2 != (int *)&DAT_02854bac);
  FUN_005ffba0();
  return;
}

