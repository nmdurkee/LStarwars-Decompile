/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4df120; label: FUN_004df120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004df120(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined *puVar7;
  int iVar8;
  int *piVar9;
  undefined *puVar10;
  float10 fVar11;
  float10 extraout_ST0;
  undefined8 uVar12;
  undefined *local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar2 = FUN_0058a900(DAT_009553d4);
  uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
  if ((iVar2 != 0) || (uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0), DAT_00951b50 != 0))
  goto LAB_004df9a4;
  iVar2 = 0;
  puVar7 = &DAT_007fff6c;
  local_10 = &DAT_00888ee0;
  do {
    if (DAT_0093b2a4 == 0) {
LAB_004df1c9:
      if (*(int *)((int)&DAT_00888f70 + iVar2) != 0) goto LAB_004df1d6;
    }
    else {
      if (*(int *)((int)&DAT_00888f70 + iVar2) == 0) {
        iVar8 = 4;
        puVar10 = local_10;
        do {
          iVar3 = FUN_005cfd60(puVar10);
          if (iVar3 != 0) {
            uVar4 = FUN_005cf9e0(puVar10);
            uVar4 = FUN_0043d890((int)**(short **)((int)&PTR_DAT_007fff9c + iVar2),uVar4,0,"Party",0
                                 ,0,1,0,0,0,0);
            *(undefined4 *)((int)&DAT_00888f70 + iVar2) = uVar4;
          }
          puVar10 = puVar10 + 0xc;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        goto LAB_004df1c9;
      }
LAB_004df1d6:
      if (*(float *)(*(int *)((int)&DAT_00888f88 + iVar2) + 0x28) == 1.0) {
        iVar8 = 4;
        puVar10 = local_10;
        do {
          iVar3 = FUN_005cfd60(puVar10);
          if (iVar3 != 0) {
            puVar5 = (undefined4 *)FUN_005cf9e0(puVar10);
            iVar3 = *(int *)((int)&DAT_00888f70 + iVar2);
            *(undefined4 *)(iVar3 + 0x5c) = *puVar5;
            *(undefined4 *)(iVar3 + 0x60) = puVar5[1];
            *(undefined4 *)(iVar3 + 100) = puVar5[2];
            iVar3 = *(int *)((int)&DAT_00888f70 + iVar2) + 0x5c;
            FUN_005b37d0(iVar3,iVar3,puVar7);
            iVar3 = *(int *)((int)&DAT_00888f70 + iVar2);
            *(undefined4 *)(iVar3 + 0x10bc) = *(undefined4 *)(iVar3 + 0x5c);
            *(undefined4 *)(iVar3 + 0x10c0) = *(undefined4 *)(iVar3 + 0x60);
            *(undefined4 *)(iVar3 + 0x10c4) = *(undefined4 *)(iVar3 + 100);
            *(undefined2 *)(*(int *)((int)&DAT_00888f70 + iVar2) + 0x27a) =
                 *(undefined2 *)((int)&DAT_007fff90 + iVar2);
            *(undefined4 *)(*(int *)((int)&DAT_00888f70 + iVar2) + 0x68) = 0;
            *(undefined4 *)(*(int *)((int)&DAT_00888f70 + iVar2) + 0x6c) = 0;
            *(undefined4 *)(*(int *)((int)&DAT_00888f70 + iVar2) + 0x70) = 0;
            *(undefined4 *)(*(int *)((int)&DAT_00888f70 + iVar2) + 0x1d8) = 0;
          }
          puVar10 = puVar10 + 0xc;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    }
    local_10 = local_10 + 0x30;
    iVar2 = iVar2 + 4;
    puVar7 = puVar7 + 0xc;
  } while ((int)local_10 < 0x888f70);
  DAT_00888fb0 = 0;
  DAT_00888fb4 = 0;
  uVar12 = 0;
  if (4.0 <= _DAT_00888ed8) {
    if (DAT_00888ed4 == 7) {
      if (DAT_00888fa8 != 0) {
        uVar12 = __allshl();
      }
    }
    else {
      fVar11 = (float10)_DAT_007fff54 * (float10)_DAT_007fff54;
      if (fVar11 < (float10)(float)DAT_0093d810[0x20] * (float10)(float)DAT_0093d810[0x20] +
                   (float10)(float)DAT_0093d810[0x22] * (float10)(float)DAT_0093d810[0x22]) {
        uVar12 = __allshl();
        fVar11 = extraout_ST0;
      }
      if ((DAT_0093d814 != (int *)0x0) &&
         (fVar11 < (float10)(float)DAT_0093d814[0x20] * (float10)(float)DAT_0093d814[0x20] +
                   (float10)(float)DAT_0093d814[0x22] * (float10)(float)DAT_0093d814[0x22]))
      goto LAB_004df325;
    }
  }
  else {
    if (DAT_0093d810 != (int *)0x0) {
      uVar12 = __allshl();
    }
    if (DAT_0093d814 != (int *)0x0) {
LAB_004df325:
      DAT_00888fb4 = (uint)((ulonglong)uVar12 >> 0x20);
      DAT_00888fb0 = (uint)uVar12;
      uVar12 = __allshl();
      DAT_00888fb0 = DAT_00888fb0 | (uint)uVar12;
      DAT_00888fb4 = DAT_00888fb4 | (uint)((ulonglong)uVar12 >> 0x20);
      uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
    }
  }
  piVar9 = &DAT_0093d7f4;
  do {
    DAT_00888fb4 = (uint)((ulonglong)uVar12 >> 0x20);
    DAT_00888fb0 = (uint)uVar12;
    iVar2 = piVar9[-1];
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0xeb8) = 0;
      *(undefined4 *)(iVar2 + 0xebc) = 0;
      iVar2 = piVar9[-1];
      uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
      if ((((*(byte *)(iVar2 + 0x1fc) & 0x80) == 0) &&
          (uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0), DAT_00888fa8 != 0)) &&
         (uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0), DAT_00888ed4 == 7)) {
        uVar12 = __allshl();
        *(uint *)(iVar2 + 0xeb8) = *(uint *)(iVar2 + 0xeb8) | (uint)uVar12;
        *(uint *)(iVar2 + 0xebc) = *(uint *)(iVar2 + 0xebc) | (uint)((ulonglong)uVar12 >> 0x20);
        uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
      }
    }
    DAT_00888fb4 = (uint)((ulonglong)uVar12 >> 0x20);
    DAT_00888fb0 = (uint)uVar12;
    iVar2 = *piVar9;
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0xeb8) = 0;
      *(undefined4 *)(iVar2 + 0xebc) = 0;
      iVar2 = *piVar9;
      uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
      if ((((*(byte *)(iVar2 + 0x1fc) & 0x80) == 0) &&
          (uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0), DAT_00888fa8 != 0)) &&
         (uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0), DAT_00888ed4 == 7)) {
        uVar12 = __allshl();
        *(uint *)(iVar2 + 0xeb8) = *(uint *)(iVar2 + 0xeb8) | (uint)uVar12;
        *(uint *)(iVar2 + 0xebc) = *(uint *)(iVar2 + 0xebc) | (uint)((ulonglong)uVar12 >> 0x20);
        uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
      }
    }
    DAT_00888fb4 = (uint)((ulonglong)uVar12 >> 0x20);
    DAT_00888fb0 = (uint)uVar12;
    iVar2 = piVar9[1];
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0xeb8) = 0;
      *(undefined4 *)(iVar2 + 0xebc) = 0;
      iVar2 = piVar9[1];
      uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
      if ((((*(byte *)(iVar2 + 0x1fc) & 0x80) == 0) &&
          (uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0), DAT_00888fa8 != 0)) &&
         (uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0), DAT_00888ed4 == 7)) {
        uVar12 = __allshl();
        *(uint *)(iVar2 + 0xeb8) = *(uint *)(iVar2 + 0xeb8) | (uint)uVar12;
        *(uint *)(iVar2 + 0xebc) = *(uint *)(iVar2 + 0xebc) | (uint)((ulonglong)uVar12 >> 0x20);
        uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
      }
    }
    DAT_00888fb4 = (uint)((ulonglong)uVar12 >> 0x20);
    DAT_00888fb0 = (uint)uVar12;
    iVar2 = piVar9[2];
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0xeb8) = 0;
      *(undefined4 *)(iVar2 + 0xebc) = 0;
      iVar2 = piVar9[2];
      uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
      if ((((*(byte *)(iVar2 + 0x1fc) & 0x80) == 0) &&
          (uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0), DAT_00888fa8 != 0)) &&
         (uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0), DAT_00888ed4 == 7)) {
        uVar12 = __allshl();
        *(uint *)(iVar2 + 0xeb8) = *(uint *)(iVar2 + 0xeb8) | (uint)uVar12;
        *(uint *)(iVar2 + 0xebc) = *(uint *)(iVar2 + 0xebc) | (uint)((ulonglong)uVar12 >> 0x20);
        uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
      }
    }
    DAT_00888fb4 = (uint)((ulonglong)uVar12 >> 0x20);
    DAT_00888fb0 = (uint)uVar12;
    piVar9 = piVar9 + 4;
  } while ((int)piVar9 < 0x93d814);
  if (DAT_00888ed6 == 0) {
    FUN_004dead0(param_1);
    uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
  }
  else if (DAT_00888ed6 == 1) {
    FUN_004def30();
    uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
  }
  else if (DAT_00888ed6 == 2) {
    FUN_004df0c0();
    uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
  }
  _DAT_008894b0 = 0;
  local_10 = (undefined *)0x0;
  if (0 < DAT_00888ed0) {
    piVar9 = &DAT_00882be4;
    do {
      DAT_00888fb4 = (uint)((ulonglong)uVar12 >> 0x20);
      DAT_00888fb0 = (uint)uVar12;
      iVar2 = *piVar9;
      if (iVar2 == 0) {
        if ((*(byte *)(piVar9 + 0x12) & 0x10) == 0) {
          iVar2 = FUN_0054fd90(piVar9 + -5,&DAT_009250e8,&DAT_009250f4,0,0x3fc00000,0);
          if (iVar2 == 0) {
            iVar2 = FUN_0054fd90(piVar9 + -5,&DAT_00925100,&DAT_0092510c,0,0x3fc00000,0);
            uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
            if (iVar2 == 0) goto LAB_004df821;
          }
        }
        else {
LAB_004df821:
          DAT_00888fb4 = (uint)((ulonglong)uVar12 >> 0x20);
          DAT_00888fb0 = (uint)uVar12;
          if ((*(byte *)(piVar9 + 0x12) & 1) == 0) {
LAB_004df89b:
            local_c = piVar9[-5];
            local_8 = piVar9[-4];
            local_4 = piVar9[-3];
          }
          else {
            piVar6 = piVar9 + -5;
            iVar2 = FUN_0054fd90(piVar6,&DAT_009250e8,&DAT_009250f4,0,0x3f000000,0);
            uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
            if (iVar2 != 0) goto LAB_004df89b;
            iVar2 = FUN_0054fd90(piVar6,&DAT_00925100,&DAT_0092510c,0,0x3f000000,0);
            uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
            if (iVar2 != 0) goto LAB_004df89b;
            local_c = *piVar6;
            local_8 = piVar9[-4];
            local_4 = piVar9[-3];
            FUN_005b3620(&local_c,&local_c,0x8000);
            uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
          }
          DAT_00888fb4 = (uint)((ulonglong)uVar12 >> 0x20);
          DAT_00888fb0 = (uint)uVar12;
          if (piVar9[-1] == -1) {
            FUN_004de2a0();
            uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
          }
          DAT_00888fb4 = (uint)((ulonglong)uVar12 >> 0x20);
          DAT_00888fb0 = (uint)uVar12;
          iVar2 = FUN_0043d890(piVar9[-1],&local_c,piVar9[-2],"gen_bdroids",piVar9 + 10,0,1,0,0,0,0)
          ;
          *piVar9 = iVar2;
          if (iVar2 != 0) {
            *(int **)(iVar2 + 0x36c) = piVar9 + 2;
            *(code **)(*piVar9 + 0xea8) = FUN_004de9d0;
            if (piVar9[-1] == (int)DAT_007f19dc) {
              if (piVar9[0x11] == 0) {
                piVar9[0x11] = *(int *)(*piVar9 + 0x1048);
                if ((*(uint *)(*piVar9 + 0xef0) & 0x200) == 0) {
                  piVar9[0x12] = piVar9[0x12] & 0xfffffffb;
                }
                else {
                  piVar9[0x12] = piVar9[0x12] | 4;
                }
              }
              else {
                *(int *)(*piVar9 + 0x1048) = piVar9[0x11];
                if ((*(byte *)(piVar9 + 0x12) & 4) == 0) {
                  puVar1 = (uint *)(*piVar9 + 0xef0);
                  *puVar1 = *puVar1 & 0xfffffdff;
                }
                else {
                  puVar1 = (uint *)(*piVar9 + 0xef0);
                  *puVar1 = *puVar1 | 0x200;
                }
              }
            }
          }
        }
LAB_004df958:
        iVar2 = *piVar9;
        if ((iVar2 != 0) &&
           (_DAT_008894b0 = _DAT_008894b0 + 1, (*(byte *)(piVar9 + 0x12) & 0x10) == 0)) {
          *(uint *)(iVar2 + 0xeb8) = *(uint *)(iVar2 + 0xeb8) | DAT_00888fb0;
          *(uint *)(iVar2 + 0xebc) = *(uint *)(iVar2 + 0xebc) | DAT_00888fb4;
        }
      }
      else {
        if ((*(byte *)(piVar9 + 0x12) & 0x10) != 0) {
          *(undefined4 *)(iVar2 + 0x36c) = 0;
          if ((((*(uint *)(DAT_0093d810[0x15] + 4) & 0x80000) == 0) &&
              ((*(short *)(*DAT_0093d810 + 0x1064) != DAT_007f19c4 ||
               ((*(byte *)(DAT_0093d810 + 0x7f) & 0x80) != 0)))) &&
             ((piVar6 = DAT_0093d810,
              *(char *)(*(int *)(DAT_0093d810[0x15] + 0x24) + 0x116) != '\x04' ||
              (*(char *)(*(int *)(*(int *)(*piVar9 + 0x54) + 0x24) + 0x116) != '\x04')))) {
LAB_004df69b:
            if (piVar6 != (int *)0x0) {
              *(int **)(*piVar9 + 0x3ac) = piVar6;
            }
          }
          else {
            if (*(int **)(*piVar9 + 0x3ac) == DAT_0093d810) {
              *(undefined4 *)(*piVar9 + 0x3ac) = 0;
            }
            if (DAT_0093d814 != (int *)0x0) {
              if ((((*(uint *)(DAT_0093d814[0x15] + 4) & 0x80000) == 0) &&
                  ((*(short *)(*DAT_0093d810 + 0x1064) != DAT_007f19c4 ||
                   ((*(byte *)(DAT_0093d810 + 0x7f) & 0x80) != 0)))) &&
                 ((piVar6 = DAT_0093d814,
                  *(char *)(*(int *)(DAT_0093d810[0x15] + 0x24) + 0x116) != '\x04' ||
                  (*(char *)(*(int *)(*(int *)(*piVar9 + 0x54) + 0x24) + 0x116) != '\x04'))))
              goto LAB_004df69b;
              if (*(int **)(*piVar9 + 0x3ac) == DAT_0093d814) {
                *(undefined4 *)(*piVar9 + 0x3ac) = 0;
              }
            }
          }
          goto LAB_004df958;
        }
        iVar2 = FUN_0054fd90(iVar2 + 0x5c,&DAT_009250e8,&DAT_009250f4,0,0x40000000,0);
        if ((iVar2 == 0) &&
           (iVar2 = FUN_0054fd90(*piVar9 + 0x5c,&DAT_00925100,&DAT_0092510c,0,0x40000000,0),
           iVar2 == 0)) {
LAB_004df790:
          if (*piVar9 != 0) {
            iVar2 = *(int *)(*piVar9 + 4);
            if (((*(int *)(iVar2 + 0xe4) == 0) && (piVar9[1] != 0)) &&
               (iVar8 = *(int *)(piVar9[1] + 0x14), iVar8 != 0)) {
              *(int *)(iVar2 + 0xe4) = iVar8;
            }
            goto LAB_004df958;
          }
        }
        else {
          iVar2 = FUN_0054fd90(piVar9 + 6,&DAT_009250e8,&DAT_009250f4,0,0x40000000,0);
          if ((iVar2 == 0) &&
             (iVar2 = FUN_0054fd90(piVar9 + 6,&DAT_00925100,&DAT_0092510c,0,0x40000000,0),
             iVar2 == 0)) goto LAB_004df790;
          iVar2 = *piVar9;
          piVar9[-5] = *(int *)(iVar2 + 0x5c);
          piVar9[-4] = *(int *)(iVar2 + 0x60);
          piVar9[-3] = *(int *)(iVar2 + 100);
          piVar9[-2] = (uint)*(ushort *)(iVar2 + 0x27a);
          FUN_0055cad0(iVar2,1);
          *piVar9 = 0;
        }
      }
      uVar12 = CONCAT44(DAT_00888fb4,DAT_00888fb0);
      local_10 = (undefined *)((int)local_10 + 1);
      piVar9 = piVar9 + 0x18;
    } while ((int)local_10 < (int)DAT_00888ed0);
  }
LAB_004df9a4:
  DAT_00888fb4 = (uint)((ulonglong)uVar12 >> 0x20);
  DAT_00888fb0 = (uint)uVar12;
  return;
}

