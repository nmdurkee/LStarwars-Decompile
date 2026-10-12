/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x679080; label: FUN_00679080
 */

undefined4 FUN_00679080(float *param_1,undefined4 *param_2,int param_3,int param_4,int param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  ushort uVar5;
  ushort uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  ushort *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  
  iVar22 = DAT_0292186c;
  puVar9 = *(ushort **)(DAT_0292186c + 0x8c);
  uVar6 = *(ushort *)(*(int *)(DAT_0292fc68 + 0x68) + 0x48 + param_3 * 0x6c);
  uVar5 = *puVar9;
  while (0 < (short)uVar5) {
    if (puVar9[1] == uVar6) {
      uVar5 = (short)*puVar9 >> 0xf;
      *puVar9 = -((*puVar9 ^ uVar5) - uVar5);
    }
    uVar21 = (int)(short)*puVar9 >> 0x1f;
    iVar20 = ((int)(short)*puVar9 ^ uVar21) - uVar21;
    puVar1 = puVar9 + iVar20 * 2 + 2;
    puVar9 = puVar9 + iVar20 * 2 + 2;
    uVar5 = *puVar1;
  }
  if ((*(float *)(iVar22 + 0x20) < param_1[1]) && (param_1[1] < *(float *)(iVar22 + 0x20) + 0.01)) {
    *(float *)(iVar22 + 0x20) = param_1[1];
  }
  uVar2 = *(undefined4 *)(iVar22 + 0x98);
  uVar7 = *(undefined2 *)(iVar22 + 0x6c);
  uVar10 = *(undefined4 *)(iVar22 + 0x30);
  uVar3 = *(undefined4 *)(iVar22 + 0x9c);
  uVar4 = *(undefined1 *)(iVar22 + 0x88);
  uVar11 = *(undefined4 *)(iVar22 + 0x90);
  uVar12 = *(undefined4 *)(iVar22 + 0x2c);
  uVar8 = *(undefined2 *)(iVar22 + 0x8a);
  uVar13 = *(undefined4 *)(iVar22 + 0x28);
  uVar14 = *(undefined4 *)(iVar22 + 0xa8);
  *(float *)(iVar22 + 0x28) = *param_1 - *(float *)(iVar22 + 0x1c);
  uVar15 = *(undefined4 *)(iVar22 + 0xac);
  uVar16 = *(undefined4 *)(iVar22 + 0xb0);
  *(float *)(iVar22 + 0x2c) = param_1[1] - *(float *)(iVar22 + 0x20);
  uVar17 = *(undefined4 *)(iVar22 + 0xb4);
  uVar18 = *(undefined4 *)(iVar22 + 0xb8);
  uVar19 = *(undefined4 *)(iVar22 + 0xbc);
  *(float *)(iVar22 + 0x30) = param_1[2] - *(float *)(iVar22 + 0x24);
  FUN_0066f8f0();
  FUN_00675240();
  iVar22 = DAT_0292186c;
  if ((param_4 != 0) && (*(char *)(DAT_0292186c + 0x88) != '\0')) {
    FUN_00678410();
    iVar22 = DAT_0292186c;
    FUN_00678f60(*(undefined4 *)(DAT_0292186c + 0x40));
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(iVar22 + 0xa8);
      param_2[1] = *(undefined4 *)(iVar22 + 0xac);
      param_2[2] = *(undefined4 *)(iVar22 + 0xb0);
    }
    *param_1 = *(float *)(iVar22 + 0x1c);
    param_1[1] = *(float *)(iVar22 + 0x20);
    param_1[2] = *(float *)(iVar22 + 0x24);
  }
  *(undefined4 *)(iVar22 + 0x98) = uVar2;
  *(undefined4 *)(iVar22 + 0x9c) = uVar3;
  *(undefined4 *)(iVar22 + 0x28) = uVar13;
  *(undefined4 *)(iVar22 + 0x2c) = uVar12;
  *(undefined4 *)(iVar22 + 0x30) = uVar10;
  *(undefined2 *)(iVar22 + 0x6c) = uVar7;
  *(undefined4 *)(iVar22 + 0x90) = uVar11;
  *(undefined4 *)(iVar22 + 0xa8) = uVar14;
  *(undefined2 *)(iVar22 + 0x8a) = uVar8;
  *(undefined4 *)(iVar22 + 0xac) = uVar15;
  *(undefined4 *)(iVar22 + 0xb4) = uVar17;
  puVar9 = *(ushort **)(iVar22 + 0x8c);
  *(undefined4 *)(iVar22 + 0xb0) = uVar16;
  *(undefined4 *)(iVar22 + 0xb8) = uVar18;
  *(undefined4 *)(iVar22 + 0xbc) = uVar19;
  if ((*(byte *)(iVar22 + 0x88) < 0x10) || (param_5 == 0)) {
    uVar5 = *puVar9;
    while (uVar5 != 0) {
      if (puVar9[1] == uVar6) {
        uVar5 = (short)*puVar9 >> 0xf;
        *puVar9 = (*puVar9 ^ uVar5) - uVar5;
      }
      uVar21 = (int)(short)*puVar9 >> 0x1f;
      iVar20 = ((int)(short)*puVar9 ^ uVar21) - uVar21;
      puVar1 = puVar9 + iVar20 * 2 + 2;
      puVar9 = puVar9 + iVar20 * 2 + 2;
      uVar5 = *puVar1;
    }
  }
  if (*(char *)(iVar22 + 0x88) == '\0') {
    *(undefined1 *)(iVar22 + 0x88) = uVar4;
    return 1;
  }
  *(undefined1 *)(iVar22 + 0x88) = uVar4;
  return 0;
}

