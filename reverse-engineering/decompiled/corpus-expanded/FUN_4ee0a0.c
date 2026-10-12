/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ee0a0; label: FUN_004ee0a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ee0a0(int param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  int *piVar7;
  byte local_8;
  byte local_7;
  byte local_6;
  byte local_5;
  
  if ((param_1 != 0) && (*(int **)(param_1 + 0x50b8) != (int *)0x0)) {
    bVar6 = 0;
    local_5 = 0;
    local_8 = 0;
    local_6 = 0;
    local_7 = 0;
    bVar4 = 0;
    piVar7 = &DAT_0093d7f4;
    do {
      iVar3 = piVar7[-1];
      if ((((iVar3 != 0) && ((*(uint *)(iVar3 + 0x1fc) & 0x1000) != 0)) &&
          (*(char *)(iVar3 + 0x28b) == '\0')) &&
         ((*(int *)(iVar3 + 0xcd0) != 0 && (*(char *)(*(int *)(iVar3 + 0xcd0) + 0x7b5) == ';')))) {
        sVar2 = *(short *)(iVar3 + 0x1064);
        if (sVar2 == DAT_007f1944) {
          local_7 = ~DAT_0088a6cc;
          local_5 = 0xff;
        }
        else if (sVar2 == DAT_007f1a84) {
          bVar6 = ~DAT_0088a56c;
          local_8 = 0xff;
        }
        else if (sVar2 == DAT_007f1a88) {
          bVar4 = ~DAT_0088a56d;
          local_6 = 0xff;
        }
      }
      iVar3 = *piVar7;
      if (((iVar3 != 0) && ((*(uint *)(iVar3 + 0x1fc) & 0x1000) != 0)) &&
         ((*(char *)(iVar3 + 0x28b) == '\0' &&
          ((*(int *)(iVar3 + 0xcd0) != 0 && (*(char *)(*(int *)(iVar3 + 0xcd0) + 0x7b5) == ';'))))))
      {
        sVar2 = *(short *)(iVar3 + 0x1064);
        if (sVar2 == DAT_007f1944) {
          local_7 = ~DAT_0088a6cc;
          local_5 = 0xff;
        }
        else if (sVar2 == DAT_007f1a84) {
          bVar6 = ~DAT_0088a56c;
          local_8 = 0xff;
        }
        else if (sVar2 == DAT_007f1a88) {
          bVar4 = ~DAT_0088a56d;
          local_6 = 0xff;
        }
      }
      iVar3 = piVar7[1];
      if ((((iVar3 != 0) && ((*(uint *)(iVar3 + 0x1fc) & 0x1000) != 0)) &&
          (*(char *)(iVar3 + 0x28b) == '\0')) &&
         ((*(int *)(iVar3 + 0xcd0) != 0 && (*(char *)(*(int *)(iVar3 + 0xcd0) + 0x7b5) == ';')))) {
        sVar2 = *(short *)(iVar3 + 0x1064);
        if (sVar2 == DAT_007f1944) {
          local_7 = ~DAT_0088a6cc;
          local_5 = 0xff;
        }
        else if (sVar2 == DAT_007f1a84) {
          bVar6 = ~DAT_0088a56c;
          local_8 = 0xff;
        }
        else if (sVar2 == DAT_007f1a88) {
          bVar4 = ~DAT_0088a56d;
          local_6 = 0xff;
        }
      }
      iVar3 = piVar7[2];
      if (((iVar3 != 0) && ((*(uint *)(iVar3 + 0x1fc) & 0x1000) != 0)) &&
         ((*(char *)(iVar3 + 0x28b) == '\0' &&
          ((*(int *)(iVar3 + 0xcd0) != 0 && (*(char *)(*(int *)(iVar3 + 0xcd0) + 0x7b5) == ';'))))))
      {
        sVar2 = *(short *)(iVar3 + 0x1064);
        if (sVar2 == DAT_007f1944) {
          local_7 = ~DAT_0088a6cc;
          local_5 = 0xff;
        }
        else if (sVar2 == DAT_007f1a84) {
          bVar6 = ~DAT_0088a56c;
          local_8 = 0xff;
        }
        else if (sVar2 == DAT_007f1a88) {
          bVar4 = ~DAT_0088a56d;
          local_6 = 0xff;
        }
      }
      piVar7 = piVar7 + 4;
    } while ((int)piVar7 < 0x93d814);
    if (local_5 == 0) {
      local_7 = DAT_0088a6cc;
    }
    if (local_8 == 0) {
      bVar6 = DAT_0088a56c;
    }
    if (local_6 == 0) {
      bVar4 = DAT_0088a56d;
    }
    DAT_0088a6cc = local_5;
    DAT_0088a56c = local_8;
    DAT_0088a56d = local_6;
    if ((bVar4 != 0 || bVar6 != 0) || local_7 != 0) {
      iVar3 = **(int **)(param_1 + 0x50b8);
      for (iVar5 = 0; (iVar3 != 0 && (iVar5 < *(int *)(*(int *)(param_1 + 0x50b8) + 8)));
          iVar5 = iVar5 + 1) {
        if (((*(byte *)(iVar3 + 0x17) & 8) == 0) &&
           (((cVar1 = *(char *)(iVar3 + 0x18), bVar6 = local_5, cVar1 == '\x02' ||
             (bVar6 = local_8, cVar1 == '\x03')) || (bVar6 = local_6, cVar1 == '\x04')))) {
          *(byte *)(iVar3 + 0x24) = bVar6;
        }
        iVar3 = iVar3 + 0x2c;
      }
    }
  }
  return;
}

