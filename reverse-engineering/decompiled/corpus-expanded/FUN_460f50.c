/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x460f50; label: FUN_00460f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00460f50(int param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 in_FPUControlWord;
  float10 fVar7;
  float10 fVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float local_110;
  float local_10c;
  float local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_110;
  if (param_3 != 0) {
    if (((0 < *(int *)(param_1 + 0x14)) &&
        (fVar1 = *(float *)(param_1 + 0x18), !NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0))) &&
       (*(float *)(param_1 + 0x18) < *(float *)(param_1 + 0x1c) - 1.0)) {
      fVar7 = (float10)2.0;
      uVar5 = (uint)DAT_0086e4e2;
      uVar6 = (uint)*(byte *)(param_2 + 0xbd);
      local_10c = (float)((uVar5 - uVar6) + -1);
      fVar8 = (float10)2.0;
      if (fVar7 <= (float10)*(float *)(param_1 + 0x18)) {
        local_108 = (float)((float10)*(float *)(param_1 + 0x1c) - fVar8);
        fVar1 = 1.0;
        if (local_108 <= *(float *)(param_1 + 0x18)) {
          iVar2 = FUN_006e6b90();
          fVar7 = extraout_ST1_00;
          fVar8 = extraout_ST0_00;
          fVar1 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
        }
      }
      else {
        iVar2 = FUN_006e6b90();
        fVar7 = extraout_ST0;
        fVar8 = extraout_ST1;
        fVar1 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
      }
      local_108 = fVar1;
      uVar3 = uVar6;
      if ((fVar7 <= (float10)*(float *)(param_1 + 0x18)) &&
         (uVar3 = uVar5,
         (float10)*(float *)(param_1 + 0x18) < (float10)(int)local_10c * (float10)2.5 + fVar8)) {
        local_10c = (float)(uVar6 + 1);
        uVar3 = FUN_006e6b90();
      }
      _sprintf(local_104,"%i/%i",uVar3,DAT_0093b30c);
      uVar4 = FUN_006e6b90();
      local_10c = (float)(extraout_ST0_01 * (float10)-0.9999999403953552 +
                         (float10)1.2999999523162842);
      FUN_0050d910(local_104,0,local_10c,0x3f800000,0x3fc00000,0x3fc00000,0x3fc00000,0,0xff,0xff,
                   0xff,0x3fd9999a,1,0,0,uVar4);
      fVar7 = (float10)FUN_005b7d30(_DAT_00925028,0x40800000);
      uVar5 = (int)ROUND(fVar7 * (float10)0.25 * (float10)65536.0) & 0xffff;
      local_10c = (float)CONCAT22(local_10c._2_2_,in_FPUControlWord);
      local_110 = local_108 * 0.99999994 - 1.3;
      FUN_00552d10(0,local_110,0x3f800000,0x3f800000,0x3f800000,0x3f800000,
                   (int)ROUND((float)(&DAT_029899a0)[(int)(uVar5 * 2) >> 1 & 0x7fff] * 1820.0) &
                   0xffff,uVar5,0,*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd30,2);
      if (0x3c < DAT_0086e4e2) {
        local_110 = _DAT_007fc314 + local_108 * (_DAT_007fc310 - _DAT_007fc314);
        FUN_004b80e0(**(undefined4 **)(param_2 + 0x1c),local_110,_DAT_0087b93c,1,0x3f800000,0xff,
                     0xbf,0);
      }
    }
    if (((*(int *)(param_1 + 0x14) == 0) || (*(float *)(param_1 + 0x18) < 1.0)) &&
       ((*(char *)(param_2 + 0xa7) != '\0' && (*(byte *)(param_2 + 0xbd) < DAT_0086e4e2)))) {
      _DAT_0087a1d0 = 0;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_110);
  return;
}

