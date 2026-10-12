/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40fac0; label: FUN_0040fac0
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_0040fac0(int param_1,int param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  float *pfVar5;
  int local_2054;
  undefined4 local_2050;
  undefined4 local_204c;
  undefined4 local_2048;
  undefined4 local_2044;
  int local_2038;
  int local_2034;
  float local_2030;
  float local_202c;
  float local_2028;
  int local_2014;
  float local_2010 [2047];
  undefined4 uStack_14;
  
  uStack_14 = 0x40fad0;
  if ((param_2 != 1) && ((param_2 == 2 || (param_2 == 3)))) {
    local_2038 = 0x14;
    if (param_2 == 3) {
      local_2038 = *(int *)(param_1 + 0x400) * 8;
    }
    local_2054 = local_2038;
    FUN_0040f510(local_2010,local_2038);
    if (1 < local_2054) {
      local_2054 = local_2054 + -1;
      pfVar5 = local_2010 + 2;
      do {
        if (param_2 == 3) {
          local_2030 = pfVar5[2] - pfVar5[-2];
          local_202c = pfVar5[3] - pfVar5[-1];
          local_2028 = pfVar5[4] - *pfVar5;
          sVar1 = FUN_005be2d0(local_2030,local_2028);
          FUN_005b3620(&local_2050,&local_2030,-(int)sVar1);
          sVar2 = FUN_005be2d0(local_204c,local_2048);
          local_2050 = 0x3f800000;
          local_204c = 0;
          local_2048 = 0;
          local_2044 = 0;
          sVar3 = FUN_006e6b90();
          FUN_005b3690(&local_2050,&local_2050,(int)sVar3);
          FUN_005b35a0(&local_2050,&local_2050,-(int)sVar2);
          FUN_005b3620(&local_2050,&local_2050,(int)sVar1);
        }
        pfVar5 = pfVar5 + 4;
        local_2054 = local_2054 + -1;
      } while (local_2054 != 0);
    }
    local_2014 = *(int *)(param_1 + 0x400);
    local_2034 = 0;
    if (0 < local_2014) {
      do {
        local_2014 = local_2014 + -1;
        iVar4 = FUN_006e6b90();
        if (iVar4 < 0) {
          iVar4 = 0;
        }
        else if (local_2038 + -2 < iVar4) {
          iVar4 = local_2038 + -2;
        }
        local_2030 = local_2010[iVar4 * 4 + 4] - local_2010[iVar4 * 4];
        local_202c = local_2010[iVar4 * 4 + 5] - local_2010[iVar4 * 4 + 1];
        local_2028 = local_2010[iVar4 * 4 + 6] - local_2010[iVar4 * 4 + 2];
        sVar1 = FUN_005be2d0(local_2030,local_2028);
        FUN_005b3620(&local_2050,&local_2030,-(int)sVar1);
        sVar2 = FUN_005be2d0(local_204c,local_2048);
        local_2050 = 0x40000000;
        local_204c = 0;
        local_2048 = 0;
        local_2044 = 0;
        sVar3 = FUN_006e6b90();
        FUN_005b3690(&local_2050,&local_2050,(int)sVar3);
        FUN_005b35a0(&local_2050,&local_2050,-(int)sVar2);
        FUN_005b3620(&local_2050,&local_2050,(int)sVar1);
        local_2014 = *(int *)(param_1 + 0x400);
        local_2034 = local_2034 + 1;
      } while (local_2034 < local_2014);
    }
  }
  return;
}

