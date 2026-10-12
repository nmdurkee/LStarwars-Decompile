/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x429300; label: FUN_00429300
 */

void FUN_00429300(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  undefined4 uVar15;
  
  sVar3 = *(short *)(param_1 + 0x1064);
  iVar4 = *(int *)(param_1 + 0xcbc);
  if ((sVar3 == DAT_007f17b8) || (sVar3 == DAT_007f180c)) {
    if (param_2 != 0) {
      iVar14 = FUN_004cc9a0((int)sVar3,1);
      *(int *)(param_1 + 0xcbc) = iVar14;
      if (iVar14 != 0) goto LAB_0042936f;
      sVar3 = *(short *)(param_1 + 0x1064);
    }
    uVar15 = FUN_004cca00((int)sVar3);
    *(undefined4 *)(param_1 + 0xcbc) = uVar15;
  }
  else {
    *(undefined4 *)(param_1 + 0xcbc) = 0;
  }
LAB_0042936f:
  if (iVar4 != *(int *)(param_1 + 0xcbc)) {
    uVar1 = *(undefined1 *)(param_1 + 0x405);
    uVar15 = *(undefined4 *)(param_1 + 0x420);
    uVar5 = *(undefined4 *)(param_1 + 0x424);
    uVar6 = *(uint *)(param_1 + 0xef0);
    uVar7 = *(undefined4 *)(param_1 + 0x428);
    uVar8 = *(undefined4 *)(param_1 + 0x42c);
    uVar9 = *(undefined4 *)(param_1 + 0x430);
    uVar2 = *(undefined1 *)(param_1 + 0x404);
    uVar10 = *(undefined4 *)(param_1 + 0xf14);
    uVar11 = *(undefined4 *)(param_1 + 0x434);
    uVar12 = *(undefined4 *)(param_1 + 0xf08);
    uVar13 = *(undefined4 *)(param_1 + 0x4c0);
    FUN_0041b0a0(param_1);
    *(undefined4 *)(param_1 + 0x420) = uVar15;
    *(undefined4 *)(param_1 + 0x424) = uVar5;
    *(undefined1 *)(param_1 + 0x405) = uVar1;
    *(undefined4 *)(param_1 + 0x428) = uVar7;
    *(undefined4 *)(param_1 + 0x42c) = uVar8;
    *(undefined4 *)(param_1 + 0x430) = uVar9;
    *(undefined4 *)(param_1 + 0xf14) = uVar10;
    *(uint *)(param_1 + 0xef0) =
         *(uint *)(param_1 + 0xef0) ^
         ((uVar6 >> 0x15 & 1) << 0x15 ^ *(uint *)(param_1 + 0xef0)) & 0x200000;
    *(undefined1 *)(param_1 + 0x404) = uVar2;
    *(undefined4 *)(param_1 + 0x434) = uVar11;
    *(undefined4 *)(param_1 + 0xf08) = uVar12;
    *(undefined4 *)(param_1 + 0x4c0) = uVar13;
  }
  return;
}

