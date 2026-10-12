/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x475c60; label: FUN_00475c60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00475c60(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  undefined4 uVar6;
  undefined1 auStack_94 [4];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 *local_80 [6];
  undefined4 local_68;
  undefined4 local_64;
  int local_58;
  undefined1 local_31;
  undefined4 local_2c [8];
  uint local_c;
  
  local_c = DAT_00829570 ^ (uint)auStack_94;
  puVar4 = &DAT_00802cd8;
  ppuVar5 = local_80;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar5 = (undefined4 *)*puVar4;
    puVar4 = puVar4 + 1;
    ppuVar5 = ppuVar5 + 1;
  }
  if (param_2 == 0) {
    if (DAT_007f3b14 != -1) goto LAB_00475f8c;
    iVar2 = FUN_0055f1a0();
    if (iVar2 != 0) {
      iVar2 = *(int *)(&DAT_007f9f5c + DAT_007fa198 * 4);
      (&DAT_00879544)[param_1] = (&DAT_00879544)[param_1] + 1;
      if ((0 < iVar2) && (iVar2 <= (int)(&DAT_00879544)[param_1])) {
        FUN_0042b6f0(param_1);
        _DAT_0086e71c = 0;
        FUN_00509830(0xb,0xffffffff,0xffffffff);
        (&DAT_0087956c)[param_1] = (&DAT_0087956c)[param_1] + 1;
      }
      goto LAB_00475ca1;
    }
    bVar1 = false;
    FUN_00547930(0x32,0,0,0);
    FUN_0054a910(0,0x3e4ccccd,0,1);
LAB_00475d4a:
    uVar6 = (&DAT_00879544)[param_1];
  }
  else {
    (&DAT_0087956c)[param_1] = 0;
LAB_00475ca1:
    bVar1 = true;
    iVar2 = FUN_0054fa60();
    if (iVar2 < 0x8000) {
      local_84 = 0xbf19999a;
    }
    else {
      local_84 = 0x3f19999a;
    }
    FUN_00549de0(0,local_84,2,0);
    FUN_0054a910(0x3f800000,0x3dcccccd,0,1);
    FUN_00549bb0(PTR_DAT_008021b4,0x3f800000,0x3f800000,0x3f800000);
    FUN_00547930(0x2c,0,0,0);
    FUN_00547930(0x26,0,0,0);
    if (param_2 == 0) goto LAB_00475d4a;
    uVar6 = (&DAT_0087956c)[param_1];
  }
  FUN_004f2740(local_2c,&DAT_00751730,uVar6);
  if (param_1 == 0) {
    local_90 = 0xbc75c28f;
    local_31 = 8;
  }
  else {
    local_90 = 0x3c75c28f;
    local_31 = 2;
  }
  local_80[0] = local_2c;
  local_80[1] = &local_90;
  local_8c = _DAT_007fc310;
  local_88 = 0x3f800000;
  local_80[3] = (undefined4 *)0x3f333333;
  local_80[4] = (undefined4 *)0x40066666;
  local_68 = 0x4028;
  local_64 = 0x40000000;
  local_80[2] = local_80[1];
  FUN_00560b60(local_80);
  if (param_2 == 0) {
    if (!bVar1) {
      _DAT_007fa1ac = 0x3fc00000;
      __security_check_cookie(local_c ^ (uint)auStack_94);
      return;
    }
    iVar2 = (int)*(short *)(*(short *)((&DAT_0093d7f0)[param_1] + 0x1064) * 0x4c + 0x42 +
                           DAT_0093b274);
    if (iVar2 != -1) {
      if ((*(char *)(*(short *)((&DAT_0093d7f0)[param_1] + 0x1064) * 0x120 + 0x116 + DAT_0093b284)
           == '\0') && (iVar2 != DAT_00803b98)) {
        iVar2 = iVar2 + 1;
      }
      local_90 = 0;
      local_8c = _DAT_007fa1b0;
      puVar4 = &DAT_00802cd8;
      ppuVar5 = local_80;
      for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
        *ppuVar5 = (undefined4 *)*puVar4;
        puVar4 = puVar4 + 1;
        ppuVar5 = ppuVar5 + 1;
      }
      local_88 = 0x3f800000;
      local_80[3] = (undefined4 *)0x3eaa7efa;
      local_80[4] = (undefined4 *)0x3f0e147b;
      local_80[1] = &local_90;
      local_58 = iVar2 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0);
      local_68 = 0x14120;
      local_64 = 0x40200000;
      FUN_00560b60(local_80);
      iVar2 = (0xa6 - (uint)(param_1 != 0)) * 0x10;
      if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar2) != '\0') {
        local_58 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar2;
        FUN_00560b60(local_80);
      }
    }
  }
LAB_00475f8c:
  __security_check_cookie(local_c ^ (uint)auStack_94);
  return;
}

