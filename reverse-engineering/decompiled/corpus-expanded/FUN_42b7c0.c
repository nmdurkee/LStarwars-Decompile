/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42b7c0; label: FUN_0042b7c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042b7c0(void)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  float10 fVar7;
  
  if ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 2) != 0) {
    FUN_00509760();
  }
  piVar6 = &DAT_0093d7f0;
  do {
    iVar3 = *piVar6;
    if ((iVar3 != 0) && ((*(byte *)(iVar3 + 0xef3) & 1) == 0)) {
      FUN_0041b420(iVar3,1,0,1);
    }
    piVar6 = piVar6 + 1;
  } while ((int)piVar6 < 0x93d810);
  fVar7 = (float10)FUN_00499920();
  if (_DAT_0087b8b8 < (float)fVar7) {
    _DAT_0087b8b8 = (float)fVar7;
  }
  FUN_00499b60();
  FUN_0055e410();
  DAT_00951238 = -(uint)(*(int *)(PTR_DAT_00802c54 + 300) != 0) & DAT_00951230;
  DAT_00951244 = DAT_00951240;
  DAT_00951b80 = 0;
  DAT_0087658c = 0;
  piVar6 = &DAT_0093d7f0;
  do {
    if ((*piVar6 != 0) && (*(int *)(*piVar6 + 0x7fc) != 0)) {
      iVar3 = FUN_0046c690();
      *(undefined2 *)(*(int *)(*piVar6 + 0x7fc) + 8) = *(undefined2 *)(&DAT_007f8e08 + iVar3 * 0x38)
      ;
      if ((&DAT_007f8e05)[iVar3 * 0x38] != '\0') {
        iVar2 = *(int *)(*piVar6 + 0x7fc);
        iVar4 = FUN_0054fa60();
        psVar1 = (short *)(iVar2 + 8);
        *psVar1 = *psVar1 + (short)(iVar4 / ((int)(0xffff / (ulonglong)
                                                            (longlong)
                                                            (int)(uint)(byte)(&DAT_007f8e05)
                                                                             [iVar3 * 0x38]) + 1));
      }
    }
    piVar6 = piVar6 + 1;
  } while ((int)piVar6 < 0x93d7f8);
  iVar3 = 0;
  if (0 < DAT_0093d500) {
    puVar5 = (uint *)(DAT_0093d504 + 0xef0);
    do {
      if (((puVar5[-0x33d] & 1) != 0) && ((puVar5[-0x33d] & 0x1000) != 0)) {
        *puVar5 = *puVar5 | 0x80;
      }
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 0x436;
    } while (iVar3 < DAT_0093d500);
  }
  FUN_00564ca0();
  FUN_00419e00(0);
  return;
}

