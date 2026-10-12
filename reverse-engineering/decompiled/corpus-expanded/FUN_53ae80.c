/* Ghidra pseudocode, not original source.
 * ev_4dde03cd79a837517a28bb41bf0bd080ad03d09c77c06073e29a0b26ddc1f284
 * Entry: 0x53ae80; label: FUN_0053ae80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053ae80(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  int *piVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  bool bVar14;
  char local_a4 [16];
  char local_94 [16];
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_a4;
  if ((*(byte *)(param_1 + 0x78) & 0x80) != 0) {
    FUN_0053ac10();
    __security_check_cookie(local_4 ^ (uint)local_a4);
    return;
  }
  iVar3 = FUN_004f1ff0(DAT_009238e4 + 0x411e8);
  if (iVar3 != 0) {
    if (*(int *)(DAT_009238e4 + 0x41208) != 0) {
      _sprintf(local_84,"Add locators \"%s\" to set \"%s\"?",DAT_009238e4 + 0x411e8,
               *(int *)(DAT_009238e4 + 0x41208) + 8);
      iVar3 = FUN_00619250(100,0x46,0x1b8,0x10e,DAT_02912e80,FUN_00527360,local_84);
      if (iVar3 != 0) {
        uVar4 = FUN_00627a80(0,&DAT_00801cb4,0,0,&LAB_00531510,&DAT_0075f2d0);
        FUN_00618e10(iVar3,uVar4);
        uVar4 = FUN_00627a80(1,&DAT_00801cb4,0,0,&LAB_00531510,&PTR_DAT_0075f2d4);
        FUN_00618e10(iVar3,uVar4);
        __security_check_cookie(local_4 ^ (uint)local_a4);
        return;
      }
    }
    iVar3 = DAT_009238e4;
    *(undefined4 *)(DAT_009238e4 + 0x411e8) = 0;
    *(undefined4 *)(iVar3 + 0x411ec) = 0;
    *(undefined4 *)(iVar3 + 0x411f0) = 0;
    *(undefined4 *)(iVar3 + 0x411f4) = 0;
  }
  iVar3 = DAT_009238e4;
  uVar8 = *(uint *)(param_1 + 0x70);
  if ((uVar8 & 0x40) == 0) {
    uVar2 = *(uint *)(param_1 + 0x78);
    if ((uVar2 & 0x10) != 0) {
      if ((*(int *)(DAT_009238e4 + 0x3cbe0) != 0) &&
         (*(int *)(DAT_009238e4 + 0x3cbe0) == *(int *)(DAT_009238e4 + 0x3cbe4))) {
        FUN_005389a0();
        __security_check_cookie(local_4 ^ (uint)local_a4);
        return;
      }
      goto LAB_0053b75f;
    }
    if ((uVar8 & 0x100) == 0) {
      if ((uVar8 & 0x2000) == 0) {
        if ((uVar8 & 0x8000) != 0) {
          iVar3 = *(int *)(DAT_009238e4 + 0x3cbe0);
          if ((iVar3 != 0) && (iVar3 == *(int *)(DAT_009238e4 + 0x3cbe4))) {
            DAT_00921f30 = *(int *)(iVar3 + 0x24);
          }
          if ((*(uint *)(param_1 + 0x78) & 0x2000) == 0) {
            *(int *)(DAT_009238e4 + 0x371b4) = *(int *)(DAT_009238e4 + 0x371b4) + 0x14;
            if (600 < *(int *)(DAT_009238e4 + 0x371b4)) {
              *(undefined4 *)(DAT_009238e4 + 0x371b4) = 600;
            }
          }
          else {
            *(undefined4 *)(DAT_009238e4 + 0x371b4) = 0x14;
          }
          DAT_00921f30 = FUN_005be5b0(DAT_00921f30,*(undefined4 *)(DAT_009238e4 + 0x371b4));
          iVar3 = *(int *)(DAT_009238e4 + 0x3cbe0);
          if ((iVar3 == 0) || (iVar3 != *(int *)(DAT_009238e4 + 0x3cbe4))) goto LAB_0053b75f;
          *(int *)(iVar3 + 0x24) = DAT_00921f30;
          goto LAB_0053b569;
        }
        if ((uVar8 & 0x4000) == 0) {
          if (((((uVar8 & 0x20) != 0) && (*(int *)(DAT_009238e4 + 0x41208) != 0)) &&
              ((uVar2 & 0x20) != 0)) && (iVar3 = *(int *)(DAT_009238e4 + 0x3cbe4), iVar3 != 0)) {
            if ((*(int *)(DAT_009238e4 + 0x41208) != 0) && (iVar3 != 0)) {
              iVar12 = 0;
              piVar10 = (int *)(*(int *)(DAT_009238e4 + 0x41208) + 0x18);
              do {
                if (*piVar10 == iVar3) {
                  FUN_00521ad0();
                  iVar12 = *(int *)(DAT_009238e4 + 0x3cbe0);
                  if ((iVar12 == 0) || (iVar12 == *(int *)(DAT_009238e4 + 0x3cbe4)))
                  goto LAB_0053b75f;
                  iVar3 = *(int *)(DAT_009238e4 + 0x3cbe4);
                  goto LAB_0053b707;
                }
                if (*piVar10 == 0) break;
                iVar12 = iVar12 + 1;
                piVar10 = piVar10 + 1;
              } while (iVar12 < 0x40);
            }
            iVar12 = *(int *)(DAT_009238e4 + 0x3cbe0);
            if ((iVar12 == 0) || (iVar12 == iVar3)) {
              iVar12 = 0;
            }
LAB_0053b707:
            iVar3 = FUN_00521b30(iVar3,iVar12);
            if (iVar3 != 0) {
              *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = *(undefined4 *)(DAT_009238e4 + 0x3cbe4);
              *(undefined4 *)(DAT_009238e4 + 0x4868) =
                   *(undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x2c);
              DAT_00921f30 = *(int *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x24);
              FUN_00620f10(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x18);
            }
          }
          goto LAB_0053b75f;
        }
        uVar8 = FUN_005be5b0(DAT_00921f30,*(undefined4 *)(DAT_009238e4 + 0x60));
        iVar3 = (int)(uVar8 + ((int)uVar8 >> 0x1f & 0x3fffU)) >> 0xe;
        uVar8 = uVar8 & 0x80003fff;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xffffc000) + 1;
        }
        if ((int)uVar8 < 0x2001) {
          if ((int)uVar8 < -0x2000) {
            iVar3 = iVar3 + -1;
          }
        }
        else {
          iVar3 = iVar3 + 1;
        }
        uVar4 = *(undefined4 *)(DAT_009238e4 + 0x60);
        iVar3 = iVar3 << 0xe;
      }
      else {
        iVar3 = *(int *)(DAT_009238e4 + 0x3cbe0);
        if ((iVar3 != 0) && (iVar3 == *(int *)(DAT_009238e4 + 0x3cbe4))) {
          DAT_00921f30 = *(int *)(iVar3 + 0x24);
        }
        if ((*(uint *)(param_1 + 0x78) & 0x8000) == 0) {
          *(int *)(DAT_009238e4 + 0x371b4) = *(int *)(DAT_009238e4 + 0x371b4) + 0x14;
          if (600 < *(int *)(DAT_009238e4 + 0x371b4)) {
            *(undefined4 *)(DAT_009238e4 + 0x371b4) = 600;
          }
        }
        else {
          *(undefined4 *)(DAT_009238e4 + 0x371b4) = 0x14;
        }
        uVar4 = *(undefined4 *)(DAT_009238e4 + 0x371b4);
        iVar3 = DAT_00921f30;
      }
      DAT_00921f30 = FUN_005be590(iVar3,uVar4);
      iVar3 = *(int *)(DAT_009238e4 + 0x3cbe0);
      if ((iVar3 != 0) && (iVar3 == *(int *)(DAT_009238e4 + 0x3cbe4))) {
        *(int *)(iVar3 + 0x24) = DAT_00921f30;
        uVar4 = FUN_005be5b0(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x24),
                             *(undefined4 *)(DAT_009238e4 + 0x60));
        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x40) = uVar4;
      }
      goto LAB_0053b75f;
    }
    if ((uVar2 & 8) == 0) {
      if ((uVar2 & 2) == 0) {
        bVar14 = (uVar2 & 0x100) != 0;
        if (bVar14) {
          uVar4 = FUN_00521fd0(0);
          *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = uVar4;
        }
      }
      else {
        if (*(int *)(DAT_009238e4 + 0x41208) == 0) {
          if (*(int *)(DAT_009238e4 + 0x3cbe0) != 0) {
            uVar4 = FUN_004f1470(DAT_009238e4 + 0x3cbd8,*(undefined4 *)(DAT_009238e4 + 0x3cbe0));
            *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = uVar4;
          }
          if (*(int *)(DAT_009238e4 + 0x3cbe0) == 0) {
            uVar4 = FUN_004f1450(DAT_009238e4 + 0x3cbd8);
            goto LAB_0053b3bd;
          }
          goto LAB_0053b3d2;
        }
        uVar4 = FUN_005224a0();
        *(undefined4 *)(iVar3 + 0x3cbe0) = uVar4;
        bVar14 = true;
      }
    }
    else if (*(int *)(DAT_009238e4 + 0x41208) == 0) {
      if (*(int *)(DAT_009238e4 + 0x3cbe0) != 0) {
        uVar4 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,*(undefined4 *)(DAT_009238e4 + 0x3cbe0));
        *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = uVar4;
      }
      if (*(int *)(DAT_009238e4 + 0x3cbe0) == 0) {
        uVar4 = FUN_004f1440(DAT_009238e4 + 0x3cbd8);
LAB_0053b3bd:
        *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = uVar4;
      }
LAB_0053b3d2:
      bVar14 = true;
    }
    else {
      uVar4 = FUN_00522460();
      *(undefined4 *)(iVar3 + 0x3cbe0) = uVar4;
      bVar14 = true;
    }
    if (((*(int *)(DAT_009238e4 + 0x3cbe0) != 0) && (bVar14)) &&
       (*(undefined4 *)(DAT_009238e4 + 0x4868) =
             *(undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x2c),
       *(int *)(DAT_009238e4 + 0x3cbe0) != 0)) {
      FUN_00620f10(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x18);
    }
    goto LAB_0053b75f;
  }
  if (*(int *)(DAT_009238e4 + 0x3cbe4) != 0) {
    if ((*(byte *)(param_1 + 0x78) & 0x40) == 0) {
      if (*(int *)(DAT_009238e4 + 0x3cbe0) == 0) goto LAB_0053b75f;
      if (*(int *)(DAT_009238e4 + 0x48) != 0) {
        iVar12 = *(int *)(DAT_009238e4 + 0x3cbe0);
        *(undefined4 *)(iVar12 + 0x18) = *(undefined4 *)(DAT_009238e4 + 0x28);
        *(undefined4 *)(iVar12 + 0x1c) = *(undefined4 *)(iVar3 + 0x2c);
        *(undefined4 *)(iVar12 + 0x20) = *(undefined4 *)(iVar3 + 0x30);
        puVar11 = (undefined4 *)(DAT_009238e4 + 0x48);
        puVar13 = (undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x28);
        for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar13 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar13 = puVar13 + 1;
        }
LAB_0053b569:
        uVar4 = FUN_005be5b0(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x24),
                             *(undefined4 *)(DAT_009238e4 + 0x60));
        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x40) = uVar4;
        goto LAB_0053b75f;
      }
    }
    else {
      *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = *(undefined4 *)(DAT_009238e4 + 0x3cbe4);
      *(undefined4 *)(DAT_009238e4 + 0x4868) =
           *(undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x2c);
      DAT_00921f30 = *(int *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x24);
    }
    FUN_00620f10(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x18);
    goto LAB_0053b75f;
  }
  if (((*(byte *)(param_1 + 0x78) & 0x40) == 0) || (*(int *)(DAT_009238e4 + 0x48) == 0))
  goto LAB_0053b75f;
  if ((*(int *)(DAT_009238e4 + 0x41208) == 0) ||
     (iVar3 = FUN_004f1ff0(*(int *)(DAT_009238e4 + 0x41208) + 8), iVar3 == 0)) {
    if (*(int *)(DAT_009238e4 + 0x3cbe0) != 0) {
      iVar3 = *(int *)(DAT_009238e4 + 0x3cbe0);
      goto LAB_0053b0c1;
    }
    FUN_004f1f10(local_a4,"Locator");
  }
  else {
    iVar3 = *(int *)(DAT_009238e4 + 0x41208);
LAB_0053b0c1:
    FUN_004f1f10(local_a4,iVar3 + 8);
    pcVar5 = _strrchr(local_a4,0x5f);
    if (pcVar5 != (char *)0x0) {
      *pcVar5 = '\0';
    }
  }
  iVar3 = *(int *)(DAT_009238e4 + 0x3cbe0);
  uVar4 = FUN_005219d0(DAT_00921f30);
  *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = uVar4;
  if (*(int *)(DAT_009238e4 + 0x3cbe0) != 0) {
    iVar12 = 0;
    do {
      iVar12 = iVar12 + 1;
      _sprintf(local_94,"%s_%d",local_a4,iVar12);
      iVar6 = FUN_004f1440(DAT_009238e4 + 0x3cbd8);
      while( true ) {
        if (iVar6 == 0) {
          pcVar5 = local_94;
          pcVar9 = (char *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 8);
          do {
            cVar1 = *pcVar5;
            *pcVar9 = cVar1;
            pcVar5 = pcVar5 + 1;
            pcVar9 = pcVar9 + 1;
          } while (cVar1 != '\0');
          *(undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x2c) =
               *(undefined4 *)(DAT_009238e4 + 0x4868);
          puVar11 = (undefined4 *)(DAT_009238e4 + 0x48);
          puVar13 = (undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x28);
          for (iVar12 = 7; iVar12 != 0; iVar12 = iVar12 + -1) {
            *puVar13 = *puVar11;
            puVar11 = puVar11 + 1;
            puVar13 = puVar13 + 1;
          }
          uVar4 = FUN_005be5b0(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x24),
                               *(undefined4 *)(DAT_009238e4 + 0x60));
          *(undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x40) = uVar4;
          if ((iVar3 == 0) || (iVar3 == *(int *)(DAT_009238e4 + 0x3cbe0))) {
            FUN_00521b30(*(undefined4 *)(DAT_009238e4 + 0x3cbe0),0);
          }
          else {
            FUN_00521b30(*(undefined4 *)(DAT_009238e4 + 0x3cbe0),iVar3);
          }
          goto LAB_0053b75f;
        }
        iVar7 = FUN_004f8b10(local_94,iVar6 + 8);
        if (iVar7 == 0) break;
        iVar6 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar6);
      }
    } while( true );
  }
LAB_0053b75f:
  uVar4 = FUN_00528b30(1);
  *(undefined4 *)(DAT_009238e4 + 0x371ac) = uVar4;
  uVar4 = FUN_00521fd0(1);
  *(undefined4 *)(DAT_009238e4 + 0x3cbe4) = uVar4;
  __security_check_cookie(local_4 ^ (uint)local_a4);
  return;
}

