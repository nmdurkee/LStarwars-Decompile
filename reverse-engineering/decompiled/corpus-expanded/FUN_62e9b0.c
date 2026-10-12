/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62e9b0; label: FUN_0062e9b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062e9b0(int param_1,float *param_2,float param_3,float param_4,float param_5,
                 undefined4 param_6)

{
  float fVar1;
  undefined1 uVar2;
  short sVar3;
  short sVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  float fVar9;
  bool bVar10;
  float10 fVar11;
  float10 fVar12;
  
  bVar10 = 0.0 <= param_4;
  uVar2 = 0;
  bVar8 = false;
  if (!bVar10) {
    param_4 = -param_4;
  }
  if (param_1 == 0) {
    return;
  }
  if (param_2 == (float *)0x0) {
    return;
  }
  fVar9 = param_2[0xc];
  *(undefined1 *)(param_2 + 0xc) = 0;
  if (*(char *)((int)param_2 + 0x31) == '\0') {
    fVar1 = *param_2;
  }
  else {
    fVar1 = param_2[5];
  }
  param_2[1] = fVar1;
  if (param_3 == 0.0) {
    *(undefined1 *)(param_2 + 0xc) = 0x20;
    return;
  }
  if (*(short *)((int)param_2 + 0x42) != -1) goto LAB_0062edd9;
  sVar3 = *(short *)((int)param_2 + 0x3a);
  if (*(char *)((int)param_2 + 0x31) == '\0') {
    if ((sVar3 == *(short *)(param_2 + 0xe)) &&
       (((((uint)fVar9 & 0x80) == 0 || (sVar3 != *(short *)((int)param_2 + 0x36))) ||
        (*(int *)(*(int *)(param_1 + 0xc) + *(short *)((int)param_2 + 0x36) * 4) == 0)))) {
      *(short *)((int)param_2 + 0x36) = sVar3;
      *(undefined1 *)((int)param_2 + 0x31) = 0;
      goto LAB_0062edd9;
    }
  }
  else {
    if (((sVar3 != -1) && (sVar3 != *(short *)(param_2 + 0xd))) &&
       ((iVar6 = sVar3 * 4, *(int *)(iVar6 + *(int *)(param_1 + 0xc)) != 0 &&
        (*(float *)(*(int *)(iVar6 + *(int *)(param_1 + 8)) + 0x10) == 0.0)))) {
      *(short *)((int)param_2 + 0x36) = sVar3;
      if (((bVar10) || (*(int *)(iVar6 + *(int *)(param_1 + 0xc)) == 0)) ||
         ((*(byte *)(*(int *)(iVar6 + *(int *)(param_1 + 8)) + 4) & 0x80) == 0)) {
        fVar11 = (float10)1;
        *(undefined1 *)((int)param_2 + 0x3e) = 0;
      }
      else {
        *(undefined1 *)((int)param_2 + 0x3e) = 1;
        fVar11 = (float10)FUN_005ca470(*(undefined4 *)(iVar6 + *(int *)(param_1 + 0xc)));
      }
      *(byte *)(param_2 + 0xc) = *(byte *)(param_2 + 0xc) | 4;
      *param_2 = (float)fVar11;
      *(undefined1 *)((int)param_2 + 0x31) = 0;
      param_2[1] = *param_2;
      goto LAB_0062edd9;
    }
    fVar1 = param_2[2] + param_5;
    param_2[2] = fVar1;
    if (param_2[3] < fVar1 != (param_2[3] == fVar1)) {
      *(undefined1 *)((int)param_2 + 0x31) = 0;
      *param_2 = param_2[5];
      *(undefined2 *)((int)param_2 + 0x36) = *(undefined2 *)(param_2 + 0xd);
      *(undefined1 *)((int)param_2 + 0x3e) = *(undefined1 *)((int)param_2 + 0x3d);
      *(undefined1 *)(param_2 + 0xc) = 0x40;
      goto LAB_0062edd9;
    }
    if (((DAT_0080fb90 != 1) || (sVar3 == *(short *)(param_2 + 0xd))) ||
       (*(int *)(*(int *)(param_1 + 0xc) + sVar3 * 4) == 0)) goto LAB_0062edd9;
    bVar8 = true;
    if (param_2[3] * 0.5 <= fVar1) {
      *(short *)(param_2 + 0xe) = *(short *)(param_2 + 0xd);
      uVar2 = *(undefined1 *)((int)param_2 + 0x3d);
      param_2[4] = param_2[5];
    }
    else {
      uVar2 = *(undefined1 *)(param_2 + 0xf);
      *(undefined2 *)(param_2 + 0xe) = *(undefined2 *)((int)param_2 + 0x32);
    }
  }
  sVar4 = *(short *)(param_2 + 0xe);
  if ((sVar4 == -1) || (sVar3 == -1)) {
LAB_0062ed71:
    *(short *)((int)param_2 + 0x36) = sVar3;
    if (((bVar10) || (iVar6 = sVar3 * 4, *(int *)(iVar6 + *(int *)(param_1 + 0xc)) == 0)) ||
       ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + iVar6) + 4) & 0x80) == 0)) {
      fVar11 = (float10)1;
      *(undefined1 *)((int)param_2 + 0x3e) = 0;
    }
    else {
      *(undefined1 *)((int)param_2 + 0x3e) = 1;
      fVar11 = (float10)FUN_005ca470(*(undefined4 *)(iVar6 + *(int *)(param_1 + 0xc)));
    }
    *param_2 = (float)fVar11;
    *(undefined1 *)((int)param_2 + 0x31) = 0;
    param_2[1] = *param_2;
  }
  else {
    iVar6 = sVar4 * 4;
    if (((*(int *)(iVar6 + *(int *)(param_1 + 0xc)) == 0) ||
        ((iVar7 = sVar3 * 4, *(int *)(*(int *)(param_1 + 0xc) + iVar7) == 0 ||
         (*(float *)(*(int *)(iVar6 + *(int *)(param_1 + 8)) + 0x14) <= param_5)))) ||
       (*(float *)(*(int *)(*(int *)(param_1 + 8) + iVar7) + 0x10) <= param_5)) goto LAB_0062ed71;
    *(undefined1 *)((int)param_2 + 0x31) = 1;
    *(short *)((int)param_2 + 0x32) = sVar4;
    *(undefined1 *)(param_2 + 0xf) = uVar2;
    *(short *)(param_2 + 0xd) = sVar3;
    if (!bVar8) {
      param_2[4] = *param_2;
    }
    *(undefined1 *)(param_2 + 0xf) = *(undefined1 *)((int)param_2 + 0x3e);
    if ((((*(byte *)(*(int *)(iVar6 + *(int *)(param_1 + 8)) + 4) & 2) == 0) ||
        ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + iVar7) + 4) & 2) == 0)) ||
       (*(float *)(*(int *)(*(int *)(param_1 + 8) + iVar7) + 0x18) !=
        *(float *)(*(int *)(*(int *)(param_1 + 8) + iVar6) + 0x18))) {
LAB_0062ecd4:
      if (((bVar10) ||
          (iVar6 = *(short *)(param_2 + 0xd) * 4, *(int *)(iVar6 + *(int *)(param_1 + 0xc)) == 0))
         || ((*(byte *)(*(int *)(iVar6 + *(int *)(param_1 + 8)) + 4) & 0x80) == 0)) {
        param_2[5] = 1.0;
LAB_0062ed15:
        *(undefined1 *)((int)param_2 + 0x3d) = 0;
      }
      else {
        *(undefined1 *)((int)param_2 + 0x3d) = 1;
        fVar11 = (float10)FUN_005ca470(*(undefined4 *)(iVar6 + *(int *)(param_1 + 0xc)));
        param_2[5] = (float)fVar11;
      }
    }
    else {
      fVar11 = (float10)FUN_005ca470(*(undefined4 *)(iVar6 + *(int *)(param_1 + 0xc)));
      fVar12 = (float10)FUN_005ca470(*(undefined4 *)
                                      (*(int *)(param_1 + 0xc) + *(short *)(param_2 + 0xd) * 4));
      if (fVar12 != (float10)(double)fVar11) goto LAB_0062ecd4;
      param_2[5] = param_2[4];
      if (((bVar10) || (*(int *)(*(short *)(param_2 + 0xd) * 4 + *(int *)(param_1 + 0xc)) == 0)) ||
         ((*(byte *)(*(int *)(*(short *)(param_2 + 0xd) * 4 + *(int *)(param_1 + 8)) + 4) & 0x80) ==
          0)) goto LAB_0062ed15;
      *(undefined1 *)((int)param_2 + 0x3d) = 1;
    }
    param_2[2] = 0.0;
    fVar1 = *(float *)(*(int *)(*(int *)(param_1 + 8) + *(short *)(param_2 + 0xd) * 4) + 0x10);
    param_2[3] = fVar1;
    iVar6 = *(short *)((int)param_2 + 0x32) * 4;
    if (*(float *)(*(int *)(iVar6 + *(int *)(param_1 + 8)) + 0x14) < fVar1) {
      fVar1 = *(float *)(*(int *)(iVar6 + *(int *)(param_1 + 8)) + 0x14);
      *(byte *)(param_2 + 0xc) = *(byte *)(param_2 + 0xc) | 4;
      param_2[3] = fVar1;
      goto LAB_0062edd9;
    }
  }
  *(byte *)(param_2 + 0xc) = *(byte *)(param_2 + 0xc) | 4;
LAB_0062edd9:
  bVar10 = !bVar10;
  if (*(short *)((int)param_2 + 0x42) == -1) {
    if (*(char *)((int)param_2 + 0x31) == '\0') {
      if ((*(short *)((int)param_2 + 0x36) != -1) &&
         (*(int *)(*(int *)(param_1 + 0xc) + *(short *)((int)param_2 + 0x36) * 4) != 0)) {
        if (((uint)fVar9 & 0x10) != 0) {
          param_3 = 0.0;
        }
        fVar11 = (float10)FUN_0062e760(param_2,*param_2,param_3,param_4,1,(int)param_2 + 0x3e,bVar10
                                       ,param_6);
        *param_2 = (float)fVar11;
        return;
      }
      uVar5 = *(undefined2 *)((int)param_2 + 0x3a);
      FUN_0062e650(param_2,0xffffffff);
      *(undefined2 *)((int)param_2 + 0x3a) = uVar5;
    }
    else if ((*(int *)(*(int *)(param_1 + 0xc) + *(short *)((int)param_2 + 0x32) * 4) != 0) &&
            (*(int *)(*(int *)(param_1 + 0xc) + *(short *)(param_2 + 0xd) * 4) != 0)) {
      fVar11 = (float10)FUN_0062e760(param_2,param_2[4],param_3,param_4,0,param_2 + 0xf,bVar10,
                                     param_6);
      param_2[4] = (float)fVar11;
      fVar11 = (float10)FUN_0062e760(param_2,param_2[5],param_3,param_4,1,(int)param_2 + 0x3d,bVar10
                                     ,param_6);
      param_2[5] = (float)fVar11;
      return;
    }
  }
  else if ((*(int *)(*(int *)(param_1 + 0xc) + *(short *)((int)param_2 + 0x3a) * 4) != 0) &&
          (*(int *)(*(int *)(param_1 + 0xc) + *(short *)((int)param_2 + 0x42) * 4) != 0)) {
    fVar11 = (float10)FUN_0062e760(param_2,param_2[4],param_3,param_4,0,param_2 + 0xf,bVar10,param_6
                                  );
    param_2[4] = (float)fVar11;
    fVar11 = (float10)FUN_0062e760(param_2,param_2[5],param_3,param_4,1,(int)param_2 + 0x3d,bVar10,
                                   param_6);
    param_2[5] = (float)fVar11;
    return;
  }
  return;
}

