/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x647ca0; label: FUN_00647ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00647ca0(undefined4 param_1,char param_2)

{
  short sVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  short *psVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  int local_24;
  undefined1 local_20 [12];
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_24;
  iVar6 = 0;
  iVar9 = 0;
  local_14[0] = '\0';
  local_14[1] = '\0';
  local_14[2] = '\0';
  local_14[3] = '\0';
  local_14[4] = '\0';
  local_14[5] = '\0';
  local_14[6] = '\0';
  local_14[7] = '\0';
  local_14[8] = '\0';
  local_14[9] = '\0';
  local_14[10] = '\0';
  local_14[0xb] = '\0';
  local_14[0xc] = '\0';
  local_14[0xd] = '\0';
  local_14[0xe] = '\0';
  local_14[0xf] = '\0';
  local_24 = 0;
  pcVar2 = &DAT_02913b0b;
  do {
    if ((pcVar2[-0xb3] != '\0') && (*pcVar2 == param_2)) {
      iVar9 = iVar9 + 1;
    }
    if ((pcVar2[0xc5] != '\0') && (pcVar2[0x178] == param_2)) {
      iVar9 = iVar9 + 1;
    }
    if ((pcVar2[0x23d] != '\0') && (pcVar2[0x2f0] == param_2)) {
      iVar9 = iVar9 + 1;
    }
    if ((pcVar2[0x3b5] != '\0') && (pcVar2[0x468] == param_2)) {
      iVar9 = iVar9 + 1;
    }
    pcVar2 = pcVar2 + 0x5e0;
  } while ((int)pcVar2 < 0x291f70b);
  FUN_006211c0(1);
  iVar3 = FUN_00621270(param_1,1);
  if (iVar3 == 0) {
    __security_check_cookie(local_4 ^ (uint)&local_24);
    return;
  }
  FUN_006211b0(1);
  FUN_00621520(0x10);
  FUN_00621520(iVar9);
  pcVar2 = &DAT_02913a58;
  do {
    if ((*pcVar2 != '\0') && (pcVar2[0xb3] == param_2)) {
      FUN_00621440(pcVar2,0x10);
      iVar6 = 0;
      do {
        FUN_00621600(pcVar2[iVar6 + 0xa0]);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 8);
      iVar6 = 0;
      psVar8 = (short *)(pcVar2 + 0x90);
      pcVar7 = pcVar2;
      do {
        pcVar7 = pcVar7 + 0x10;
        sVar1 = *psVar8;
        if (sVar1 == -1) {
          uVar11 = 0x10;
          pcVar4 = local_14;
        }
        else if (sVar1 == 9999) {
          uVar11 = 0x10;
          pcVar4 = s_NULL_instance_008101c4;
        }
        else if (sVar1 == 0x270e) {
          uVar11 = 0x10;
          pcVar4 = pcVar7;
        }
        else if (pcVar2[iVar6 + 0xa0] == '\0') {
          FUN_005da860(local_20,DAT_02962114,(int)sVar1);
          uVar11 = 0x10;
          pcVar4 = (char *)FUN_005cfa50(local_20,0x10);
        }
        else if (pcVar2[iVar6 + 0xa0] == '\x01') {
          FUN_005da860(local_20,DAT_02962918,(int)sVar1);
          uVar11 = 0x10;
          pcVar4 = (char *)FUN_005cfa50(local_20,0x10);
        }
        else {
          uVar11 = 0x10;
          pcVar4 = local_14;
        }
        FUN_00621440(pcVar4,uVar11);
        iVar6 = iVar6 + 1;
        psVar8 = psVar8 + 1;
      } while (iVar6 < 8);
      FUN_00621600(pcVar2[0xb1]);
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0xb4));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0xb8));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0xbc));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0xc0));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0xc4));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 200));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0xcc));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0xd0));
      FUN_00621620(pcVar2 + 0xd4);
      FUN_00621620(pcVar2 + 0xe0);
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0xec));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0xf0));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0xf4));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0xf8));
      FUN_00621520(*(undefined4 *)(pcVar2 + 0xfc));
      FUN_00621520(*(undefined4 *)(pcVar2 + 0x100));
      FUN_00621520(*(undefined4 *)(pcVar2 + 0x104));
      FUN_00621520(*(undefined4 *)(pcVar2 + 0x108));
      FUN_00621520(*(undefined4 *)(pcVar2 + 0x10c));
      FUN_00621520(*(undefined4 *)(pcVar2 + 0x110));
      FUN_00621560(*(undefined4 *)(pcVar2 + 0x114));
      if (*(int *)(pcVar2 + 0x118) == -1) {
        pcVar7 = local_14;
      }
      else {
        pcVar7 = *(char **)(DAT_0296209c + *(int *)(pcVar2 + 0x118) * 4);
      }
      FUN_00621440(pcVar7,0x10);
      if (*(int *)(pcVar2 + 0x11c) == -1) {
        pcVar7 = local_14;
      }
      else {
        pcVar7 = *(char **)(DAT_0296209c + *(int *)(pcVar2 + 0x11c) * 4);
      }
      FUN_00621440(pcVar7,0x10);
      if (*(int *)(pcVar2 + 0x128) == -1) {
        pcVar7 = local_14;
      }
      else {
        pcVar7 = *(char **)(DAT_0296209c + *(int *)(pcVar2 + 0x128) * 4);
      }
      FUN_00621440(pcVar7,0x10);
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0x120));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0x124));
      if (*(int *)(pcVar2 + 0x144) == -1) {
        pcVar7 = local_14;
      }
      else {
        pcVar7 = *(char **)(DAT_0296209c + *(int *)(pcVar2 + 0x144) * 4);
      }
      FUN_00621440(pcVar7,0x10);
      if (*(int *)(pcVar2 + 300) == -1) {
        pcVar7 = local_14;
      }
      else {
        pcVar7 = *(char **)(DAT_0296209c + *(int *)(pcVar2 + 300) * 4);
      }
      FUN_00621440(pcVar7,0x10);
      if (*(int *)(pcVar2 + 0x130) == -1) {
        pcVar7 = local_14;
      }
      else {
        pcVar7 = &DAT_02913a58 + *(int *)(pcVar2 + 0x130) * 0x178;
      }
      FUN_00621440(pcVar7,0x10);
      piVar5 = (int *)(pcVar2 + 0x148);
      iVar6 = 4;
      do {
        if (*piVar5 == -1) {
          pcVar7 = local_14;
        }
        else {
          pcVar7 = *(char **)(*piVar5 * 0x40 + DAT_02947b74);
        }
        FUN_00621440(pcVar7,0x10);
        piVar5 = piVar5 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      iVar6 = 0;
      do {
        FUN_00621600(pcVar2[iVar6 + 0x158]);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 4);
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0x15c));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0x160));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0x164));
      FUN_006214d0(*(undefined4 *)(pcVar2 + 0x168));
      iVar6 = local_24;
    }
    pcVar2 = pcVar2 + 0x178;
  } while ((int)pcVar2 < 0x291f658);
  if (param_2 == '\x01') {
    piVar5 = &DAT_0291f7dc;
    do {
      if ((piVar5[-10] != -1) && (*piVar5 == 0)) {
        iVar6 = iVar6 + 1;
      }
      if ((piVar5[0x11] != -1) && (piVar5[0x1b] == 0)) {
        iVar6 = iVar6 + 1;
      }
      if ((piVar5[0x2c] != -1) && (piVar5[0x36] == 0)) {
        iVar6 = iVar6 + 1;
      }
      if ((piVar5[0x47] != -1) && (piVar5[0x51] == 0)) {
        iVar6 = iVar6 + 1;
      }
      if ((piVar5[0x62] != -1) && (piVar5[0x6c] == 0)) {
        iVar6 = iVar6 + 1;
      }
      piVar5 = piVar5 + 0x87;
    } while ((int)piVar5 < 0x29208bc);
    FUN_00621520(iVar6);
    puVar10 = &DAT_0291f7a8;
    do {
      if (puVar10[3] != -1) {
        FUN_00621620(puVar10);
        FUN_00621440(puVar10 + 4,0x10);
        FUN_006215a0(*(undefined2 *)(puVar10 + 0xc));
        FUN_006215a0(*(undefined2 *)((int)puVar10 + 0x2e));
        FUN_006215a0(*(undefined2 *)(puVar10 + 0xb));
        FUN_006215a0(*(undefined2 *)(puVar10 + 0x11));
        FUN_006215a0(*(undefined2 *)((int)puVar10 + 0x46));
      }
      puVar10 = puVar10 + 0x1b;
    } while ((int)puVar10 < 0x2920888);
  }
  else {
    FUN_00621520(0);
  }
  FUN_006211b0(0);
  FUN_006213e0();
  __security_check_cookie(local_4 ^ (uint)&local_24);
  return;
}

