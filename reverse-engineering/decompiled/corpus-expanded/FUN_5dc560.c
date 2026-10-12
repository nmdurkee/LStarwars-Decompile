/* Ghidra pseudocode, not original source.
 * ev_87b0cc36f0a526e4b097042d81b23e73008cbbd7a9cf76d2852b3ccb3adbc9c9
 * Entry: 0x5dc560; label: FUN_005dc560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005dc560(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  DAT_02854d1c = DAT_02854d1c + 1;
  fVar2 = (float)param_1 * 0.0625;
  fVar3 = (float)param_2 * 0.0625;
  fVar4 = (float)param_7 * 5.960465e-08;
  FUN_00600b20(0);
  FUN_00607d70(0xd,7,param_6);
  FUN_005c1f70();
  FUN_006009e0(fVar2,fVar3,fVar4);
  FUN_005c1f70();
  fVar5 = (float)param_3 * 0.0625 + fVar2;
  FUN_006009e0(fVar5,fVar3,fVar4);
  FUN_005c1f70();
  fVar3 = (float)param_4 * 0.0625 + fVar3;
  FUN_006009e0(fVar2,fVar3,fVar4);
  FUN_005c1f70();
  FUN_006009e0(fVar5,fVar3,fVar4);
  FUN_006009a0();
  iVar1 = DAT_02854d1c * 4;
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar1));
  return;
}

