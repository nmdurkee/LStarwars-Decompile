/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x60f5e0; label: FUN_0060f5e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060f5e0(float param_1,float param_2,float param_3,float param_4)

{
  float *pfVar1;
  undefined4 uVar2;
  int in_ECX;
  float10 fVar3;
  float10 fVar4;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float local_90;
  float local_8c;
  float local_88;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_90;
  local_8c = param_3 * 0.5;
  DAT_02854d1c = DAT_02854d1c + 1;
  FUN_00600b20(1);
  FUN_00607d70(0xf,5,0);
  FUN_0060f3d0();
  fVar3 = (float10)param_1;
  pfVar1 = (float *)*DAT_02854d10;
  *pfVar1 = param_1;
  pfVar1[1] = param_2;
  *(undefined4 *)(*DAT_02854d10 + 8) = 0;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  fVar4 = (float10)FUN_0060f3d0();
  pfVar1 = (float *)*DAT_02854d10;
  *pfVar1 = (float)fVar3;
  local_90 = (float)(extraout_ST1 - (float10)param_4);
  fVar3 = (float10)local_90;
  pfVar1[1] = local_90;
  *(float *)(*DAT_02854d10 + 8) = (float)fVar4;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  fVar4 = (float10)FUN_0060f3d0();
  pfVar1 = (float *)*DAT_02854d10;
  local_90 = (float)((float10)local_8c + extraout_ST1_00);
  *pfVar1 = local_90;
  pfVar1[1] = (float)fVar3;
  *(float *)(*DAT_02854d10 + 8) = (float)fVar4;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_006009a0();
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20(*(undefined4 *)(&DAT_00981c50 + DAT_02854d1c * 4));
  FUN_005d0a40(3);
  FUN_005d0880(2);
  uVar2 = DAT_009738b8;
  fVar3 = (float10)FUN_005d0e80(DAT_009738b8);
  local_8c = (float)fVar3;
  FUN_005d1060(uVar2,0x80808080);
  FUN_005d0fe0(uVar2,0x3f400000,0x3f400000);
  local_88 = local_8c + param_2;
  FUN_005eabb0(uVar2,local_90,local_88,0);
  FUN_005f3510(uVar2,*(undefined4 *)(in_ECX + 4));
  local_88 = local_88 + local_8c;
  FUN_005eabb0(uVar2,local_90,local_88,0);
  FUN_004f2740(local_84,"total b %d : %d",*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xc))
  ;
  FUN_005f3510(uVar2,local_84);
  local_8c = local_88 + local_8c;
  FUN_005eabb0(uVar2,local_90,local_8c,0);
  FUN_004f2740(local_84,"total p%d : %d",*(undefined4 *)(in_ECX + 0x10),
               *(undefined4 *)(in_ECX + 0x14));
  FUN_005f3510(uVar2,local_84);
  FUN_005d08c0();
  FUN_005d0a70();
  __security_check_cookie(local_4 ^ (uint)&local_90);
  return;
}

