/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41bc20; label: FUN_0041bc20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041bc20(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  int iVar23;
  
  if ((((param_2 == param_3) || (param_2 < 0)) || (DAT_0093b278 <= param_2)) ||
     (*(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_2 * 2) == -1)) {
    return 0;
  }
  FUN_004c0c80(PTR_DAT_00802c54,param_1);
  if (DAT_00951288 == 0) {
    FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x5c,param_1 + 0x80);
  }
  cVar1 = *(char *)(param_1 + 0x7b5);
  uVar6 = *(undefined2 *)(param_1 + 0xe18);
  uVar8 = *(uint *)(*(int *)(param_1 + 0x54) + 4);
  FUN_00433aa0(param_1,0,1);
  FUN_00597350(param_1);
  *(short *)(param_1 + 0x1064) = (short)param_2;
  uVar9 = *(uint *)(param_1 + 0x1fc);
  *(int *)(param_1 + 0x50) =
       *(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_2 * 2) * 0x54 +
       *(int *)(DAT_029130e4 + 0x18);
  uVar10 = *(undefined4 *)(param_1 + 0x68);
  uVar11 = *(undefined4 *)(param_1 + 0x70);
  *(int *)(param_1 + 0x54) = param_2 * 0x4c + *(int *)(DAT_029130e4 + 0x20);
  uVar12 = *(undefined4 *)(param_1 + 0x6c);
  uVar2 = *(undefined1 *)(param_1 + 0x107f);
  uVar3 = *(undefined1 *)(param_1 + 0x107e);
  *(undefined4 *)(param_1 + 0xcd4) = 0;
  uVar22 = FUN_004cca00(param_2);
  uVar4 = *(undefined1 *)(param_1 + 0x404);
  uVar13 = *(undefined4 *)(param_1 + 0xf14);
  uVar14 = *(uint *)(param_1 + 0xef0);
  *(undefined4 *)(param_1 + 0xcbc) = uVar22;
  uVar5 = *(undefined1 *)(param_1 + 0x405);
  uVar22 = *(undefined4 *)(param_1 + 0x420);
  uVar15 = *(undefined4 *)(param_1 + 0x424);
  uVar16 = *(undefined4 *)(param_1 + 0x428);
  uVar17 = *(undefined4 *)(param_1 + 0x42c);
  uVar18 = *(undefined4 *)(param_1 + 0x430);
  uVar19 = *(undefined4 *)(param_1 + 0x434);
  uVar20 = *(undefined4 *)(param_1 + 0xf08);
  uVar21 = *(undefined4 *)(param_1 + 0x4c0);
  FUN_0041b0a0(param_1);
  *(undefined4 *)(param_1 + 0xf14) = uVar13;
  *(uint *)(param_1 + 0xef0) =
       *(uint *)(param_1 + 0xef0) ^
       ((uVar14 >> 0x15 & 1) << 0x15 ^ *(uint *)(param_1 + 0xef0)) & 0x200000;
  *(undefined1 *)(param_1 + 0x404) = uVar4;
  *(undefined1 *)(param_1 + 0x405) = uVar5;
  *(undefined4 *)(param_1 + 0xff8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x420) = uVar22;
  *(undefined4 *)(param_1 + 0x424) = uVar15;
  *(undefined4 *)(param_1 + 0x428) = uVar16;
  *(undefined4 *)(param_1 + 0x42c) = uVar17;
  *(undefined4 *)(param_1 + 0x430) = uVar18;
  *(undefined4 *)(param_1 + 0xf08) = uVar20;
  *(undefined4 *)(param_1 + 0x434) = uVar19;
  *(undefined4 *)(param_1 + 0x4c0) = uVar21;
  *(undefined4 *)(param_1 + 0x1048) =
       *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xa0);
  *(undefined1 *)(param_1 + 0xe38) =
       *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xf5);
  *(undefined1 *)(param_1 + 0xe39) = 4;
  FUN_0055e4a0(param_1,1);
  FUN_0041af70(param_1);
  FUN_00414ca0(param_1);
  FUN_0062e650(param_1 + 8,0xffffffff);
  FUN_0055e4e0(param_1 + 0x6c4);
  FUN_0055cd20(param_1);
  FUN_0055cc40(param_1);
  *(undefined4 *)(param_1 + 0xd60) = 0x40000000;
  uVar13 = _DAT_00802be8;
  *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) | 0x80;
  *(undefined4 *)(param_1 + 0xda4) = uVar13;
  FUN_005728a0(param_1);
  iVar23 = FUN_00572660(param_1,1);
  FUN_00466820(param_1);
  *(undefined4 *)(param_1 + 0xee4) = 0;
  *(undefined4 *)(param_1 + 0xee8) = 0;
  *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xfff7ffff;
  *(uint *)(param_1 + 0x1fc) =
       *(uint *)(param_1 + 0x1fc) ^
       ((uVar9 >> 0xd & 1) << 0xd ^ *(uint *)(param_1 + 0x1fc)) & 0x2000;
  *(undefined1 *)(param_1 + 0x107f) = uVar2;
  *(undefined1 *)(param_1 + 0x107e) = uVar3;
  FUN_0062e690(param_1 + 2000,0xffffffff);
  if ((*(byte *)(param_1 + 0xe22) & 1) == 0) {
    uVar13 = 0;
  }
  else {
    uVar13 = 0x3f800000;
  }
  *(undefined4 *)(param_1 + 0xd3c) = uVar13;
  *(undefined1 *)(param_1 + 0xe33) = 0;
  if (iVar23 == 0) {
    *(undefined4 *)(param_1 + 0x6c) = uVar12;
  }
  else {
    *(undefined4 *)(param_1 + 0xd24) = 0x3e4ccccd;
  }
  if (cVar1 == '3') {
    iVar23 = FUN_004a74e0(param_1,0);
    if (iVar23 != 0) {
      *(undefined4 *)(param_1 + 0x68) = uVar10;
      *(undefined4 *)(param_1 + 0x70) = uVar11;
    }
  }
  if (*(float *)(param_1 + 0x6c) == 0.0) {
    *(undefined4 *)(param_1 + 0x6c) = 0xbdcccccd;
  }
  if (((uVar8 & 0x2000) != 0) && ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) != 0)) {
    *(undefined2 *)(param_1 + 0xe18) = uVar6;
  }
  sVar7 = *(short *)(param_1 + 0x1064);
  iVar23 = sVar7 * 0x4c;
  *(undefined4 *)(param_1 + 0x230) =
       *(undefined4 *)(*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + iVar23) + 100);
  *(undefined4 *)(param_1 + 0x234) =
       *(undefined4 *)(*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + iVar23) + 0x68);
  *(undefined4 *)(param_1 + 0x238) =
       *(undefined4 *)(*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + iVar23) + 0x6c);
  *(undefined4 *)(param_1 + 0x23c) =
       *(undefined4 *)(*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + iVar23) + 0x70);
  *(uint *)(param_1 + 0xef4) =
       *(uint *)(param_1 + 0xef4) ^
       (*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) >> 6 ^
       *(uint *)(param_1 + 0xef4)) & 0x800;
  if (sVar7 == DAT_007f18d0) {
    FUN_0041a9c0();
    FUN_00414ce0();
    return 1;
  }
  if (sVar7 == DAT_007f18d4) {
    FUN_0041ab00();
    FUN_00414ce0();
    return 1;
  }
  if (sVar7 == DAT_007f18d8) {
    FUN_0041ab90();
    FUN_00414ce0();
    return 1;
  }
  if (sVar7 == DAT_007f19dc) {
    FUN_0041ac40();
    FUN_00414ce0();
    return 1;
  }
  if (sVar7 == DAT_007f18dc) {
    iVar23 = FUN_0054fa60();
    *(uint *)(param_1 + 0xef0) =
         *(uint *)(param_1 + 0xef0) ^
         ((uint)(iVar23 < 0x8000) << 9 ^ *(uint *)(param_1 + 0xef0)) & 0x200;
  }
  FUN_00414ce0();
  return 1;
}

