/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61b470; label: FUN_0061b470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0061b470(undefined4 param_1,float param_2,int param_3,int param_4,int param_5)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort in_FPUControlWord;
  float local_20;
  float local_1c;
  uint local_18;
  float local_14;
  float local_10;
  float local_c;
  longlong local_8;
  
  fVar1 = param_2;
  iVar5 = (int)(param_5 * 3 + (param_5 * 3 >> 0x1f & 3U)) >> 2;
  *(int *)((int)param_2 + 0x1c) = param_3;
  *(int *)((int)param_2 + 0x20) = param_4;
  local_18 = iVar5;
  FUN_006189c0(param_4,param_5,iVar5,0,0x3e2aaaab,0x80000000,0x80000000,0x800000ff,0x8000ffff,8);
  FUN_006189c0(param_4,param_5,iVar5,0x3e2aaaab,0x3eaaaaab,0x80000000,0x80000000,0x8000ffff,
               0x8000ff00,8);
  FUN_006189c0(param_4,param_5,iVar5,0x3eaaaaab,0x3f000000,0x80000000,0x80000000,0x8000ff00,
               0x80ffff00,8);
  FUN_006189c0(param_4,param_5,iVar5,0x3f000000,0x3f2aaaab,0x80000000,0x80000000,0x80ffff00,
               0x80ff0000,8);
  FUN_006189c0(param_4,param_5,iVar5,0x3f2aaaab,0x3f555555,0x80000000,0x80000000,0x80ff0000,
               0x80ff00ff,8);
  FUN_006189c0(param_4,param_5,iVar5,0x3f555555,0x3f800000,0x80000000,0x80000000,0x80ff00ff,
               0x800000ff,8);
  if (DAT_02912eb8 == 0) {
    param_2 = (float)(int)local_18;
    iVar3 = FUN_006e6b90(0x80ffffff,DAT_02900c70);
    FUN_006e6b90((param_3 + param_5) * 0x10 + -0x10,iVar3 * 8);
    iVar3 = FUN_006e6b90();
    FUN_005db5b0(param_3 << 4,iVar3 * 8);
    if (DAT_02912eb8 == 0) {
      iVar3 = FUN_006e6b90();
      FUN_005db5b0(iVar3 << 4,param_4 * 8,iVar3 << 4,(iVar5 + param_4) * 8 + -8,0x80ffffff,
                   DAT_02900c70);
    }
  }
  local_18 = (int)(param_5 + (param_5 >> 0x1f & 7U)) >> 3;
  param_4 = param_4 + iVar5;
  FUN_00618180(*(undefined4 *)((int)fVar1 + 0x54),0x3f800000,*(undefined4 *)((int)fVar1 + 0x5c),
               &local_1c);
  local_8._0_4_ = (int)(longlong)ROUND(param_2 * -255.0);
  iVar5 = (int)local_8 + 0x8000;
  local_8._0_4_ = (int)(longlong)ROUND(local_20 * -255.0);
  iVar5 = iVar5 * 0x100 + (int)local_8;
  local_c = (float)(in_FPUControlWord | 0xc00);
  local_8 = (longlong)ROUND(local_1c * 255.0);
  local_10 = (float)((int)local_8 + iVar5 * -0x100);
  FUN_00618180(*(undefined4 *)((int)fVar1 + 0x54),0,*(undefined4 *)((int)fVar1 + 0x5c),&local_1c);
  uVar2 = local_18;
  local_c = (float)(in_FPUControlWord | 0xc00);
  local_8 = (longlong)ROUND(local_1c * 255.0);
  FUN_00618920(param_3,param_4,param_5,local_18,0,0x3f800000);
  if (DAT_02912eb8 == 0) {
    local_c = (float)(param_3 + 1);
    iVar5 = (uVar2 & 0xfffffffe) + param_4 * 2;
    local_14 = (float)(int)local_c;
    local_8 = CONCAT44(local_8._4_4_,iVar5);
    iVar3 = iVar5 * 4 + -8;
    iVar4 = FUN_006e6b90();
    iVar5 = param_4 * 8;
    FUN_005db5b0(iVar4 << 4,iVar5,iVar4 << 4,iVar3,0x80ffffff,DAT_02900c70);
    if (DAT_02912eb8 == 0) {
      local_10 = (float)param_3;
      iVar4 = FUN_006e6b90();
      FUN_005db5b0(iVar4 << 4,iVar5,iVar4 << 4,iVar3,0x80ffffff,DAT_02900c70);
      if (DAT_02912eb8 == 0) {
        local_c = (float)(param_3 + -1);
        iVar4 = FUN_006e6b90();
        FUN_005db5b0(iVar4 << 4,iVar5,iVar4 << 4,iVar3,0x80ffffff,DAT_02900c70);
        if (DAT_02912eb8 == 0) {
          iVar5 = (local_18 + param_4) * 8 + -8;
          iVar4 = FUN_006e6b90();
          iVar3 = (int)local_8 * 4;
          FUN_005db5b0(iVar4 << 4,iVar3,iVar4 << 4,iVar5,0x80000000,DAT_02900c70);
          if (DAT_02912eb8 == 0) {
            iVar4 = FUN_006e6b90();
            FUN_005db5b0(iVar4 << 4,iVar3,iVar4 << 4,iVar5,0x80000000,DAT_02900c70);
            if (DAT_02912eb8 == 0) {
              iVar4 = FUN_006e6b90();
              FUN_005db5b0(iVar4 << 4,iVar3,iVar4 << 4,iVar5,0x80000000,DAT_02900c70);
            }
          }
        }
      }
    }
  }
  FUN_00618180(*(undefined4 *)((int)fVar1 + 0x54),*(undefined4 *)((int)fVar1 + 0x58),
               *(undefined4 *)((int)fVar1 + 0x5c),&local_1c);
  local_8 = (longlong)ROUND(local_1c * 255.0);
  FUN_00618920(param_3,local_18 + param_4,param_5,local_18,0,0x3f800000);
  return param_5;
}

