/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f62f0; label: FUN_004f62f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f62f0(void)

{
  ushort uVar1;
  byte bVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  byte bVar6;
  int in_EDX;
  int extraout_EDX;
  uint uVar7;
  
  _DAT_00916fdc = 0;
  _DAT_00916fe0 = 0;
  _DAT_00916fe4 = 0;
  _DAT_00916fe8 = 0;
  _DAT_00916fec = 0;
  _DAT_00916ff0 = 0;
  _DAT_00916ff4 = 0;
  _DAT_00916ff8 = 0;
  DAT_00916ffc = 0;
  if (in_EDX < DAT_00915fa8) {
    iVar3 = DAT_0091ef38;
    if (0xf < DAT_0091ef38) {
      iVar3 = 0x10;
    }
    *(short *)(&DAT_00916fdc + iVar3 * 2) = *(short *)(&DAT_00916fdc + iVar3 * 2) + 1;
  }
  else {
    DAT_0091ef38 = DAT_0091ef38 + 1;
    FUN_004f6290(*(undefined2 *)(&DAT_02982740 + in_EDX * 2));
    FUN_004f6290(*(undefined2 *)(&DAT_02982f40 + extraout_EDX * 2));
    DAT_0091ef38 = DAT_0091ef38 + -1;
  }
  iVar3 = 0;
  bVar6 = 0;
  puVar4 = (ushort *)&DAT_00916ffc;
  do {
    uVar1 = *puVar4;
    bVar2 = bVar6 & 0x1f;
    puVar4 = puVar4 + -1;
    bVar6 = bVar6 + 1;
    iVar3 = iVar3 + ((uint)uVar1 << bVar2);
  } while (0x916fdc < (int)puVar4);
  if (iVar3 != 0x10000) {
    iVar3 = iVar3 + -0x10000;
    do {
      DAT_00916ffc = DAT_00916ffc + -1;
      iVar5 = 0xf;
      do {
        if (*(short *)(&DAT_00916fdc + iVar5 * 2) != 0) {
          *(short *)(&DAT_00916fdc + iVar5 * 2) = *(short *)(&DAT_00916fdc + iVar5 * 2) + -1;
          (&DAT_00916fde)[iVar5] = (&DAT_00916fde)[iVar5] + 2;
          break;
        }
        iVar5 = iVar5 + -1;
      } while (0 < iVar5);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  iVar3 = DAT_00916fd4;
  iVar5 = 0x10;
  do {
    uVar7 = (uint)*(ushort *)(&DAT_00916fdc + iVar5 * 2);
    while (uVar7 = uVar7 - 1, -1 < (int)uVar7) {
      uVar1 = *DAT_0090fba0;
      DAT_0090fba0 = DAT_0090fba0 + 1;
      *(char *)((uint)uVar1 + iVar3) = (char)iVar5;
    }
    iVar5 = iVar5 + -1;
  } while (0 < iVar5);
  return;
}

