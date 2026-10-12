/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x457f70; label: FUN_00457f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00457f70(short *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined2 in_FPUControlWord;
  float10 fVar8;
  float10 extraout_ST0;
  float local_424;
  float local_420;
  uint local_41c;
  float local_418;
  float local_414;
  float local_410;
  float local_40c;
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_424;
  if ((param_1 != (short *)0x0) && (_DAT_00950780 == 0.0)) {
    fVar8 = (float10)FUN_00457ec0();
    local_414 = (float)fVar8;
    local_410 = 0.0;
    if (0.0 < local_414) {
      local_40c = local_410;
      if ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x400) == 0) {
        local_40c = -0.7;
      }
      if ((*(byte *)(param_1 + 1) & 4) == 0) {
        iVar6 = 2;
        local_410 = -_DAT_007fc31c + 0.09;
      }
      else {
        iVar6 = 0;
      }
      local_418 = -_DAT_007fc31c;
      if (*(int *)(DAT_00926c20 + *param_1 * 4) != 0) {
        FUN_0054bd50(*(undefined4 *)(DAT_00926c20 + *param_1 * 4),local_404);
        fVar8 = (float10)FUN_005b7d30(_DAT_00925030,0x3f000000);
        uVar7 = (uint)*(char *)((int)param_1 + 3);
        local_424 = (float)(&DAT_029899a0)
                           [(uint)(int)ROUND(fVar8 * (float10)2.0 * (float10)65536.0) >> 1 & 0x7fff]
                    * 0.5 + 0.5;
        if (*(char *)((int)param_1 + 3) == -1) {
          uVar7 = (uint)DAT_009514bd;
        }
        local_41c = (uint)(byte)(&DAT_00761ea4)[uVar7 * 3];
        local_420 = (float)local_41c;
        uVar2 = FUN_006e6b90();
        local_424 = (float)(uint)(byte)(&DAT_00761ea5)[uVar7 * 3];
        local_420 = (float)(int)local_424;
        uVar3 = FUN_006e6b90();
        local_424 = (float)(uint)*(byte *)((int)&PTR_DAT_00761ea6 + uVar7 * 3);
        local_420 = (float)(int)local_424;
        uVar4 = FUN_006e6b90();
        if (param_2 == -1) {
          param_2 = 3;
        }
        if (iVar6 == 0) {
          local_420 = (float)CONCAT22(local_420._2_2_,in_FPUControlWord);
          local_424 = (float)(int)ROUND(local_414 * 128.0);
          FUN_0050d910(local_404,local_410,local_40c,0x3f800000,0x3f000000,0x3f000000,0x3f000000,0,
                       uVar2,uVar3,uVar4,0x3fb33333,param_2,0,0,(uint)local_424 & 0xff);
          local_418 = -(DAT_009213ec * 0.5) - 0.075;
        }
        else {
          local_420 = (float)CONCAT22(local_420._2_2_,in_FPUControlWord);
          local_424 = (float)((extraout_ST0 - ((float10)1.0 + (float10)local_410)) -
                             (float10)0.15000000596046448);
          FUN_0050d910(local_404,local_410,local_40c,0x3f800000,0x3f000000,0x3f000000,0x3f000000,
                       iVar6,uVar2,uVar3,uVar4,local_424,param_2,0,0,
                       (int)ROUND(local_414 * 128.0) & 0xff);
        }
      }
      iVar1 = *(int *)(PTR_DAT_00802c54 + 0x2ac0);
      if (*(char *)(iVar1 + 0xd4e) != '\0') {
        iVar5 = FUN_006e6b90();
        local_418 = (local_418 - -1.1) * (float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] - 1.1;
        fVar8 = (float10)FUN_005b7d30(_DAT_0092505c,0x40200000,0,iVar1 + 0xd40,2);
        local_420 = (float)CONCAT22(local_420._2_2_,in_FPUControlWord);
        local_424 = (float)(int)ROUND((fVar8 / (float10)2.5) * (float10)65536.0);
        FUN_00552d10(local_418,local_40c,0x3f800000,0x3f000000,0x3f000000,0x3f000000,0,
                     (uint)local_424 & 0xffff);
        if (iVar6 == 0) {
          fVar8 = (float10)FUN_005b7d30(_DAT_0092505c,0x40200000,0,
                                        *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd40,2);
          local_420 = (float)CONCAT22(local_420._2_2_,in_FPUControlWord);
          local_424 = (float)(int)ROUND((fVar8 / (float10)2.5) * (float10)65536.0);
          FUN_00552d10(-local_418,local_40c,0x3f800000,0x3f000000,0x3f000000,0x3f000000,0,
                       (uint)local_424 & 0xffff);
        }
      }
      __security_check_cookie(local_4 ^ (uint)&local_424);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_424);
  return;
}

