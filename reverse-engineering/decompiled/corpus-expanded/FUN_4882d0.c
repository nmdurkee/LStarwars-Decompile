/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x4882d0; label: FUN_004882d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004882d0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float10 fVar9;
  undefined4 local_1a8 [44];
  undefined1 local_f8;
  undefined4 local_d8 [44];
  undefined1 local_28;
  
  iVar6 = *(int *)(param_1 + 0xcd0);
  if (iVar6 != 0) {
    iVar3 = param_1;
    if (*(char *)(param_1 + 0x7b5) == ';') {
      iVar3 = iVar6;
      iVar6 = param_1;
    }
    puVar7 = (undefined4 *)(iVar6 + 0x2c8);
    puVar8 = local_1a8;
    for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    puVar7 = (undefined4 *)(iVar3 + 0x2c8);
    puVar8 = local_d8;
    for (iVar4 = 0x33; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    uVar1 = *(uint *)(iVar6 + 0x1fc);
    uVar2 = *(uint *)(iVar3 + 0x1fc);
    if (((*(byte *)(iVar6 + 0xef4) & 2) != 0) ||
       (iVar4 = FUN_004876a0(iVar6,iVar3,1,0,0), iVar4 != 0)) {
      iVar4 = FUN_00486f20(*(undefined4 *)(*(int *)(iVar6 + 0x54) + 0xc),
                           *(undefined4 *)(*(int *)(iVar3 + 0x54) + 0xc));
      puVar7 = local_d8;
      puVar8 = (undefined4 *)(iVar6 + 0x2c8);
      for (iVar5 = 0x33; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      puVar7 = local_1a8;
      puVar8 = (undefined4 *)(iVar4 + 0x2c8);
      for (iVar5 = 0x33; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      *(undefined1 *)(iVar6 + 0x378) = local_f8;
      *(undefined1 *)(iVar4 + 0x378) = local_28;
      FUN_00415000(iVar4);
      *(uint *)(iVar6 + 0x1fc) =
           *(uint *)(iVar6 + 0x1fc) ^ ((uVar2 >> 8 & 1) << 8 ^ *(uint *)(iVar6 + 0x1fc)) & 0x100;
      *(uint *)(iVar3 + 0x1fc) =
           *(uint *)(iVar3 + 0x1fc) ^ ((uVar1 >> 8 & 1) << 8 ^ *(uint *)(iVar3 + 0x1fc)) & 0x100;
      if (*(int *)(iVar6 + 0xcd0) != 0) {
        FUN_004871a0(*(int *)(iVar6 + 0xcd0),iVar6 + 0x5c);
        iVar4 = *(int *)(iVar6 + 0xcd0);
        *(undefined2 *)(iVar6 + 0x278) = 0;
        *(undefined2 *)(iVar6 + 0x27c) = 0;
        *(undefined2 *)(iVar6 + 0x27a) = *(undefined2 *)(iVar4 + 0x58);
        *(undefined2 *)(iVar6 + 0x58) = *(undefined2 *)(iVar4 + 0x58);
        *(undefined2 *)(iVar6 + 0x5a) = *(undefined2 *)(iVar4 + 0x58);
      }
      FUN_0055d2b0(iVar6);
      *(undefined4 *)(iVar6 + 0xcd0) = 0;
      *(undefined1 *)(iVar6 + 0x7b5) = 0xff;
      if ((*(short *)(iVar3 + 0x1064) == DAT_007f1914) &&
         (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234)) {
        fVar9 = (float10)FUN_004c99b0(iVar6 + 0x5c,&DAT_007fa574);
        FUN_00561e20(iVar6,&DAT_007fa574,0,(float)fVar9 * _DAT_007fa56c,(float)fVar9 * _DAT_007fa570
                     ,0);
        FUN_0054a3e0(PTR_DAT_008021b4,0x40000000,0,1);
      }
      else {
        FUN_005a01f0(iVar6,iVar3);
      }
      iVar4 = *(int *)(*(int *)(iVar3 + 0x54) + 0x24);
      if (*(float *)(iVar4 + 0x28) <= 0.0) {
        if ((*(uint *)(iVar4 + 0x94) & 0x20000) != 0) {
          FUN_005a0320(iVar3,iVar6);
        }
      }
      else {
        *(float *)(iVar3 + 0x6c) = *(float *)(iVar3 + 0x6c) - *(float *)(iVar6 + 0x6c) * 0.5;
      }
      *(undefined4 *)(iVar3 + 0xcd0) = 0;
      *(uint *)(iVar6 + 0xe20) = *(uint *)(iVar6 + 0xe20) & 0x7fffffff;
      *(uint *)(iVar3 + 0xe20) = *(uint *)(iVar3 + 0xe20) & 0x7fffffff;
      *(ushort *)(iVar6 + 0x42e) = *(ushort *)(iVar6 + 0x42e) & 0xfffe;
      *(undefined4 *)(iVar3 + 0x10bc) = *(undefined4 *)(iVar3 + 0x5c);
      *(undefined4 *)(iVar3 + 0x10c0) = *(undefined4 *)(iVar3 + 0x60);
      *(undefined4 *)(iVar3 + 0x10c4) = *(undefined4 *)(iVar3 + 100);
      if ((*(char *)(iVar6 + 0x280) != -1) || (*(char *)(iVar3 + 0x280) != -1)) {
        FUN_0054a3e0(PTR_DAT_008021b4,0x3e99999a,0,1);
      }
      iVar4 = iVar6 + 0x2c8;
      iVar5 = FUN_0052c790(iVar4,"ReleasedTakeOver");
      if (iVar5 != 0) {
        FUN_0052cc90(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar6,iVar4,iVar4,_DAT_00925018);
      }
      iVar6 = iVar3 + 0x2c8;
      iVar4 = FUN_0052c790(iVar6,"ReleasedTakeOver");
      if (iVar4 != 0) {
        FUN_0052cc90(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar3,iVar6,iVar6,_DAT_00925018);
      }
    }
  }
  return;
}

