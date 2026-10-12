/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42d180; label: FUN_0042d180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042d180(int param_1)

{
  undefined1 *puVar1;
  ushort *puVar2;
  int iVar3;
  
  if (0 < DAT_00951360) {
    puVar1 = &DAT_0086e0f5;
    puVar2 = (ushort *)(DAT_00951354 + 0x84);
    iVar3 = DAT_00951360;
    do {
      puVar1[-1] = 1;
      *puVar1 = 1;
      if (*puVar2 != 0) {
        *(float *)(puVar1 + 7) = (float)*puVar2 - 0.5;
      }
      if (param_1 != 0) {
        puVar1[6] = 1;
      }
      puVar2 = puVar2 + 0x4e;
      puVar1 = puVar1 + 0xc;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  DAT_008668c8._3_1_ = 1;
  if ((PTR_DAT_00802c54 != (undefined *)0x0) && (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94)
     ) {
    FUN_00478ae0(PTR_DAT_00802c54);
  }
  FUN_0042b080();
  return;
}

