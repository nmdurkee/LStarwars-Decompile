/* Ghidra pseudocode, not original source.
 * ev_817077ca9f28b5da8eda466d74b875e7bf54783851332e01356736ec14054f9d
 * Entry: 0x589f80; label: FUN_00589f80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00589f80(void)

{
  undefined4 uVar1;
  float fVar2;
  uint uVar3;
  byte bVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  float10 fVar11;
  float local_20;
  int local_1c;
  int local_14;
  float local_c;
  float local_8;
  float local_4;
  
  local_14 = 0;
  iVar10 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if ((((((*(uint *)(iVar10 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar10 + 0x1fc) & 0x1000) != 0))
           && (*(char *)(iVar10 + 0x28b) == '\0')) &&
          (((iVar7 = *(int *)(iVar10 + 0x54), (*(uint *)(iVar7 + 4) & 0x10000) == 0 &&
            (*(char *)(iVar10 + 0x1079) != '\0')) &&
           ((*(short *)(*(int *)(iVar7 + 0x24) + 0xf0) != 0 &&
            ((*(char *)(iVar10 + 0x288) != '\0' &&
             ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar10 + 0x7b5) * 0x10 + 8) & 0x20000) == 0)))
            ))))) && (0.0 < *(float *)(iVar10 + 0x1020))) {
        *(undefined2 *)(iVar10 + 0x105a) = *(undefined2 *)(*(int *)(iVar7 + 0x24) + 0xf0);
        if (99.0 <= *(float *)(*(int *)(iVar7 + 0x24) + 0x8c)) {
          uVar1 = *(undefined4 *)(iVar7 + 0x30);
        }
        else {
          uVar1 = *(undefined4 *)(*(int *)(iVar7 + 0x24) + 0x8c);
        }
        iVar6 = 0;
        *(undefined4 *)(iVar10 + 0x1024) = uVar1;
        local_1c = 0;
        bVar4 = 0;
        iVar7 = 0x14;
        pfVar8 = (float *)(iVar10 + 0x834);
        pfVar9 = (float *)(iVar10 + 0x6c8);
        do {
          if (4 < iVar6) goto LAB_0058a241;
          if ((((uint)*(ushort *)(iVar10 + 0x105a) & 1 << (bVar4 & 0x1f)) != 0) &&
             (*(int *)(iVar7 + *(int *)(iVar10 + 0x50)) != 0)) {
            pfVar9[-1] = *pfVar8;
            pfVar9[1] = pfVar8[2];
            if ((*(byte *)(iVar10 + 0x1fc) & 0x10) == 0) {
              local_c = *pfVar8;
              local_8 = pfVar8[1];
              local_4 = pfVar8[2];
              fVar11 = (float10)FUN_005506f0(iVar10,&local_c,0x40a00000,0xffffffff);
              local_20 = (float)fVar11;
              *pfVar9 = local_20;
              if (local_20 != 2e+06) {
                uVar3 = FUN_0067a670();
                if (((_DAT_02920d84 != 2e+06) && (uVar3 < 0x11)) &&
                   (((&DAT_0080364c)[uVar3 * 0xc] & 1) != 0)) {
                  if (local_20 < _DAT_02920d84) {
                    *pfVar9 = 2e+06;
                    local_20 = 2e+06;
                  }
                  else if (pfVar8[1] + 0.075 < local_20) {
                    *pfVar9 = 2e+06;
                    local_20 = 2e+06;
                  }
                }
                if (local_20 != 2e+06) {
                  pfVar9[3] = DAT_0292fdbc;
                  FUN_0054fec0(&DAT_0292fdb8,0,0);
                  *(undefined2 *)(pfVar9 + 2) = DAT_0092b0c4;
                  *(undefined2 *)((int)pfVar9 + 10) = DAT_0092b0c0;
                }
              }
            }
            else {
              fVar2 = *(float *)(iVar10 + 0x21c);
              *(undefined2 *)(pfVar9 + 2) = 0;
              *pfVar9 = fVar2;
              *(undefined2 *)((int)pfVar9 + 10) = 0;
              pfVar9[3] = 1.0;
            }
            iVar6 = local_1c + 1;
            pfVar9 = pfVar9 + 5;
            local_1c = iVar6;
          }
          bVar4 = bVar4 + 1;
          iVar7 = iVar7 + 4;
          pfVar8 = pfVar8 + 0x10;
        } while (iVar7 < 0x54);
        if (iVar6 < 5) {
          iVar7 = 5 - iVar6;
          puVar5 = (undefined4 *)(iVar10 + 0x6c8 + iVar6 * 0x14);
          do {
            iVar7 = iVar7 + -1;
            *puVar5 = 0x49f42400;
            puVar5 = puVar5 + 5;
          } while (iVar7 != 0);
        }
      }
LAB_0058a241:
      local_14 = local_14 + 1;
      iVar10 = iVar10 + 0x10d8;
    } while (local_14 < DAT_0093d500);
  }
  return;
}

