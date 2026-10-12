/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c3240; label: FUN_006c3240
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c3240(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *in_ECX;
  bool bVar7;
  float10 fVar8;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  uint local_48;
  float local_44;
  float local_40;
  float local_3c;
  uint local_38;
  uint local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  local_54 = 0.5;
  local_58 = 0.5;
  in_ECX[0x10] = param_2;
  *in_ECX = *(undefined4 *)(param_1 + 0x30);
  in_ECX[1] = *(undefined4 *)(param_1 + 0x34);
  in_ECX[2] = *(undefined4 *)(param_1 + 0x38);
  in_ECX[4] = *(undefined4 *)(param_1 + 0x10);
  in_ECX[5] = *(undefined4 *)(param_1 + 0x14);
  in_ECX[6] = *(undefined4 *)(param_1 + 0x18);
  in_ECX[4] = (float)in_ECX[4] * 1000.0;
  in_ECX[5] = (float)in_ECX[5] * 1000.0;
  in_ECX[6] = (float)in_ECX[6] * 1000.0;
  iVar2 = FUN_0061f870(param_2);
  if (iVar2 < 1) {
    FUN_006dde00(&local_4c,&local_50);
    if ((_DAT_00820258 == local_4c) && (_DAT_00820254 == local_50)) {
      if (DAT_02974ca4 == '\0') goto LAB_006c3356;
    }
    else {
      DAT_02974ca4 = '\x01';
      _DAT_00820258 = local_4c;
      _DAT_00820254 = local_50;
    }
    local_54 = _DAT_00820258;
    local_58 = _DAT_00820254;
  }
  else {
    FUN_0061f810(0x3f000000,0x3f000000);
    local_58 = 0.5;
    DAT_02974ca4 = '\0';
    local_54 = 0.5;
  }
LAB_006c3356:
  FUN_005d6e10(local_54,local_58,in_ECX + 8,&local_20,param_1);
  local_30 = local_20 - (float)in_ECX[8];
  local_2c = local_1c - (float)in_ECX[9];
  local_28 = local_18 - (float)in_ECX[10];
  in_ECX[0xc] = local_30;
  in_ECX[0xd] = local_2c;
  in_ECX[0xe] = local_28;
  in_ECX[0xf] = local_24;
  in_ECX[0x11] = param_3;
  if (DAT_0080f59c < 0) {
    uVar3 = FUN_006d6c20(0x36);
    uVar4 = FUN_006d6c20(0x2a);
    local_38 = FUN_006d6c20(0x1f);
    local_38 = local_38 | uVar3 | uVar4;
    uVar3 = FUN_006d6c20(0xb8);
    uVar4 = FUN_006d6c20(0x39);
    uVar5 = FUN_006d6c20(0x38);
    uVar5 = uVar5 | uVar3 | uVar4;
    uVar3 = FUN_006d6c20(0x9d);
    uVar4 = FUN_006d6c20(0x2e);
    uVar6 = FUN_006d6c20(0x1d);
    uVar6 = uVar6 | uVar3 | uVar4;
    local_34 = uVar6;
    iVar2 = FUN_006d58b0();
    bVar7 = true;
    if ((iVar2 == 1) || ((*(uint *)(in_ECX[0x10] + 0x70) & 0x800) != 0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    local_4c = 0.0;
    if (((!bVar1) || (uVar5 != 0)) || (local_50 = 1.4013e-45, uVar6 != 0)) {
      local_50 = 0.0;
    }
    fVar8 = (float10)FUN_006d5bf0();
    local_44 = (float)fVar8;
    fVar8 = (float10)FUN_006d5c10();
    local_40 = (float)fVar8;
    fVar8 = (float10)FUN_006d5c30();
    local_3c = (float)fVar8;
    if (DAT_02973a94 == 0) {
      iVar2 = FUN_0061f000();
      if (iVar2 == 0) {
        local_48 = *(uint *)(in_ECX[0x10] + 0x70) & 0x40;
        local_4c = (float)(*(uint *)(in_ECX[0x10] + 0x70) & 0x80);
        FUN_006b9680(0x26,(float)local_48,param_3);
      }
      iVar2 = FUN_006d58b0();
      if ((iVar2 != 2) && ((*(byte *)(in_ECX[0x10] + 0x70) & 0x20) == 0)) {
        bVar7 = false;
      }
    }
    else {
      iVar2 = FUN_006d58b0();
      bVar7 = iVar2 == 2;
    }
    FUN_006b9680(0,local_44,param_3);
    FUN_006b9680(1,local_40,param_3);
    FUN_006b9680(2,local_3c,param_3);
    FUN_006b9680(3,(float)(int)local_50,param_3);
    if (((bVar7) && (uVar5 == 0)) && (uVar6 == 0)) {
      local_50 = 1.4013e-45;
    }
    else {
      local_50 = 0.0;
    }
    FUN_006b9680(4,(float)(int)local_50,param_3);
    local_3c = (float)FUN_006d6c20(0x10);
    FUN_006b9680(5,(float)(int)local_3c,param_3);
    local_3c = (float)FUN_006d6c20(0x11);
    FUN_006b9680(6,(float)(int)local_3c,param_3);
    local_3c = (float)FUN_006d6c20(0x12);
    FUN_006b9680(7,(float)(int)local_3c,param_3);
    local_3c = (float)FUN_006d6c20(0x13);
    FUN_006b9680(8,(float)(int)local_3c,param_3);
    local_3c = (float)FUN_006d6c20(0x21);
    FUN_006b9680(9,(float)(int)local_3c,param_3);
    local_3c = (float)FUN_006d6c20(0x22);
    FUN_006b9680(10,(float)(int)local_3c,param_3);
    local_3c = (float)FUN_006d6c20(0xd2);
    FUN_006b9680(0xb,(float)(int)local_3c,param_3);
    local_3c = (float)FUN_006d6c20(0xd3);
    FUN_006b9680(0xc,(float)(int)local_3c,param_3);
    FUN_006b9680(0xd,(float)(int)uVar5,param_3);
    local_3c = (float)FUN_006d6c20(0xd);
    FUN_006b9680(0xe,(float)(int)local_3c,param_3);
    local_3c = (float)FUN_006d6c20(0xc);
    FUN_006b9680(0xf,(float)(int)local_3c,param_3);
    local_50 = (float)(int)local_38;
    FUN_006b9680(0x10,local_50,param_3);
    local_38 = FUN_006d6c20(0x1b);
    FUN_006b9680(0x11,(float)(int)local_38,param_3);
    local_38 = FUN_006d6c20(0x1a);
    FUN_006b9680(0x12,(float)(int)local_38,param_3);
    local_38 = FUN_006d6c20(0xcd);
    FUN_006b9680(0x13,(float)(int)local_38,param_3);
    local_38 = FUN_006d6c20(0xcb);
    FUN_006b9680(0x14,(float)(int)local_38,param_3);
    FUN_006b9680(0x15,local_50,param_3);
    FUN_006b9680(0x16,(float)(int)local_34,param_3);
    iVar2 = FUN_006d6c20(0x1f);
    if ((iVar2 == 0) || (local_50 = 1.4013e-45, uVar6 == 0)) {
      local_50 = 0.0;
    }
    FUN_006b9680(0x17,(float)(int)local_50,param_3);
    local_34 = FUN_006d6c20(1);
    FUN_006b9680(0x18,(float)(int)local_34,param_3);
    if (((!bVar1) || (uVar5 != 0)) || (local_50 = 1.4013e-45, uVar6 == 0)) {
      local_50 = 0.0;
    }
    FUN_006b9680(0x19,(float)(int)local_50,param_3);
    local_34 = FUN_006d6c20(2);
    FUN_006b9680(0x1a,(float)(int)local_34,param_3);
    local_34 = FUN_006d6c20(3);
    FUN_006b9680(0x1b,(float)(int)local_34,param_3);
    local_34 = FUN_006d6c20(4);
    FUN_006b9680(0x1c,(float)(int)local_34,param_3);
    local_34 = FUN_006d6c20(5);
    FUN_006b9680(0x1d,(float)(int)local_34,param_3);
    local_34 = FUN_006d6c20(6);
    FUN_006b9680(0x1e,(float)(int)local_34,param_3);
    local_34 = FUN_006d6c20(7);
    FUN_006b9680(0x1f,(float)(int)local_34,param_3);
    local_34 = FUN_006d6c20(8);
    FUN_006b9680(0x20,(float)(int)local_34,param_3);
    local_34 = FUN_006d6c20(9);
    FUN_006b9680(0x21,(float)(int)local_34,param_3);
    local_34 = FUN_006d6c20(10);
    FUN_006b9680(0x22,(float)(int)local_34,param_3);
    local_34 = FUN_006d6c20(0xb);
    FUN_006b9680(0x23,(float)(int)local_34,param_3);
    FUN_006b9680(0x25,(float)(int)local_4c,param_3);
    local_34 = *(uint *)(in_ECX[0x10] + 0x70) & 0x800;
    FUN_006b9680(0x27,(float)local_34,param_3);
  }
  else {
    iVar2 = 0;
    do {
      FUN_006b9680(iVar2,0,param_3);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x28);
  }
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x43] = 0;
  in_ECX[0x44] = 0;
  in_ECX[0x45] = 0;
  return;
}

