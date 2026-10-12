/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x460700; label: FUN_00460700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00460700(int param_1,int param_2,int param_3)

{
  uint uVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 in_FPUControlWord;
  float10 fVar6;
  float10 fVar7;
  float10 extraout_ST0;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST1;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_120;
  if (param_3 == 0) {
    if (*(char *)(param_1 + 0x12) != '\0') {
      FUN_0045e430(param_2,_DAT_0087b93c,1,0x3f800000,0xff,0xbf,0);
      iVar5 = FUN_006e6b90();
      local_120 = (_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] +
                  _DAT_007fc314;
      FUN_004b80e0(**(undefined4 **)(param_2 + 0x1c),local_120);
    }
    __security_check_cookie(local_4 ^ (uint)&local_120);
    return;
  }
  fVar7 = (float10)1;
  local_114 = (float)fVar7;
  local_110 = _DAT_007fc314;
  local_118 = _DAT_007fc314;
  fVar6 = (float10)_DAT_007f8624;
  local_108 = _DAT_007f8624;
  fVar10 = (float10)0;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case 0:
    local_114 = (float)fVar10;
    break;
  case 1:
    local_114 = *(float *)(param_1 + 0x18);
    local_120 = *(float *)(param_1 + 0x18) / *(float *)(param_1 + 0x1c);
    iVar5 = FUN_006e6b90();
    local_118 = 1.0 - ((float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] + 1.0) * 0.5;
    fVar7 = (float10)FUN_0045e370(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
    fVar7 = (float10)FUN_004850e0((float)fVar7);
    _DAT_0087a188 = (float)fVar7;
    local_110 = _DAT_007fc314 + (_DAT_007fc310 - _DAT_007fc314) * local_118;
    local_108 = _DAT_007f8624;
    fVar10 = (float10)0;
    fVar7 = (float10)1;
    local_118 = _DAT_007fc314 + local_118 * (_DAT_007f8620 - _DAT_007fc314);
    break;
  case 2:
    local_118 = _DAT_007f8620;
    local_110 = _DAT_007fc310;
    break;
  case 3:
    local_114 = 1.0 - *(float *)(param_1 + 0x18);
    local_120 = 1.0 - *(float *)(param_1 + 0x18) / *(float *)(param_1 + 0x1c);
    fVar7 = (float10)_DAT_007fc314;
    iVar5 = FUN_006e6b90();
    fVar8 = (float10)_DAT_007fc310;
    fVar9 = (float10)(float)(extraout_ST0 -
                            ((float10)(float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] + extraout_ST0) *
                            (float10)0.5);
    local_110 = (float)((fVar8 - fVar6) * fVar9 + fVar6);
    local_108 = (float)((fVar10 - (float10)_DAT_0087b93c) * fVar9 + (float10)_DAT_0087b93c);
    fVar10 = extraout_ST1;
    local_118 = (float)(fVar8 + fVar9 * ((float10)_DAT_007f8620 - fVar8));
  }
  if (0 < *(int *)(param_1 + 0x14)) {
    iVar5 = 0;
    do {
      if (*(char *)(param_2 + 0xa4 + iVar5) == '\0') {
        local_11c = _DAT_007fc2d8;
      }
      else {
        local_11c = (float)fVar7;
      }
      if (iVar5 == 0) {
        local_10c = -_DAT_007fc2e0;
        uVar4 = 2;
        local_120 = -_DAT_007fc2ec;
      }
      else {
        local_10c = _DAT_007fc2e0;
        uVar4 = 8;
        local_120 = _DAT_007fc2ec;
      }
      uVar1 = *(uint *)(param_2 + 0x84 + iVar5 * 4);
      if (uVar1 < 1000) {
        iVar3 = (-(uint)(uVar1 < 100) & 0xfffffff8) + 0xbb;
      }
      else {
        iVar3 = 0xc3;
      }
      iVar3 = iVar3 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0);
      if (*(char *)(iVar3 + 0xe) != '\0') {
        FUN_00552c10(local_10c,local_110,(float)fVar7,_DAT_007fc2f4,_DAT_007fc2f4,_DAT_007fc2f4,0,0,
                     0,iVar3,0,local_11c);
      }
      FUN_0054bb30(*(undefined4 *)(param_2 + 0x84 + iVar5 * 4),local_104);
      fVar2 = local_11c * 128.0;
      local_11c = (float)CONCAT22(local_11c._2_2_,in_FPUControlWord);
      local_10c = (float)(int)ROUND(fVar2);
      FUN_0050c780(local_104,local_120,local_110,0x3f800000,_DAT_007fc2f8,_DAT_007fc2f8,
                   _DAT_007fc2f8,uVar4,0xff,0xbf,0,(uint)local_10c & 0xff);
      fVar7 = (float10)1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    FUN_004b80e0(**(undefined4 **)(param_2 + 0x1c),local_118,local_108,1,(float)fVar7,0xff,0xbf,0);
    fVar10 = (float10)0;
    fVar7 = (float10)1;
  }
  if (fVar10 <= (float10)local_114) {
    if (fVar7 < (float10)local_114) {
      local_114 = (float)fVar7;
    }
  }
  else {
    local_114 = (float)fVar10;
  }
  local_11c = (float)CONCAT22(local_11c._2_2_,in_FPUControlWord);
  local_120 = (float)(int)ROUND(local_114 * 128.0);
  FUN_0050c780(*(undefined4 *)(DAT_00926c20 + DAT_008808b4 * 4),(float)fVar10,_DAT_007fa4c0,
               (float)fVar7,_DAT_007f8628,_DAT_007f8628,_DAT_007f8628,0,0xff,0xff,0xff,
               (uint)local_120 & 0xff);
  __security_check_cookie(local_4 ^ (uint)&local_120);
  return;
}

