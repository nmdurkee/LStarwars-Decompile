/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x635660; label: FUN_00635660
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00635660(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (_DAT_02913970 == 0) {
    return 0xffffffff;
  }
  puVar2 = (undefined4 *)FUN_00547240(_DAT_02913970);
  if (puVar2 != (undefined4 *)0x0) {
    *(byte *)((int)puVar2 + 0x59) = *(byte *)((int)puVar2 + 0x59) & 0xfe;
    puVar2[2] = 0;
    puVar2[1] = 0;
    puVar1 = puVar2 + 3;
    *puVar2 = 0;
    puVar2[0xf] = 0x3f800000;
    puVar2[0x10] = 0x40000000;
    *(undefined1 *)(puVar2 + 0x16) = 2;
    *(undefined2 *)((int)puVar2 + 0x5e) = 0;
    *(undefined2 *)(puVar2 + 0x18) = 0;
    *(undefined2 *)((int)puVar2 + 0x5a) = 0;
    puVar2[9] = 0x3f800000;
    *(undefined2 *)(puVar2 + 0x17) = 0;
    puVar2[10] = 0x3f800000;
    *(undefined1 *)((int)puVar2 + 0x7a) = 0xff;
    puVar2[0xb] = 0x3f800000;
    *(undefined1 *)((int)puVar2 + 0x79) = 0xff;
    *(undefined1 *)((int)puVar2 + 0x7b) = 0;
    puVar2[0xc] = 0x3f000000;
    puVar2[0x1f] = 0;
    puVar2[0xd] = 0x3f000000;
    puVar2[0xe] = 0x3f000000;
    puVar2[0x11] = 0x3dcccccd;
    puVar2[0x12] = 0x3dcccccd;
    puVar2[0x13] = 0x3dcccccd;
    puVar2[0x14] = 0x3dcccccd;
    puVar2[0x15] = 0;
    *puVar1 = 0;
    puVar2[4] = 0;
    puVar2[0x19] = 0;
    puVar2[5] = 0x3f800000;
    puVar2[0x1b] = 0x3f800000;
    FUN_005b35a0(puVar1,puVar1,0);
    FUN_005b3620(puVar1,puVar1,(int)*(short *)(puVar2 + 0x17));
    *(short *)((int)puVar2 + 0x6a) = DAT_0080fdfc;
    DAT_0080fdfc = DAT_0080fdfc + 1;
    if (DAT_0080fdfc == 0) {
      DAT_0080fdfc = 1;
    }
    _DAT_02913978 = _DAT_02913978 + 1;
    return (uint)*(ushort *)(puVar2 + -1);
  }
  return 0xffffffff;
}

