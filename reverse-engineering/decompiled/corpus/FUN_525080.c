/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x525080; label: FUN_00525080
 */

void FUN_00525080(byte *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  int iVar10;
  undefined8 uVar11;
  undefined1 uVar12;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00621520(*param_1);
  local_8 = 0;
  if (*param_1 != 0) {
    do {
      iVar6 = *(int *)(*(int *)(param_1 + 4) + local_8 * 4);
      FUN_00621440(iVar6,0x10);
      FUN_00621600(*(undefined1 *)(iVar6 + 0x10));
      FUN_00621600(*(undefined1 *)(iVar6 + 0x11));
      FUN_006215a0(*(undefined2 *)(iVar6 + 0x12));
      if ((*(short *)(iVar6 + 0x12) != 0) && (iVar5 = 0, *(short *)(iVar6 + 0x12) != 0)) {
        iVar10 = 0;
        do {
          puVar7 = (undefined4 *)(*(int *)(iVar6 + 0x80) + iVar10);
          FUN_00621600(*(undefined1 *)(*(int *)(iVar6 + 0x80) + 0x10 + iVar10));
          FUN_00621600(*(undefined1 *)((int)puVar7 + 0x11));
          if (DAT_0080171c < 0xc) {
            if (DAT_0080171c < 9) {
              FUN_00621600(*(undefined1 *)puVar7);
              FUN_00621600(*(undefined1 *)(puVar7 + 1));
            }
            else {
              FUN_006215a0(*(undefined2 *)puVar7);
              FUN_006215a0(*(undefined2 *)(puVar7 + 1));
            }
          }
          else {
            FUN_00621520(*puVar7);
            FUN_00621520(puVar7[1]);
          }
          FUN_006215a0(*(undefined2 *)((int)puVar7 + 0x12));
          FUN_006215a0(*(undefined2 *)(puVar7 + 5));
          FUN_006214d0(puVar7[6]);
          FUN_006214d0(puVar7[7]);
          iVar5 = iVar5 + 1;
          iVar10 = iVar10 + 0x24;
        } while (iVar5 < (int)(uint)*(ushort *)(iVar6 + 0x12));
      }
      local_14 = 0;
      if (*(char *)(iVar6 + 0x10) != '\0') {
        local_10 = 0;
        do {
          puVar7 = (undefined4 *)(*(int *)(iVar6 + 0x7c) + local_10);
          pcVar2 = (char *)*puVar7;
          if (pcVar2 == (char *)0x0) {
            pcVar2 = (char *)0x0;
          }
          else {
            pcVar3 = pcVar2 + 1;
            do {
              cVar1 = *pcVar2;
              pcVar2 = pcVar2 + 1;
            } while (cVar1 != '\0');
            pcVar2 = pcVar2 + (1 - (int)pcVar3);
          }
          FUN_00621520(pcVar2);
          if (pcVar2 != (char *)0x0) {
            FUN_00621440(*puVar7,pcVar2);
          }
          FUN_006214d0(puVar7[1]);
          FUN_006214d0(puVar7[2]);
          FUN_006214d0(puVar7[3]);
          FUN_006214d0(puVar7[4]);
          if (7 < DAT_0080171c) {
            FUN_006214d0(puVar7[6]);
            FUN_006214d0(puVar7[8]);
          }
          FUN_00621600(*(undefined1 *)(puVar7 + 10));
          FUN_00621600(*(undefined1 *)((int)puVar7 + 0x29));
          FUN_00621600(0);
          FUN_00621600(*(undefined1 *)((int)puVar7 + 0x2b));
          FUN_006215a0(*(undefined2 *)(puVar7 + 0xb));
          if (DAT_0080171c < 0x13) {
            uVar12 = 0;
          }
          else {
            uVar12 = *(undefined1 *)(puVar7 + 0xc);
          }
          FUN_00621600(uVar12);
          iVar5 = FUN_005cfac0(puVar7 + 0x10);
          if ((iVar5 == 0) || (pcVar2 = (char *)FUN_005cfa50(puVar7 + 0x10), pcVar2 == (char *)0x0))
          {
            FUN_00621600(0);
          }
          else {
            pcVar3 = pcVar2;
            do {
              cVar1 = *pcVar3;
              pcVar3 = pcVar3 + 1;
            } while (cVar1 != '\0');
            FUN_00621600(pcVar3 + (1 - (int)(pcVar2 + 1)));
            FUN_00621440(pcVar2,pcVar3 + (1 - (int)(pcVar2 + 1)));
            FUN_006214d0(puVar7[0x13]);
            FUN_006214d0(puVar7[0x14]);
            FUN_006214d0(puVar7[0x15]);
          }
          iVar5 = 0;
          if (*(char *)(puVar7 + 10) != '\0') {
            do {
              FUN_006215a0((*(int *)(puVar7[0xd] + iVar5 * 4) - *(int *)(iVar6 + 0x80)) / 0x24);
              iVar5 = iVar5 + 1;
            } while (iVar5 < (int)(uint)*(byte *)(puVar7 + 10));
          }
          if ((*(byte *)(puVar7 + 10) & 1) != 0) {
            FUN_006215a0(0);
          }
          FUN_006215a0(*(undefined2 *)(puVar7 + 0x16));
          FUN_006215a0(*(undefined2 *)((int)puVar7 + 0x5a));
          local_10 = local_10 + 0x5c;
          local_14 = local_14 + 1;
        } while (local_14 < (int)(uint)*(byte *)(iVar6 + 0x10));
      }
      uVar4 = (uint)*(byte *)(iVar6 + 0x10);
      iVar5 = 0;
      if (uVar4 != 0) {
        do {
          FUN_00621440(*(undefined4 *)(*(int *)(iVar6 + 0x84) + iVar5 * 4),uVar4);
          uVar4 = (uint)*(byte *)(iVar6 + 0x10);
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)uVar4);
      }
      FUN_00621600(*(undefined1 *)(iVar6 + 0x14));
      if (*(char *)(iVar6 + 0x14) != '\0') {
        local_14 = 0;
        local_c = 0;
        do {
          puVar7 = (undefined4 *)(*(int *)(iVar6 + 0x88) + local_c);
          pcVar3 = (char *)*puVar7;
          pcVar2 = pcVar3 + 1;
          do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          FUN_00621600(pcVar3 + (1 - (int)pcVar2));
          FUN_00621440(*puVar7,pcVar3 + (1 - (int)pcVar2));
          FUN_00621600(*(undefined1 *)(puVar7 + 4));
          FUN_00621600(*(undefined1 *)((int)puVar7 + 0x11));
          FUN_00621600(0);
          FUN_00621600(0);
          if (*(char *)(puVar7 + 4) != '\0') {
            FUN_00621440(puVar7[1],*(undefined1 *)(iVar6 + 0x10));
            FUN_00621440(puVar7[2],*(undefined1 *)(puVar7 + 4));
            uVar4 = (uint)*(byte *)(puVar7 + 4);
            iVar5 = 0;
            if (uVar4 != 0) {
              do {
                FUN_00621440(*(undefined4 *)(puVar7[5] + iVar5 * 4),uVar4);
                uVar4 = (uint)*(byte *)(puVar7 + 4);
                iVar5 = iVar5 + 1;
              } while (iVar5 < (int)uVar4);
            }
            if (*(char *)((int)puVar7 + 0x11) != '\0') {
              FUN_00621440(puVar7[3],*(char *)((int)puVar7 + 0x11));
            }
          }
          if (DAT_00923890 == (code *)0x0) {
            FUN_00621600(0);
          }
          else {
            uVar4 = puVar7[8];
            local_10 = 0;
            iVar5 = 0;
            do {
              uVar11 = __allshl();
              if (((uint)uVar11 & uVar4) != 0 ||
                  ((uint)((ulonglong)uVar11 >> 0x20) & puVar7[9]) != 0) {
                local_10 = local_10 + 1;
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < 0x40);
            FUN_00621600(local_10);
            iVar5 = 0;
            do {
              uVar11 = __allshl();
              if (((uint)uVar11 & puVar7[8]) != 0 ||
                  ((uint)((ulonglong)uVar11 >> 0x20) & puVar7[9]) != 0) {
                pcVar2 = (char *)(*DAT_00923890)(iVar5);
                if (pcVar2 == (char *)0x0) {
                  FUN_00621600(0);
                }
                else {
                  pcVar3 = pcVar2;
                  do {
                    cVar1 = *pcVar3;
                    pcVar3 = pcVar3 + 1;
                  } while (cVar1 != '\0');
                  FUN_00621600(pcVar3 + (1 - (int)(pcVar2 + 1)));
                  FUN_00621440(pcVar2,pcVar3 + (1 - (int)(pcVar2 + 1)));
                }
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < 0x3f);
            if ((puVar7[9] & 0x80000000) != 0) {
              FUN_00621600(9);
              FUN_00621440("Everyone",9);
            }
          }
          local_c = local_c + 0x28;
          local_14 = local_14 + 1;
        } while (local_14 < (int)(uint)*(byte *)(iVar6 + 0x14));
      }
      if (0x12 < DAT_0080171c) {
        FUN_00621600(*(undefined1 *)(iVar6 + 0x7a));
        if (*(char *)(iVar6 + 0x7a) != '\0') {
          puVar8 = *(undefined1 **)(iVar6 + 0x8c);
          iVar5 = 0;
          if (*(char *)(iVar6 + 0x7a) != '\0') {
            do {
              FUN_00621610(*puVar8);
              FUN_006215a0(*(undefined2 *)(puVar8 + 2));
              iVar5 = iVar5 + 1;
              puVar8 = puVar8 + 4;
            } while (iVar5 < (int)(uint)*(byte *)(iVar6 + 0x7a));
          }
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < (int)(uint)*param_1);
  }
  if (0x12 < DAT_0080171c) {
    FUN_006215a0(*(undefined2 *)(param_1 + 2));
    if (*(short *)(param_1 + 2) != 0) {
      pbVar9 = *(byte **)(param_1 + 0xc);
      iVar6 = 0;
      if (*(short *)(param_1 + 2) != 0) {
        do {
          FUN_00621600(*pbVar9);
          iVar5 = 0;
          if (*pbVar9 != 0) {
            do {
              FUN_00621600(*(undefined1 *)(*(int *)(*(int *)(pbVar9 + 4) + iVar5 * 4) + 0x15));
              iVar5 = iVar5 + 1;
            } while (iVar5 < (int)(uint)*pbVar9);
          }
          iVar6 = iVar6 + 1;
          pbVar9 = pbVar9 + 8;
        } while (iVar6 < (int)(uint)*(ushort *)(param_1 + 2));
      }
    }
  }
  return;
}

