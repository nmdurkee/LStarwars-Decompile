/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x4148a0; label: FUN_004148a0
 */

void FUN_004148a0(int param_1)

{
  ushort *puVar1;
  undefined4 uVar2;
  undefined1 extraout_AH;
  int iVar3;
  
  *(byte *)(param_1 + 0x101) = *(byte *)(param_1 + 0x101) & 0xfe;
  *(undefined4 *)(param_1 + 0x660) = 0;
  *(undefined4 *)(param_1 + 0x684) = 0;
  *(undefined2 *)(param_1 + 0x754) = 0;
  *(undefined2 *)(param_1 + 0x756) = 0;
  *(undefined2 *)(param_1 + 0x758) = 0;
  FUN_0055e4e0(param_1);
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 0xc) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 0x14) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 0x18) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 0x1c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 0x20) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 0x40) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 0x44) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 0x48) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 0x4c) = 0;
  puVar1 = (ushort *)(*(int *)(param_1 + 0x5e0) + 0x5a);
  *puVar1 = *puVar1 & 0xfffd;
  puVar1 = (ushort *)(*(int *)(param_1 + 0x5e0) + 0x5a);
  *puVar1 = *puVar1 & 0xfffb;
  puVar1 = (ushort *)(*(int *)(param_1 + 0x5e0) + 0x5a);
  *puVar1 = *puVar1 & 0xffef;
  *(uint *)(param_1 + 0x75c) = *(uint *)(param_1 + 0x75c) & 0xfffffbff;
  *(undefined4 *)(param_1 + 0x65c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5e0) + 0x54) = 0;
  FUN_00589f60(param_1);
  *(undefined4 *)(param_1 + 0x614) = 0;
  *(undefined4 *)(param_1 + 0x618) = 0;
  *(undefined4 *)(param_1 + 0x61c) = 0;
  *(undefined4 *)(param_1 + 0x620) = 0;
  *(undefined4 *)(param_1 + 0x624) = 0;
  *(undefined4 *)(param_1 + 0x628) = 0;
  *(undefined4 *)(param_1 + 0x62c) = 0;
  *(undefined4 *)(param_1 + 0x630) = 0;
  *(undefined4 *)(param_1 + 0x6b8) = 0;
  *(undefined4 *)(param_1 + 0x6d8) = 0;
  FUN_004a4ca0(param_1);
  *(uint *)(param_1 + 0x75c) = *(uint *)(param_1 + 0x75c) & 0xfffffffe;
  *(undefined4 *)(param_1 + 0x6dc) = 0x49f42400;
  *(undefined4 *)(param_1 + 0x72c) = 0;
  *(undefined2 *)(param_1 + 0x75a) = 0xffff;
  *(undefined4 *)(param_1 + 0x6ec) = 0;
  *(undefined2 *)(param_1 + 0x74c) = 0xffff;
  iVar3 = FUN_0054fa60();
  *(ushort *)(param_1 + 0x74e) = ((0x7fff < iVar3) - 1 & 0xffd7) + 0x4f;
  iVar3 = 0;
  *(undefined4 *)(param_1 + 0x708) = 0;
  do {
    FUN_0054fa60();
    *(undefined1 *)(param_1 + 0x764 + iVar3) = extraout_AH;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  *(uint *)(param_1 + 0x760) = *(uint *)(param_1 + 0x760) & 0xfffff3fe;
  *(undefined4 *)(param_1 + 0x70c) = 0;
  *(undefined4 *)(param_1 + 0x604) = 0;
  *(undefined4 *)(param_1 + 0x710) = 0;
  *(undefined1 *)(param_1 + 0x77f) = 0xff;
  *(undefined4 *)(param_1 + 0x718) = 0;
  *(undefined4 *)(param_1 + 0x5d4) = DAT_00802500;
  *(undefined4 *)(param_1 + 0x5d8) = DAT_00802504;
  uVar2 = DAT_00802508;
  *(undefined4 *)(param_1 + 0x690) = 0;
  *(undefined4 *)(param_1 + 0x688) = 0;
  *(undefined4 *)(param_1 + 0x5dc) = uVar2;
  *(undefined4 *)(param_1 + 0x784) = 0;
  return;
}

