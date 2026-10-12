/* Ghidra analysis pseudocode, not original source.
 * ev_ad38b5b12c7b5b6be74e46159191c12aead9520624245f9f1862d693e1fa9ce5
 * Entry: 0x6f9cc0; label: __handle_exc
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __handle_exc
   
   Library: Visual Studio 2005 Release */

bool __handle_exc(uint param_1,double *param_2,uint param_3)

{
  double dVar1;
  double dVar2;
  bool bVar3;
  ulonglong uVar4;
  double dVar5;
  uint uVar6;
  bool bVar7;
  float10 fVar8;
  undefined8 local_14;
  int local_c;
  uint local_8;
  
  uVar6 = param_1 & 0x1f;
  bVar3 = true;
  local_8 = uVar6;
  if (((param_1 & 8) != 0) && ((param_3 & 1) != 0)) {
    FUN_006fa22a(1);
    uVar6 = param_1 & 0x17;
    goto LAB_006f9e7f;
  }
  if (((param_1 & 4) != 0) && ((param_3 & 4) != 0)) {
    FUN_006fa22a(4);
    uVar6 = param_1 & 0x1b;
    goto LAB_006f9e7f;
  }
  if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {
    if (((param_1 & 2) != 0) && ((param_3 & 0x10) != 0)) {
      bVar7 = (param_1 & 0x10) != 0;
      if (*param_2 != 0.0) {
        fVar8 = (float10)FUN_006f98f5(*param_2,&local_c);
        dVar2 = (double)fVar8;
        local_c = local_c + -0x600;
        if (local_c < -0x432) {
          local_14 = dVar2 * 0.0;
          bVar7 = bVar3;
        }
        else {
          local_14 = (double)((ulonglong)dVar2 & 0xfffffffffffff | 0x10000000000000);
          if (local_c < -0x3fd) {
            local_c = -0x3fd - local_c;
            do {
              if ((((ulonglong)local_14 & 1) != 0) && (!bVar7)) {
                bVar7 = bVar3;
              }
              uVar6 = (uint)local_14 >> 1;
              uVar4 = (ulonglong)local_14 & 0x100000000;
              local_14._0_4_ = uVar6;
              if (uVar4 != 0) {
                local_14._0_4_ = uVar6 | 0x80000000;
              }
              local_14 = (double)CONCAT44(local_14._4_4_ >> 1,(uint)local_14);
              local_c = local_c + -1;
            } while (local_c != 0);
          }
          if (dVar2 < 0.0) {
            local_14 = -local_14;
          }
        }
        *param_2 = local_14;
        bVar3 = bVar7;
      }
      if (bVar3) {
        FUN_006fa22a(0x10);
      }
      uVar6 = local_8 & 0xfffffffd;
      local_8 = uVar6;
    }
    goto LAB_006f9e7f;
  }
  FUN_006fa22a(8);
  uVar6 = param_3 & 0xc00;
  dVar2 = _DAT_00829f40;
  dVar5 = _DAT_00829f40;
  if (uVar6 == 0) {
    dVar1 = *param_2;
joined_r0x006f9d62:
    if (dVar1 <= 0.0) {
      dVar2 = -dVar5;
    }
    *param_2 = dVar2;
  }
  else {
    if (uVar6 == 0x400) {
      dVar1 = *param_2;
      dVar2 = _DAT_00829f50;
      goto joined_r0x006f9d62;
    }
    dVar5 = _DAT_00829f50;
    if (uVar6 == 0x800) {
      dVar1 = *param_2;
      goto joined_r0x006f9d62;
    }
    if (uVar6 == 0xc00) {
      dVar1 = *param_2;
      dVar2 = _DAT_00829f50;
      goto joined_r0x006f9d62;
    }
  }
  uVar6 = param_1 & 0x1e;
LAB_006f9e7f:
  if (((param_1 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    FUN_006fa22a(0x20);
    uVar6 = uVar6 & 0xffffffef;
  }
  return uVar6 == 0;
}

