/* Ghidra analysis pseudocode, not original source.
 * ev_d8945a36929edeac9ee45c1fd9ef4d2b22c6103a52c54fc2dc40f3cab4594402
 * Entry: 0x5dba30; label: FUN_005dba30
 */

void FUN_005dba30(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10)

{
  int iVar1;
  
  DAT_02854d1c = DAT_02854d1c + 1;
  FUN_00600b20(0);
  FUN_00607d70(0x10,7,param_10);
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = param_5;
  *(undefined4 *)(iVar1 + 0x14) = param_6;
  FUN_005c1f70();
  FUN_006009e0((float)param_1 * 0.0625,(float)param_2 * 0.0625,0);
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = param_7;
  *(undefined4 *)(iVar1 + 0x14) = param_8;
  FUN_005c1f70();
  FUN_006009e0((float)param_3 * 0.0625 + (float)param_1 * 0.0625,
               (float)param_4 * 0.0625 + (float)param_2 * 0.0625,0);
  FUN_006009a0();
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20(*(undefined4 *)(&DAT_00981c50 + DAT_02854d1c * 4));
  return;
}

