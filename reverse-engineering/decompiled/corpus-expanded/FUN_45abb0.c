/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x45abb0; label: FUN_0045abb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045abb0(int param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 fVar5;
  float local_18;
  float local_10;
  float local_c;
  int local_8;
  
  if ((param_3 != 0) && (0 < *(int *)(param_1 + 0x14))) {
    fVar5 = (float10)0;
    local_10 = (float)fVar5;
    local_18 = (float)fVar5;
    uVar4 = 0;
    uVar3 = 0;
    local_c = 1.0;
    switch(*(int *)(param_1 + 0x14)) {
    case 1:
      iVar2 = FUN_006e6b90();
      uVar4 = 0;
      uVar3 = 0;
      local_c = 1.0 - ((float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + 1.0) * 0.5;
      local_18 = (float)extraout_ST0;
      local_10 = (float)extraout_ST0;
      fVar5 = extraout_ST0;
      break;
    case 2:
      iVar2 = FUN_006e6b90();
      uVar3 = DAT_00876db4 & 0xffff;
      uVar4 = 0;
      local_18 = 1.0 - ((float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + 1.0) * 0.5;
      local_10 = (float)extraout_ST0_00;
      fVar5 = extraout_ST0_00;
      break;
    case 3:
      uVar4 = 0;
      local_18 = 1.0;
      uVar3 = 0;
      local_10 = (float)fVar5;
      break;
    case 4:
      local_18 = 1.0;
      iVar2 = FUN_006e6b90();
      uVar3 = 0;
      uVar4 = -DAT_00876db4 & 0xffff;
      local_10 = 1.0 - ((float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + 1.0) * 0.5;
      fVar5 = extraout_ST0_01;
      break;
    case 5:
      uVar4 = 0;
      local_18 = 1.0;
      uVar3 = 0;
      local_10 = 1.0;
      break;
    case 6:
      uVar4 = 0;
      local_10 = 1.0;
      uVar3 = 0;
      local_18 = 1.0;
      iVar2 = FUN_006e6b90();
      local_c = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] * 0.25 + 1.0;
      fVar5 = extraout_ST0_02;
      break;
    case 7:
      iVar2 = FUN_006e6b90();
      uVar3 = DAT_00876db4 & 0xffff;
      uVar4 = -DAT_00876db4 & 0xffff;
      local_18 = 1.0 - (1.0 - ((float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + 1.0) * 0.5);
      fVar5 = extraout_ST0_03;
      local_10 = local_18;
      local_c = local_18;
    }
    fVar1 = _DAT_007f8218 * local_10;
    local_8 = (int)(longlong)ROUND(local_18 * 255.0);
    FUN_00482f40(*(undefined4 *)
                  (DAT_00926c20 +
                  *(short *)(&PTR_DAT_007f3d9c)[*(char *)(*(int *)(param_2 + 0x14) + 0x7e) * 8] * 4)
                 ,uVar3,(float)fVar5,_DAT_007f8218 * local_18 * _DAT_007fa4c0,
                 _DAT_007f8218 * local_18,local_8 << 0x18 | 0xa0af5,0);
    fVar5 = (float10)FUN_005b7d30(_DAT_00925028,0x40800000);
    uVar3 = (int)ROUND(fVar5 * (float10)0.25 * (float10)65536.0) & 0xffff;
    FUN_00552d10(0,0,0x3f800000,local_c,local_c,local_c,
                 (int)ROUND((float)(&DAT_029899a0)[(int)(uVar3 * 2) >> 1 & 0x7fff] * 1820.0) &
                 0xffff,uVar3,0,*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd20,2);
    local_8 = (int)(longlong)ROUND(local_10 * 255.0);
    FUN_00482f40(*(undefined4 *)(DAT_00926c20 + DAT_00880728 * 4),uVar4,0,-_DAT_007fa4c0 * fVar1,
                 fVar1,local_8 << 0x18 | 0xa0af5,0);
  }
  return;
}

