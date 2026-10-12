/* Ghidra pseudocode, not original source.
 * ev_87b0cc36f0a526e4b097042d81b23e73008cbbd7a9cf76d2852b3ccb3adbc9c9
 * Entry: 0x5dbb40; label: FUN_005dbb40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005dbb40(float *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  float10 fVar2;
  float10 extraout_ST1;
  
  DAT_02854d1c = DAT_02854d1c + 1;
  FUN_00600b20(0);
  FUN_00607d70(0xe,7,param_2);
  if (0 < param_3) {
    do {
      fVar2 = (float10)FUN_005c1f70();
      iVar1 = *DAT_02854d10;
      *(float *)(iVar1 + 0x10) = (float)extraout_ST1;
      *(float *)(iVar1 + 0x14) = (float)extraout_ST1;
      FUN_006009e0((float)(fVar2 * (float10)*param_1),(float)((float10)param_1[1] * fVar2),
                   (float)extraout_ST1);
      param_1 = param_1 + 7;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  FUN_006009a0();
  iVar1 = DAT_02854d1c * 4;
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar1));
  return 1;
}

