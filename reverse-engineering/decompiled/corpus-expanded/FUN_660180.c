/* Ghidra pseudocode, not original source.
 * ev_3c91a6b80548833a29ecc2d389e89e55b74ab0261b3e94a742c4850371a9aab1
 * Entry: 0x660180; label: FUN_00660180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00660180(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  FUN_0065ee90();
  DAT_02961ffc = FUN_005e4d40(1);
  *(undefined4 *)(DAT_02961ffc + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_02961ffc + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_02961ffc + 0x5c) = 0x3f000000;
  *(uint *)(DAT_02961ffc + 0x40) = *(uint *)(DAT_02961ffc + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02961ffc + 0x40) = *(uint *)(DAT_02961ffc + 0x40) & 0xffff3fff;
  *(undefined4 *)(DAT_02961ffc + 0x70) = 0x3f800000;
  *(uint *)(DAT_02961ffc + 0x40) = *(uint *)(DAT_02961ffc + 0x40) & 0xfffffff0;
  FUN_005e4b00(DAT_02961ffc);
  DAT_02961fe8 = FUN_005e4d00(1);
  *(undefined4 *)(DAT_02961fe8 + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_02961fe8 + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_02961fe8 + 0x5c) = 0x3f000000;
  *(uint *)(DAT_02961fe8 + 0x40) = *(uint *)(DAT_02961fe8 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02961fe8 + 0x40) = *(uint *)(DAT_02961fe8 + 0x40) | 0xc000;
  *(undefined4 *)(DAT_02961fe8 + 0x70) = 0x3f800000;
  *(uint *)(DAT_02961fe8 + 0x40) = *(uint *)(DAT_02961fe8 + 0x40) & 0xfffffff0;
  FUN_005e4b00(DAT_02961fe8);
  piVar1 = DAT_029629d0;
  if (DAT_029629d0 == (int *)0x0) {
    DAT_02962a00 = FUN_004eef40(0xc0080,"d:\\projects\\legosagapc\\gameapi.saga\\gamelib\\edgra.c",
                                0xb0a);
    DAT_02962a04 = FUN_004eef40(0x24000,"d:\\projects\\legosagapc\\gameapi.saga\\gamelib\\edgra.c",
                                0xb0c);
  }
  else {
    DAT_02962a00 = *DAT_029629d0 + 0xfU & 0xfffffff0;
    uVar3 = *DAT_029629d0 + 0xfU & 0xfffffff0;
    *DAT_029629d0 = uVar3 + 0xc0080;
    DAT_02962a04 = uVar3 + 0xc0080;
    *piVar1 = (*piVar1 + 0xfU & 0xfffffff0) + 0x24000;
  }
  iVar4 = 0;
  if (0 < DAT_02962a08) {
    iVar2 = 0;
    do {
      *(undefined4 *)(iVar2 + 0x4c + DAT_02962a14) = 0;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 0x50;
    } while (iVar4 < DAT_02962a08);
    DAT_029629fc = DAT_02962a04;
    DAT_029211ec = 0xffffffff;
    return;
  }
  DAT_029629fc = DAT_02962a04;
  DAT_029211ec = 0xffffffff;
  return;
}

