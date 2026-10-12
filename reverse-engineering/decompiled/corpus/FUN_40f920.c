/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40f920; label: FUN_0040f920
 */

void FUN_0040f920(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int extraout_ECX;
  float *pfVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  float10 fVar9;
  int local_110;
  int local_10c;
  int local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_110;
  local_110 = param_2;
  _sprintf(local_104,"%s%s",param_1 + 0x80,PTR_DAT_007f1204);
  FUN_006211c0(1);
  iVar1 = FUN_00621270(local_104,0);
  if (iVar1 != 0) {
    iVar2 = FUN_006217e0();
    local_108 = iVar2;
    iVar3 = FUN_006217e0();
    iVar1 = param_3;
    if (param_3 < iVar3) {
      FUN_0040e700(local_104);
      iVar1 = extraout_ECX;
    }
    iVar6 = 0;
    if (0 < iVar3) {
      do {
        FUN_0040f850(iVar6);
        iVar6 = iVar6 + 1;
        iVar1 = param_3;
      } while (iVar6 < iVar3);
    }
    if (iVar2 < 4) {
      iVar2 = 0;
      iVar6 = local_110;
      iVar8 = iVar3;
      if (0 < iVar3) {
        do {
          fVar9 = (float10)FUN_0040f5c0();
          *(float *)(iVar6 + 0x410) = (float)fVar9;
          iVar8 = iVar8 + -1;
          iVar1 = param_3;
          iVar2 = iVar3;
          iVar6 = iVar6 + 0x530;
        } while (iVar8 != 0);
      }
    }
    else {
      iVar2 = 0;
      if (0 < iVar3) {
        piVar7 = (int *)(local_110 + 0x400);
        local_10c = iVar3;
        do {
          fVar9 = (float10)FUN_006217a0();
          piVar7[4] = (int)(float)fVar9;
          if (local_108 < 5) {
            fVar9 = (float10)FUN_0040f6f0();
            piVar7[4] = (int)(float)fVar9;
          }
          else {
            iVar1 = 0;
            if (0 < *piVar7) {
              pfVar5 = (float *)(piVar7 + 5);
              do {
                fVar9 = (float10)FUN_006217a0();
                *pfVar5 = (float)fVar9;
                iVar1 = iVar1 + 1;
                pfVar5 = pfVar5 + 1;
              } while (iVar1 < *piVar7);
            }
          }
          piVar7 = piVar7 + 0x14c;
          local_10c = local_10c + -1;
        } while (local_10c != 0);
        local_10c = 0;
        iVar1 = param_3;
        iVar2 = iVar3;
      }
    }
    if (iVar2 < iVar1) {
      puVar4 = (undefined4 *)(iVar2 * 0x530 + 0x400 + local_110);
      iVar1 = iVar1 - iVar2;
      do {
        *puVar4 = 0;
        puVar4 = puVar4 + 0x14c;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    FUN_006213e0();
  }
  __security_check_cookie(local_4 ^ (uint)&local_110);
  return;
}

