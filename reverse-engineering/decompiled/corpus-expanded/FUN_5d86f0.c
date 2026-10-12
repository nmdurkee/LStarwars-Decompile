/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d86f0; label: FUN_005d86f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d86f0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar4 = DAT_00973730;
  DAT_00973984 = 1;
  fVar1 = DAT_00973730 * DAT_00973730;
  fVar2 = DAT_00966378 * DAT_00973730;
  fVar3 = DAT_00973730 * DAT_0097313c;
  fVar5 = (float10)FUN_005c0240(fVar2 * fVar2 + fVar1);
  fVar6 = (float10)FUN_005c0240(fVar3 * fVar3 + fVar1);
  FUN_005b44c0(&DAT_0096d8b0);
  _DAT_0096d8b0 = (float)((float10)1 / fVar5) * -fVar4;
  _DAT_0096d8d0 = -fVar2 * (float)((float10)1 / fVar5);
  _DAT_0096d8b4 = -_DAT_0096d8b0;
  _DAT_0096d8c8 = (float)((float10)1 / fVar6) * fVar4;
  _DAT_0096d8d8 = -fVar3 * (float)((float10)1 / fVar6);
  _DAT_0096d8cc = -_DAT_0096d8c8;
  fVar2 = _DAT_00966270 * fVar4;
  fVar3 = fVar4 * _DAT_0096dce4;
  _DAT_0096d8d4 = _DAT_0096d8d0;
  _DAT_0096d8dc = _DAT_0096d8d8;
  fVar5 = (float10)FUN_005c0240(fVar2 * fVar2 + fVar1);
  fVar6 = (float10)FUN_005c0240(fVar3 * fVar3 + fVar1);
  FUN_005b44c0(&DAT_0096d980);
  _DAT_0096d980 = (float)((float10)1 / fVar5) * -fVar4;
  _DAT_0096d9a0 = -fVar2 * (float)((float10)1 / fVar5);
  _DAT_0096d984 = -_DAT_0096d980;
  _DAT_0096d9a4 = _DAT_0096d9a0;
  _DAT_0096d998 = (float)((float10)1 / fVar6) * fVar4;
  _DAT_0096d9a8 = -fVar3 * (float)((float10)1 / fVar6);
  _DAT_0096d99c = -_DAT_0096d998;
  _DAT_0096d9ac = _DAT_0096d9a8;
  return;
}

