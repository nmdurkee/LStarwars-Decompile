/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d7ab0; label: FUN_005d7ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d7ab0(float *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  *param_1 = _DAT_0096e538;
  DAT_0096e4ec = DAT_0096e4ec + -1;
  _DAT_0097159c = _DAT_0097159c + 1.0;
  _DAT_0096e538 = _DAT_0096e538 + _DAT_0096637c;
  iVar1 = FUN_006e6b90();
  iVar2 = FUN_006e6b90();
  *param_2 = iVar1 - iVar2;
  if (DAT_0096e4ec != 0) {
    return 0;
  }
  _DAT_0096e538 = (float)_DAT_00971870;
  return 0xffffffff;
}

