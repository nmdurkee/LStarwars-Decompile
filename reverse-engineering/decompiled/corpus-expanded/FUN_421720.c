/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x421720; label: FUN_00421720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00421720(float param_1,undefined4 param_2,float param_3)

{
  uint *puVar1;
  byte bVar2;
  float fVar3;
  char cVar4;
  uint *puVar5;
  int iVar6;
  code *pcVar7;
  uint *in_ECX;
  int iVar8;
  int iVar9;
  float *pfVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  int local_14;
  uint auStack_10 [2];
  float local_8 [2];
  
  local_14 = FUN_006d6350();
  if (local_14 < 0) {
    local_14 = 0;
  }
  in_ECX[0x3ae] = (uint)param_3;
  *(undefined1 *)((int)in_ECX + 9) = 1;
  switch(in_ECX[6]) {
  case 0:
    *(undefined1 *)((int)in_ECX + 9) = 0;
    return 0;
  case 1:
    fVar3 = (float)in_ECX[5];
    in_ECX[5] = (uint)(fVar3 + param_3);
    if (fVar3 + param_3 <= 1.0) {
      param_3 = (float)in_ECX[5];
      goto LAB_004217aa;
    }
    in_ECX[5] = 0x3f800000;
    in_ECX[6] = 2;
    in_ECX[3] = in_ECX[5];
    break;
  case 2:
    local_8[0] = param_1;
    local_8[1] = (float)param_2;
    iVar8 = FUN_006d6c20(1);
    iVar9 = 0;
    if (0 < (int)in_ECX[1]) {
      do {
        fVar3 = local_8[iVar9];
        (&DAT_00856868)[iVar9] = 0;
        if (fVar3 != 0.0) {
          bVar2 = *(byte *)((int)fVar3 + 0x93);
          uVar12 = *(uint *)((int)fVar3 + 0x70);
          auStack_10[iVar9] = uVar12;
          if (0xe0 < bVar2) {
            auStack_10[iVar9] = uVar12 | 0x4000;
          }
          if (bVar2 < 0x20) {
            auStack_10[iVar9] = auStack_10[iVar9] | 0x1000;
          }
          bVar2 = *(byte *)((int)fVar3 + 0x92);
          if (0xe0 < bVar2) {
            auStack_10[iVar9] = auStack_10[iVar9] | 0x2000;
          }
          if (bVar2 < 0x20) {
            auStack_10[iVar9] = auStack_10[iVar9] | 0x8000;
          }
          uVar12 = auStack_10[iVar9];
          if ((uVar12 == (&DAT_00856860)[iVar9]) && (uVar12 != 0)) {
            param_1 = (float)(&DAT_00856858)[iVar9] - (float)in_ECX[0x3ae];
            (&DAT_00856858)[iVar9] = param_1;
            if (param_1 < 0.0 != (param_1 == 0.0)) {
              (&DAT_00856868)[iVar9] = (&DAT_00856860)[iVar9];
              (&DAT_00856858)[iVar9] = (float)(&DAT_00856858)[iVar9] + 0.1;
            }
          }
          else {
            (&DAT_00856860)[iVar9] = uVar12;
            (&DAT_00856858)[iVar9] = 0x3f000000;
            (&DAT_00856868)[iVar9] = uVar12;
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < (int)in_ECX[1]);
    }
    param_3 = (float)iVar8;
    iVar9 = FUN_006e6b90();
    DAT_00856854 = DAT_00856854 + iVar9;
    param_1 = (float)(&DAT_029899a0)[DAT_00856854 >> 1 & 0x7fff] + 1.0;
    in_ECX[4] = (uint)(param_1 * 0.5);
    _DAT_00856850 = (&DAT_00856868)[local_14];
    iVar9 = FUN_004203c0();
    if (iVar9 == 0) goto LAB_00422295;
    puVar5 = in_ECX + in_ECX[8] * 3 + 0x29;
    switch(in_ECX[9]) {
    case 0:
      if ((char)in_ECX[2] == '\0') {
        if ((_DAT_00856850 & 0x2000) != 0) {
          uVar12 = in_ECX[0xe];
          if ((code *)in_ECX[0x3b0] != (code *)0x0) {
            (*(code *)in_ECX[0x3b0])(3);
          }
          uVar12 = uVar12 + 1;
          if ((int)in_ECX[1] <= (int)uVar12) {
            uVar12 = 0;
          }
          in_ECX[0xe] = uVar12;
          FUN_00421430();
          FUN_00420690(puVar5);
        }
        if ((_DAT_00856850 & 0x8000) != 0) {
          uVar12 = in_ECX[0xe];
          if ((code *)in_ECX[0x3b0] != (code *)0x0) {
            (*(code *)in_ECX[0x3b0])(3);
          }
          uVar12 = uVar12 - 1;
          if ((int)uVar12 < 0) {
            uVar12 = in_ECX[1] - 1;
          }
          in_ECX[0xe] = uVar12;
          FUN_00421430();
          FUN_00420690(puVar5);
        }
        if ((_DAT_00856850 & 0x4000) != 0) {
          if ((code *)in_ECX[0x3b0] != (code *)0x0) {
            (*(code *)in_ECX[0x3b0])(3);
          }
          puVar5[1] = puVar5[1] + 1;
          if ((int)*puVar5 <= (int)puVar5[1]) {
            puVar5[1] = 0;
          }
          FUN_00420690(puVar5);
        }
        if ((_DAT_00856850 & 0x1000) != 0) {
          if ((code *)in_ECX[0x3b0] != (code *)0x0) {
            (*(code *)in_ECX[0x3b0])(3);
          }
          uVar12 = puVar5[2];
          do {
            puVar1 = puVar5 + 1;
            *puVar1 = *puVar1 - 1;
            if ((int)*puVar1 < 0) {
              puVar5[1] = *puVar5 - 1;
            }
          } while ((((in_ECX[0xe] == 0) && ((*(byte *)(uVar12 + 3 + puVar5[1] * 8) & 0x20) != 0)) ||
                   ((in_ECX[0xe] == 1 && ((*(byte *)(uVar12 + 3 + puVar5[1] * 8) & 0x40) != 0)))) ||
                  ((*(byte *)(uVar12 + 3 + puVar5[1] * 8) & 0x80) != 0));
        }
      }
      if (((_DAT_00856850 & 0x20) == 0) && (param_3 == 0.0)) {
        if ((_DAT_00856850 & 0x40) != 0) {
          uVar12 = puVar5[1];
          cVar4 = *(char *)(puVar5[2] + uVar12 * 8);
          if (cVar4 == '\0') {
            iVar8 = FUN_00420640(puVar5,uVar12,in_ECX[0xe]);
            pcVar7 = (code *)in_ECX[0x3b0];
            if (iVar8 == 0) {
LAB_004221fa:
              if (pcVar7 != (code *)0x0) {
                (*pcVar7)(6);
              }
            }
            else {
              if (pcVar7 != (code *)0x0) {
                (*pcVar7)(2);
              }
              in_ECX[0xb] = 3;
              in_ECX[10] = 3;
              FUN_006d5db0();
              in_ECX[9] = 1;
            }
          }
          else if (cVar4 == '\x02') {
            iVar8 = FUN_00420640(puVar5,uVar12,in_ECX[0xe]);
            pcVar7 = (code *)in_ECX[0x3b0];
            if (iVar8 == 0) {
              if (pcVar7 != (code *)0x0) {
                (*pcVar7)(6);
              }
            }
            else {
              if (pcVar7 != (code *)0x0) {
                (*pcVar7)(2);
              }
              in_ECX[0xb] = 3;
              in_ECX[10] = 3;
              FUN_006d5db0();
              iVar8 = FUN_006d67a0(in_ECX[in_ECX[0xe] + 0xf]);
              if (iVar8 == 0) {
                in_ECX[in_ECX[0xe] + 0x22] = in_ECX[in_ECX[0xe] + 0x1e];
                in_ECX[9] = 3;
              }
              else {
                in_ECX[9] = 4;
                in_ECX[0x27] = in_ECX[0x26];
              }
            }
          }
          else if (cVar4 == '\x04') {
            if ((code *)in_ECX[0x3b0] != (code *)0x0) {
              (*(code *)in_ECX[0x3b0])(2);
            }
            switch(*(undefined1 *)(puVar5[2] + 2 + puVar5[1] * 8)) {
            case 0:
              if (in_ECX[in_ECX[0xe] + 0xf] == 0xffffffff) {
                if ((code *)in_ECX[0x3b0] != (code *)0x0) {
                  (*(code *)in_ECX[0x3b0])(1);
                }
                in_ECX[6] = 3;
              }
              cVar4 = FUN_00420570();
              *(char *)(in_ECX + 0x1c) = cVar4;
              pcVar7 = (code *)in_ECX[0x3b0];
              if (cVar4 != '\0') goto LAB_004221fa;
              *in_ECX = 3;
              in_ECX[6] = 3;
              if (pcVar7 != (code *)0x0) {
                (*pcVar7)(1);
              }
              break;
            case 1:
              goto switchD_00421fb8_caseD_1;
            case 3:
              in_ECX[0xb] = 3;
              in_ECX[10] = 3;
              FUN_006d5db0();
              in_ECX[9] = 2;
              break;
            case 0x28:
              uVar12 = in_ECX[0xe];
              iVar8 = 0;
              do {
                iVar9 = FUN_006d6920(1,in_ECX[in_ECX[0xe] + 0xf],uVar12);
                if (iVar9 != 0) {
                  uVar12 = in_ECX[0xe];
                  FUN_006d6840(iVar9,in_ECX[uVar12 + 0xf],uVar12,1,uVar12);
                  FUN_006d9650(in_ECX[0xe],in_ECX[1]);
                  iVar8 = FUN_006d9370(in_ECX[in_ECX[0xe] + 0xf]);
                  in_ECX[in_ECX[0xe] + 0x1e] = (uint)(float)iVar8;
                  break;
                }
                uVar12 = uVar12 + 1;
                if (uVar12 == 2) {
                  uVar12 = 0;
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 < 2);
              break;
            case 0x2b:
              iVar8 = FUN_006d6710();
              if ((-1 < iVar8) && (iVar9 = FUN_006d67c0(in_ECX[iVar8 + 0xf]), iVar9 != 0)) {
                in_ECX[iVar8 + 0xf] = in_ECX[iVar8 + 0xf] + 1;
                FUN_006d95b0(in_ECX[iVar8 + 0xf],iVar8,iVar8);
              }
              iVar9 = iVar8 + 1;
              if (iVar9 < (int)in_ECX[1]) {
                iVar6 = FUN_006d67a0(in_ECX[iVar8 + 0x10]);
                if (iVar6 == 0) {
                  iVar9 = iVar8 + 2;
                  if (iVar9 < (int)in_ECX[1]) {
                    iVar8 = FUN_006d67a0(in_ECX[iVar8 + 0x11]);
                    if (iVar8 != 0) goto LAB_0042202b;
                  }
                  else {
                    iVar9 = -1;
                  }
                }
                else {
LAB_0042202b:
                  iVar8 = FUN_006d67c0(in_ECX[iVar9 + 0xf]);
                  if (iVar8 == 0) {
                    in_ECX[iVar9 + 0xf] = in_ECX[iVar9 + 0xf] - 1;
                  }
                  FUN_006d95b0(in_ECX[iVar9 + 0xf],iVar9,iVar9);
                }
              }
              else {
                iVar9 = -1;
              }
              FUN_006d66f0(iVar9);
              FUN_00421430();
            }
          }
        }
      }
      else {
switchD_00421fb8_caseD_1:
        if ((code *)in_ECX[0x3b0] != (code *)0x0) {
          (*(code *)in_ECX[0x3b0])(0);
        }
        in_ECX[6] = 3;
        *in_ECX = 2;
      }
      break;
    case 1:
      if (iVar8 == 0) {
        uVar13 = FUN_006d9120(0,0x13,&param_1,&param_3,1);
        uVar12 = FUN_006d9510(uVar13,in_ECX[0xe]);
        if ((-1 < (int)uVar12) && (uVar12 == in_ECX[in_ECX[0xe] + 0xf])) {
          iVar8 = FUN_006d95f0(in_ECX[0xe],in_ECX[1],param_1,param_3);
          if (iVar8 != 0) {
            FUN_006d9210(*(undefined1 *)(puVar5[2] + 1 + puVar5[1] * 8),uVar12,param_1,param_3,1,1,
                         in_ECX[0xe],0);
            FUN_006d9650(in_ECX[0xe],in_ECX[1]);
            FUN_006d94f0(in_ECX[0xe],in_ECX[1]);
          }
          in_ECX[9] = 0;
          in_ECX[0xb] = 3;
          in_ECX[10] = 3;
          FUN_006d5db0();
          cVar4 = FUN_00420570();
          if (cVar4 == '\0') {
            *(undefined1 *)(in_ECX + 0x1c) = 0;
          }
        }
      }
      else {
LAB_00421a0c:
        if ((code *)in_ECX[0x3b0] != (code *)0x0) {
          (*(code *)in_ECX[0x3b0])(0);
        }
        in_ECX[9] = 0;
        in_ECX[0xb] = 3;
        in_ECX[10] = 3;
        FUN_006d5db0();
      }
      break;
    case 2:
      if (iVar8 != 0) goto LAB_00421a0c;
      uVar13 = FUN_006d9120(0,0x1a,&param_2,&param_1,1);
      uVar12 = FUN_006d9510(uVar13,in_ECX[0xe]);
      if (-1 < (int)uVar12) {
        in_ECX[0xb] = 3;
        in_ECX[10] = 3;
        FUN_006d5db0();
        cVar4 = FUN_004204e0(in_ECX[0xe],uVar12,1);
        pcVar7 = (code *)in_ECX[0x3b0];
        if (cVar4 == '\0') goto LAB_004221fa;
        if (pcVar7 != (code *)0x0) {
          (*pcVar7)(2);
        }
        in_ECX[in_ECX[0xe] + 0xf] = uVar12;
        FUN_006d95b0(uVar12,in_ECX[0xe],in_ECX[0xe]);
        iVar8 = FUN_006d67a0(uVar12);
        if (iVar8 != 0) {
          FUN_006d9650(in_ECX[0xe],in_ECX[1]);
        }
        in_ECX[9] = 0;
        cVar4 = FUN_00420570();
        if (cVar4 == '\0') {
          *(undefined1 *)(in_ECX + 0x1c) = 0;
        }
        param_3 = (float)FUN_006d9370(uVar12);
        in_ECX[in_ECX[0xe] + 0x1e] = (uint)(float)(int)param_3;
        iVar8 = FUN_006d67a0(uVar12);
        if (iVar8 != 0) {
          param_3 = (float)FUN_006d93a0(uVar12);
          in_ECX[0x26] = (uint)(float)(int)param_3;
        }
        FUN_00421430();
      }
      break;
    case 3:
      if ((_DAT_00856850 & 0x3000) != 0) {
        in_ECX[in_ECX[0xe] + 0x1e] = (uint)((float)in_ECX[in_ECX[0xe] + 0x1e] + 5.0);
        if ((float)in_ECX[in_ECX[0xe] + 0x1e] <= 100.0) {
          pcVar7 = (code *)in_ECX[0x3b0];
          if (pcVar7 != (code *)0x0) {
            uVar13 = 4;
            goto LAB_00421d5c;
          }
        }
        else {
          in_ECX[in_ECX[0xe] + 0x1e] = 0x42c80000;
          pcVar7 = (code *)in_ECX[0x3b0];
          if (pcVar7 != (code *)0x0) {
            uVar13 = 6;
LAB_00421d5c:
            (*pcVar7)(uVar13);
          }
        }
      }
      if ((_DAT_00856850 & 0xc000) != 0) {
        in_ECX[in_ECX[0xe] + 0x1e] = (uint)((float)in_ECX[in_ECX[0xe] + 0x1e] - 5.0);
        if (16.0 <= (float)in_ECX[in_ECX[0xe] + 0x1e]) {
          pcVar7 = (code *)in_ECX[0x3b0];
          if (pcVar7 != (code *)0x0) {
            uVar13 = 4;
            goto LAB_00421db4;
          }
        }
        else {
          in_ECX[in_ECX[0xe] + 0x1e] = 0x41800000;
          pcVar7 = (code *)in_ECX[0x3b0];
          if (pcVar7 != (code *)0x0) {
            uVar13 = 6;
LAB_00421db4:
            (*pcVar7)(uVar13);
          }
        }
      }
      if ((iVar8 != 0) || ((_DAT_00856850 & 0x20) != 0)) {
        if ((code *)in_ECX[0x3b0] != (code *)0x0) {
          (*(code *)in_ECX[0x3b0])(0);
        }
        in_ECX[in_ECX[0xe] + 0x1e] = in_ECX[in_ECX[0xe] + 0x22];
        in_ECX[9] = 0;
        in_ECX[0xb] = 3;
        in_ECX[10] = 3;
        FUN_006d5db0();
      }
      if ((_DAT_00856850 & 0x40) != 0) {
        if ((code *)in_ECX[0x3b0] != (code *)0x0) {
          (*(code *)in_ECX[0x3b0])(1);
        }
        in_ECX[9] = 0;
        in_ECX[0xb] = 3;
        in_ECX[10] = 3;
        FUN_006d5db0();
      }
      break;
    case 4:
      if ((_DAT_00856850 & 0x3000) != 0) {
        param_1 = (float)in_ECX[0x26] + 1.0;
        in_ECX[0x26] = (uint)param_1;
        pcVar7 = (code *)in_ECX[0x3b0];
        if (param_1 <= 10.0) {
          if (pcVar7 != (code *)0x0) {
            uVar13 = 5;
            goto LAB_00421c44;
          }
        }
        else {
          in_ECX[0x26] = 0x41200000;
          if (pcVar7 != (code *)0x0) {
            uVar13 = 6;
LAB_00421c44:
            (*pcVar7)(uVar13);
          }
        }
      }
      if ((_DAT_00856850 & 0xc000) != 0) {
        param_1 = (float)in_ECX[0x26] - 1.0;
        in_ECX[0x26] = (uint)param_1;
        pcVar7 = (code *)in_ECX[0x3b0];
        if (1.0 <= param_1) {
          if (pcVar7 != (code *)0x0) {
            uVar13 = 5;
            goto LAB_00421c98;
          }
        }
        else {
          in_ECX[0x26] = 0x3f800000;
          if (pcVar7 != (code *)0x0) {
            uVar13 = 6;
LAB_00421c98:
            (*pcVar7)(uVar13);
          }
        }
      }
      if (iVar8 != 0) {
        if ((code *)in_ECX[0x3b0] != (code *)0x0) {
          (*(code *)in_ECX[0x3b0])(0);
        }
        in_ECX[9] = 0;
        in_ECX[0x26] = in_ECX[0x27];
        in_ECX[0xb] = 3;
        in_ECX[10] = 3;
        FUN_006d5db0();
      }
      if ((_DAT_00856850 & 0x40) != 0) {
        if ((code *)in_ECX[0x3b0] != (code *)0x0) {
          (*(code *)in_ECX[0x3b0])(1);
        }
        in_ECX[9] = 0;
        in_ECX[0xb] = 3;
        in_ECX[10] = 3;
        FUN_006d5db0();
      }
    }
    break;
  case 3:
    param_3 = (float)in_ECX[5] - param_3;
    in_ECX[5] = (uint)param_3;
    if (param_3 < 0.0) {
      FUN_006d6320(0);
      in_ECX[5] = 0;
      in_ECX[6] = 0;
      *(undefined1 *)((int)in_ECX + 9) = 0;
      if (0 < (int)in_ECX[1]) {
        puVar5 = in_ECX + 0x17;
        iVar8 = 0;
        do {
          *puVar5 = puVar5[-8];
          iVar8 = iVar8 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar8 < (int)in_ECX[1]);
      }
      if (*in_ECX == 3) {
        uVar12 = FUN_00420330();
        if (in_ECX[0x1b] != uVar12) {
          FUN_00420450();
        }
        iVar8 = 0;
        if (0 < (int)in_ECX[1]) {
          puVar5 = in_ECX + 0xf;
          do {
            if (-1 < (int)puVar5[4]) {
              FUN_004f47f0(iVar8,*puVar5);
            }
            iVar8 = iVar8 + 1;
            puVar5 = puVar5 + 1;
          } while (iVar8 < (int)in_ECX[1]);
        }
      }
      return *in_ECX;
    }
LAB_004217aa:
    in_ECX[3] = (uint)param_3;
    break;
  case 4:
    in_ECX[6] = 3;
    return 4;
  }
  uVar12 = 0;
  if (0 < (int)in_ECX[7]) {
    puVar5 = in_ECX + 0x29;
    do {
      uVar11 = 0;
      if (0 < (int)*puVar5) {
        pfVar10 = (float *)(puVar5[2] + 4);
        do {
          if ((uVar12 == in_ECX[8]) && (uVar11 == puVar5[1])) {
            fVar3 = (float)in_ECX[0x3ae] * 8.0 + *pfVar10;
            *pfVar10 = fVar3;
            if (1.0 < fVar3) {
              *pfVar10 = 1.0;
            }
          }
          else if ((0.0 < *pfVar10) &&
                  (fVar3 = *pfVar10 - (float)in_ECX[0x3ae] * 8.0, *pfVar10 = fVar3, fVar3 < 0.0)) {
            *pfVar10 = 0.0;
          }
          uVar11 = uVar11 + 1;
          pfVar10 = pfVar10 + 2;
        } while ((int)uVar11 < (int)*puVar5);
      }
      uVar12 = uVar12 + 1;
      puVar5 = puVar5 + 3;
    } while ((int)uVar12 < (int)in_ECX[7]);
  }
LAB_00422295:
  return (uint)*(byte *)((int)in_ECX + 9);
}

