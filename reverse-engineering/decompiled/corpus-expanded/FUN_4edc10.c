/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4edc10; label: FUN_004edc10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004edc10(int param_1)

{
  short sVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  int *piVar6;
  byte local_a;
  byte local_9;
  byte local_8;
  byte local_7;
  byte local_6;
  byte local_5;
  
  if ((param_1 != 0) && (*(int **)(param_1 + 0x50b8) != (int *)0x0)) {
    bVar5 = 0;
    local_6 = 0;
    local_a = 0;
    local_9 = 0;
    local_5 = 0;
    local_7 = 0;
    local_8 = 0;
    bVar3 = 0;
    piVar6 = &DAT_0093d7f4;
    do {
      iVar2 = piVar6[-1];
      if ((((iVar2 != 0) && ((*(uint *)(iVar2 + 0x1fc) & 0x1000) != 0)) &&
          (*(char *)(iVar2 + 0x28b) == '\0')) &&
         ((*(int *)(iVar2 + 0xcd0) != 0 && (*(char *)(*(int *)(iVar2 + 0xcd0) + 0x7b5) == ';')))) {
        sVar1 = *(short *)(iVar2 + 0x1064);
        if (sVar1 == DAT_007f1a80) {
          local_7 = ~DAT_0088a56f;
          local_6 = 0xff;
        }
        else if (sVar1 == DAT_007f1944) {
          local_8 = ~DAT_0088a6cc;
          local_a = 0xff;
        }
        else if (sVar1 == DAT_007f1a5c) {
          bVar5 = ~DAT_0088a56e;
          local_9 = 0xff;
        }
        else if (sVar1 == DAT_007f1a7c) {
          bVar3 = ~DAT_0088a6cd;
          local_5 = 0xff;
        }
      }
      iVar2 = *piVar6;
      if (((iVar2 != 0) && ((*(uint *)(iVar2 + 0x1fc) & 0x1000) != 0)) &&
         ((*(char *)(iVar2 + 0x28b) == '\0' &&
          ((*(int *)(iVar2 + 0xcd0) != 0 && (*(char *)(*(int *)(iVar2 + 0xcd0) + 0x7b5) == ';'))))))
      {
        sVar1 = *(short *)(iVar2 + 0x1064);
        if (sVar1 == DAT_007f1a80) {
          local_7 = ~DAT_0088a56f;
          local_6 = 0xff;
        }
        else if (sVar1 == DAT_007f1944) {
          local_8 = ~DAT_0088a6cc;
          local_a = 0xff;
        }
        else if (sVar1 == DAT_007f1a5c) {
          bVar5 = ~DAT_0088a56e;
          local_9 = 0xff;
        }
        else if (sVar1 == DAT_007f1a7c) {
          bVar3 = ~DAT_0088a6cd;
          local_5 = 0xff;
        }
      }
      iVar2 = piVar6[1];
      if ((((iVar2 != 0) && ((*(uint *)(iVar2 + 0x1fc) & 0x1000) != 0)) &&
          (*(char *)(iVar2 + 0x28b) == '\0')) &&
         ((*(int *)(iVar2 + 0xcd0) != 0 && (*(char *)(*(int *)(iVar2 + 0xcd0) + 0x7b5) == ';')))) {
        sVar1 = *(short *)(iVar2 + 0x1064);
        if (sVar1 == DAT_007f1a80) {
          local_7 = ~DAT_0088a56f;
          local_6 = 0xff;
        }
        else if (sVar1 == DAT_007f1944) {
          local_8 = ~DAT_0088a6cc;
          local_a = 0xff;
        }
        else if (sVar1 == DAT_007f1a5c) {
          bVar5 = ~DAT_0088a56e;
          local_9 = 0xff;
        }
        else if (sVar1 == DAT_007f1a7c) {
          bVar3 = ~DAT_0088a6cd;
          local_5 = 0xff;
        }
      }
      iVar2 = piVar6[2];
      if (((iVar2 != 0) && ((*(uint *)(iVar2 + 0x1fc) & 0x1000) != 0)) &&
         ((*(char *)(iVar2 + 0x28b) == '\0' &&
          ((*(int *)(iVar2 + 0xcd0) != 0 && (*(char *)(*(int *)(iVar2 + 0xcd0) + 0x7b5) == ';'))))))
      {
        sVar1 = *(short *)(iVar2 + 0x1064);
        if (sVar1 == DAT_007f1a80) {
          local_7 = ~DAT_0088a56f;
          local_6 = 0xff;
        }
        else if (sVar1 == DAT_007f1944) {
          local_8 = ~DAT_0088a6cc;
          local_a = 0xff;
        }
        else if (sVar1 == DAT_007f1a5c) {
          bVar5 = ~DAT_0088a56e;
          local_9 = 0xff;
        }
        else if (sVar1 == DAT_007f1a7c) {
          bVar3 = ~DAT_0088a6cd;
          local_5 = 0xff;
        }
      }
      piVar6 = piVar6 + 4;
    } while ((int)piVar6 < 0x93d814);
    if (local_6 == 0) {
      local_7 = DAT_0088a56f;
    }
    if (local_a == 0) {
      local_8 = DAT_0088a6cc;
    }
    if (local_9 == 0) {
      bVar5 = DAT_0088a56e;
    }
    if (local_5 == 0) {
      bVar3 = DAT_0088a6cd;
    }
    DAT_0088a56f = local_6;
    DAT_0088a6cc = local_a;
    DAT_0088a56e = local_9;
    DAT_0088a6cd = local_5;
    if (((bVar3 != 0 || bVar5 != 0) || local_8 != 0) || local_7 != 0) {
      iVar2 = **(int **)(param_1 + 0x50b8);
      for (iVar4 = 0; (iVar2 != 0 && (iVar4 < *(int *)(*(int *)(param_1 + 0x50b8) + 8)));
          iVar4 = iVar4 + 1) {
        if ((*(byte *)(iVar2 + 0x17) & 8) == 0) {
          switch(*(undefined1 *)(iVar2 + 0x18)) {
          case 3:
            bVar5 = local_6;
            break;
          case 4:
            bVar5 = local_a;
            break;
          case 5:
            bVar5 = local_9;
            break;
          case 6:
            bVar5 = local_5;
            break;
          default:
            goto switchD_004edf70_default;
          }
          *(byte *)(iVar2 + 0x24) = bVar5;
        }
switchD_004edf70_default:
        iVar2 = iVar2 + 0x2c;
      }
    }
  }
  return;
}

