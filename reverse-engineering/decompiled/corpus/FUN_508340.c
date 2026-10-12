/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x508340; label: FUN_00508340
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00508340(float param_1,int param_2,int param_3,float param_4)

{
  byte *pbVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar6 = (int)param_1;
  uVar7 = DAT_00921350 << 0x13;
  *(uint *)((int)param_1 + 0x8c) = *(uint *)((int)param_1 + 0x8c) & 0xffffefff;
  piVar3 = *(int **)((int)param_1 + 0x58);
  *(uint *)((int)param_1 + 0x88) =
       *(uint *)((int)param_1 + 0x88) ^ (uVar7 ^ *(uint *)((int)param_1 + 0x88)) & 0x7f80000;
  if ((*(uint *)((int)param_1 + 0x88) & 0x800) != 0) {
    return;
  }
  if ((*(byte *)(piVar3 + 0xe) & 8) != 0) {
    return;
  }
  *(float *)((int)param_1 + 0xe4) = param_4;
  if ((((((DAT_009213bc != (code *)0x0) && ((*(byte *)(piVar3 + 0xe) & 4) != 0)) &&
        ((*(uint *)((int)param_1 + 0x8c) & 0x20) != 0)) &&
       ((iVar8 = FUN_005d6170(), iVar8 != 0 &&
        (*(float *)(iVar8 + 0x30) < *(float *)((int)param_1 + 0x78))))) &&
      ((*(float *)((int)param_1 + 0x6c) < *(float *)(iVar8 + 0x30) &&
       ((*(float *)(iVar8 + 0x34) < *(float *)((int)param_1 + 0x7c) &&
        (*(float *)((int)param_1 + 0x70) < *(float *)(iVar8 + 0x34))))))) &&
     ((*(float *)(iVar8 + 0x38) < *(float *)((int)param_1 + 0x80) &&
      (*(float *)((int)param_1 + 0x74) < *(float *)(iVar8 + 0x38))))) {
    (*DAT_009213bc)(param_1);
  }
  *(uint *)((int)param_1 + 0x88) = *(uint *)((int)param_1 + 0x88) & 0xbfffffff;
  if ((*(short *)((int)param_1 + 0xd8) != 0) && ((*(uint *)((int)param_1 + 0x88) & 1) == 0)) {
    uVar7 = *(uint *)((int)param_1 + 0x8c);
    iVar8 = (int)(uVar7 << 0x1c) >> 0x1c;
    if (iVar8 != 0) {
      *(uint *)((int)param_1 + 0x8c) = (iVar8 - 1U ^ uVar7) & 0xf ^ uVar7;
      *(uint *)((int)param_1 + 0x88) = *(uint *)((int)param_1 + 0x88) | 0x40000000;
      param_2 = 1;
    }
  }
  uVar7 = *(uint *)((int)param_1 + 0x88);
  if ((uVar7 & 2) == 0) {
    if ((uVar7 & 1) != 0) {
      return;
    }
    if ((uVar7 & 0x40) == 0) {
      return;
    }
    FUN_00505f20(param_1);
  }
  if (((*(byte *)(piVar3 + 0xe) & 8) != 0) && ((*(uint *)((int)param_1 + 0x88) & 0x8000000) == 0)) {
    return;
  }
  if (1 < **(int **)((int)param_1 + 0x58)) {
    if (((((*(uint *)((int)param_1 + 0x88) & 0x20000000) == 0) || (DAT_00921378 != 0)) ||
        ((*(uint *)((int)param_1 + 0x88) & 0x8000000) != 0)) ||
       (*(char *)((int)param_1 + 0xdf) == *(char *)(*(int *)((int)param_1 + 0x5c) + 0x40))) {
      if (((*(int *)((int)param_1 + 0xf4) != 0) && (DAT_00921378 == 0)) &&
         (*(char *)((int)param_1 + 0xdf) == *(char *)(*(int *)((int)param_1 + 0x5c) + 0x40))) {
        DAT_00921378 = *(int *)((int)param_1 + 0xf4);
        *(undefined4 *)((int)param_1 + 0xf4) = 0;
      }
    }
    else {
      DAT_00921378 = (int)param_1;
    }
  }
  FUN_00500570();
  if ((*(uint *)((int)param_1 + 0x88) & 0x400) == 0) {
    return;
  }
  if ((*(uint *)((int)param_1 + 0x88) & 4) != 0) {
    param_2 = 1;
  }
  if (((DAT_00921380 == 0) && ((*(byte *)((int)param_1 + 0x8c) & 0x10) == 0)) ||
     ((*piVar3 < 2 || ((*(byte *)(piVar3 + 0xe) & 1) == 0)))) {
    if ((*(byte *)((int)param_1 + 0x8c) & 0x10) != 0) {
      if (param_3 == 0) goto LAB_005085a0;
      *(float *)((int)param_1 + 0x90) =
           ((float)piVar3[2] - 1.0) - *(float *)((int)param_1 + 0x98) * param_4;
      _DAT_00921374 = 1;
    }
  }
  else if (param_3 == 0) {
LAB_005085a0:
    _DAT_00921370 = 1;
  }
  else {
    *(uint *)((int)param_1 + 0x8c) = *(uint *)((int)param_1 + 0x8c) | 0x400;
  }
  if ((*(uint *)((int)param_1 + 0x8c) & 0x200) != 0) {
    DAT_0092137c = 1;
  }
  if ((*(uint *)((int)param_1 + 0x88) & 1) == 0) {
    if (param_2 == 0) {
      *(uint *)((int)param_1 + 0x88) = *(uint *)((int)param_1 + 0x88) | 1;
    }
  }
  else if (param_2 == 0) {
    *(float *)((int)param_1 + 0x90) =
         *(float *)((int)param_1 + 0x90) + param_4 * *(float *)((int)param_1 + 0x98);
    if ((*(uint *)((int)param_1 + 0x8c) & 0x400) != 0) {
      FUN_00506710(param_4);
    }
    if (1.0 <= *(float *)((int)param_1 + 0x90)) {
      fVar2 = (float)piVar3[2] - 1.0;
      if (*(float *)((int)param_1 + 0x90) < fVar2) goto LAB_00508a92;
      piVar4 = *(int **)((int)param_1 + 0x58);
      if ((1 < *piVar4) && ((*(byte *)(piVar4 + 0xe) & 1) != 0)) {
        pbVar1 = (byte *)((int)param_1 + 0xdf);
        if (*pbVar1 < *(byte *)(*(int *)((int)param_1 + 0x5c) + 0x40)) {
          if ((*(uint *)((int)param_1 + 0x88) & 0x8000000) == 0) {
            FUN_00500a70();
          }
          else {
            param_1 = *(float *)((int)param_1 + 0x90) - ((float)piVar4[2] - 1.0);
            if ((float)piVar4[2] < param_1) {
              param_1 = 0.0;
            }
            *(byte *)(iVar6 + 0xdf) = *pbVar1 + 1;
            *(float *)(iVar6 + 0xe0) = *(float *)(iVar6 + 0xe0) + (float)piVar4[2];
            if ((*(byte *)(iVar6 + 0x8c) & 0x80) == 0) {
              if (*(int *)(iVar6 + 0xec) == 0) {
                uVar7 = *(uint *)(iVar6 + 0x88);
                if ((uVar7 & 0x10000000) == 0) {
                  *(uint *)(iVar6 + 0x88) = uVar7 | 0x10000000;
                  *(undefined4 *)(iVar6 + 0xec) = *(undefined4 *)(iVar6 + 0xbc);
                  FUN_004fff20(*(undefined4 *)(*(int *)(iVar6 + 0x58) + 0x2c));
                }
                else {
                  *(uint *)(iVar6 + 0x88) = uVar7 & 0xefffffff;
                  *(undefined4 *)(iVar6 + 0xec) = *(undefined4 *)(iVar6 + 0xc0);
                  FUN_004fff20(*(undefined4 *)(*(int *)(iVar6 + 0x58) + 0x2c));
                }
                if (DAT_00800890 < 2) {
                  FUN_00500830(*(undefined4 *)(iVar6 + 0x58),
                               *(undefined4 *)
                                (iVar6 + 0xbc + (*(int *)(iVar6 + 0x88) * 8 >> 0x1f & 1U) * 4));
                }
                else {
                  FUN_00500600(iVar6);
                }
                *(uint *)(iVar6 + 0x88) = *(uint *)(iVar6 + 0x88) & 0xf7ffffff;
                FUN_00505f20(iVar6);
                *(uint *)(iVar6 + 0x88) = *(uint *)(iVar6 + 0x88) | 1;
                *(float *)(iVar6 + 0x90) = param_1 + *(float *)(iVar6 + 0x90);
                goto LAB_00508a92;
              }
              iVar8 = *(int *)(*(int *)(iVar6 + 0x58) + 0x2c);
            }
            else {
              iVar8 = piVar4[0xb];
            }
            FUN_004fff20(iVar8);
            FUN_00500a70();
            *(char *)(iVar6 + 0xdf) = *(char *)(iVar6 + 0xdf) + -1;
          }
        }
        else if ((*(byte *)((int)param_1 + 0x8c) & 0x40) == 0) {
          FUN_005060e0(param_1);
          *(undefined4 *)((int)param_1 + 0xe0) = 0;
        }
        else {
          *(uint *)((int)param_1 + 0x88) = *(uint *)((int)param_1 + 0x88) | 0x1000;
          *(float *)((int)param_1 + 0x90) = fVar2;
        }
        goto LAB_00508a92;
      }
      if ((*(uint *)((int)param_1 + 0x88) & 0x10) != 0) {
        *(float *)((int)param_1 + 0x90) =
             ((float)piVar3[2] - 1.0) - (*(float *)((int)param_1 + 0x90) - ((float)piVar3[2] - 1.0))
        ;
        if (0.0 < *(float *)((int)param_1 + 0x98)) {
          *(float *)((int)param_1 + 0x98) = -*(float *)((int)param_1 + 0x98);
        }
        goto LAB_00508a92;
      }
      if ((*(byte *)((int)param_1 + 0x8c) & 0x40) != 0) {
        *(float *)((int)param_1 + 0x90) = fVar2;
        *(uint *)((int)param_1 + 0x88) = *(uint *)((int)param_1 + 0x88) | 0x1000;
        goto LAB_00508a92;
      }
      pcVar5 = *(code **)((int)param_1 + 0xb4);
      if (pcVar5 != (code *)0x0) {
        *(undefined4 *)((int)param_1 + 0xb4) = 0;
        (*pcVar5)(param_1);
      }
      uVar7 = *(uint *)((int)param_1 + 0x88);
      if ((int)((uVar7 & 0xffffe000) << 0xe) < 1) {
        if (*(int *)((int)param_1 + 0xb0) != 0) {
          param_1 = *(float *)((int)param_1 + 0x90) - ((float)piVar3[2] - 1.0);
          if ((float)piVar3[2] < param_1) {
            param_1 = 0.0;
          }
          FUN_005060e0(iVar6);
          goto LAB_005089ca;
        }
        if ((uVar7 & 8) == 0) {
          FUN_005060e0(param_1);
          goto LAB_00508a92;
        }
      }
      else {
        *(uint *)((int)param_1 + 0x88) =
             (((int)((uVar7 & 0xffffe000) << 0xe) >> 0xe) - 1U ^ uVar7) & 0x3e000 ^ uVar7;
      }
      param_1 = *(float *)((int)param_1 + 0x90) - ((float)piVar3[2] - 1.0);
      if ((float)piVar3[2] < param_1) {
        param_1 = 0.0;
      }
    }
    else {
      uVar7 = *(uint *)((int)param_1 + 0x88);
      if ((uVar7 & 0x10) == 0) {
        if ((uVar7 & 0x20) == 0) {
          FUN_005061e0(param_1);
        }
        else {
          *(undefined4 *)((int)param_1 + 0x90) = 0x3f800000;
        }
        goto LAB_00508a92;
      }
      if ((uVar7 & 8) != 0) {
        if (*(float *)((int)param_1 + 0x98) < 0.0) {
          *(float *)((int)param_1 + 0x98) = -*(float *)((int)param_1 + 0x98);
        }
        *(float *)((int)param_1 + 0x90) = 2.0 - *(float *)((int)param_1 + 0x90);
        goto LAB_00508a92;
      }
      if ((int)((uVar7 & 0xffffe000) << 0xe) < 1) {
        if (*(int *)((int)param_1 + 0xb0) == 0) {
          FUN_005061e0(param_1);
          return;
        }
        fVar2 = *(float *)((int)param_1 + 0x90);
        FUN_005061e0(param_1);
        param_1 = 1.0 - fVar2;
LAB_005089ca:
        FUN_00505f20(*(undefined4 *)(iVar6 + 0xb0));
        *(float *)(*(int *)(iVar6 + 0xb0) + 0x90) =
             *(float *)(*(int *)(iVar6 + 0xb0) + 0x90) + param_1;
        FUN_00500570();
        FUN_00508340(*(undefined4 *)(iVar6 + 0xb0),0,param_3,param_4);
        *(undefined4 *)(iVar6 + 0xb0) = 0;
        return;
      }
      *(uint *)((int)param_1 + 0x88) =
           (((int)((uVar7 & 0xffffe000) << 0xe) >> 0xe) - 1U ^ uVar7) & 0x3e000 ^ uVar7;
      param_1 = 1.0 - *(float *)((int)param_1 + 0x90);
    }
    FUN_00505f20(iVar6);
    *(uint *)(iVar6 + 0x88) = *(uint *)(iVar6 + 0x88) | 1;
    *(float *)(iVar6 + 0x90) = param_1 + *(float *)(iVar6 + 0x90);
  }
LAB_00508a92:
  if ((*(uint *)(iVar6 + 0x88) & 2) != 0) {
    fVar2 = *(float *)(iVar6 + 0x90);
    *(float *)(iVar6 + 0x94) = fVar2;
    if ((*(uint *)(iVar6 + 0x88) & 0x40000) == 0) {
      if ((DAT_0080089c != 0) && (*(int *)(iVar6 + 0xa4) != 0)) {
        FUN_00502bb0(iVar6,fVar2,param_2);
      }
      if ((DAT_00800894 != 0) && (*(int *)(iVar6 + 0x9c) != 0)) {
        FUN_00506880(iVar6,*(undefined4 *)(iVar6 + 0x90));
      }
      if (*(int *)(iVar6 + 0xac) != 0) {
        FUN_00503770(*(undefined4 *)(iVar6 + 0x94));
      }
      if ((DAT_00800898 != 0) && (*(int *)(iVar6 + 0xa0) != 0)) {
        FUN_00507d80(iVar6,*(undefined4 *)(iVar6 + 0x94),param_2);
      }
    }
    else {
      if ((DAT_0080089c != 0) && (*(int *)(iVar6 + 0xa4) != 0)) {
        FUN_00502bb0(iVar6,(float)piVar3[2] - fVar2,param_2);
      }
      if ((DAT_00800894 != 0) && (*(int *)(iVar6 + 0x9c) != 0)) {
        FUN_00506880(iVar6,(float)piVar3[2] - *(float *)(iVar6 + 0x90));
      }
      if (*(int *)(iVar6 + 0xac) != 0) {
        FUN_00503770((float)piVar3[2] - *(float *)(iVar6 + 0x94));
      }
      if ((DAT_00800898 != 0) && (*(int *)(iVar6 + 0xa0) != 0)) {
        FUN_00507d80(iVar6,(float)piVar3[2] - *(float *)(iVar6 + 0x94),param_2);
        return;
      }
    }
  }
  return;
}

