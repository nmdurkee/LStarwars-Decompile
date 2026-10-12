/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f39f0; label: FUN_005f39f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f39f0(undefined2 param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,float param_7,float param_8,float param_9,int param_10)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = DAT_00973928;
  *(undefined2 *)(DAT_00973928 + 0x74) = param_1;
  FUN_00601030(iVar2);
  psVar1 = (short *)(iVar2 + 0x2c0);
  *psVar1 = *psVar1 + 1;
  FUN_005d4290(1);
  DAT_02854d1c = DAT_02854d1c + 1;
  FUN_00600b20(*(undefined4 *)(&DAT_00764280 + param_10 * 4));
  FUN_00607d70(0xd,7,DAT_00973924);
  FUN_005c1f70();
  iVar2 = *DAT_02854d10;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  FUN_006009e0(param_2,param_3,0);
  FUN_005c1f70();
  iVar2 = *DAT_02854d10;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  FUN_006009e0(param_2 + param_4,param_3,0);
  FUN_005c1f70();
  iVar2 = *DAT_02854d10;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  FUN_006009e0(param_2,param_3 + param_5,0);
  FUN_005c1f70();
  iVar2 = *DAT_02854d10;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  FUN_006009e0(param_2 + param_4,param_3 + param_5,0);
  FUN_006009a0();
  iVar2 = DAT_02854d1c * 4;
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar2));
  DAT_02854d1c = DAT_02854d1c + 1;
  FUN_00600b20(*(undefined4 *)(&DAT_00764280 + param_10 * 4));
  FUN_00607d70(0xd,7,DAT_00973928);
  FUN_005c1f70();
  iVar2 = *DAT_02854d10;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  FUN_006009e0(param_6,param_7,0x3f800000);
  FUN_005c1f70();
  iVar2 = *DAT_02854d10;
  *(undefined4 *)(iVar2 + 0x10) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  FUN_006009e0(param_6 + param_8,param_7,0x3f800000);
  FUN_005c1f70();
  iVar2 = *DAT_02854d10;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0x3f800000;
  FUN_006009e0(param_6,param_7 + param_9,0x3f800000);
  FUN_005c1f70();
  iVar2 = *DAT_02854d10;
  *(undefined4 *)(iVar2 + 0x10) = 0x3f800000;
  *(undefined4 *)(iVar2 + 0x14) = 0x3f800000;
  FUN_006009e0(param_6 + param_8,param_7 + param_9,0x3f800000);
  FUN_006009a0();
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20(*(undefined4 *)(&DAT_00981c50 + DAT_02854d1c * 4));
  FUN_005f3950();
  return;
}

