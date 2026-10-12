/* Ghidra analysis pseudocode, not original source.
 * ev_b1d683d72d7bcdb306124a83b006db4b41bf581671bc5ef620d768a8a4b84d3d
 * Entry: 0x6691f0; label: FUN_006691f0
 */

undefined4 FUN_006691f0(undefined4 param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  
  cVar1 = param_2;
  iVar7 = 0;
  if (param_2 == '\x06') {
    param_2 = '\x01';
  }
  iVar2 = 1;
  if (1 < DAT_02962098) {
    pcVar4 = (char *)(DAT_029620a0 + 0x438);
    do {
      if (*(int *)(DAT_0296209c + iVar2 * 4) != 0) {
        if (param_2 != '\x02') {
          if (param_2 == '\x01') {
            if (*pcVar4 != '\x01') goto LAB_0066925c;
            bVar10 = DAT_008109cc == pcVar4[1];
          }
          else {
            bVar10 = *pcVar4 == param_2;
          }
          if (!bVar10) goto LAB_0066925c;
        }
        iVar7 = iVar7 + 1;
      }
LAB_0066925c:
      iVar2 = iVar2 + 1;
      pcVar4 = pcVar4 + 0x428;
    } while (iVar2 < DAT_02962098);
  }
  if (DAT_02962a28 == 0) {
    uVar12 = 1;
  }
  else {
    uVar12 = 2;
  }
  FUN_006211c0(uVar12);
  iVar2 = FUN_00621270(param_1,1);
  if (iVar2 == 0) {
    return 0;
  }
  FUN_006211b0(1);
  FUN_00621520(0x29);
  FUN_00621520(iVar7);
  iVar7 = 1;
  if (1 < DAT_02962098) {
    iVar8 = 0x428;
    iVar2 = DAT_029620a0;
    do {
      if (*(int *)(DAT_0296209c + iVar7 * 4) != 0) {
        if (param_2 != '\x02') {
          if (param_2 == '\x01') {
            if (*(char *)(iVar8 + 0x10 + iVar2) != '\x01') goto LAB_00669c19;
            bVar10 = DAT_008109cc == *(char *)(iVar8 + 0x11 + iVar2);
          }
          else {
            bVar10 = *(char *)(iVar8 + 0x10 + iVar2) == param_2;
          }
          if (!bVar10) goto LAB_00669c19;
        }
        FUN_00621440(iVar2 + iVar8,0x10);
        FUN_006215a0(*(undefined2 *)(iVar8 + 0x16 + DAT_029620a0));
        FUN_006215a0(*(undefined2 *)(iVar8 + 0x14 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x18 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x1c + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x20 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x24 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x28 + DAT_029620a0));
        FUN_00621600(*(undefined1 *)(iVar8 + 0x2c + DAT_029620a0));
        FUN_00621600(*(undefined1 *)(iVar8 + 0x2d + DAT_029620a0));
        FUN_00621600(*(undefined1 *)(iVar8 + 0x12 + DAT_029620a0));
        FUN_00621600(*(undefined1 *)(iVar8 + 0x2e + DAT_029620a0));
        FUN_00621600(*(undefined1 *)(iVar8 + 0x412 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x30 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x34 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x38 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x3c + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x40 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x44 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x48 + DAT_029620a0));
        FUN_00621620(iVar8 + 0x4c + DAT_029620a0);
        FUN_00621620(iVar8 + 0x58 + DAT_029620a0);
        FUN_00621620(iVar8 + 100 + DAT_029620a0);
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x70 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x74 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x78 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x7c + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x80 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x84 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x88 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x8c + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x90 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x94 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x98 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x9c + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0xa0 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0xa4 + DAT_029620a0));
        FUN_006215a0(*(undefined2 *)(iVar8 + 0xa8 + DAT_029620a0));
        FUN_00621600(*(undefined1 *)(iVar8 + 0xaa + DAT_029620a0));
        FUN_00621600(*(undefined1 *)(iVar8 + 0xab + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0xac + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0xb0 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0xb4 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0xb8 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0xbc + DAT_029620a0));
        iVar5 = 8;
        iVar2 = iVar8;
        do {
          FUN_006214d0(*(undefined4 *)(iVar2 + 0xc0 + DAT_029620a0));
          FUN_00621610(*(undefined1 *)(iVar2 + 0xc4 + DAT_029620a0));
          FUN_00621610(*(undefined1 *)(iVar2 + 0xc5 + DAT_029620a0));
          FUN_00621610(*(undefined1 *)(iVar2 + 0xc6 + DAT_029620a0));
          FUN_00621610(*(undefined1 *)(iVar2 + 199 + DAT_029620a0));
          iVar2 = iVar2 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        iVar5 = 8;
        iVar2 = iVar8;
        do {
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x100 + DAT_029620a0));
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x104 + DAT_029620a0));
          iVar2 = iVar2 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x140 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x144 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x148 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x14c + DAT_029620a0));
        iVar5 = 8;
        iVar2 = iVar8;
        do {
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x150 + DAT_029620a0));
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x154 + DAT_029620a0));
          iVar2 = iVar2 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        iVar5 = 8;
        iVar2 = iVar8;
        do {
          FUN_006214d0(*(undefined4 *)(iVar2 + 400 + DAT_029620a0));
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x194 + DAT_029620a0));
          iVar2 = iVar2 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x1d0 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x1d4 + DAT_029620a0));
        iVar5 = 8;
        iVar2 = iVar8;
        do {
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x1d8 + DAT_029620a0));
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x1dc + DAT_029620a0));
          iVar2 = iVar2 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        iVar5 = 8;
        iVar2 = iVar8;
        do {
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x218 + DAT_029620a0));
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x21c + DAT_029620a0));
          iVar2 = iVar2 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        iVar5 = 8;
        iVar2 = iVar8;
        do {
          FUN_006214d0(*(undefined4 *)(iVar2 + 600 + DAT_029620a0));
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x25c + DAT_029620a0));
          iVar2 = iVar2 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x298 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x29c + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x2a0 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x2a4 + DAT_029620a0));
        iVar5 = 8;
        iVar2 = iVar8;
        do {
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x2b0 + DAT_029620a0));
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x2b4 + DAT_029620a0));
          iVar2 = iVar2 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        FUN_00621600(*(undefined1 *)(iVar8 + 0x2f0 + DAT_029620a0));
        FUN_00621600(*(undefined1 *)(iVar8 + 0x2f1 + DAT_029620a0));
        FUN_00621600(*(undefined1 *)(iVar8 + 0x2f2 + DAT_029620a0));
        FUN_00621600(*(undefined1 *)(iVar8 + 0x2f3 + DAT_029620a0));
        FUN_00621620(iVar8 + 0x2f8 + DAT_029620a0);
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x2f4 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x304 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x308 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x30c + DAT_029620a0));
        iVar5 = 8;
        iVar2 = iVar8;
        do {
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x310 + DAT_029620a0));
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x314 + DAT_029620a0));
          iVar2 = iVar2 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        iVar5 = 8;
        iVar2 = iVar8;
        do {
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x350 + DAT_029620a0));
          FUN_006214d0(*(undefined4 *)(iVar2 + 0x354 + DAT_029620a0));
          iVar2 = iVar2 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        iVar2 = 8;
        iVar5 = iVar8;
        do {
          iVar6 = iVar2;
          FUN_006214d0(*(undefined4 *)(iVar5 + 0x390 + DAT_029620a0));
          FUN_006214d0(*(undefined4 *)(iVar5 + 0x394 + DAT_029620a0));
          iVar5 = iVar5 + 8;
          iVar2 = iVar6 + -1;
        } while (iVar2 != 0);
        iVar2 = 0;
        if (*(int *)(iVar8 + 0x3e0 + DAT_029620a0) != -1) {
          iVar2 = iVar6;
        }
        if (*(int *)(iVar8 + 0x3ec + DAT_029620a0) != -1) {
          iVar2 = iVar2 + 1;
        }
        if (*(int *)(iVar8 + 0x3f8 + DAT_029620a0) != -1) {
          iVar2 = iVar2 + 1;
        }
        if (*(int *)(iVar8 + 0x404 + DAT_029620a0) != -1) {
          iVar2 = iVar2 + 1;
        }
        FUN_00621520(iVar2);
        iVar5 = 4;
        iVar2 = iVar8;
        do {
          iVar6 = *(int *)(iVar2 + 0x3e0 + DAT_029620a0);
          if (iVar6 != -1) {
            FUN_00621440(*(undefined4 *)(iVar6 * 0x40 + DAT_02947b74),0x10);
            FUN_00621520(*(undefined4 *)(iVar2 + 0x3e4 + DAT_029620a0));
            FUN_00621520(*(undefined4 *)(iVar2 + 1000 + DAT_029620a0));
          }
          iVar2 = iVar2 + 0xc;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        FUN_00621600(*(undefined1 *)(iVar8 + 0x410 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x414 + DAT_029620a0));
        FUN_00621600(*(undefined1 *)(iVar8 + 0x411 + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x41c + DAT_029620a0));
        FUN_006214d0(*(undefined4 *)(iVar8 + 0x418 + DAT_029620a0));
        iVar2 = DAT_029620a0;
      }
LAB_00669c19:
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x428;
    } while (iVar7 < DAT_02962098);
  }
  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
    iVar7 = 0;
    piVar3 = &DAT_02924bb8;
    do {
      if (piVar3[-0x16] != -1) {
        iVar7 = iVar7 + 1;
      }
      if (*piVar3 != -1) {
        iVar7 = iVar7 + 1;
      }
      if (piVar3[0x16] != -1) {
        iVar7 = iVar7 + 1;
      }
      if (piVar3[0x2c] != -1) {
        iVar7 = iVar7 + 1;
      }
      piVar3 = piVar3 + 0x58;
    } while ((int)piVar3 < 0x292fbb8);
    FUN_00621520(iVar7);
    puVar9 = &DAT_02924b50;
    do {
      if (puVar9[4] != -1) {
        FUN_00621620(puVar9);
        FUN_006215a0(*(undefined2 *)(puVar9 + 5));
        FUN_006215a0(*(undefined2 *)((int)puVar9 + 0x16));
        FUN_006215a0(*(undefined2 *)(puVar9 + 6));
        FUN_006215a0(*(undefined2 *)((int)puVar9 + 0x1a));
        FUN_006215a0(*(undefined2 *)(puVar9 + 7));
        FUN_006214d0(puVar9[8]);
        if (puVar9[3] == -1) {
          puVar11 = puVar9 + 9;
        }
        else {
          puVar11 = *(undefined4 **)(DAT_0296209c + puVar9[3] * 4);
        }
        FUN_00621440(puVar11,0x10);
        FUN_00621520(puVar9[0xd]);
        FUN_00621520(puVar9[0xe]);
        FUN_006214d0(puVar9[0xf]);
        FUN_006215a0(*(undefined2 *)(puVar9 + 0x10));
        FUN_006215a0(*(undefined2 *)((int)puVar9 + 0x42));
        FUN_006214d0(puVar9[0x11]);
        FUN_006214d0(puVar9[0x12]);
        FUN_006215a0(*(undefined2 *)(puVar9 + 0x13));
        FUN_006215d0(*(undefined2 *)((int)puVar9 + 0x4e));
        FUN_00621600(*(undefined1 *)(puVar9 + 0x14));
        FUN_00621600(*(undefined1 *)((int)puVar9 + 0x52));
        FUN_00621600(*(undefined1 *)((int)puVar9 + 0x53));
        FUN_006215a0(*(undefined2 *)(puVar9 + 0x15));
        FUN_006215a0(*(undefined2 *)((int)puVar9 + 0x56));
      }
      puVar9 = puVar9 + 0x16;
    } while ((int)puVar9 < 0x292fb50);
  }
  FUN_006211b0(0);
  FUN_006213e0();
  return 1;
}

