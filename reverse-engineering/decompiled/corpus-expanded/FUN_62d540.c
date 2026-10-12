/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62d540; label: FUN_0062d540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062d540(short *param_1,int param_2,uint *param_3,uint param_4,int param_5)

{
  uint uVar1;
  bool bVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int extraout_ECX;
  int iVar9;
  int *piVar10;
  undefined2 *puVar11;
  int iVar12;
  int *piVar13;
  uint *local_484;
  short *local_480;
  int local_47c;
  int local_478;
  int local_474;
  int *piStack_470;
  int local_46c;
  undefined4 uStack_468;
  undefined4 uStack_464;
  undefined4 uStack_460;
  undefined4 local_45c;
  undefined1 local_458;
  undefined4 local_450;
  undefined1 local_44c;
  undefined1 local_444 [64];
  undefined1 local_404 [256];
  undefined1 local_304 [256];
  undefined1 local_204 [256];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_484;
  local_484 = param_3;
  local_45c = 0x336e612e;
  local_480 = param_1;
  local_458 = 0;
  local_450 = 0x6173622e;
  local_44c = 0;
  if (DAT_029130e8 == 0) {
    FUN_0062d500();
    iVar7 = *(int *)(DAT_029130e4 + 0x18);
    iVar12 = 0;
    iVar9 = DAT_029130e4;
    if (0 < *(int *)(DAT_029130e4 + 0xc)) {
      do {
        iVar5 = 0;
        if (0 < *(int *)(iVar9 + 8)) {
          do {
            if (((*(int *)(*(int *)(iVar7 + 0xc) + iVar5 * 4) != 0) ||
                (*(int *)(*(int *)(iVar7 + 0x10) + iVar5 * 4) != 0)) &&
               ((*(byte *)(*(int *)(*(int *)(iVar7 + 8) + iVar5 * 4) + 4) & 1) == 0)) {
              *(undefined4 *)(*(int *)(iVar7 + 8) + iVar5 * 4) = 0;
              *(undefined4 *)(*(int *)(iVar7 + 0xc) + iVar5 * 4) = 0;
              *(undefined4 *)(*(int *)(iVar7 + 0x10) + iVar5 * 4) = 0;
              iVar9 = DAT_029130e4;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < *(int *)(iVar9 + 8));
        }
        iVar12 = iVar12 + 1;
        iVar7 = iVar7 + 0x54;
      } while (iVar12 < *(int *)(iVar9 + 0xc));
    }
    iVar12 = *(int *)(iVar9 + 0xc);
    if (iVar12 < *(int *)(iVar9 + 4)) {
      puVar8 = (undefined4 *)(iVar7 + 4);
      do {
        *puVar8 = 0;
        iVar12 = iVar12 + 1;
        puVar8 = puVar8 + 0x15;
        iVar9 = DAT_029130e4;
      } while (iVar12 < *(int *)(DAT_029130e4 + 4));
    }
    *(undefined4 *)(iVar9 + 0x10) = *(undefined4 *)(iVar9 + 0xc);
  }
  DAT_029130e8 = 0;
  if (param_1 != (short *)0x0) {
    sVar4 = *param_1;
    while ((iVar7 = (int)sVar4, local_46c = iVar7, iVar7 != -1 &&
           (*(int *)(DAT_029130e4 + 0x10) < *(int *)(DAT_029130e4 + 4)))) {
      iVar9 = iVar7 * 0x4c;
      iVar12 = *(int *)(DAT_029130e4 + 0x20) + iVar9;
      local_478 = iVar12;
      FUN_004f1f10(local_444,"chars\\");
      FUN_004f1e80(local_444,*(undefined4 *)(iVar12 + 8));
      FUN_004f1e80(local_444,&DAT_0075a204);
      local_474 = 0;
      if (*(short *)(*(int *)(DAT_029130e4 + 0x1c) + iVar7 * 2) == -1) {
        if ((param_5 == 0) || (param_1[1] == 0)) {
          uVar6 = *(undefined4 *)(iVar12 + 0xc);
        }
        else {
          uVar6 = *(undefined4 *)(iVar12 + 0xc);
        }
        FUN_0062a5f0(uVar6);
        puVar11 = (undefined2 *)
                  (*(int *)(DAT_029130e4 + 0x10) * 0x54 + *(int *)(DAT_029130e4 + 0x18));
        FUN_0062d2e0(puVar11);
        FUN_004f1f10(local_404,local_444);
        FUN_004f1f10(local_304,local_444);
        FUN_004f1e80(local_404,*(undefined4 *)(iVar12 + 0xc));
        FUN_004f1e80(local_304,*(undefined4 *)(iVar12 + 8));
        FUN_004f1f10(local_204,local_404);
        FUN_004f1e80(local_204,&DAT_0076b1b0);
        FUN_004f1e80(local_304,&DAT_0076b1b0);
        FUN_004f1e80(local_404,&DAT_0075eacc);
        iVar7 = FUN_005ef810(local_404,local_484,param_4);
        *(int *)(puVar11 + 2) = iVar7;
        if (iVar7 != 0) {
          iVar7 = 0;
          puVar8 = (undefined4 *)(puVar11 + 10);
          do {
            uVar6 = FUN_00604c50(*(undefined4 *)(puVar11 + 2),iVar7);
            *puVar8 = uVar6;
            iVar7 = iVar7 + 1;
            puVar8 = puVar8 + 1;
          } while (iVar7 < 0x10);
          local_474 = 1;
          param_1 = local_480;
          goto LAB_0062d807;
        }
      }
      else {
        sVar4 = FUN_0062a5f0();
        puVar11 = (undefined2 *)(sVar4 * 0x54 + *(int *)(extraout_ECX + 0x18));
LAB_0062d807:
        if ((param_5 == 0) || (param_1[1] == 0)) {
          piVar13 = (int *)0x0;
        }
        else {
          piVar13 = *(int **)(*(int *)(DAT_029130e4 + 0x20) + 0x10 + iVar9);
        }
        if (DAT_029130ec == 0) {
          FUN_004f1f10(local_104,local_304);
          local_47c = FUN_004fd9f0(local_104,local_484,param_4,0x10);
          iVar7 = local_47c;
          if (local_47c == 0) {
            FUN_004f1f10(local_104,local_204);
            local_47c = FUN_004fd9f0(local_204,local_484,param_4,0x10);
            iVar7 = local_47c;
            if (local_47c == 0) goto joined_r0x0062dd2f;
          }
          for (; (piVar13 != (int *)0x0 && (*piVar13 != 0)); piVar13 = piVar13 + 0x13) {
            uVar1 = piVar13[1];
            if ((uVar1 & 0x8000) == 0) {
              if (param_2 == 0) {
                if ((uVar1 & 1) == 0) goto LAB_0062d8f2;
              }
              else if ((uVar1 & 1) != 0) {
LAB_0062d8f2:
                if (((uVar1 & 4) != 0) &&
                   (*(int *)(*(int *)(puVar11 + 6) + (short)piVar13[2] * 4) == 0)) {
                  if ((DAT_029130f0 == (code *)0x0) ||
                     (iVar12 = (*DAT_029130f0)(s_chars_commonanims__0080fb98,DAT_029130f4,piVar13,
                                               local_404), iVar12 == 0)) {
                    FUN_004f1f10(local_404,local_444);
                    FUN_004f1e80(local_404,*piVar13);
                  }
                  FUN_004f1e80(local_404,&local_45c);
                  iVar12 = FUN_004f9de0(iVar7,local_404);
                  if (iVar12 != 0) {
                    FUN_004f0fb0(iVar7,iVar12,1);
                  }
                }
                if (((*(byte *)(piVar13 + 1) & 8) != 0) &&
                   (*(int *)(*(int *)(puVar11 + 8) + (short)piVar13[2] * 4) == 0)) {
                  if ((DAT_029130f0 == (code *)0x0) ||
                     (iVar12 = (*DAT_029130f0)(s_chars_commonanims__0080fb98,DAT_029130f4,piVar13,
                                               local_404), iVar12 == 0)) {
                    FUN_004f1f10(local_404,local_444);
                    FUN_004f1e80(local_404,*piVar13);
                  }
                  FUN_004f1e80(local_404,&local_450);
                  iVar12 = FUN_004f9de0(iVar7,local_404);
                  if (iVar12 != 0) {
                    FUN_004f0fb0(iVar7,iVar12,1);
                  }
                }
              }
            }
          }
          iVar12 = FUN_004f0e60(iVar7);
          *local_484 = *local_484 - iVar12;
          if ((param_5 != 0) && (local_480[1] != 0)) {
            for (piVar13 = *(int **)(*(int *)(DAT_029130e4 + 0x20) + 0x10 + iVar9);
                (piVar13 != (int *)0x0 && (*piVar13 != 0)); piVar13 = piVar13 + 0x13) {
              uVar1 = piVar13[1];
              if ((uVar1 & 0x8000) == 0) {
                if (param_2 == 0) {
                  if ((uVar1 & 1) == 0) goto LAB_0062daa2;
                  goto LAB_0062dc8e;
                }
                if ((uVar1 & 1) == 0) goto LAB_0062dc8e;
LAB_0062daa2:
                if (((uVar1 & 4) != 0) &&
                   (*(int *)(*(int *)(puVar11 + 6) + (short)piVar13[2] * 4) == 0)) {
                  if ((DAT_029130f0 == (code *)0x0) ||
                     (iVar9 = (*DAT_029130f0)(s_chars_commonanims__0080fb98,DAT_029130f4,piVar13,
                                              local_404), iVar9 == 0)) {
                    FUN_004f1f10(local_404,local_444);
                    FUN_004f1e80(local_404,*piVar13);
                  }
                  FUN_004f1e80(local_404,&local_45c);
                  iVar9 = FUN_004f9de0(iVar7,local_404);
                  if ((iVar9 != 0) &&
                     (iVar9 = FUN_004f0f30(iVar7,iVar9,&piStack_470,&uStack_460), iVar9 != 0)) {
                    bVar2 = piStack_470[1] < 0x414e4935;
                    piVar10 = piStack_470;
                    if (!bVar2) {
                      piVar10 = piStack_470 + 1;
                    }
                    if (*(char *)((int)piVar10 + 0x12) == '\0') {
                      if (bVar2) {
                        FUN_005f3140(uStack_460,&piStack_470);
                      }
                      else {
                        FUN_004f4f40(piStack_470);
                      }
                      *(undefined1 *)((int)piVar10 + 0x12) = 1;
                    }
                    *(int **)(*(int *)(puVar11 + 6) + (short)piVar13[2] * 4) = piVar10;
                    *(int **)(*(int *)(puVar11 + 4) + (short)piVar13[2] * 4) = piVar13;
                    iVar7 = local_47c;
                  }
                }
                if ((*(byte *)(piVar13 + 1) & 8) != 0) {
                  if (*(int *)(*(int *)(puVar11 + 8) + (short)piVar13[2] * 4) == 0) {
                    if ((DAT_029130f0 == (code *)0x0) ||
                       (iVar9 = (*DAT_029130f0)(s_chars_commonanims__0080fb98,DAT_029130f4,piVar13,
                                                local_404), iVar9 == 0)) {
                      FUN_004f1f10(local_404,local_444);
                      FUN_004f1e80(local_404,*piVar13);
                    }
                    FUN_004f1e80(local_404,&local_450);
                    iVar9 = FUN_004f9de0(iVar7,local_404);
                    if ((iVar9 != 0) &&
                       (iVar9 = FUN_004f0f30(iVar7,iVar9,&uStack_464,&uStack_468), iVar9 != 0)) {
                      uVar6 = FUN_0062d360(local_404,param_2,uStack_464,uStack_468);
                      *(undefined4 *)(*(int *)(puVar11 + 8) + (short)piVar13[2] * 4) = uVar6;
                      if (*(int *)(*(int *)(puVar11 + 8) + (short)piVar13[2] * 4) != 0) {
                        *(int **)(*(int *)(puVar11 + 4) + (short)piVar13[2] * 4) = piVar13;
                      }
                    }
                  }
                  goto LAB_0062dc8e;
                }
              }
              else {
LAB_0062dc8e:
                if (((*(byte *)(piVar13 + 1) & 8) != 0) &&
                   (*(int *)(*(int *)(puVar11 + 8) + (short)piVar13[2] * 4) == 0)) {
                  FUN_004f1f10(local_404,local_444);
                  FUN_004f1e80(local_404,*piVar13);
                  FUN_004f1e80(local_404,&DAT_0075eb10);
                  uVar6 = FUN_0062d400(local_404,param_2,local_484,param_4);
                  *(undefined4 *)(*(int *)(puVar11 + 8) + (short)piVar13[2] * 4) = uVar6;
                  if (*(int *)(*(int *)(puVar11 + 8) + (short)piVar13[2] * 4) != 0) {
                    *(int **)(*(int *)(puVar11 + 4) + (short)piVar13[2] * 4) = piVar13;
                  }
                }
              }
            }
          }
        }
        else {
joined_r0x0062dd2f:
          for (; (piVar13 != (int *)0x0 && (*piVar13 != 0)); piVar13 = piVar13 + 0x13) {
            uVar1 = piVar13[1];
            if ((uVar1 & 0x8000) == 0) {
              if (param_2 == 0) {
                if ((uVar1 & 1) == 0) goto LAB_0062dd6f;
              }
              else if ((uVar1 & 1) != 0) {
LAB_0062dd6f:
                if (((uVar1 & 4) != 0) &&
                   (*(int *)(*(int *)(puVar11 + 6) + (short)piVar13[2] * 4) == 0)) {
                  if ((DAT_029130f0 == (code *)0x0) ||
                     (iVar7 = (*DAT_029130f0)(s_chars_commonanims__0080fb98,DAT_029130f4,piVar13,
                                              local_404), iVar7 == 0)) {
                    FUN_004f1f10(local_404,local_444);
                    FUN_004f1e80(local_404,*piVar13);
                  }
                  FUN_004f1e80(local_404,&local_45c);
                  iVar7 = thunk_FUN_004fa610(local_404);
                  if (iVar7 != 0) {
                    uVar6 = FUN_0062d400(local_404,param_2,local_484,param_4);
                    *(undefined4 *)(*(int *)(puVar11 + 6) + (short)piVar13[2] * 4) = uVar6;
                  }
                  iVar7 = (short)piVar13[2] * 4;
                  if (*(int *)(iVar7 + *(int *)(puVar11 + 6)) != 0) {
                    *(int **)(iVar7 + *(int *)(puVar11 + 4)) = piVar13;
                  }
                }
                if (((*(byte *)(piVar13 + 1) & 8) != 0) &&
                   (*(int *)(*(int *)(puVar11 + 8) + (short)piVar13[2] * 4) == 0)) {
                  FUN_004f1f10(local_404,local_444);
                  FUN_004f1e80(local_404,*piVar13);
                  FUN_004f1e80(local_404,&DAT_0075eb10);
                  uVar6 = FUN_0062d400(local_404,param_2,local_484,param_4);
                  *(undefined4 *)(*(int *)(puVar11 + 8) + (short)piVar13[2] * 4) = uVar6;
                  if (*(int *)(*(int *)(puVar11 + 8) + (short)piVar13[2] * 4) != 0) {
                    *(int **)(*(int *)(puVar11 + 4) + (short)piVar13[2] * 4) = piVar13;
                  }
                }
              }
            }
          }
        }
        iVar7 = local_478;
        if (param_4 <= *local_484) {
          FUN_0062a5e0(*local_484 - param_4 >> 10,*(undefined4 *)(local_478 + 0xc));
        }
        param_1 = local_480;
        if (local_474 != 0) {
          *puVar11 = (short)local_46c;
          if ((param_5 == 0) || (local_480[1] == 0)) {
            bVar3 = 0;
          }
          else {
            bVar3 = 1;
          }
          *(byte *)(puVar11 + 1) = *(byte *)(puVar11 + 1) ^ (*(byte *)(puVar11 + 1) ^ bVar3) & 1;
          *(undefined2 *)(*(int *)(DAT_029130e4 + 0x1c) + local_46c * 2) =
               *(undefined2 *)(DAT_029130e4 + 0x10);
          if (param_2 != 0) {
            *(int *)(DAT_029130e4 + 0xc) = *(int *)(DAT_029130e4 + 0xc) + 1;
            *(uint *)(iVar7 + 4) = *(uint *)(iVar7 + 4) | 2;
          }
          *(int *)(DAT_029130e4 + 0x10) = *(int *)(DAT_029130e4 + 0x10) + 1;
        }
      }
      local_480 = param_1 + 2;
      sVar4 = *local_480;
      param_1 = local_480;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_484);
  return;
}

