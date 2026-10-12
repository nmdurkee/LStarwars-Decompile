/* Ghidra analysis pseudocode, not original source.
 * ev_f0df202184b9720525c4247b3bb30bed7ac4e9212116aa7e13e8156c499e8a94
 * Entry: 0x601e20; label: FUN_00601e20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00601e20(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  int *piVar2;
  size_t _Size;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  void *unaff_EBX;
  size_t unaff_ESI;
  uint uVar7;
  undefined1 local_2d;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  uint local_8;
  int local_4;
  
  local_1c = 0;
  if (DAT_02854d90 == (void *)0x0) {
    DAT_02854d90 = (void *)FUN_004eef40(PTR_DAT_0080e6cc,
                                        "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nugscn_dlist.c"
                                        ,0x3f);
    _DAT_02854d98 = PTR_DAT_0080e6cc + (int)DAT_02854d90;
  }
  _DAT_00986e88 = 0;
  DAT_00986e8c = (void *)0x0;
  _DAT_00986e90 = 0;
  DAT_00986e94 = (void *)0x0;
  _DAT_00986e98 = 0;
  DAT_00986e9c = (void *)0x0;
  DAT_02854d94 = DAT_02854d90;
  iVar3 = FUN_004fb550(param_3,&local_1c,4);
  iVar4 = FUN_004fb550(param_3,&DAT_00986e98,2);
  pvVar1 = DAT_02854d94;
  iVar3 = iVar3 + iVar4;
  _Size = (_DAT_00986e98 & 0xffff) * 4;
  DAT_00986e9c = DAT_02854d94;
  DAT_02854d94 = (void *)((int)DAT_02854d94 + _Size);
  _memset(pvVar1,0,_Size);
  uVar7 = 0;
  if (DAT_00986e98 != 0) {
    local_28 = 0x10;
    local_2c = 0xc;
    local_24 = 8;
    do {
      iVar4 = local_24;
      iVar5 = FUN_004fb550(param_3,&local_18,0x18);
      pvVar1 = DAT_02854d94;
      iVar3 = iVar3 + iVar5;
      if (local_4 == 0) {
        *(undefined4 *)((int)DAT_00986e9c + uVar7 * 4) = 0;
        local_24 = iVar4;
        if (local_18 < 0) {
          *(undefined4 *)((int)DAT_00986e9c + uVar7 * 4 + 4) = 0;
          *(undefined4 *)(iVar4 + (int)DAT_00986e9c) = 0;
          *(undefined4 *)(local_2c + (int)DAT_00986e9c) = 0;
          *(undefined4 *)(local_28 + (int)DAT_00986e9c) = 0;
          *(undefined4 *)((int)DAT_00986e9c + uVar7 * 4 + 0x14) = 0;
          uVar7 = uVar7 + 5;
          local_28 = local_28 + 0x14;
          local_24 = iVar4 + 0x14;
          local_2c = local_2c + 0x14;
        }
      }
      else if (local_18 == 0) {
        uVar6 = FUN_005f74a0();
        *(undefined4 *)((int)DAT_00986e9c + uVar7 * 4) = uVar6;
        local_24 = iVar4;
      }
      else {
        local_20 = 0;
        if (((DAT_008264c7 == '\0') && (0 < local_18)) &&
           (((local_8 & 0xc) != 0 || ((local_8 & 0x3c00) != 0)))) {
          local_20 = 1;
        }
        DAT_02854d94 = (void *)((int)DAT_02854d94 + local_4);
        iVar4 = FUN_004fb550(param_3,pvVar1,local_4);
        iVar3 = iVar3 + iVar4;
        if (local_20 == 0) {
          FUN_006df300();
          if (local_18 < 0) {
            local_18 = -local_18;
            FUN_006e5a90(pvVar1,local_4,(void *)((int)DAT_00986e9c + uVar7 * 4));
            *(undefined4 *)((int)DAT_00986e9c + uVar7 * 4 + 4) = 0;
            *(undefined4 *)(local_24 + (int)DAT_00986e9c) = 0;
            *(undefined4 *)(local_2c + (int)DAT_00986e9c) = 0;
            *(undefined4 *)(local_28 + (int)DAT_00986e9c) = 0;
            *(undefined4 *)((int)DAT_00986e9c + uVar7 * 4 + 0x14) = 0;
            local_24 = local_24 + 0x14;
            local_2c = local_2c + 0x14;
            uVar7 = uVar7 + 5;
            local_28 = local_28 + 0x14;
          }
          else {
            *(undefined4 *)((int)DAT_00986e9c + uVar7 * 4) = 0;
            FUN_006e5a30(pvVar1,local_4,local_18,local_14,0xfffffffd,0,0,1,0xffffffff,0xffffffff,0,0
                         ,0,(void *)((int)DAT_00986e9c + uVar7 * 4));
          }
          FUN_006df310();
          iVar4 = FUN_004ff0a0();
          if ((iVar4 != 0) && (iVar4 = FUN_006df330(), iVar4 != 0)) {
            Sleep(10);
          }
        }
        DAT_02854d94 = (void *)((int)DAT_02854d94 - local_4);
      }
      local_2c = local_2c + 4;
      local_28 = local_28 + 4;
      uVar7 = uVar7 + 1;
      local_24 = local_24 + 4;
    } while (uVar7 != (_DAT_00986e98 & 0xffff));
  }
  local_20 = 0;
  iVar4 = FUN_004fb550(param_3,&DAT_00986e88,2);
  iVar3 = iVar3 + iVar4;
  pvVar1 = (void *)((int)DAT_02854d94 + (_DAT_00986e88 & 0xffff) * 4);
  uVar7 = 0;
  DAT_00986e8c = DAT_02854d94;
  DAT_02854d94 = pvVar1;
  if ((_DAT_00986e88 & 0xffff) != 0) {
    do {
      local_28 = 0;
      iVar4 = FUN_004fb550(param_3,&local_28,4);
      pvVar1 = DAT_02854d94;
      iVar3 = iVar3 + iVar4;
      if (local_28 == 0) {
        FUN_005f74a0();
        *(undefined4 *)((int)DAT_00986e8c + uVar7 * 4) = 0;
      }
      else {
        DAT_02854d94 = (void *)((int)DAT_02854d94 + local_28);
        iVar4 = FUN_004fb550(param_3,pvVar1,local_28);
        iVar3 = iVar3 + iVar4;
        FUN_006df300();
        FUN_006e4810(local_28,0,0,1,(void *)((int)DAT_00986e8c + uVar7 * 4));
        piVar2 = *(int **)((int)DAT_00986e8c + uVar7 * 4);
        (**(code **)(*piVar2 + 0x2c))(piVar2,0,0,&local_20,0);
        _memcpy(unaff_EBX,pvVar1,unaff_ESI);
        piVar2 = *(int **)((int)DAT_00986e8c + uVar7 * 4);
        (**(code **)(*piVar2 + 0x30))(piVar2);
        FUN_006df310();
        DAT_02854d94 = (void *)((int)DAT_02854d94 - local_28);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 != (_DAT_00986e88 & 0xffff));
  }
  local_20 = 0;
  iVar4 = FUN_004fb550(param_3,&DAT_00986e90,2);
  iVar3 = iVar3 + iVar4;
  pvVar1 = (void *)((int)DAT_02854d94 + (_DAT_00986e90 & 0xffff) * 4);
  uVar7 = 0;
  DAT_00986e94 = DAT_02854d94;
  DAT_02854d94 = pvVar1;
  if ((_DAT_00986e90 & 0xffff) != 0) {
    do {
      local_28 = 0;
      iVar4 = FUN_004fb550(param_3,&local_28,4);
      pvVar1 = DAT_02854d94;
      iVar3 = iVar3 + iVar4;
      if (local_28 == 0) {
        FUN_005f74a0();
        *(undefined4 *)((int)DAT_00986e94 + uVar7 * 4) = 0;
      }
      else {
        DAT_02854d94 = (void *)((int)DAT_02854d94 + local_28);
        iVar4 = FUN_004fb550(param_3,pvVar1,local_28);
        iVar3 = iVar3 + iVar4;
        FUN_006df300();
        FUN_006e46f0(local_28,0,0x65,1,(void *)((int)DAT_00986e94 + uVar7 * 4),0);
        piVar2 = *(int **)((int)DAT_00986e94 + uVar7 * 4);
        (**(code **)(*piVar2 + 0x2c))(piVar2,0,0,&local_20,0);
        _memcpy(unaff_EBX,pvVar1,unaff_ESI);
        piVar2 = *(int **)((int)DAT_00986e94 + uVar7 * 4);
        (**(code **)(*piVar2 + 0x30))(piVar2);
        FUN_006df310();
        DAT_02854d94 = (void *)((int)DAT_02854d94 - local_28);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 != (_DAT_00986e90 & 0xffff));
  }
  iVar4 = local_1c + 4;
  if (iVar3 < iVar4) {
    for (iVar3 = iVar4 - iVar3; iVar3 != 0; iVar3 = iVar3 + -1) {
      FUN_004fb550(param_3,&local_2d,1);
    }
  }
  return iVar4;
}

