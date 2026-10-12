/* Ghidra pseudocode, not original source.
 * ev_22c329bac68cac2fc7bcf67b722cf469408ea6fe3402124ef456f33d7f316bc5
 * Entry: 0x6e5c50; label: FUN_006e5c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e5c50(int param_1,int param_2)

{
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x178))(DAT_029765cc,param_1,param_2,1);
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x178))(DAT_029765cc,param_1 + 1,param_2 + 0xc,1);
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x178))(DAT_029765cc,param_1 + 2,param_2 + 0x18,1);
  return;
}

