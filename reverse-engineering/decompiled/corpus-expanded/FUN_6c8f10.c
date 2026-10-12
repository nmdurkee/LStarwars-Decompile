/* Ghidra pseudocode, not original source.
 * ev_cc6b5d9c9dc19119c5b50c1e1d885dc592b880ad73e24652555bc61e14428cde
 * Entry: 0x6c8f10; label: FUN_006c8f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Type propagation algorithm not settling */

int FUN_006c8f10(float *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_110;
  int *piStack_10c;
  int local_108;
  int local_104;
  int local_100;
  float fStack_fc;
  int local_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  int local_d0 [16];
  int local_90 [16];
  undefined1 auStack_50 [48];
  undefined1 auStack_20 [28];
  
  local_90[0] = 0;
  _memset(local_90 + 1,0,0x3c);
  local_d0[0] = 0;
  _memset(local_d0 + 1,0,0x3c);
  iVar3 = 0;
  local_108 = 0;
  local_104 = 0;
  if (0 < DAT_02973bac) {
    local_100 = 0;
    do {
      iVar4 = local_100 + DAT_02973b90;
      if (((*(uint *)(local_f8 + 0x6c) & 1 << ((byte)local_104 & 0x1f)) != 0) &&
         ((*(byte *)(iVar4 + 4) & 8) != 0)) {
        for (iVar1 = (**(code **)(**(int **)(iVar4 + 0x14) + 0x14))(0); iVar1 != 0;
            iVar1 = (**(code **)(**(int **)(iVar4 + 0x14) + 0x14))(iVar1)) {
          iVar2 = FUN_006c8b60(iVar1,iVar4,0xffffffff);
          if ((iVar2 != 0) && (iVar2 = FUN_006c6a10(&uStack_110,iVar1,8,1), iVar2 != 0)) {
            if ((*(byte *)(piStack_10c + 7) & 8) != 0) {
              if (piStack_10c[3] == DAT_02973abc) {
                (**(code **)(*piStack_10c + 4))(uStack_110,DAT_02973abc,auStack_50,0);
                FUN_004ef660(&fStack_e0,auStack_20,0x10);
                iVar3 = local_108;
              }
              else {
                (**(code **)(*piStack_10c + 4))(uStack_110,DAT_02973ab8,&fStack_e0,0);
              }
            }
            fStack_f0 = fStack_e0 - *param_1;
            fStack_ec = fStack_dc - param_1[1];
            fStack_e8 = fStack_d8 - param_1[2];
            fStack_f4 = fStack_e8 * fStack_e8 + fStack_f0 * fStack_f0 + fStack_ec * fStack_ec;
            fStack_fc = 1.0;
            iVar2 = FUN_006c6a10(&uStack_110,iVar1,0x40,1);
            if ((iVar2 != 0) && ((*(byte *)(piStack_10c + 7) & 0x40) != 0)) {
              (**(code **)(*piStack_10c + 4))(uStack_110,DAT_02973ab4,&fStack_fc,0);
            }
            if ((fStack_f4 < fStack_fc * fStack_fc) && (iVar3 < 0x10)) {
              local_d0[iVar3] = iVar1;
              local_90[iVar3] = iVar4;
              iVar3 = iVar3 + 1;
              local_108 = iVar3;
            }
          }
        }
      }
      local_104 = local_104 + 1;
      local_100 = local_100 + 0x18;
    } while (local_104 < DAT_02973bac);
  }
  iVar4 = 0;
  if (local_d0[0] != 0) {
    if (-1 < iVar3) {
      do {
        if (local_d0[iVar4] == *(int *)(param_3 + 4)) {
          if (iVar4 < iVar3 + -1) {
            iVar3 = local_90[iVar4 + 1];
            param_2[1] = local_d0[iVar4 + 1];
            *param_2 = iVar3;
            return 1;
          }
          break;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 <= iVar3);
    }
    param_2[1] = local_d0[0];
    *param_2 = local_90[0];
    iVar4 = 1;
  }
  return iVar4;
}

