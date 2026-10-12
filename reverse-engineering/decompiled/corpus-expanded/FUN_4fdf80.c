/* Ghidra pseudocode, not original source.
 * ev_291f832bd6f6d010a6248a6acee690ff87721c4cdff92148d1e7c4ba042507e6
 * Entry: 0x4fdf80; label: FUN_004fdf80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004fdf80(undefined4 param_1,uint *param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  uint *puVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  short *psVar11;
  int iVar12;
  uint uVar13;
  short *psVar14;
  char *pcVar15;
  char *pcVar16;
  uint *puVar17;
  int local_10;
  int local_8;
  
  iVar7 = (int)DAT_0091eef4;
  puVar3 = &DAT_0091eed0 + iVar7 * 3;
  if (*puVar3 != 0) {
    FUN_004ef790();
  }
  param_3 = param_3 + -0x100000;
  *puVar3 = 0;
  *(undefined4 *)(&DAT_0091eed8 + iVar7 * 0xc) = 0;
  (&DAT_0091eed4)[iVar7 * 3] = 0;
  local_10 = 0;
  local_8 = 0;
  iVar8 = FUN_004fd5d0(param_1,param_3,0x100000);
  if (0x100000 - iVar8 < 0x8000) {
    FUN_004ef790();
  }
  pcVar2 = (char *)(param_3 + iVar8);
  if (0 < iVar8) {
    iVar12 = 0;
    piVar9 = &DAT_02983750;
    do {
      if (*piVar9 == 0) {
        iVar6 = iVar12 * 0x14;
        *(char **)(&DAT_02983744 + iVar6) = pcVar2 + -1;
        iVar1 = iVar12 + 0x400;
        *(int *)(&DAT_02983740 + iVar6) = param_3;
        *(int *)(&DAT_02983748 + iVar6) = param_3;
        *(undefined4 *)(iVar6 + 0x298374c) = 0;
        (&DAT_02983750)[iVar12 * 5] = 1;
        if (iVar1 != 0) {
          puVar10 = (undefined4 *)FUN_004fc750(iVar1);
          if (puVar10 != (undefined4 *)0x0) {
            iVar12 = FUN_004fc5b0(puVar10);
            while (iVar12 != 0) {
              local_10 = local_10 + 1;
              iVar12 = FUN_004fc5b0(puVar10);
            }
            *puVar10 = 0;
          }
          FUN_004f99e0(iVar1);
        }
        break;
      }
      piVar9 = piVar9 + 5;
      iVar12 = iVar12 + 1;
    } while ((int)piVar9 < 0x29838e0);
  }
  uVar13 = *param_2 + 3 & 0xfffffffc;
  *param_2 = (*param_2 + 3 & 0xfffffffc) + local_10 * 8;
  if (0 < iVar8) {
    iVar8 = 0;
    piVar9 = &DAT_02983750;
    while (*piVar9 != 0) {
      piVar9 = piVar9 + 5;
      iVar8 = iVar8 + 1;
      if (0x29838df < (int)piVar9) {
        return (&DAT_0091eed4)[iVar7 * 3];
      }
    }
    iVar1 = iVar8 * 0x14;
    iVar12 = iVar8 + 0x400;
    *(int *)(&DAT_02983740 + iVar1) = param_3;
    *(char **)(&DAT_02983744 + iVar1) = pcVar2 + -1;
    *(int *)(&DAT_02983748 + iVar1) = param_3;
    *(undefined4 *)(iVar1 + 0x298374c) = 0;
    (&DAT_02983750)[iVar8 * 5] = 1;
    if (iVar12 != 0) {
      puVar10 = (undefined4 *)FUN_004fc750(iVar12);
      if (puVar10 != (undefined4 *)0x0) {
        iVar8 = FUN_004fc5b0(puVar10);
        if (iVar8 != 0) {
          puVar17 = (uint *)(uVar13 + 4);
          do {
            FUN_004f7fb0(puVar10);
            FUN_004f7fb0(puVar10);
            psVar11 = (short *)puVar10[0x144];
            iVar8 = 0;
            sVar5 = *psVar11;
            while (sVar5 != 0) {
              psVar11 = psVar11 + 1;
              iVar8 = iVar8 + 1;
              sVar5 = *psVar11;
            }
            puVar17[-1] = *param_2;
            *param_2 = *param_2 + iVar8 + 1;
            FUN_004f2dc0(puVar17[-1],puVar10[0x144]);
            FUN_004f7fb0(puVar10);
            psVar11 = (short *)puVar10[0x144];
            iVar8 = 0;
            sVar5 = *psVar11;
            while (sVar5 != 0) {
              psVar11 = psVar11 + 1;
              iVar8 = iVar8 + 1;
              sVar5 = *psVar11;
            }
            *puVar17 = *param_2 + 1 & 0xfffffffe;
            *param_2 = (*param_2 + 1 & 0xfffffffe) + 2 + iVar8 * 2;
            psVar11 = (short *)puVar10[0x144];
            psVar14 = (short *)*puVar17;
            if (psVar11 == (short *)0x0) {
              *psVar14 = 0;
            }
            else {
              do {
                *psVar14 = *psVar11;
                sVar5 = *psVar11;
                psVar14 = psVar14 + 1;
                psVar11 = psVar11 + 1;
              } while (sVar5 != 0);
            }
            psVar11 = (short *)puVar10[0x144];
            if (DAT_00800484 == 1) {
              iVar8 = 0;
              sVar5 = *psVar11;
              while (sVar5 != 0) {
                psVar11 = psVar11 + 1;
                iVar8 = iVar8 + 1;
                sVar5 = *psVar11;
              }
              *puVar17 = *param_2 + 1 & 0xfffffffe;
              *param_2 = (*param_2 + 1 & 0xfffffffe) + 2 + iVar8 * 2;
              psVar11 = (short *)puVar10[0x144];
              psVar14 = (short *)*puVar17;
              if (psVar11 == (short *)0x0) {
                *psVar14 = 0;
              }
              else {
                do {
                  *psVar14 = *psVar11;
                  sVar5 = *psVar11;
                  psVar14 = psVar14 + 1;
                  psVar11 = psVar11 + 1;
                } while (sVar5 != 0);
              }
            }
            else {
              FUN_004f2e60(pcVar2,psVar11);
              iVar8 = FUN_004f1ff0(pcVar2);
              *puVar17 = *param_2 + 1 & 0xfffffffe;
              *param_2 = (*param_2 + 1 & 0xfffffffe) + iVar8 + 1;
              pcVar15 = (char *)*puVar17;
              if (pcVar2 != (char *)0x0) {
                cVar4 = *pcVar2;
                pcVar16 = pcVar2;
                while (cVar4 != '\0') {
                  pcVar16 = pcVar16 + 1;
                  *pcVar15 = cVar4;
                  pcVar15 = pcVar15 + 1;
                  cVar4 = *pcVar16;
                }
              }
              *pcVar15 = '\0';
            }
            local_8 = local_8 + 1;
            puVar17 = puVar17 + 2;
            iVar8 = FUN_004fc5b0(puVar10);
          } while (iVar8 != 0);
        }
        *puVar10 = 0;
        *puVar3 = uVar13;
        (&DAT_0091eed4)[iVar7 * 3] = local_8;
        *(int *)(&DAT_0091eed8 + iVar7 * 0xc) = local_10;
      }
      FUN_004f99e0(iVar12);
    }
  }
  return (&DAT_0091eed4)[iVar7 * 3];
}

