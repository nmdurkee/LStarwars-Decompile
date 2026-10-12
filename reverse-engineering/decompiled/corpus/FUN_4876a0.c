/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x4876a0; label: FUN_004876a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004876a0(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined1 uVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint local_1c4;
  uint local_1c0;
  undefined4 local_1a8 [44];
  undefined1 local_f8;
  undefined4 local_d8 [44];
  undefined1 local_28;
  
  if (DAT_00951c5c != 0) {
    return 0;
  }
  uVar1 = *(undefined4 *)(param_1 + 0xda8);
  uVar5 = *(undefined4 *)(param_1 + 0xca4);
  uVar6 = *(undefined4 *)(param_2 + 0xca4);
  uVar2 = *(undefined1 *)(param_2 + 0x107f);
  uVar7 = *(uint *)(param_2 + 0x1fc);
  cVar3 = *(char *)(param_1 + 0x107f);
  uVar8 = *(uint *)(param_1 + 0x1fc);
  local_1c0 = 0;
  local_1c4 = 0;
  if (param_3 != 0) {
    puVar13 = (undefined4 *)(param_1 + 0x2c8);
    puVar14 = local_1a8;
    for (iVar11 = 0x33; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar14 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
    }
    local_1c0 = uVar8 >> 8 & 1;
    local_1c4 = uVar7 >> 8 & 1;
    puVar13 = (undefined4 *)(param_2 + 0x2c8);
    puVar14 = local_d8;
    for (iVar11 = 0x33; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar14 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
    }
  }
  FUN_004a4ca0(param_1 + 0x6c4);
  FUN_004a4ca0(param_2 + 0x6c4);
  *(undefined4 *)(param_2 + 0xca4) = uVar5;
  *(undefined4 *)(param_1 + 0xca4) = uVar6;
  *(uint *)(param_1 + 0x1fc) =
       *(uint *)(param_1 + 0x1fc) ^ ((uVar7 >> 7 & 1) << 7 ^ *(uint *)(param_1 + 0x1fc)) & 0x80;
  *(uint *)(param_2 + 0x1fc) =
       *(uint *)(param_2 + 0x1fc) ^ ((uVar8 >> 7 & 1) << 7 ^ *(uint *)(param_2 + 0x1fc)) & 0x80;
  *(undefined4 *)(param_1 + 0xda8) = *(undefined4 *)(param_2 + 0xda8);
  *(undefined4 *)(param_2 + 0xda8) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x7fc);
  *(undefined4 *)(param_1 + 0x7fc) = *(undefined4 *)(param_2 + 0x7fc);
  *(undefined4 *)(param_2 + 0x7fc) = uVar1;
  uVar10 = *(undefined1 *)(param_1 + 0x280);
  *(undefined1 *)(param_1 + 0x280) = *(undefined1 *)(param_2 + 0x280);
  *(undefined1 *)(param_2 + 0x280) = uVar10;
  uVar1 = *(undefined4 *)(param_1 + 0xdec);
  *(undefined4 *)(param_1 + 0xdec) = *(undefined4 *)(param_2 + 0xdec);
  *(undefined4 *)(param_2 + 0xdec) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x800);
  *(undefined4 *)(param_1 + 0x800) = *(undefined4 *)(param_2 + 0x800);
  *(undefined4 *)(param_2 + 0x800) = uVar1;
  FUN_00466820(param_1);
  FUN_00466820(param_2);
  uVar7 = *(uint *)(param_1 + 0x1f8);
  uVar8 = (-(uint)(param_3 != 0) & 0x10005) + 0x46f8;
  uVar12 = ~uVar8 & uVar7;
  *(uint *)(param_1 + 0x1f8) = uVar12;
  *(uint *)(param_1 + 0x1f8) = *(uint *)(param_2 + 0x1f8) & uVar8 | uVar12;
  *(uint *)(param_2 + 0x1f8) = ~uVar8 & *(uint *)(param_2 + 0x1f8) | uVar7 & uVar8 & uVar8;
  uVar1 = *(undefined4 *)(param_1 + 0xea8);
  *(undefined4 *)(param_1 + 0xea8) = *(undefined4 *)(param_2 + 0xea8);
  *(undefined4 *)(param_2 + 0xea8) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x1000);
  *(undefined4 *)(param_1 + 0x1000) = *(undefined4 *)(param_2 + 0x1000);
  *(undefined4 *)(param_2 + 0x1000) = uVar1;
  FUN_00415000(param_1);
  if (param_3 != 0) {
    if (*(char *)(param_1 + 0x280) != -1) {
      (&DAT_0093d7f0)[*(char *)(param_1 + 0x280)] = param_1;
    }
    if (*(char *)(param_2 + 0x280) != -1) {
      (&DAT_0093d7f0)[*(char *)(param_2 + 0x280)] = param_2;
    }
    goto LAB_00487aa0;
  }
  *(undefined4 *)(param_1 + 0xd60) = 0;
  *(undefined4 *)(param_1 + 0xda4) = _DAT_00802be8;
  *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xffe7ffff | 0x80;
  *(undefined4 *)(param_1 + 0xee4) = 0;
  *(undefined4 *)(param_1 + 0xee8) = 0;
  *(undefined4 *)(param_2 + 0xd60) = 0x40000000;
  uVar1 = _DAT_00802be8;
  *(uint *)(param_2 + 0xef0) = *(uint *)(param_2 + 0xef0) | 0x80;
  *(undefined4 *)(param_2 + 0xda4) = uVar1;
  FUN_0054a8d0(**(undefined4 **)(param_2 + 0xca4),2,0);
  if ((*(char *)(param_1 + 0x280) == -1) ||
     ((&DAT_0093d7f0)[*(char *)(param_1 + 0x280)] = param_1, *(int *)(param_1 + 0xcd0) != 0)) {
    uVar10 = *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xf4);
LAB_004879cc:
    *(undefined1 *)(param_1 + 0x107e) = uVar10;
  }
  else {
    uVar10 = DAT_00802bd4;
    if (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b160) goto LAB_004879cc;
  }
  if ((*(char *)(param_2 + 0x280) == -1) ||
     ((&DAT_0093d7f0)[*(char *)(param_2 + 0x280)] = param_2, *(int *)(param_2 + 0xcd0) != 0)) {
    uVar10 = *(undefined1 *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0xf4);
LAB_00487a16:
    *(undefined1 *)(param_2 + 0x107e) = uVar10;
  }
  else {
    uVar10 = DAT_00802bd4;
    if (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b160) goto LAB_00487a16;
  }
  bVar4 = *(byte *)(param_2 + 0x107e);
  *(char *)(param_2 + 0x107f) = cVar3;
  if ((int)(uint)bVar4 < (int)cVar3) {
    *(byte *)(param_2 + 0x107f) = bVar4;
  }
  if ((*(char *)(param_2 + 0x107f) == '\0') && (bVar4 != 0)) {
    *(undefined1 *)(param_2 + 0x107f) = 1;
  }
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b160) ||
     ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) {
    *(undefined1 *)(param_1 + 0x107f) = uVar2;
  }
  else if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x20) == 0) {
    *(undefined1 *)(param_1 + 0x107f) = *(undefined1 *)(param_1 + 0x107e);
  }
  else {
    *(undefined1 *)(param_1 + 0x107f) = *(undefined1 *)(param_1 + 0xe39);
  }
LAB_00487aa0:
  *(uint *)(param_2 + 0xef0) = *(uint *)(param_2 + 0xef0) & 0xffe7ffff;
  *(undefined4 *)(param_2 + 0xee4) = 0;
  *(undefined4 *)(param_2 + 0xee8) = 0;
  *(undefined4 *)(param_2 + 0x7c0) = 0x3f800000;
  if ((param_1 == DAT_0087a7c8) && (param_2 != DAT_0087a7cc)) {
    _DAT_0087a7d0 = 0;
    DAT_0087a7c8 = 0;
    DAT_0087a7cc = 0;
    DAT_0087a7d4 = 0;
  }
  if (param_3 != 0) {
    iVar11 = param_2 + 0x2c8;
    iVar9 = FUN_0052c790(iVar11,"JustBeenTakenOver");
    if (iVar9 != 0) {
      FUN_0052cc90(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_2,iVar11,iVar11,_DAT_00925018);
    }
    puVar13 = local_d8;
    puVar14 = (undefined4 *)(param_1 + 0x2c8);
    for (iVar11 = 0x33; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar14 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
    }
    puVar13 = local_1a8;
    puVar14 = (undefined4 *)(param_2 + 0x2c8);
    for (iVar11 = 0x33; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar14 = *puVar13;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
    }
    *(undefined1 *)(param_1 + 0x378) = local_f8;
    *(undefined1 *)(param_2 + 0x378) = local_28;
    FUN_00415000(param_1);
    *(uint *)(param_1 + 0x1fc) =
         *(uint *)(param_1 + 0x1fc) ^ (local_1c4 << 8 ^ *(uint *)(param_1 + 0x1fc)) & 0x100;
    *(uint *)(param_2 + 0x1fc) =
         *(uint *)(param_2 + 0x1fc) ^ (local_1c0 << 8 ^ *(uint *)(param_2 + 0x1fc)) & 0x100;
    FUN_004a25b0(param_1,0);
    FUN_0058ff10(param_1,0);
    FUN_0059cb00(param_1);
    FUN_0055e4e0(param_1 + 0x6c4);
    if ((*(byte *)(param_1 + 0xeec) & 0x10) == 0) {
      FUN_0058d8e0(param_1);
    }
    *(int *)(param_1 + 0xcd0) = param_2;
    *(int *)(param_2 + 0xcd0) = param_1;
    *(undefined4 *)(param_1 + 0xea4) = 0;
    *(undefined4 *)(param_2 + 0xea4) = 0;
    *(int *)(param_1 + 0xcd4) = param_2;
    *(undefined1 *)(param_1 + 0x7b5) = 0x3b;
    FUN_00487270();
    *(undefined4 *)(param_1 + 0xdd0) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x748) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x74c) = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x750) = *(undefined4 *)(param_1 + 100);
    if (param_4 != 0) {
      FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
    }
    if (0.0 < *(float *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0x28)) {
      *(float *)(param_2 + 0x6c) =
           *(float *)(param_2 + 0x6c) -
           *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x2c) * 0.5;
    }
  }
  return 1;
}

