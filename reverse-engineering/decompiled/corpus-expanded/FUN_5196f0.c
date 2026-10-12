/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x5196f0; label: FUN_005196f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005196f0(int param_1,int param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  int iVar8;
  undefined8 uVar9;
  int local_310;
  float local_30c [2];
  float local_304;
  int aiStack_300 [192];
  
  if (param_1 != 0) {
    iVar5 = *(int *)(param_1 + 0x1380);
    iVar8 = 0;
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0x137c)) {
      do {
        if (0xbf < iVar4) break;
        if ((*(char *)(iVar5 + 0x48) != '\0') &&
           ((*(char *)(iVar5 + 0x4b) == '\0' || (iVar3 = FUN_005cfd60(iVar5 + 0x20), iVar3 != 0))))
        {
          aiStack_300[iVar4] = iVar5;
          iVar4 = iVar4 + 1;
        }
        iVar8 = iVar8 + 1;
        iVar5 = iVar5 + 0x58;
      } while (iVar8 < *(int *)(param_1 + 0x137c));
    }
    iVar5 = 0;
    pcVar6 = &DAT_009222b3;
    do {
      if (0xbf < iVar4) break;
      if ((pcVar6[-3] != '\0') &&
         ((*pcVar6 == '\0' || (iVar8 = FUN_005cfd60(pcVar6 + -0x2b), iVar8 != 0)))) {
        aiStack_300[iVar4] = (int)(pcVar6 + -0x4b);
        iVar4 = iVar4 + 1;
      }
      iVar5 = iVar5 + 1;
      pcVar6 = pcVar6 + 0x58;
    } while (iVar5 < 0x40);
    if ((iVar4 != 0) && (local_310 = 0, 0 < param_2)) {
      do {
        iVar5 = *(int *)(param_3 + local_310 * 4);
        if (((*(uint *)(iVar5 + 0x1fc) & 0x20000) == 0) &&
           ((-1 < (char)*(uint *)(iVar5 + 0x1fc) && (iVar8 = 0, 0 < iVar4)))) {
          do {
            pfVar1 = (float *)aiStack_300[iVar8];
            iVar3 = FUN_005cfac0(iVar5 + 0x20c);
            if (((iVar3 == 0) || (iVar3 = FUN_005d0450(iVar5 + 0x20c,pfVar1 + 8), iVar3 == 0)) &&
               (uVar9 = __allshl(),
               ((uint)uVar9 & (uint)pfVar1[0x14]) == 0 &&
               ((uint)((ulonglong)uVar9 >> 0x20) & (uint)pfVar1[0x15]) == 0)) {
              fVar2 = *(float *)(*(int *)(iVar5 + 4) + 0x120) + pfVar1[3];
              local_30c[0] = *(float *)(*(int *)(iVar5 + 4) + 0x114) - *pfVar1;
              if ((((local_30c[0] <= fVar2) && (-fVar2 <= local_30c[0])) &&
                  ((local_304 = *(float *)(*(int *)(iVar5 + 4) + 0x11c) - pfVar1[2],
                   local_304 <= fVar2 &&
                   ((-fVar2 <= local_304 && (*(float *)(iVar5 + 0x17c) <= pfVar1[6])))))) &&
                 (pfVar1[4] <= *(float *)(iVar5 + 0x188))) {
                (*(code *)(&PTR_FUN_00801c7c)[*(byte *)((int)pfVar1 + 0x4a)])
                          (iVar5,pfVar1,local_30c,fVar2);
              }
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar4);
        }
        local_310 = local_310 + 1;
      } while (local_310 < param_2);
    }
  }
  pbVar7 = &DAT_009222b1;
  do {
    if ((pbVar7[-1] != 0) && ((*pbVar7 & 4) != 0)) {
      _memset(pbVar7 + -0x49,0,0x58);
    }
    pbVar7 = pbVar7 + 0x58;
  } while ((int)pbVar7 < 0x9238b1);
  return;
}

