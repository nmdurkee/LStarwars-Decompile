/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x460c10; label: FUN_00460c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00460c10(int param_1,int param_2,float param_3)

{
  int iVar1;
  float fVar2;
  short sVar3;
  char *pcVar4;
  int iVar5;
  short *psVar6;
  float local_120;
  int local_11c;
  int local_118;
  float local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_120;
  iVar5 = ((uint)DAT_0086e4e2 - (uint)*(byte *)(param_2 + 0xbd)) + -1;
  local_118 = param_1;
  local_11c = iVar5;
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(float *)(param_1 + 0x1c) = (float)iVar5 * 2.5 + 2.0 + 3.0 + 1.0 + 1.0;
    __security_check_cookie(local_4 ^ (uint)&local_120);
    return;
  }
  if (*(int *)(param_1 + 0x14) == 1) {
    local_114 = *(float *)(param_1 + 0x18);
    local_120 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = local_120;
    if (*(float *)(param_1 + 0x1c) < local_120 != (*(float *)(param_1 + 0x1c) == local_120)) {
      FUN_004838f0(param_2);
      __security_check_cookie(local_4 ^ (uint)&local_120);
      return;
    }
    local_120 = 0.0;
    if (-1 < iVar5) {
      psVar6 = (short *)(param_2 + 300);
      do {
        fVar2 = local_120;
        local_120 = (float)(int)local_120 * 2.5 + 2.0;
        if ((local_114 < local_120) && (local_120 <= *(float *)(param_1 + 0x18))) {
          FUN_00681f40("TrueJedi_100pc",0);
          FUN_004836f0(0xffffffff,0x3f19999a,0,0);
          iVar1 = *(byte *)(param_2 + 0xbd) + 1 + (int)fVar2;
          _sprintf(local_104,"%i/%i",iVar1,DAT_0093b30c);
          FUN_00561b20(local_104,0,0x3e99999a,0x3f400000,0x3fa00000,1,1);
          sVar3 = *psVar6;
          local_110 = 0;
          local_10c = 0x3d19999a;
          local_108 = 0x3f800000;
          if (sVar3 == DAT_00880f7c) {
            FUN_004f1f10(local_104,*(undefined4 *)(DAT_00926c20 + sVar3 * 4));
            if (DAT_0093b314 != 0) {
              FUN_004f1e80(local_104,&DAT_007587cc);
              sVar3 = DAT_00880888;
              if ((*(byte *)(param_2 + 0xb0) & 0x40) == 0) {
                sVar3 = DAT_00880884;
              }
              FUN_004f1e80(local_104,*(undefined4 *)(DAT_00926c20 + sVar3 * 4));
            }
            pcVar4 = local_104;
          }
          else {
            pcVar4 = *(char **)(DAT_00926c20 + sVar3 * 4);
          }
          FUN_00560fa0(pcVar4,&local_110,0x3f333333,&local_110,0x3f333333,0xff,0,0x7f,0x4020,
                       0x40000000);
          iVar5 = local_11c;
          param_1 = local_118;
          if (0x3c < iVar1) {
            FUN_005533f0(*(undefined4 *)(param_2 + 0x1c),100000,0,0);
            _DAT_0087b93c = 0x3fc00000;
            FUN_00681f40("Shop_BuyCheat",0);
            FUN_0054bb30(100000,local_104);
            FUN_00561b20(local_104,0,-_DAT_007fc310,0x3f000000,0x3fa00000,0,0);
            iVar5 = local_11c;
            param_1 = local_118;
          }
        }
        local_120 = (float)((int)fVar2 + 1);
        psVar6 = psVar6 + 1;
      } while ((int)local_120 <= iVar5);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_120);
  return;
}

