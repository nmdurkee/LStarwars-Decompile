/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x539c10; label: FUN_00539c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00539c10(int param_1)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  undefined1 uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined1 auStack_28 [4];
  char local_24 [12];
  undefined1 local_18;
  char local_14 [16];
  uint local_4;
  
  iVar8 = DAT_009238e4;
  local_4 = DAT_00829570 ^ (uint)auStack_28;
  uVar6 = *(uint *)(param_1 + 0x78);
  iVar11 = 0;
  if ((char)uVar6 < '\0') {
    FUN_00539900();
    __security_check_cookie(local_4 ^ (uint)auStack_28);
    return;
  }
  uVar3 = *(uint *)(param_1 + 0x70);
  if ((uVar3 & 0x40) != 0) {
    if (*(int *)(DAT_009238e4 + 0x371ac) == 0) {
      if (((uVar6 & 0x40) != 0) && (*(int *)(DAT_009238e4 + 0x48) != 0)) {
        uVar10 = 0;
        if (*(int *)(DAT_009238e4 + 0x371b0) == 0) {
          uVar7 = (*DAT_0092389c)(DAT_00921f34,0xd);
          FUN_004f1f40(local_24,uVar7);
        }
        else {
          FUN_004f1f10(local_24,*(int *)(DAT_009238e4 + 0x371b0) + 8);
          pcVar4 = _strrchr(local_24,0x5f);
          if (pcVar4 != (char *)0x0) {
            *pcVar4 = '\0';
          }
          local_18 = 0;
          uVar10 = *(undefined1 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x5a);
        }
        uVar7 = FUN_00528450(DAT_009238e4 + 0x28,DAT_00921f30);
        *(undefined4 *)(DAT_009238e4 + 0x371b0) = uVar7;
        if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
LAB_00539df0:
          iVar11 = iVar11 + 1;
          _sprintf(local_14,"%s_%d",local_24,iVar11);
          iVar8 = FUN_004f1440(DAT_009238e4 + 0x371a4);
joined_r0x00539e21:
          if (iVar8 == 0) {
            pcVar4 = local_14;
            pcVar9 = (char *)(*(int *)(DAT_009238e4 + 0x371b0) + 8);
            do {
              cVar2 = *pcVar4;
              *pcVar9 = cVar2;
              pcVar4 = pcVar4 + 1;
              pcVar9 = pcVar9 + 1;
            } while (cVar2 != '\0');
            pcVar4 = &DAT_00921f20;
            do {
              cVar2 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar2 != '\0');
            if (pcVar4 != &DAT_00921f21) {
              pcVar9 = &DAT_00921f20;
              pcVar4 = (char *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x18);
              do {
                cVar2 = *pcVar9;
                *pcVar4 = cVar2;
                pcVar9 = pcVar9 + 1;
                pcVar4 = pcVar4 + 1;
              } while (cVar2 != '\0');
            }
            iVar8 = *(int *)(DAT_009238e4 + 0x371b0);
            *(undefined4 *)(iVar8 + 0x70) = DAT_00921f3c;
            *(undefined4 *)(iVar8 + 0x74) = DAT_00921f40;
            *(undefined4 *)(iVar8 + 0x78) = _DAT_00921f44;
            *(undefined4 *)(iVar8 + 0x7c) = _DAT_00921f48;
            *(uint *)(iVar8 + 0x68) = *(uint *)(iVar8 + 0x68) & 0xffffffe1;
            puVar1 = (uint *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x68);
            *puVar1 = *puVar1 | DAT_00921f4c;
            *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x3c) =
                 *(undefined4 *)(DAT_009238e4 + 0x4868);
            puVar12 = (undefined4 *)(DAT_009238e4 + 0x48);
            puVar13 = (undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x38);
            for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar13 = *puVar12;
              puVar12 = puVar12 + 1;
              puVar13 = puVar13 + 1;
            }
            uVar7 = FUN_005be5b0(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x34),
                                 *(undefined4 *)(DAT_009238e4 + 0x60));
            *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x50) = uVar7;
            *(undefined1 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x5a) = uVar10;
            goto LAB_0053a268;
          }
          iVar5 = FUN_004f8b10(local_14,iVar8 + 8);
          if (iVar5 != 0) goto code_r0x00539e38;
          goto LAB_00539df0;
        }
      }
      goto LAB_0053a349;
    }
    if ((uVar6 & 0x40) != 0) {
      *(undefined4 *)(DAT_009238e4 + 0x371b0) = *(undefined4 *)(DAT_009238e4 + 0x371ac);
      *(undefined4 *)(DAT_009238e4 + 0x4868) =
           *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x3c);
      DAT_00921f30 = *(int *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x34);
      FUN_00620f10(*(int *)(DAT_009238e4 + 0x371b0) + 0x28);
      DAT_00921f34 = (int)*(short *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x58);
      FUN_00529ad0(*(int *)(DAT_009238e4 + 0x371b0) + 0x18,*(int *)(DAT_009238e4 + 0x371b0));
      goto LAB_0053a349;
    }
    if (*(int *)(DAT_009238e4 + 0x371b0) == 0) goto LAB_0053a349;
    if (*(int *)(DAT_009238e4 + 0x48) == 0) {
      FUN_00620f10(*(int *)(DAT_009238e4 + 0x371b0) + 0x28);
      goto LAB_0053a349;
    }
    iVar11 = *(int *)(DAT_009238e4 + 0x371b0);
    *(undefined4 *)(iVar11 + 0x28) = *(undefined4 *)(DAT_009238e4 + 0x28);
    *(undefined4 *)(iVar11 + 0x2c) = *(undefined4 *)(iVar8 + 0x2c);
    *(undefined4 *)(iVar11 + 0x30) = *(undefined4 *)(iVar8 + 0x30);
    puVar12 = (undefined4 *)(DAT_009238e4 + 0x48);
    puVar13 = (undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x38);
    for (iVar8 = 7; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar13 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar13 = puVar13 + 1;
    }
LAB_0053a241:
    uVar7 = FUN_005be5b0(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x34),
                         *(undefined4 *)(DAT_009238e4 + 0x60));
    *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x50) = uVar7;
LAB_0053a268:
    FUN_0052a710();
    goto LAB_0053a349;
  }
  if ((uVar6 & 0x10) != 0) {
    iVar8 = *(int *)(DAT_009238e4 + 0x371b0);
    if (iVar8 != 0) {
      if (iVar8 == *(int *)(DAT_009238e4 + 0x371ac)) {
        FUN_00534d70();
        __security_check_cookie(local_4 ^ (uint)auStack_28);
        return;
      }
      if ((iVar8 != 0) && (iVar11 = *(int *)(DAT_009238e4 + 0x3cbe4), iVar11 != 0)) {
        if (*(int *)(iVar8 + 0x88) == iVar11) {
          *(undefined4 *)(iVar8 + 0x88) = 0;
        }
        else if (*(int *)(iVar8 + 0x3c) == *(int *)(iVar11 + 0x2c)) {
          *(int *)(iVar8 + 0x88) = iVar11;
        }
        goto LAB_0053a349;
      }
    }
    *(undefined4 *)(DAT_009238e4 + 0x371b0) = 0;
    goto LAB_0053a349;
  }
  if ((uVar6 & 0x20) != 0) {
    if ((*(int *)(DAT_009238e4 + 0x371b0) != 0) &&
       (iVar8 = *(int *)(DAT_009238e4 + 0x3cbe4), iVar8 != 0)) {
      iVar11 = *(int *)(DAT_009238e4 + 0x371b0);
      if (*(int *)(iVar11 + 0x84) == iVar8) {
        *(undefined4 *)(iVar11 + 0x84) = 0;
      }
      else if (*(int *)(iVar11 + 0x3c) == *(int *)(iVar8 + 0x2c)) {
        *(int *)(iVar11 + 0x84) = iVar8;
      }
    }
    goto LAB_0053a349;
  }
  if (((uVar6 & 0x1000) == 0) && (((uVar3 & 0x100) == 0 || ((uVar6 & 8) == 0)))) {
    if (((uVar3 & 0x100) == 0) || ((uVar6 & 2) == 0)) {
      if ((uVar6 & 0x100) == 0) {
        if ((uVar3 & 0x2000) == 0) {
          if ((uVar3 & 0x8000) == 0) {
            if ((uVar3 & 0x4000) == 0) goto LAB_0053a349;
            uVar6 = FUN_005be5b0(DAT_00921f30,*(undefined4 *)(DAT_009238e4 + 0x60));
            iVar8 = (int)(uVar6 + ((int)uVar6 >> 0x1f & 0x3fffU)) >> 0xe;
            uVar6 = uVar6 & 0x80003fff;
            if ((int)uVar6 < 0) {
              uVar6 = (uVar6 - 1 | 0xffffc000) + 1;
            }
            if ((int)uVar6 < 0x2001) {
              if ((int)uVar6 < -0x2000) {
                iVar8 = iVar8 + -1;
              }
            }
            else {
              iVar8 = iVar8 + 1;
            }
            uVar7 = *(undefined4 *)(DAT_009238e4 + 0x60);
            iVar8 = iVar8 << 0xe;
            goto LAB_0053a211;
          }
          iVar8 = *(int *)(DAT_009238e4 + 0x371b0);
          if ((iVar8 != 0) && (iVar8 == *(int *)(DAT_009238e4 + 0x371ac))) {
            DAT_00921f30 = *(int *)(iVar8 + 0x34);
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
        }
        else {
          iVar8 = *(int *)(DAT_009238e4 + 0x371b0);
          if ((iVar8 != 0) && (iVar8 == *(int *)(DAT_009238e4 + 0x371ac))) {
            DAT_00921f30 = *(int *)(iVar8 + 0x34);
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
          uVar7 = *(undefined4 *)(DAT_009238e4 + 0x371b4);
          iVar8 = DAT_00921f30;
LAB_0053a211:
          DAT_00921f30 = FUN_005be590(iVar8,uVar7);
        }
        iVar8 = *(int *)(DAT_009238e4 + 0x371b0);
        if ((iVar8 == 0) || (iVar8 != *(int *)(DAT_009238e4 + 0x371ac))) goto LAB_0053a349;
        *(int *)(iVar8 + 0x34) = DAT_00921f30;
        goto LAB_0053a241;
      }
      uVar7 = FUN_00528b30(0);
    }
    else {
      if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
        uVar7 = FUN_004f1470(DAT_009238e4 + 0x371a4,*(undefined4 *)(DAT_009238e4 + 0x371b0));
        *(undefined4 *)(DAT_009238e4 + 0x371b0) = uVar7;
        if (*(int *)(DAT_009238e4 + 0x371b0) != 0) goto LAB_0053a2e3;
      }
      uVar7 = FUN_004f1450(DAT_009238e4 + 0x371a4);
    }
LAB_0053a2c7:
    *(undefined4 *)(DAT_009238e4 + 0x371b0) = uVar7;
    if (*(int *)(DAT_009238e4 + 0x371b0) == 0) goto LAB_0053a349;
  }
  else {
    if (*(int *)(DAT_009238e4 + 0x371b0) == 0) {
LAB_0053a2bc:
      uVar7 = FUN_004f1440(DAT_009238e4 + 0x371a4);
      goto LAB_0053a2c7;
    }
    uVar7 = FUN_004f1460(DAT_009238e4 + 0x371a4,*(undefined4 *)(DAT_009238e4 + 0x371b0));
    *(undefined4 *)(DAT_009238e4 + 0x371b0) = uVar7;
    if (*(int *)(DAT_009238e4 + 0x371b0) == 0) goto LAB_0053a2bc;
  }
LAB_0053a2e3:
  *(undefined4 *)(DAT_009238e4 + 0x4868) = *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x3c);
  if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
    FUN_00620f10(*(int *)(DAT_009238e4 + 0x371b0) + 0x28);
  }
  DAT_00921f34 = (int)*(short *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x58);
  FUN_00529ad0(*(int *)(DAT_009238e4 + 0x371b0) + 0x18,*(int *)(DAT_009238e4 + 0x371b0));
LAB_0053a349:
  uVar7 = FUN_00521fd0(1);
  *(undefined4 *)(DAT_009238e4 + 0x3cbe4) = uVar7;
  uVar7 = FUN_00528b30(1);
  *(undefined4 *)(DAT_009238e4 + 0x371ac) = uVar7;
  __security_check_cookie(local_4 ^ (uint)auStack_28);
  return;
code_r0x00539e38:
  iVar8 = FUN_004f1460(DAT_009238e4 + 0x371a4,iVar8);
  goto joined_r0x00539e21;
}

