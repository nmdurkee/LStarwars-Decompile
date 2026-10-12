/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x4763d0; label: FUN_004763d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004763d0(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_198;
  float local_194;
  int local_190;
  int local_18c;
  int local_188;
  undefined1 local_184 [128];
  undefined1 local_104 [128];
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_198;
  if (DAT_0087950c == 0) {
    if (DAT_008794ec == -1) {
      if (DAT_00879580 == -1) {
        iVar5 = -1;
      }
      else {
        iVar5 = (int)*(short *)(DAT_00879580 * 0x9c + 0x78 + DAT_00951354);
      }
      FUN_004f1f10(local_184,*(undefined4 *)(DAT_00926c20 + iVar5 * 4));
      local_18c = 1;
      iVar5 = 1;
    }
    else {
      FUN_004f1f10(local_184,*(undefined4 *)(DAT_00926c20 + DAT_00880704 * 4));
      FUN_004f1f10(local_104,*(undefined4 *)(DAT_00926c20 + DAT_00880698 * 4));
      FUN_004f1f10(local_84,*(undefined4 *)(DAT_00926c20 + DAT_00880694 * 4));
      iVar5 = FUN_0059b6a0(DAT_00956290 + DAT_008794ec * 0x1c,5,4);
      iVar6 = FUN_0059b6a0(DAT_00956290 + DAT_008794ec * 0x1c,5,5);
      if (((iVar5 != -1) &&
          (iVar5 = (int)*(short *)(iVar5 * 0x9c + 0x78 + DAT_00951354), iVar5 != -1)) &&
         (*(int *)(DAT_00926c20 + iVar5 * 4) != 0)) {
        FUN_004f1e80(local_104,&DAT_007596fc);
        FUN_004f1e80(local_104,*(undefined4 *)(DAT_00926c20 + iVar5 * 4));
        FUN_004f1e80(local_104,&DAT_00755d70);
      }
      if (((iVar6 != -1) &&
          (iVar5 = (int)*(short *)(iVar6 * 0x9c + 0x78 + DAT_00951354), iVar5 != -1)) &&
         (*(int *)(DAT_00926c20 + iVar5 * 4) != 0)) {
        FUN_004f1e80(local_84,&DAT_007596fc);
        FUN_004f1e80(local_84,*(undefined4 *)(DAT_00926c20 + iVar5 * 4));
        FUN_004f1e80(local_84,&DAT_00755d70);
      }
      iVar5 = 3;
      local_18c = 3;
    }
    local_188 = FUN_006e6b90();
    local_190 = 0;
    local_194 = _DAT_007f9330 - (float)(iVar5 + -1) * -0.1;
    if (iVar5 != 0) {
      do {
        bVar4 = DAT_00921dae;
        if ((param_1 == 0) || (DAT_00879584 != local_190)) {
          uVar8 = (uint)DAT_00921da9;
          uVar9 = (uint)DAT_0080099a;
          uVar7 = (uint)DAT_0080099b;
        }
        else {
          bVar1 = DAT_008009a2;
          bVar2 = DAT_00921dae;
          bVar3 = DAT_008009a1;
          if (DAT_009213e4 != 0) {
            bVar1 = DAT_008009a0;
            bVar2 = DAT_0080099f;
            bVar3 = DAT_00921dad;
          }
          uVar8 = (uint)bVar3;
          uVar9 = (uint)bVar2;
          uVar7 = (uint)bVar1;
          if (0.0 < _DAT_00921d70) {
            local_198 = (uint)DAT_008009a1;
            uVar8 = FUN_006e6b90();
            local_198 = (uint)bVar4;
            uVar9 = FUN_006e6b90();
            local_198 = (uint)DAT_008009a2;
            uVar7 = FUN_006e6b90();
          }
        }
        iVar5 = local_188;
        if ((local_190 == 2) &&
           (iVar6 = FUN_00594b70(&DAT_00855f24,0x4000000,0x4000000,0,0,0,0), iVar6 < 1)) {
          iVar5 = (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2;
        }
        FUN_0050d910(local_184 + local_190 * 0x80,0,local_194,0x3f800000,0x3f333333,0x3f333333,
                     0x3f333333,0,uVar8,uVar9,uVar7,0x3fd9999a,1,0,0,iVar5);
        local_194 = local_194 - 0.2;
        local_190 = local_190 + 1;
      } while (local_190 < local_18c);
    }
    __security_check_cookie(local_4 ^ (uint)&local_198);
    return;
  }
  FUN_00475390(param_1,param_2);
  __security_check_cookie(local_4 ^ (uint)&local_198);
  return;
}

