/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x52ae20; label: FUN_0052ae20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052ae20(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  float local_c;
  int local_8;
  int local_4;
  
  iVar8 = DAT_009238e4;
  *(undefined4 *)(DAT_009238e4 + 0x371a4) = 0;
  *(undefined4 *)(iVar8 + 0x371a8) = 0;
  iVar8 = 0;
  do {
    FUN_004f1310(DAT_009238e4 + 0x3719c,iVar8 + 0x31b9c + DAT_009238e4);
    iVar8 = iVar8 + 0xac;
  } while (iVar8 < 0x5600);
  if (*(int *)(DAT_009238e4 + 100) != 0) {
    iVar8 = *(int *)(DAT_009238e4 + 100);
    local_4 = 0;
    if (0 < *(int *)(iVar8 + 0x14)) {
      local_8 = 0;
LAB_0052ae90:
      pcVar9 = (char *)(*(int *)(iVar8 + 0x18) + local_8);
      iVar8 = FUN_00528450(pcVar9 + 0x20,*(undefined4 *)(pcVar9 + 0x2c));
      if (iVar8 != 0) {
        uVar3 = FUN_00524b00(*(undefined4 *)(pcVar9 + 0x30));
        local_c = 0.0;
        piVar1 = (int *)(iVar8 + 0x38);
        FUN_00524900(iVar8 + 0x28,piVar1,uVar3,0);
        iVar7 = *piVar1;
        while (iVar7 == 0) {
          local_c = local_c + 0.01;
          FUN_00524900(iVar8 + 0x28,piVar1,uVar3,local_c);
          iVar7 = *piVar1;
        }
        uVar3 = FUN_005be5b0(*(undefined4 *)(iVar8 + 0x34),*(undefined4 *)(iVar8 + 0x50));
        *(undefined4 *)(iVar8 + 0x50) = uVar3;
        pcVar4 = pcVar9;
        do {
          cVar2 = *pcVar4;
          pcVar4[(iVar8 - (int)pcVar9) + 8] = cVar2;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        pcVar4 = pcVar9 + 0x10;
        iVar7 = (iVar8 + 0x18) - (int)pcVar4;
        do {
          cVar2 = *pcVar4;
          pcVar4[iVar7] = cVar2;
          pcVar4 = pcVar4 + 1;
        } while (cVar2 != '\0');
        *(char *)(iVar8 + 0x5a) = pcVar9[0x4c];
        *(char *)(iVar8 + 0x5b) = pcVar9[0x50];
        *(char *)(iVar8 + 0x5c) = pcVar9[0x51];
        *(undefined4 *)(iVar8 + 0x54) = *(undefined4 *)(pcVar9 + 0x58);
        *(undefined4 *)(iVar8 + 0x60) = *(undefined4 *)(pcVar9 + 0x5c);
        *(undefined4 *)(iVar8 + 100) = *(undefined4 *)(pcVar9 + 0x60);
        *(undefined4 *)(iVar8 + 0x68) = *(undefined4 *)(pcVar9 + 0x48);
        *(undefined4 *)(iVar8 + 0x70) = *(undefined4 *)(pcVar9 + 100);
        *(undefined4 *)(iVar8 + 0x74) = *(undefined4 *)(pcVar9 + 0x68);
        *(undefined4 *)(iVar8 + 0x78) = *(undefined4 *)(pcVar9 + 0x6c);
        *(undefined4 *)(iVar8 + 0x7c) = *(undefined4 *)(pcVar9 + 0x70);
        if (iVar8 != -0x18) {
          if (*(int *)(DAT_009238e4 + 100) != 0) {
            iVar7 = *(int *)(DAT_009238e4 + 100) + 0x1c;
            for (iVar5 = FUN_004f1440(iVar7); iVar5 != 0; iVar5 = FUN_004f1460(iVar7,iVar5)) {
              iVar6 = FUN_004f8b10(iVar8 + 0x18,*(undefined4 *)(iVar5 + 8));
              if (iVar6 == 0) goto LAB_0052b05b;
            }
          }
          for (iVar5 = FUN_004f1440(&DAT_00921ee8); iVar5 != 0;
              iVar5 = FUN_004f1460(&DAT_00921ee8,iVar5)) {
            iVar7 = FUN_004f8b10(iVar8 + 0x18,*(undefined4 *)(iVar5 + 8));
            if (iVar7 == 0) goto LAB_0052b05b;
          }
        }
        for (iVar5 = FUN_004f1440(&DAT_00921ee8); iVar5 != 0;
            iVar5 = FUN_004f1460(&DAT_00921ee8,iVar5)) {
          iVar7 = FUN_004f8b10("default",*(undefined4 *)(iVar5 + 8));
          if (iVar7 == 0) goto LAB_0052b05b;
        }
        goto LAB_0052b08b;
      }
      goto LAB_0052b28a;
    }
  }
LAB_0052b2b1:
  if ((DAT_00921f34 == -1) && (DAT_00923894 != (code *)0x0)) {
    DAT_00921f34 = (*DAT_00923894)(0);
  }
  if (DAT_009238a8 != (code *)0x0) {
    (*DAT_009238a8)();
  }
  pcVar9 = &DAT_00921f00;
  do {
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  if ((pcVar9 != &DAT_00921f01) && (iVar8 = FUN_004f1440(DAT_009238e4 + 0x371a4), iVar8 != 0)) {
    while (iVar7 = FUN_004f8b10(iVar8 + 8,&DAT_00921f00), iVar7 != 0) {
      iVar8 = FUN_004f1460(DAT_009238e4 + 0x371a4,iVar8);
      if (iVar8 == 0) {
        return;
      }
    }
    *(int *)(DAT_009238e4 + 0x371b0) = iVar8;
    if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
      FUN_00529ad0(*(int *)(DAT_009238e4 + 0x371b0) + 0x18,*(int *)(DAT_009238e4 + 0x371b0));
    }
  }
  return;
LAB_0052b05b:
  if ((pcVar9[0x48] & 2U) == 0) {
    *(undefined4 *)(iVar8 + 0x70) = *(undefined4 *)(iVar5 + 0x1c);
  }
  if ((pcVar9[0x48] & 4U) == 0) {
    *(undefined4 *)(iVar8 + 0x74) = *(undefined4 *)(iVar5 + 0x24);
  }
  if ((pcVar9[0x48] & 8U) == 0) {
    *(undefined4 *)(iVar8 + 0x78) = *(undefined4 *)(iVar5 + 0x2c);
  }
  if ((pcVar9[0x48] & 0x10U) == 0) {
    *(undefined4 *)(iVar8 + 0x7c) = *(undefined4 *)(iVar5 + 0x34);
  }
LAB_0052b08b:
  if (*(int *)(pcVar9 + 0x78) != 0) {
    for (iVar7 = FUN_004f1440(DAT_009238e4 + 0x383c0); iVar7 != 0;
        iVar7 = FUN_004f1460(DAT_009238e4 + 0x383c0,iVar7)) {
      iVar5 = FUN_004f8b10(iVar7 + 8,*(undefined4 *)(pcVar9 + 0x78));
      if (iVar5 == 0) {
        *(int *)(iVar8 + 0x80) = iVar7;
        break;
      }
    }
  }
  if (*(int *)(pcVar9 + 0x7c) != 0) {
    for (iVar7 = FUN_004f1440(DAT_009238e4 + 0x3cbd8); iVar7 != 0;
        iVar7 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar7)) {
      iVar5 = FUN_004f8b10(iVar7 + 8,*(undefined4 *)(pcVar9 + 0x7c));
      if (iVar5 == 0) {
        *(int *)(iVar8 + 0x84) = iVar7;
        break;
      }
    }
  }
  if (*(int *)(pcVar9 + 0x80) != 0) {
    for (iVar7 = FUN_004f1440(DAT_009238e4 + 0x3cbd8); iVar7 != 0;
        iVar7 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar7)) {
      iVar5 = FUN_004f8b10(iVar7 + 8,*(undefined4 *)(pcVar9 + 0x80));
      if (iVar5 == 0) {
        *(int *)(iVar8 + 0x88) = iVar7;
        break;
      }
    }
  }
  *(char *)(iVar8 + 0x8f) = pcVar9[0x87];
  if ((pcVar9[0x87] == '\x01') && (*(undefined1 *)(iVar8 + 0x8f) = 0, *(int *)(pcVar9 + 0x74) != 0))
  {
    for (iVar7 = FUN_004f1440(DAT_009238e4 + 0x383c0); iVar7 != 0;
        iVar7 = FUN_004f1460(DAT_009238e4 + 0x383c0,iVar7)) {
      iVar5 = FUN_004f8b10(iVar7 + 8,*(undefined4 *)(pcVar9 + 0x74));
      if (iVar5 == 0) {
        *(int *)(iVar8 + 0x6c) = iVar7;
        *(undefined1 *)(iVar8 + 0x8f) = 1;
        break;
      }
    }
  }
  *(char *)(iVar8 + 0x8c) = pcVar9[0x84];
  *(char *)(iVar8 + 0x8d) = pcVar9[0x85];
  *(char *)(iVar8 + 0x8e) = pcVar9[0x86];
  *(undefined4 *)(iVar8 + 0x90) = *(undefined4 *)(pcVar9 + 0x88);
  *(undefined4 *)(iVar8 + 0x94) = *(undefined4 *)(pcVar9 + 0x8c);
  *(undefined4 *)(iVar8 + 0x98) = *(undefined4 *)(pcVar9 + 0x90);
  *(undefined4 *)(iVar8 + 0x9c) = *(undefined4 *)(pcVar9 + 0x94);
  *(undefined4 *)(iVar8 + 0xa0) = *(undefined4 *)(pcVar9 + 0x98);
  *(undefined4 *)(iVar8 + 0xa4) = *(undefined4 *)(pcVar9 + 0x9c);
  *(undefined4 *)(iVar8 + 0xa8) = *(undefined4 *)(pcVar9 + 0xa0);
LAB_0052b28a:
  iVar8 = *(int *)(DAT_009238e4 + 100);
  local_8 = local_8 + 0xa4;
  local_4 = local_4 + 1;
  if (*(int *)(iVar8 + 0x14) <= local_4) goto LAB_0052b2b1;
  goto LAB_0052ae90;
}

