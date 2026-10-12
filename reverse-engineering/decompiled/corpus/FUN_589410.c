/* Ghidra analysis pseudocode, not original source.
 * ev_4597a773e0370c09a0c234dc3483b3ea71e6a654f79adb326cefb52c3abac04d
 * Entry: 0x589410; label: FUN_00589410
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00589410(int param_1,int param_2,undefined4 param_3,uint *param_4,int param_5,
                 undefined *param_6,int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  undefined4 in_EDX;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int local_b0c;
  int local_b08;
  undefined *local_b04;
  undefined4 local_b00;
  uint *local_afc;
  undefined2 local_af8 [858];
  undefined1 local_444 [896];
  undefined1 local_c4 [128];
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_b0c;
  iVar4 = param_1 * 0x4c + *(int *)(DAT_029130e4 + 0x20);
  local_afc = param_4;
  local_b0c = 0;
  local_b00 = in_EDX;
  if (param_6 == (undefined *)0x0) {
    if (param_2 == 0) goto LAB_00589a91;
    FUN_004f1f10(local_c4,param_2);
    FUN_004f1e80(local_c4,param_3);
    local_b04 = &DAT_009270b8;
    iVar1 = FUN_004fd5d0(local_c4,&DAT_009270b8,0x4000);
    if (iVar1 < 1) goto LAB_00589a91;
    (&DAT_009270b8)[iVar1] = 0;
    param_7 = FUN_0054be70(&DAT_009270b8,&DAT_009270b8,1);
    if (param_7 < 1) goto LAB_00589a91;
    if ((param_8 != 0) && (local_b0c = FUN_00584640(local_44,0x40), local_b0c != 0)) {
      FUN_004f1f10(local_c4,param_2);
      FUN_004f1e80(local_c4,local_44);
      FUN_004f1e80(local_c4,&DAT_0075d39c);
      param_7 = FUN_004fd5d0(local_c4,&DAT_009270b8,0x4000);
      if (param_7 < 1) {
        local_b0c = 0;
      }
      else {
        (&DAT_009270b8)[param_7] = 0;
        param_7 = FUN_0054be70(&DAT_009270b8,&DAT_009270b8,1);
      }
    }
  }
  else {
    local_b04 = param_6;
  }
  if (0 < param_7) {
    _memset(&DAT_00954400,0,0xfc8);
    puVar6 = local_afc;
    _DAT_0095440c = _DAT_0095440c ^ (param_5 << 6 ^ _DAT_0095440c) & 0x40;
    DAT_0095441c = (undefined2)param_1;
    iVar1 = *(int *)(iVar4 + 0x24);
    DAT_00954418 = local_af8;
    DAT_00954408 = local_444;
    DAT_00954410 = 0;
    DAT_00954420 = local_afc;
    DAT_00954424 = local_b08;
    DAT_00954400 = iVar4;
    DAT_00954404 = iVar1;
    _memset(DAT_00954418,0,0x6b4);
    if ((((*(int *)(iVar1 + 4) == 0) && ((*(byte *)(iVar4 + 4) & 1) == 0)) &&
        (puVar6 != (uint *)0x0)) && (local_b08 != 0)) {
      *(undefined1 **)(iVar1 + 4) = local_444;
      *(undefined1 *)(DAT_00954404 + 0x11f) = 0;
      _DAT_0095440c = _DAT_0095440c | 2;
      puVar6 = DAT_00954420;
    }
    else {
      DAT_00954410 = *(char *)(iVar1 + 0x11f) != '\0';
    }
    if (((*(int *)(DAT_00954400 + 0x10) == 0) && (puVar6 != (uint *)0x0)) && (DAT_00954424 != 0)) {
      *puVar6 = *puVar6 + 3 & 0xfffffffc;
      *(uint *)(DAT_00954400 + 0x10) = *DAT_00954420;
      _DAT_0095440c = _DAT_0095440c | 0x20;
    }
    iVar1 = FUN_004fc900("character",local_b04,0xffff);
    if (iVar1 != 0) {
      FUN_004f1160(iVar1,&PTR_s_name_id_00804248,local_b00);
      iVar2 = FUN_004fc5b0(iVar1);
      while (iVar2 != 0) {
        iVar2 = FUN_004f7fb0(iVar1);
        if (iVar2 != 0) {
          FUN_004fa020(iVar1);
        }
        iVar2 = FUN_004fc5b0(iVar1);
      }
      FUN_004fa300(iVar1);
    }
    *(uint *)(DAT_00954400 + 4) = *(uint *)(DAT_00954400 + 4) | 1;
    if (((_DAT_0095440c & 4) != 0) && ((_DAT_0095440c & 8) == 0)) {
      *(undefined4 *)(DAT_00954404 + 0x78) = *(undefined4 *)(DAT_00954404 + 0x74);
    }
    if (((DAT_0095440c & 0x10) == 0) && ((*(uint *)(DAT_00954400 + 4) & 0x2000) != 0)) {
      *(undefined4 *)(DAT_00954404 + 0xbc) = _DAT_00804224;
      *(undefined1 *)(DAT_00954404 + 0xcc) = DAT_00804234;
      *(undefined4 *)(DAT_00954404 + 0xc0) = _DAT_00804228;
      *(undefined1 *)(DAT_00954404 + 0xcd) = DAT_00804238;
      *(undefined4 *)(DAT_00954404 + 0xc4) = _DAT_0080422c;
      *(undefined1 *)(DAT_00954404 + 0xce) = DAT_0080423c;
      *(undefined4 *)(DAT_00954404 + 200) = _DAT_00804230;
      *(undefined1 *)(DAT_00954404 + 0xcf) = DAT_00804240;
    }
    FUN_00589390(*(undefined4 *)(DAT_00954404 + 0x2c),*(undefined4 *)(DAT_00954404 + 0x24),
                 DAT_00954404 + 0x30,DAT_00954404 + 0x34);
    FUN_00589390(*(undefined4 *)(DAT_00954404 + 0x38),*(undefined4 *)(DAT_00954404 + 0x24),
                 DAT_00954404 + 0x3c,DAT_00954404 + 0x40);
    if ((_DAT_0095440c & 0x20) != 0) {
      *(ushort *)(DAT_00954400 + 0x14) = DAT_0095441e;
      *(undefined4 *)((uint)DAT_0095441e * 0x4c + *(int *)(DAT_00954400 + 0x10)) = 0;
      *(undefined2 *)((uint)DAT_0095441e * 0x4c + 8 + *(int *)(DAT_00954400 + 0x10)) = 0xffff;
      DAT_0095441e = DAT_0095441e + 1;
      *DAT_00954420 = (uint)DAT_0095441e * 0x4c + *(int *)(iVar4 + 0x10);
      iVar4 = 0;
      if (DAT_0095441e != 1 && -1 < (int)(DAT_0095441e - 1)) {
        iVar1 = 0;
        puVar3 = &DAT_00954428;
        do {
          FUN_004f1f10(*DAT_00954420,puVar3);
          *(uint *)(iVar1 + *(int *)(DAT_00954400 + 0x10)) = *DAT_00954420;
          iVar2 = FUN_004f1ff0(*(undefined4 *)(*(int *)(DAT_00954400 + 0x10) + iVar1));
          *DAT_00954420 = *DAT_00954420 + iVar2 + 1;
          iVar4 = iVar4 + 1;
          puVar3 = puVar3 + 0x28;
          iVar1 = iVar1 + 0x4c;
        } while (iVar4 < (int)(DAT_0095441e - 1));
      }
      if (0 < DAT_00954414) {
        local_af8[DAT_00954414 * 0x1a] = 0xffff;
        DAT_00954414 = DAT_00954414 + 1;
        *DAT_00954420 = *DAT_00954420 + 3 & 0xfffffffc;
        *(uint *)(DAT_00954400 + 0x28) = *DAT_00954420;
        FUN_004ef660(*(undefined4 *)(DAT_00954400 + 0x28),local_af8,DAT_00954414 * 0x34);
        *DAT_00954420 = *DAT_00954420 + DAT_00954414 * 0x34;
      }
    }
    if ((_DAT_0095440c & 2) != 0) {
      if (*(char *)(DAT_00954404 + 0x11f) == '\0') {
        *(undefined4 *)(DAT_00954404 + 4) = 0;
        *(undefined1 *)(DAT_00954404 + 0x11f) = 0;
      }
      else {
        *DAT_00954420 = *DAT_00954420 + 3 & 0xfffffffc;
        *(uint *)(DAT_00954404 + 4) = *DAT_00954420;
        *DAT_00954420 = *DAT_00954420 + (uint)*(byte *)(DAT_00954404 + 0x11f) * 0x1c;
        FUN_004ef660(*(undefined4 *)(DAT_00954404 + 4),DAT_00954408,
                     (uint)*(byte *)(DAT_00954404 + 0x11f) * 0x1c);
        *(uint *)(DAT_00954404 + 8) = *DAT_00954420;
        *DAT_00954420 = *DAT_00954420 + 0x20;
        iVar1 = 0;
        iVar4 = DAT_00954404;
        do {
          iVar2 = 0;
          if (*(char *)(iVar4 + 0x11f) != '\0') {
            iVar5 = 0;
            do {
              if (*(short *)(*(int *)(iVar4 + 4) + 0x18 + iVar5) == iVar1) {
                *(char *)(iVar1 + *(int *)(iVar4 + 8)) = (char)iVar2;
                iVar4 = DAT_00954404;
              }
              iVar2 = iVar2 + 1;
              iVar5 = iVar5 + 0x1c;
            } while (iVar2 < (int)(uint)*(byte *)(iVar4 + 0x11f));
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < 0x20);
      }
    }
  }
LAB_00589a91:
  _DAT_009553d0 = 0;
  __security_check_cookie(local_4 ^ (uint)&local_b0c);
  return;
}

