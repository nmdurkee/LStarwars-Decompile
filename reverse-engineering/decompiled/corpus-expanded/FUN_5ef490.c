/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5ef490; label: FUN_005ef490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_005ef490(int *param_1,uint *param_2)

{
  int *piVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *extraout_ECX;
  int iVar7;
  int extraout_EDX;
  int iVar8;
  void *_Src;
  uint uVar9;
  void *_Dst;
  uint uVar10;
  uint uVar11;
  int iVar12;
  void *local_1b4;
  void *local_1ac;
  undefined1 local_1a4 [420];
  
  pvVar2 = (void *)param_1[0x75];
  uVar3 = param_1[0x76];
  uVar11 = *param_2 + 0x1f & 0xffffffe0;
  *param_2 = uVar11;
  uVar11 = uVar11 - (int)pvVar2;
  if (uVar11 == 0) {
    return param_1;
  }
  if ((uVar3 == 0) || (pvVar2 == (void *)0x0)) {
    FUN_005c12e0();
    return (int *)0x0;
  }
  FUN_004ef660(local_1a4,*(undefined4 *)(param_1[0x44] + 0x80),0x1a4);
  FUN_005ef050(param_1);
  FUN_005d3400(param_1[0x19]);
  FUN_005dee40(param_1[0x44]);
  iVar8 = 0;
  iVar7 = DAT_0097157c;
  if (0 < param_1[1]) {
    do {
      iVar4 = *(int *)(*param_1 + iVar8 * 4);
      if (0 < iVar4) {
        iVar12 = *(int *)(iVar7 + -4 + iVar4 * 4);
        if ((iVar12 == 0) || (*(int *)(iVar12 + 0x18) < 1)) {
          FUN_005f8ed0(iVar12);
          iVar7 = DAT_0097157c;
          *(undefined4 *)(DAT_0097157c + -4 + iVar4 * 4) = 0;
        }
        else if (iVar12 != 0) {
          *(int *)(iVar12 + 0x18) = *(int *)(iVar12 + 0x18) + -1;
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_1[1]);
  }
  FUN_00602800(param_1);
  if ((int)uVar11 < 1) {
    uVar5 = -uVar11;
    uVar10 = uVar3;
    if (uVar5 < uVar3) {
      uVar10 = uVar5;
    }
    local_1b4 = (void *)*param_2;
    uVar9 = uVar3;
    local_1ac = pvVar2;
    do {
      _memcpy(local_1b4,local_1ac,uVar10);
      local_1ac = (void *)((int)local_1ac + uVar10);
      local_1b4 = (void *)((int)local_1b4 + uVar10);
      uVar9 = uVar9 - uVar10;
      uVar10 = uVar5;
      if (uVar9 <= uVar5) {
        uVar10 = uVar9;
      }
    } while (uVar9 != 0);
  }
  else {
    uVar10 = uVar3;
    if (uVar11 < uVar3) {
      uVar10 = uVar11;
    }
    _Src = (void *)((uVar3 - uVar10) + (int)pvVar2);
    _Dst = (void *)((*param_2 - uVar10) + uVar3);
    local_1b4 = (void *)uVar3;
    do {
      _memcpy(_Dst,_Src,uVar10);
      local_1b4 = (void *)((int)local_1b4 - uVar10);
      _Src = (void *)((int)_Src - uVar10);
      _Dst = (void *)((int)_Dst - uVar10);
      uVar10 = uVar11;
      if (local_1b4 <= uVar11) {
        uVar10 = (uint)local_1b4;
      }
    } while (local_1b4 != (void *)0x0);
  }
  uVar6 = FUN_005c1300(pvVar2,*param_2);
  FUN_004ef660(*extraout_ECX,uVar6,uVar3);
  iVar7 = *(int *)(uVar11 + 0x1d4 + (int)param_1);
  param_1 = (int *)(uVar11 + (int)param_1);
  FUN_004f4f80(uVar11 + 0x18 + (int)pvVar2,uVar11);
  param_1[0x75] = iVar7 + uVar11;
  *param_2 = *param_2 + uVar3;
  FUN_00602810(param_1,uVar11);
  iVar7 = 0;
  if (param_1[0x18] != 0) {
    iVar8 = 0;
    do {
      iVar4 = param_1[0x19];
      piVar1 = (int *)(iVar4 + 0x10 + iVar8);
      *piVar1 = *piVar1 + uVar11;
      piVar1 = (int *)(iVar4 + 0x14 + iVar8);
      *piVar1 = *piVar1 + uVar11;
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x20;
    } while (iVar7 != param_1[0x18]);
  }
  iVar7 = 0;
  if (param_1[0x18] != 1 && -1 < param_1[0x18] + -1) {
    iVar8 = 0;
    do {
      *(int *)(param_1[0x19] + iVar8) = *(int *)(param_1[0x19] + iVar8) + uVar11;
      piVar1 = (int *)(iVar8 + 0x24 + param_1[0x19]);
      *piVar1 = *piVar1 + uVar11;
      iVar7 = iVar7 + 1;
      iVar8 = iVar8 + 0x20;
    } while (iVar7 < param_1[0x18] + -1);
  }
  iVar8 = 0;
  iVar7 = DAT_0097157c;
  if (0 < param_1[1]) {
    do {
      iVar4 = *(int *)(param_1[2] + iVar8 * 4);
      iVar12 = 0;
      if (iVar4 != 0) {
        if (0 < DAT_0096e570) {
          do {
            if (*(int *)(iVar7 + iVar12 * 4) == 0) {
              *(int *)(iVar7 + iVar12 * 4) = iVar4;
              *(int *)(DAT_009716e4 + iVar12 * 4) = DAT_00966380;
              DAT_00966380 = DAT_00966380 + 1;
              FUN_005f8e50(iVar4);
              iVar12 = iVar12 + 1;
              iVar7 = DAT_0097157c;
              goto LAB_005ef718;
            }
            iVar12 = iVar12 + 1;
          } while (iVar12 < DAT_0096e570);
        }
        FUN_005c12e0();
        iVar12 = 0;
        iVar7 = extraout_EDX;
      }
LAB_005ef718:
      *(int *)(*param_1 + iVar8 * 4) = iVar12;
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_1[1]);
  }
  FUN_005eedf0(param_1);
  FUN_005d3380(param_1[0x19]);
  *(uint *)(param_1[0x44] + 0x80) = *param_2 + 0xf & 0xfffffff0;
  *param_2 = (*param_2 + 0xf & 0xfffffff0) + 0x1a4;
  FUN_004ef660(*(undefined4 *)(param_1[0x44] + 0x80),local_1a4,0x1a4);
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  if (param_1[0x44] != 0) {
    FUN_005ded80(param_1[0x44]);
  }
  return param_1;
}

