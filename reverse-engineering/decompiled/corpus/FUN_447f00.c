/* Ghidra analysis pseudocode, not original source.
 * ev_f48dedfde503d95163bfd3eb2ed6449a9a2f0083b079fa518a64f4b7b72b2f93
 * Entry: 0x447f00; label: FUN_00447f00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00447f00(undefined4 param_1,int param_2,float param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  uint *puVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  float fVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  int iVar12;
  float10 fVar13;
  undefined8 uVar14;
  undefined4 uVar15;
  float fVar16;
  float local_18;
  undefined1 local_c [12];
  
  iVar9 = (int)param_3;
  iVar12 = 0;
  bVar6 = false;
  if (((param_3 == 0.0) || (piVar3 = *(int **)((int)param_3 + 0xd0), piVar3 == (int *)0x0)) ||
     (*piVar3 == 0)) {
    return 1;
  }
  iVar4 = *piVar3;
  DAT_00876cd0 = 1;
  if (param_6 != 0) {
    *(undefined4 *)(param_2 + 0x74) = _DAT_007f6828;
    *(undefined4 *)((int)param_3 + 0x180) = _DAT_007f6824;
    fVar13 = (float10)FUN_005b9dd0();
    local_18 = (float)fVar13;
    if (0 < param_5) {
      do {
        iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar12 * 4),"firerange");
        if (iVar7 == 0) {
          iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar12 * 4),"goalrange");
          if (iVar7 == 0) {
            iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar12 * 4),"minrange=");
            if (iVar7 == 0) {
              iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar12 * 4),"static");
              if (iVar7 == 0) {
                iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar12 * 4),"offscreen");
                if (iVar7 == 0) {
                  iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar12 * 4),"no_fire_in_minicut");
                  if (iVar7 == 0) {
                    iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar12 * 4),"circle");
                    if (iVar7 == 0) {
                      iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar12 * 4),"fireinterval");
                      if (iVar7 == 0) {
                        iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar12 * 4),"opponent=");
                        if (iVar7 == 0) {
                          iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar12 * 4),"instant");
                          if (iVar7 == 0) {
                            iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar12 * 4),
                                                 "attack_override");
                            if (iVar7 != 0) {
                              iVar7 = iVar7 + 0x10;
                              iVar8 = FUN_004f8b10(iVar7,"PUNCH_1");
                              if (iVar8 == 0) {
                                *(undefined2 *)(param_2 + 0x6a) = 1;
                              }
                              else {
                                iVar8 = FUN_004f8b10(iVar7,"PUNCH_2");
                                if (iVar8 == 0) {
                                  *(undefined2 *)(param_2 + 0x6a) = 2;
                                }
                                else {
                                  iVar8 = FUN_004f8b10(iVar7,"PUNCH_3");
                                  if (iVar8 == 0) {
                                    *(undefined2 *)(param_2 + 0x6a) = 3;
                                  }
                                  else {
                                    iVar8 = FUN_004f8b10(iVar7,"PUNCH_BEHIND");
                                    if (iVar8 == 0) {
                                      *(undefined2 *)(param_2 + 0x6a) = 4;
                                    }
                                    else {
                                      iVar8 = FUN_004f8b10(iVar7,"PUNCH_SPECIAL");
                                      if (iVar8 == 0) {
                                        *(undefined2 *)(param_2 + 0x6a) = 5;
                                      }
                                      else {
                                        iVar8 = FUN_004f8b10(iVar7,"BLOCK");
                                        if (iVar8 == 0) {
                                          *(undefined2 *)(param_2 + 0x6a) = 6;
                                        }
                                        else {
                                          iVar7 = FUN_004f8b10(iVar7,"SHOOT");
                                          *(ushort *)(param_2 + 0x6a) =
                                               (-(ushort)(iVar7 != 0) & 0xfff9) + 7;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                          else {
                            local_18 = 0.0;
                          }
                        }
                        else {
                          uVar15 = FUN_00440120(param_1,iVar7 + 9);
                          *(undefined4 *)(param_2 + 0x6c) = uVar15;
                        }
                      }
                      else {
                        fVar13 = (float10)FUN_005147c0(param_2,iVar7 + 0xd);
                        *(float *)(param_2 + 0x74) = (float)fVar13;
                      }
                    }
                    else {
                      *(uint *)((int)param_3 + 0x1e8) = *(uint *)((int)param_3 + 0x1e8) ^ 0x200;
                      *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 8;
                    }
                  }
                  else {
                    *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 4;
                  }
                }
                else {
                  *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 1;
                }
              }
              else {
                *(undefined4 *)((int)param_3 + 0x180) = 0;
              }
            }
            else {
              fVar13 = (float10)FUN_005147c0(param_2,iVar7 + 9);
              *(float *)((int)param_3 + 0x180) = (float)fVar13;
              *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 2;
            }
          }
          else {
            fVar13 = (float10)FUN_005147c0(param_2,iVar7 + 10);
            *(float *)((int)param_3 + 0x180) = (float)fVar13;
          }
        }
        else {
          fVar13 = (float10)FUN_005147c0(param_2,iVar7 + 10);
          *(float *)(param_2 + 0x70) = (float)fVar13;
          bVar6 = true;
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < param_5);
    }
    if (DAT_00876584 != 0) {
      *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 0x20;
    }
    *(float *)(param_2 + 0x9c) = *(float *)(param_2 + 0x74) * local_18;
    if (!bVar6) {
      if (*(float *)((int)param_3 + 0x180) == 0.0) {
        fVar2 = 9999.9;
      }
      else {
        fVar2 = *(float *)((int)param_3 + 0x180) + _DAT_007f682c;
      }
      *(float *)(param_2 + 0x70) = fVar2;
    }
  }
  iVar12 = *(int *)(param_2 + 0x6c);
  iVar7 = 0;
  if ((iVar12 != 0) &&
     ((((*(uint *)(iVar12 + 0x1fc) & 1) == 0 || ((*(uint *)(iVar12 + 0x1fc) & 0x1000) == 0)) ||
      ((iVar7 = iVar12, *(char *)(iVar12 + 0x28b) != '\0' && (*(float *)(iVar12 + 0x1010) <= 0.0))))
     )) {
    iVar7 = 0;
  }
  if (*(short *)(param_2 + 0x6a) != 0) {
    *(undefined1 *)(iVar4 + 0x1085) = *(undefined1 *)(param_2 + 0x6a);
  }
  if (iVar7 == 0) {
    piVar3 = *(int **)((int)param_3 + 0xe4);
    if (piVar3 == (int *)0x0) {
      return 0;
    }
    if (piVar3[1] == 0) {
      return 0;
    }
    iVar7 = *piVar3;
    if (iVar7 == 0) {
      return 0;
    }
  }
  *(uint *)(iVar4 + 0xeec) = *(uint *)(iVar4 + 0xeec) | 0x20;
  uVar11 = *(uint *)(iVar7 + 0x1fc);
  if ((uVar11 & 1) == 0) {
    return 0;
  }
  if ((uVar11 & 0x1000) == 0) {
    return 0;
  }
  if (*(char *)(iVar7 + 0x28b) != '\0') {
    return 0;
  }
  if (*(char *)(iVar7 + 0x7b5) == '+') {
    return 0;
  }
  if (((char)uVar11 < '\0') && (1.5 < *(float *)(iVar7 + 0x1000))) {
    return 0;
  }
  fVar13 = (float10)FUN_005b3c50(iVar7 + 0x5c,*(int *)((int)param_3 + 0xd0) + 0x5c,local_c);
  fVar2 = (float)fVar13;
  if ((*(uint *)(iVar4 + 0xef4) & 0x2000) != 0) {
    iVar12 = FUN_0043d410(iVar4,**(undefined4 **)(iVar4 + 0x3ac));
    if (iVar12 != 0) {
      *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) & 0xfd;
      goto LAB_0044836d;
    }
    fVar13 = (float10)FUN_0043d450(iVar4);
    *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 2;
LAB_0044840d:
    fVar16 = (float)fVar13;
    if (fVar16 != 0.0) goto LAB_0044837b;
    uVar11 = *(uint *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x90) & 0x100;
LAB_004486da:
    if (uVar11 == 0) {
      *(int *)(iVar9 + 0x1e4) = iVar7 + 0x5c;
    }
    goto LAB_004486e7;
  }
  if ((*(float *)((int)param_3 + 0x180) == 0.0) ||
     ((((*(byte *)(iVar7 + 0x1fc) & 0x80) == 0 || (*(char *)(iVar4 + 0x288) != '\0')) &&
      (uVar11 = (uint)*(byte *)(*(int *)((int)param_3 + 0xd0) + 0x28d), uVar14 = __allshl(),
      ((uint)uVar14 & *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 + uVar11 * 8)) != 0 ||
      ((uint)((ulonglong)uVar14 >> 0x20) &
      *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc + uVar11 * 8)) != 0)))) {
    fVar13 = (float10)*(float *)((int)param_3 + 0x180);
    goto LAB_0044840d;
  }
LAB_0044836d:
  fVar16 = 0.1;
LAB_0044837b:
  param_3 = fVar16;
  if (*(float *)(iVar7 + 1000) <= fVar16) {
    param_3 = *(float *)(iVar7 + 1000);
  }
  if ((((*(byte *)(iVar4 + 0xef2) & 1) == 0) &&
      (*(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) & 0xef,
      (*(byte *)(iVar4 + 0xef2) & 1) == 0)) ||
     ((*(uint *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x90) & 0x100) == 0)) {
    uVar11 = *(uint *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x90) & 0x100;
    if ((uVar11 != 0) && (fVar2 < (fVar16 - _DAT_007f682c) * (fVar16 - _DAT_007f682c))) {
      FUN_0052fcb0(iVar9,iVar7 + 0x438,param_3,iVar7 + 0x420,2,fVar16);
      *(undefined1 *)(iVar9 + 0x13f) = 1;
      if ((*(uint *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x90) & 0x100) != 0) {
        *(uint *)(iVar4 + 0xef0) = *(uint *)(iVar4 + 0xef0) | 0x8000;
      }
      goto LAB_004486e7;
    }
    bVar10 = *(byte *)(param_2 + 0x68);
    if (((bVar10 & 0x20) != 0) && (fVar2 < (fVar16 - _DAT_007f682c) * (fVar16 - _DAT_007f682c))) {
      FUN_0052fcb0(iVar9,iVar7 + 0x438,param_3,iVar7 + 0x420,2,fVar16);
      *(undefined1 *)(iVar9 + 0x13f) = 1;
      goto LAB_004486e7;
    }
    if (DAT_007f39e4 == 0) {
      fVar5 = (_DAT_007f682c + fVar16) * (_DAT_007f682c + fVar16);
      if ((fVar5 <= fVar2 / 10.0 + fVar2) || ((bVar10 & 2) == 0)) {
        if (fVar2 <= fVar5) goto LAB_004486b2;
        goto LAB_00448508;
      }
      fVar16 = _DAT_007f682c + *(float *)(iVar9 + 0x180);
      uVar15 = 2;
    }
    else if ((fVar2 <= (fVar16 + _DAT_007f682c) * (fVar16 + _DAT_007f682c)) || ((bVar10 & 2) != 0))
    {
LAB_004486b2:
      if ((bVar10 & 8) == 0) goto LAB_004486da;
      uVar15 = 3;
    }
    else {
      uVar15 = 1;
    }
  }
  else {
    bVar10 = *(byte *)(param_2 + 0x68);
    if ((bVar10 & 0x10) == 0) {
      if (fVar2 < (fVar16 - _DAT_007f682c) * (fVar16 - _DAT_007f682c)) {
        bVar10 = bVar10 | 0x10;
        goto LAB_004484b7;
      }
    }
    else if ((_DAT_007f682c + fVar16) * (_DAT_007f682c + fVar16) < fVar2) {
      bVar10 = bVar10 & 0xef;
LAB_004484b7:
      *(byte *)(param_2 + 0x68) = bVar10;
    }
    if ((*(byte *)(param_2 + 0x68) & 0x10) != 0) {
      FUN_0052fcb0(iVar9,iVar7 + 0x438,param_3,iVar7 + 0x420,2,fVar16);
      *(undefined1 *)(iVar9 + 0x13f) = 1;
      *(uint *)(iVar4 + 0xef0) = *(uint *)(iVar4 + 0xef0) | 0x8000;
      goto LAB_004486e7;
    }
    fVar16 = 0.01;
    param_3 = 0.0;
LAB_00448508:
    uVar15 = 1;
  }
  FUN_0052fcb0(iVar9,iVar7 + 0x438,param_3,iVar7 + 0x420,uVar15,fVar16);
  *(undefined1 *)(iVar9 + 0x13f) = 0;
LAB_004486e7:
  bVar10 = *(byte *)(iVar4 + 0x28d);
  uVar14 = __allshl();
  if ((((((uint)uVar14 & *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 + (uint)bVar10 * 8)) != 0
         || ((uint)((ulonglong)uVar14 >> 0x20) &
            *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc + (uint)bVar10 * 8)) != 0) &&
       ((uVar11 = *(uint *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x90) & 0x100, uVar11 == 0 ||
        ((*(byte *)(iVar4 + 0xef2) & 1) == 0)))) &&
      ((*(char *)(iVar4 + 0x288) != '\0' || ((*(byte *)(param_2 + 0x68) & 1) != 0)))) &&
     (fVar2 < *(float *)(param_2 + 0x70) * *(float *)(param_2 + 0x70))) {
    if (uVar11 == 0) {
      *(int *)(iVar9 + 0x1e4) = iVar7 + 0x5c;
    }
    if ((DAT_00855de0 == 0) || ((*(byte *)(param_2 + 0x68) & 4) == 0)) {
      fVar13 = (float10)*(float *)(param_2 + 0x9c) - (float10)param_7;
    }
    else {
      fVar13 = (float10)FUN_005b9dd0();
      fVar13 = fVar13 * (float10)*(float *)(param_2 + 0x74) + (float10)2.0;
    }
    *(float *)(param_2 + 0x9c) = (float)fVar13;
    if ((*(char *)(iVar7 + 0x28b) == '\0') &&
       (*(int *)(iVar4 + 0xea0) = iVar7, *(float *)(param_2 + 0x9c) <= 0.0)) {
      fVar13 = (float10)FUN_005b9dd0();
      *(float *)(param_2 + 0x9c) =
           (float)((float10)*(float *)(param_2 + 0x74) * (float10)0.5 +
                  fVar13 * (float10)*(float *)(param_2 + 0x74));
      iVar9 = FUN_00440150(iVar4,iVar7);
      if ((iVar9 == 0) && (iVar9 = FUN_0043d410(iVar4,iVar7), iVar9 != 0)) {
        puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
        *puVar1 = *puVar1 | DAT_0080227c;
      }
    }
  }
  return 0;
}

