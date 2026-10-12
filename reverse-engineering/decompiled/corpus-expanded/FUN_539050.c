/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x539050; label: FUN_00539050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00539050(int param_1)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  
  uVar1 = *(uint *)(param_1 + 0x78);
  if ((char)uVar1 < '\0') {
    uVar5 = FUN_00538e50();
    return uVar5;
  }
  uVar2 = *(uint *)(param_1 + 0x70);
  if ((uVar2 & 0x40) != 0) {
    iVar6 = *(int *)(DAT_009238e4 + 0x43820);
    if (iVar6 != 0) {
      if ((uVar1 & 0x40) == 0) {
        iVar8 = *(int *)(DAT_009238e4 + 0x4381c);
        if ((iVar8 != 0) && (iVar8 == iVar6)) {
          if (((uVar1 & 0x100) == 0) || (iVar6 = FUN_005cfac0(iVar8 + 0x20), iVar6 == 0)) {
            iVar8 = DAT_009238e4;
            iVar6 = *(int *)(DAT_009238e4 + 0x4381c);
            *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(DAT_009238e4 + 0x28);
            *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(iVar8 + 0x2c);
            *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar8 + 0x30);
            FUN_00527620();
            if (*(char *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x49) != '\0') {
              uVar1 = *(uint *)(param_1 + 0x70);
              if ((uVar1 & 0x8000) == 0) {
                if ((uVar1 & 0x2000) == 0) {
                  if ((uVar1 & 0x1000) == 0) {
                    if ((uVar1 & 0x4000) != 0) {
                      *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x44) =
                           *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x44) * 0.99;
                      if (*(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x44) < 0.05) {
                        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x44) = 0x3d4ccccd;
                      }
                    }
                  }
                  else {
                    *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x44) =
                         *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x44) * 1.01;
                  }
                }
                else {
                  *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x40) =
                       *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x40) * 1.01;
                }
              }
              else {
                *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x40) =
                     *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x40) * 0.99;
                if (*(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x40) < 0.05) {
                  *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x40) = 0x3d4ccccd;
                }
              }
            }
          }
          else {
            puVar7 = (undefined4 *)FUN_005cf9e0(DAT_009238e4 + 0x3c);
            if (puVar7 != (undefined4 *)0x0) {
              *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4381c) + 8) = *puVar7;
              *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x10) = puVar7[2];
              FUN_00527620();
              FUN_00620f10(*(int *)(DAT_009238e4 + 0x4381c) + 8);
            }
          }
        }
      }
      else {
        *(int *)(DAT_009238e4 + 0x4381c) = iVar6;
        FUN_00620f10(*(int *)(DAT_009238e4 + 0x4381c) + 8);
      }
      goto LAB_005398df;
    }
    if ((uVar1 & 0x40) == 0) goto LAB_005398df;
    uVar5 = FUN_005274f0();
    *(undefined4 *)(DAT_009238e4 + 0x4381c) = uVar5;
LAB_0053975a:
    FUN_00527620();
    goto LAB_005398df;
  }
  if ((uVar1 & 0x10) != 0) {
    if ((*(int *)(DAT_009238e4 + 0x4381c) != 0) &&
       (*(int *)(DAT_009238e4 + 0x4381c) == *(int *)(DAT_009238e4 + 0x43820))) {
      uVar5 = FUN_00527de0();
      return uVar5;
    }
    goto LAB_005398df;
  }
  if ((uVar1 & 0x100) != 0) {
    uVar5 = FUN_00527bc0(0);
    *(undefined4 *)(DAT_009238e4 + 0x4381c) = uVar5;
    if (*(int *)(DAT_009238e4 + 0x4381c) != 0) {
      FUN_00620f10(*(int *)(DAT_009238e4 + 0x4381c) + 8);
    }
    goto LAB_005398df;
  }
  if ((uVar2 & 0x100) == 0) {
    if ((uVar2 & 0x8000) != 0) {
      iVar6 = *(int *)(DAT_009238e4 + 0x4381c);
      if ((iVar6 != 0) && (iVar6 == *(int *)(DAT_009238e4 + 0x43820))) {
        if (*(char *)(iVar6 + 0x49) == '\0') {
          *(float *)(iVar6 + 0x14) = *(float *)(iVar6 + 0x14) * 0.99;
          if (*(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x14) < 0.05) {
            *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x14) = 0x3d4ccccd;
          }
        }
        else {
          DAT_00921f30 = *(undefined4 *)(iVar6 + 0x3c);
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
          iVar6 = *(int *)(DAT_009238e4 + 0x4381c);
          if ((iVar6 != 0) && (iVar6 == *(int *)(DAT_009238e4 + 0x43820))) {
            *(undefined4 *)(iVar6 + 0x3c) = DAT_00921f30;
          }
          FUN_00527620();
        }
      }
      goto LAB_005398df;
    }
    if ((uVar2 & 0x2000) != 0) {
      iVar6 = *(int *)(DAT_009238e4 + 0x4381c);
      if ((iVar6 == 0) || (iVar6 != *(int *)(DAT_009238e4 + 0x43820))) goto LAB_005398df;
      if (*(char *)(iVar6 + 0x49) == '\0') {
        *(float *)(iVar6 + 0x14) = *(float *)(iVar6 + 0x14) * 1.01;
        goto LAB_005398df;
      }
      DAT_00921f30 = *(undefined4 *)(iVar6 + 0x3c);
      if ((*(uint *)(param_1 + 0x78) & 0x8000) == 0) {
        *(int *)(DAT_009238e4 + 0x371b4) = *(int *)(DAT_009238e4 + 0x371b4) + 0x14;
        if (600 < *(int *)(DAT_009238e4 + 0x371b4)) {
          *(undefined4 *)(DAT_009238e4 + 0x371b4) = 600;
        }
      }
      else {
        *(undefined4 *)(DAT_009238e4 + 0x371b4) = 0x14;
      }
      DAT_00921f30 = FUN_005be590(DAT_00921f30,*(undefined4 *)(DAT_009238e4 + 0x371b4));
      iVar6 = *(int *)(DAT_009238e4 + 0x4381c);
      if ((iVar6 != 0) && (iVar6 == *(int *)(DAT_009238e4 + 0x43820))) {
        *(undefined4 *)(iVar6 + 0x3c) = DAT_00921f30;
      }
      goto LAB_0053975a;
    }
    if ((uVar2 & 0x1000) == 0) {
      if (((((uVar2 & 0x4000) == 0) || ((DAT_00921f50 & 0x100) == 0)) ||
          (*(int *)(DAT_009238e4 + 0x4381c) == 0)) ||
         (*(int *)(DAT_009238e4 + 0x4381c) != *(int *)(DAT_009238e4 + 0x43820))) goto LAB_005398df;
      *(uint *)(DAT_009238e4 + 0x43828) = *(uint *)(DAT_009238e4 + 0x43828) | 4;
      fVar3 = (*(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x1c) -
              *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x18)) * 0.05;
      if ((*(uint *)(param_1 + 0x70) & 4) == 0) {
        if ((*(uint *)(param_1 + 0x70) & 1) != 0) {
          iVar6 = *(int *)(DAT_009238e4 + 0x4381c);
          fVar3 = *(float *)(iVar6 + 0x18) - fVar3;
          goto LAB_005398a7;
        }
      }
      else {
        iVar6 = *(int *)(DAT_009238e4 + 0x4381c);
        fVar3 = *(float *)(iVar6 + 0x18) + fVar3;
LAB_005398a7:
        *(float *)(iVar6 + 0x18) = fVar3;
      }
      if (*(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x1c) - 0.01 <
          *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x18)) {
        *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x18) =
             *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x1c) - 0.01;
      }
      goto LAB_005398df;
    }
    if ((((DAT_00921f50 & 0x100) == 0) || (*(int *)(DAT_009238e4 + 0x4381c) == 0)) ||
       (*(int *)(DAT_009238e4 + 0x4381c) != *(int *)(DAT_009238e4 + 0x43820))) goto LAB_005398df;
    *(uint *)(DAT_009238e4 + 0x43828) = *(uint *)(DAT_009238e4 + 0x43828) | 4;
    fVar3 = (*(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x1c) -
            *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x18)) * 0.05;
    if ((*(uint *)(param_1 + 0x70) & 4) == 0) {
      if ((*(uint *)(param_1 + 0x70) & 1) != 0) {
        iVar6 = *(int *)(DAT_009238e4 + 0x4381c);
        fVar3 = *(float *)(iVar6 + 0x1c) - fVar3;
        goto LAB_005397ea;
      }
    }
    else {
      iVar6 = *(int *)(DAT_009238e4 + 0x4381c);
      fVar3 = fVar3 + *(float *)(iVar6 + 0x1c);
LAB_005397ea:
      *(float *)(iVar6 + 0x1c) = fVar3;
    }
    if (*(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x1c) <
        *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x18) + 0.01) {
      *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x1c) =
           *(float *)(*(int *)(DAT_009238e4 + 0x4381c) + 0x18) + 0.01;
    }
    goto LAB_005398df;
  }
  bVar4 = false;
  if ((uVar1 & 8) != 0) {
LAB_00539322:
    if (*(int *)(DAT_009238e4 + 0x4381c) == 0) {
LAB_0053935f:
      uVar5 = FUN_004f1440(DAT_009238e4 + 0x43814);
      *(undefined4 *)(DAT_009238e4 + 0x4381c) = uVar5;
    }
    else {
      uVar5 = FUN_004f1460(DAT_009238e4 + 0x43814,*(undefined4 *)(DAT_009238e4 + 0x4381c));
      *(undefined4 *)(DAT_009238e4 + 0x4381c) = uVar5;
      if (*(int *)(DAT_009238e4 + 0x4381c) == 0) goto LAB_0053935f;
    }
    if (bVar4) {
      if (*(int *)(DAT_009238e4 + 0x4381c) == 0) goto LAB_005398df;
      iVar6 = FUN_005cfac0(*(int *)(DAT_009238e4 + 0x4381c) + 0x20);
      if (iVar6 != 0) {
        iVar6 = *(int *)(DAT_009238e4 + 0x4381c);
        do {
          uVar5 = FUN_004f1460(DAT_009238e4 + 0x43814,*(undefined4 *)(DAT_009238e4 + 0x4381c));
          *(undefined4 *)(DAT_009238e4 + 0x4381c) = uVar5;
          iVar8 = *(int *)(DAT_009238e4 + 0x4381c);
          if (iVar8 == 0) {
            uVar5 = FUN_004f1440(DAT_009238e4 + 0x43814);
            *(undefined4 *)(DAT_009238e4 + 0x4381c) = uVar5;
            iVar8 = *(int *)(DAT_009238e4 + 0x4381c);
            if (iVar8 == 0) break;
          }
          if (iVar8 == iVar6) goto LAB_0053956a;
          iVar8 = FUN_005cfac0(*(int *)(DAT_009238e4 + 0x4381c) + 0x20);
        } while (iVar8 != 0);
      }
    }
    goto LAB_00539579;
  }
  if ((uVar1 & 2) == 0) {
    if ((uVar1 & 4) != 0) {
      bVar4 = true;
      goto LAB_00539322;
    }
    if ((uVar1 & 1) == 0) goto LAB_005398df;
    bVar4 = true;
  }
  if (*(int *)(DAT_009238e4 + 0x4381c) == 0) {
LAB_00539494:
    uVar5 = FUN_004f1450(DAT_009238e4 + 0x43814);
    *(undefined4 *)(DAT_009238e4 + 0x4381c) = uVar5;
  }
  else {
    uVar5 = FUN_004f1470(DAT_009238e4 + 0x43814,*(undefined4 *)(DAT_009238e4 + 0x4381c));
    *(undefined4 *)(DAT_009238e4 + 0x4381c) = uVar5;
    if (*(int *)(DAT_009238e4 + 0x4381c) == 0) goto LAB_00539494;
  }
  if (bVar4) {
    if (*(int *)(DAT_009238e4 + 0x4381c) == 0) goto LAB_005398df;
    iVar6 = FUN_005cfac0(*(int *)(DAT_009238e4 + 0x4381c) + 0x20);
    if (iVar6 != 0) {
      iVar6 = *(int *)(DAT_009238e4 + 0x4381c);
      do {
        uVar5 = FUN_004f1470(DAT_009238e4 + 0x43814,*(undefined4 *)(DAT_009238e4 + 0x4381c));
        *(undefined4 *)(DAT_009238e4 + 0x4381c) = uVar5;
        iVar8 = *(int *)(DAT_009238e4 + 0x4381c);
        if (iVar8 == 0) {
          uVar5 = FUN_004f1450(DAT_009238e4 + 0x43814);
          *(undefined4 *)(DAT_009238e4 + 0x4381c) = uVar5;
          iVar8 = *(int *)(DAT_009238e4 + 0x4381c);
          if (iVar8 == 0) break;
        }
        if (iVar8 == iVar6) goto LAB_0053956a;
        iVar8 = FUN_005cfac0(*(int *)(DAT_009238e4 + 0x4381c) + 0x20);
      } while (iVar8 != 0);
    }
  }
LAB_00539579:
  if (*(int *)(DAT_009238e4 + 0x4381c) != 0) {
    FUN_00620f10(*(int *)(DAT_009238e4 + 0x4381c) + 8);
  }
LAB_005398df:
  uVar5 = FUN_00527bc0(1);
  *(undefined4 *)(DAT_009238e4 + 0x43820) = uVar5;
  return 0;
LAB_0053956a:
  *(undefined4 *)(DAT_009238e4 + 0x4381c) = 0;
  goto LAB_00539579;
}

