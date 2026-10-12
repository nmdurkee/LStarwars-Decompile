/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54e980; label: FUN_0054e980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054e980(void)

{
  float fVar1;
  int unaff_ESI;
  float10 fVar2;
  
  FUN_00561ba0();
  *(uint *)(unaff_ESI + 0xe24) = *(uint *)(unaff_ESI + 0xe24) | 0x1000;
  FUN_00547930(0x45,unaff_ESI + 0x80,0,0);
  if ((*(byte *)(unaff_ESI + 0x1fc) & 0x80) != 0) {
    FUN_00576960(DAT_00803994);
  }
  if (((*(char *)(*(int *)(unaff_ESI + 0x798) + 0x1c) == '\0') &&
      (*(char *)(unaff_ESI + 0x7b3) == '\x01')) &&
     (fVar1 = (*(float *)(*(int *)(unaff_ESI + 0x798) + 0x14) + 0.1) - *(float *)(unaff_ESI + 0x1a0)
     , 0.0 < fVar1)) {
    fVar2 = (float10)FUN_005c0240(*(float *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x24) *
                                  -2.0 * fVar1);
    if (*(float *)(unaff_ESI + 0x6c) < (float)fVar2) {
      *(float *)(unaff_ESI + 0x6c) = (float)fVar2;
      return;
    }
  }
  return;
}

