/* Ghidra pseudocode, not original source.
 * ev_87b0cc36f0a526e4b097042d81b23e73008cbbd7a9cf76d2852b3ccb3adbc9c9
 * Entry: 0x5db880; label: FUN_005db880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005db880(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  
  DAT_02854d1c = DAT_02854d1c + 1;
  FUN_00600b20(0);
  FUN_00607d70(0x10,7,param_6);
  FUN_005c1f70();
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  FUN_006009e0((float)param_1 * 0.0625,(float)param_2 * 0.0625,0);
  FUN_005c1f70();
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x14) = 0x3f800000;
  FUN_006009e0((float)param_3 * 0.0625 + (float)param_1 * 0.0625,
               (float)param_4 * 0.0625 + (float)param_2 * 0.0625,0);
  FUN_006009a0();
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20(*(undefined4 *)(&DAT_00981c50 + DAT_02854d1c * 4));
  return;
}

