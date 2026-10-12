/* Ghidra analysis pseudocode, not original source.
 * ev_8e6c58f632ba894c996161736f16e550f9c9cdfbb0c94bd06c2a8d698c289bc5
 * Entry: 0x5d49b0; label: FUN_005d49b0
 */

void FUN_005d49b0(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,uint param_6)

{
  char *pcVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  short *psVar13;
  int local_270;
  int local_26c;
  int local_268;
  int local_264;
  undefined4 local_260;
  int local_25c;
  int local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_24c;
  undefined1 local_244 [64];
  short local_204 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_270;
  local_260 = param_2;
  local_25c = param_3;
  local_258 = param_5;
  if ((DAT_0080c008 != 0) &&
     (iVar4 = FUN_006042e0(param_1 + 0x1ac,param_1 + 0x1b8,param_2,0,0), iVar4 != 0)) {
    piVar8 = *(int **)(param_1 + 0x19c);
    if ((piVar8 != (int *)0x0) &&
       ((*(char *)(param_1 + 0x1a0) == '\0' && (uVar9 = 0, *(char *)((int)piVar8 + 0xf) != -1)))) {
      do {
        uVar7 = (uint)*(byte *)(piVar8 + 3);
        if (uVar7 != 0) {
          pbVar5 = (byte *)(*piVar8 + 4);
          do {
            if ((*pbVar5 & 1) == 0) {
              uVar9 = uVar9 + 1;
            }
            pbVar5 = pbVar5 + 0x30;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        uVar7 = (uint)*(byte *)((int)piVar8 + 0xd);
        if (uVar7 != 0) {
          pbVar5 = (byte *)(piVar8[1] + 4);
          do {
            if ((*pbVar5 & 1) == 0) {
              uVar9 = uVar9 + 1;
            }
            pbVar5 = pbVar5 + 0x40;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        pcVar1 = (char *)((int)piVar8 + 0x1f);
        piVar8 = piVar8 + 4;
      } while (*pcVar1 != -1);
      if (uVar9 != 0) {
        if (0 < (int)uVar9) {
          psVar13 = local_204;
          for (uVar7 = uVar9 >> 1; uVar7 != 0; uVar7 = uVar7 - 1) {
            psVar13[0] = 0;
            psVar13[1] = 0;
            psVar13 = psVar13 + 2;
          }
          for (uVar7 = (uint)((uVar9 & 1) != 0); uVar7 != 0; uVar7 = uVar7 - 1) {
            *psVar13 = 0;
            psVar13 = psVar13 + 1;
          }
        }
        iVar4 = param_4;
        if (0 < param_4) {
          do {
            iVar6 = FUN_005b9e50();
            local_204[(int)(CONCAT44(iVar6 >> 0x1f,iVar6 >> 8) % (longlong)(int)uVar9)] =
                 local_204[(int)(CONCAT44(iVar6 >> 0x1f,iVar6 >> 8) % (longlong)(int)uVar9)] + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        cVar2 = *(char *)((int)*(int **)(param_1 + 0x19c) + 0xf);
        local_270 = 0;
        piVar8 = *(int **)(param_1 + 0x19c);
        while (cVar2 != -1) {
          iVar4 = 0;
          if (param_4 != 0) {
            local_268 = 0;
            local_26c = 0;
            if ((char)piVar8[3] != '\0') {
              do {
                if ((param_6 == 0) || ((*(uint *)(iVar4 + 4 + *piVar8) & param_6) == 0)) {
                  sVar3 = local_204[local_270];
                  psVar13 = local_204 + local_270;
                  if (sVar3 != 0) {
                    if (local_268 == 0) {
                      FUN_005c0500(local_244,(uint)*(byte *)((int)piVar8 + 0xf) * 0x40 + local_25c,
                                   local_260);
                      local_268 = 1;
                    }
                    if (0 < sVar3) {
                      iVar11 = (int)*psVar13;
                      iVar6 = param_4 - iVar11;
                      puVar12 = (undefined4 *)(local_258 + param_4 * 0xc);
                      do {
                        FUN_005d4780(&local_254,local_244,*piVar8 + iVar4);
                        puVar12[-3] = local_254;
                        iVar11 = iVar11 + -1;
                        puVar12[-2] = local_250;
                        puVar12[-1] = local_24c;
                        puVar12 = puVar12 + -3;
                        param_4 = iVar6;
                      } while (iVar11 != 0);
                    }
                  }
                  local_270 = local_270 + 1;
                }
                local_26c = local_26c + 1;
                iVar4 = iVar4 + 0x30;
              } while (local_26c < (int)(uint)*(byte *)(piVar8 + 3));
            }
            local_26c = 0;
            if (*(char *)((int)piVar8 + 0xd) != '\0') {
              local_264 = 0;
              do {
                iVar4 = local_26c;
                if ((param_6 == 0) ||
                   (iVar6 = local_26c, (*(uint *)(local_264 + 4 + *piVar8) & param_6) == 0)) {
                  sVar3 = local_204[local_270];
                  psVar13 = local_204 + local_270;
                  iVar6 = iVar4;
                  if (sVar3 != 0) {
                    if (local_268 == 0) {
                      FUN_005c0500(local_244,(uint)*(byte *)((int)piVar8 + 0xf) * 0x40 + local_25c,
                                   local_260);
                      local_268 = 1;
                    }
                    if (0 < sVar3) {
                      iVar10 = (int)*psVar13;
                      iVar11 = param_4 - iVar10;
                      puVar12 = (undefined4 *)(local_258 + param_4 * 0xc);
                      do {
                        FUN_005d48a0(&local_254,local_244,piVar8[1] + iVar4 * 0x40);
                        puVar12[-3] = local_254;
                        iVar10 = iVar10 + -1;
                        puVar12[-2] = local_250;
                        puVar12[-1] = local_24c;
                        iVar6 = local_26c;
                        puVar12 = puVar12 + -3;
                        param_4 = iVar11;
                      } while (iVar10 != 0);
                    }
                  }
                  local_270 = local_270 + 1;
                }
                local_264 = local_264 + 0x30;
                local_26c = iVar6 + 1;
              } while (local_26c < (int)(uint)*(byte *)((int)piVar8 + 0xd));
            }
          }
          cVar2 = *(char *)((int)piVar8 + 0x1f);
          piVar8 = piVar8 + 4;
        }
      }
    }
    __security_check_cookie(local_4 ^ (uint)&local_270);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_270);
  return;
}

