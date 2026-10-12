/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x4827a0; label: FUN_004827a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004827a0(undefined4 param_1,float param_2)

{
  char cVar1;
  float fVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  float10 fVar8;
  uint local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c [3];
  
  iVar5 = (int)param_2;
  cVar1 = *(char *)((int)param_2 + 0x7b5);
  if (cVar1 != '[') {
    if ((((*(char *)((int)param_2 + 0x281) == '\0') && (*(float *)((int)param_2 + 0x6c) <= 0.0)) &&
        (((cVar1 == -1 || (cVar1 == 'C')) ||
         ((cVar1 == '\0' && (0.1 <= *(float *)((int)param_2 + 0x77c))))))) &&
       (((*(byte *)((int)param_2 + 0x1fc) & 0x80) != 0 ||
        ((*(uint *)((int)param_2 + 0xef4) & 0x8000) != 0)))) {
      local_34 = *(float *)((int)param_2 + 0x1dc) * 3.0;
      local_30 = *(float *)((int)param_2 + 0x80) - local_34;
      local_3c = *(float *)((int)param_2 + 0x80) + local_34;
      local_2c = *(float *)((int)param_2 + 0x84);
      local_38 = *(float *)((int)param_2 + 0x194);
      local_28 = *(float *)((int)param_2 + 0x88) - local_34;
      local_34 = local_34 + *(float *)((int)param_2 + 0x88);
      local_24 = (local_3c + local_30) * 0.5;
      local_20 = (local_38 + local_2c) * 0.5;
      local_1c = (local_34 + local_28) * 0.5;
      iVar5 = FUN_00482310(param_1,&local_24,&local_30,&local_3c,&local_40);
      if (iVar5 != 0) {
        *(undefined1 *)((int)param_2 + 0x7b5) = 0x5b;
        *(undefined2 *)((int)param_2 + 0x7aa) = 0x9d;
        *(undefined4 *)((int)param_2 + 0x68) = DAT_0093b0cc;
        *(undefined4 *)((int)param_2 + 0x6c) = DAT_0093b0d0;
        *(undefined4 *)((int)param_2 + 0x70) = DAT_0093b0d4;
        FUN_00482290(param_2);
        return;
      }
    }
    return;
  }
  iVar4 = *(int *)((int)param_2 + 0xca4);
  if ((*(uint *)(iVar4 + 8) & DAT_00802278) != 0) {
    FUN_00561ba0(param_2,0);
    *(uint *)((int)param_2 + 0xe24) = *(uint *)((int)param_2 + 0xe24) | 0x1000;
    fVar2 = (*(float *)((int)param_2 + 0x74c) + 0.2) - *(float *)((int)param_2 + 0x78c);
    if (fVar2 <= 0.0) {
      return;
    }
    fVar8 = (float10)FUN_005c0240(*(float *)(*(int *)(*(int *)((int)param_2 + 0x54) + 0x24) + 0x24)
                                  * -2.0 * fVar2);
    *(float *)((int)param_2 + 0x6c) = (float)fVar8;
    return;
  }
  if ((*(byte *)((int)param_2 + 0x281) & 2) != 0) {
    *(undefined1 *)((int)param_2 + 0x7b5) = 0xff;
    return;
  }
  if (*(float *)(iVar4 + 0x28) <= 0.0) {
    *(undefined2 *)((int)param_2 + 0x7aa) = 0x9d;
    return;
  }
  uVar3 = FUN_0054b3d0(param_2,iVar4);
  uVar6 = *(short *)((int)param_2 + 0x5a) + 0x4000;
  uVar7 = (uint)uVar6;
  local_40 = uVar7;
  fVar8 = (float10)FUN_00550180(uVar3,uVar7);
  if ((float)fVar8 <= DAT_02996ef4) {
    if (-DAT_02996ef4 <= (float)fVar8) {
      *(undefined2 *)((int)param_2 + 0x7aa) = 0x9d;
      return;
    }
    if (*(int *)(*(int *)(*(int *)((int)param_2 + 0x50) + 0xc) + 0x278) == 0) {
      param_2 = -0.5;
      goto LAB_004828dc;
    }
    *(undefined2 *)((int)param_2 + 0x7aa) = 0x9e;
    fVar8 = (float10)FUN_0062f1c0(*(int *)((int)param_2 + 0x50),0x9e);
    fVar8 = -fVar8;
  }
  else {
    if (*(int *)(*(int *)(*(int *)((int)param_2 + 0x50) + 0xc) + 0x27c) == 0) {
      param_2 = 0.5;
      goto LAB_004828dc;
    }
    *(undefined2 *)((int)param_2 + 0x7aa) = 0x9f;
    fVar8 = (float10)FUN_0062f1c0(*(int *)((int)param_2 + 0x50),0x9f);
  }
  param_2 = (float)fVar8;
  if (param_2 == 0.0) {
    return;
  }
LAB_004828dc:
  local_14 = *(float *)(iVar5 + 0x74c);
  local_30 = *(float *)(iVar5 + 0x80) - *(float *)(iVar5 + 0x1dc);
  local_18 = *(float *)(iVar5 + 0x748);
  local_10 = *(float *)(iVar5 + 0x750);
  local_3c = *(float *)(iVar5 + 0x1dc) + *(float *)(iVar5 + 0x80);
  local_2c = *(float *)(iVar5 + 0x84);
  local_38 = *(float *)(iVar5 + 0x194);
  local_28 = *(float *)(iVar5 + 0x88) - *(float *)(iVar5 + 0x1dc);
  local_34 = *(float *)(iVar5 + 0x1dc) + *(float *)(iVar5 + 0x88);
  local_c[0] = (float)(&DAT_029899a0)[uVar6 >> 1] * _DAT_00925018 * param_2;
  local_c[1] = 0.0;
  local_c[2] = _DAT_00925018 * param_2 * (float)(&DAT_029899a0)[(int)(uVar7 + 0x4000) >> 1 & 0x7fff]
  ;
  FUN_005b37d0(&local_24,(float *)(iVar5 + 0x748),local_c);
  iVar4 = FUN_00482310(param_1,&local_24,&local_30,&local_3c,&local_40);
  if ((iVar4 == 0) ||
     (((FUN_00482290(iVar5), local_18 == *(float *)(iVar5 + 0x748) &&
       (local_14 == *(float *)(iVar5 + 0x74c))) && (local_10 == *(float *)(iVar5 + 0x750))))) {
    *(undefined2 *)(iVar5 + 0x7aa) = 0x9d;
  }
  return;
}

