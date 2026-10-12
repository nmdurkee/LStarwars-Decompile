/* Ghidra analysis pseudocode, not original source.
 * ev_f77d0ac966a5398976b96c42189a5c308704a96dca5e44da054727b198f01d57
 * Entry: 0x42dff0; label: FUN_0042dff0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042dff0(int param_1)

{
  int iVar1;
  float10 fVar2;
  
  if (((DAT_0087b4d8 == 0) && (DAT_00951be0 == 0)) && (DAT_00855de0 == 0)) {
    iVar1 = *(int *)(param_1 + 0x128);
    if (((iVar1 == DAT_0087b08c) || (iVar1 == DAT_0087b090)) || (iVar1 == DAT_0087b094)) {
      iVar1 = FUN_004daa70(PTR_DAT_00802c54);
      if (iVar1 != 0) {
        return;
      }
    }
    else {
      if (iVar1 != DAT_0087b0a0) {
        return;
      }
      fVar2 = (float10)FUN_004dbb60(PTR_DAT_00802c54);
      if (fVar2 < (float10)0.0 == (fVar2 == (float10)0.0)) {
        return;
      }
    }
    FUN_005c51a0(0x3c23d70a,0xbcc49ba6,0x3ca3d70a);
    FUN_005ec620(DAT_0093b328,_DAT_007f5d4c);
  }
  return;
}

