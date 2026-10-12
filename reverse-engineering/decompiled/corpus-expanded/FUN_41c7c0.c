/* Ghidra pseudocode, not original source.
 * ev_12b000564e8cba1f3519ff70f1088df218803466ba65b3333f742de5377565cf
 * Entry: 0x41c7c0; label: FUN_0041c7c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041c7c0(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 uVar9;
  
  _DAT_00855f80 = 0;
  if ((param_2 < 0) || (0x153 < param_2)) {
    return 0;
  }
  if (*(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_2 * 2) == -1) {
    return 0;
  }
  iVar5 = *(int *)(DAT_029130e4 + 0x20) + param_2 * 0x4c;
  *(int *)(param_1 + 0x54) = iVar5;
  *(undefined4 *)(param_1 + 0x1048) = *(undefined4 *)(*(int *)(iVar5 + 0x24) + 0xa0);
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  *(undefined2 *)(param_1 + 0x1070) = 0xffff;
  _memset((void *)(param_1 + 0x6c4),0,0x788);
  *(undefined1 *)(param_1 + 0x280) = 0xff;
  puVar6 = (undefined4 *)FUN_0055e300(param_1);
  uVar9 = puVar6[2];
  uVar3 = *puVar6;
  uVar4 = puVar6[1];
  *(uint *)(param_1 + 0x1f8) = *(uint *)(param_1 + 0x1f8) | 2;
  if (param_3 != 0) {
    *(uint *)(param_1 + 0x1f8) = *(uint *)(param_1 + 0x1f8) | 0x4000;
  }
  if ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x40000) == 0) {
    *(uint *)(param_1 + 0x1f8) = *(uint *)(param_1 + 0x1f8) | 0x40;
  }
  iVar5 = FUN_0054a5a0();
  *(int *)(param_1 + 0xca4) = iVar5;
  *(undefined1 *)(iVar5 + 0x25) = 1;
  uVar1 = *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xf4);
  *(undefined1 *)(param_1 + 0x107e) = uVar1;
  *(undefined1 *)(param_1 + 0x107f) = uVar1;
  FUN_004148a0(param_1 + 0x6c4,*(int *)(param_1 + 0x54));
  *(undefined4 *)(param_1 + 0x200) = DAT_0093b0cc;
  *(undefined4 *)(param_1 + 0x204) = DAT_0093b0d0;
  *(undefined4 *)(param_1 + 0x208) = DAT_0093b0d4;
  *(undefined1 *)(param_1 + 0xe38) =
       *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xf5);
  *(undefined1 *)(param_1 + 0xe39) = 4;
  *(short *)(param_1 + 0x1064) = (short)param_2;
  *(int *)(param_1 + 0x50) =
       *(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_2 * 2) * 0x54 +
       *(int *)(DAT_029130e4 + 0x18);
  uVar7 = FUN_004cca00((int)(short)param_2);
  *(undefined4 *)(param_1 + 0xcbc) = uVar7;
  *(undefined1 *)(param_1 + 0x400) = 0xff;
  FUN_00414ca0(param_1);
  puVar6 = (undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x100c) = 0x3f000000;
  *(undefined4 *)(param_1 + 0x8c) = uVar3;
  *puVar6 = uVar3;
  *(undefined4 *)(param_1 + 0x98) = uVar3;
  *(undefined4 *)(param_1 + 0x80) = uVar3;
  *(undefined4 *)(param_1 + 0x90) = uVar4;
  *(undefined4 *)(param_1 + 0x60) = uVar4;
  *(undefined4 *)(param_1 + 0x9c) = uVar4;
  *(undefined4 *)(param_1 + 0x84) = uVar4;
  *(undefined4 *)(param_1 + 0x94) = uVar9;
  *(undefined4 *)(param_1 + 100) = uVar9;
  *(undefined4 *)(param_1 + 0xa0) = uVar9;
  *(undefined4 *)(param_1 + 0x88) = uVar9;
  FUN_0055cd20(param_1);
  FUN_0055cc40(param_1);
  *(undefined2 *)(param_1 + 0x3e) = 1;
  if ((*(int *)(param_1 + 0x50) != 0) &&
     (piVar8 = *(int **)(*(int *)(param_1 + 0x50) + 0xc), piVar8[1] == 0)) {
    iVar5 = 0;
    do {
      if (*piVar8 != 0) {
        if (iVar5 < 0xe9) {
          *(short *)(param_1 + 0x3e) = (short)iVar5;
        }
        break;
      }
      iVar5 = iVar5 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar5 < 0xe9);
  }
  FUN_0062e650(param_1 + 8,(int)*(short *)(param_1 + 0x3e));
  uVar9 = FUN_00415050(param_1);
  FUN_004150d0(param_1,2,uVar9);
  FUN_00595840(puVar6,param_1 + 0x4d8,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab4));
  *(float *)(param_1 + 1000) = *(float *)(param_1 + 0x1dc) + _DAT_007f2374;
  FUN_0055d2b0(param_1);
  *(undefined4 *)(param_1 + 0x1b4) = *puVar6;
  *(undefined4 *)(param_1 + 0x10bc) = *puVar6;
  *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x10c0) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x10c4) = *(undefined4 *)(param_1 + 100);
  *(uint *)(param_1 + 0xef4) =
       *(uint *)(param_1 + 0xef4) ^
       (*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) >> 6 ^
       *(uint *)(param_1 + 0xef4)) & 0x800;
  sVar2 = *(short *)(param_1 + 0x1064);
  if (sVar2 == DAT_007f18d0) {
    FUN_0041a9c0();
    FUN_00414ce0();
    return 1;
  }
  if (sVar2 == DAT_007f18d4) {
    FUN_0041ab00();
    FUN_00414ce0();
    return 1;
  }
  if (sVar2 == DAT_007f18d8) {
    FUN_0041ab90();
    FUN_00414ce0();
    return 1;
  }
  if (sVar2 != DAT_007f19dc) {
    if (sVar2 == DAT_007f18dc) {
      iVar5 = FUN_0054fa60();
      *(uint *)(param_1 + 0xef0) =
           *(uint *)(param_1 + 0xef0) ^
           ((uint)(iVar5 < 0x8000) << 9 ^ *(uint *)(param_1 + 0xef0)) & 0x200;
    }
    FUN_00414ce0();
    return 1;
  }
  FUN_0041ac40();
  FUN_00414ce0();
  return 1;
}

