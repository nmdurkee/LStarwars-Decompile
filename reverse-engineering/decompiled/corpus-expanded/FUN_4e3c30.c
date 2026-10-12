/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e3c30; label: FUN_004e3c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e3c30(void)

{
  int iVar1;
  float10 fVar2;
  undefined1 local_c [12];
  
  if (DAT_0087b130 != 0) {
    iVar1 = FUN_0055e340(local_c,0);
    if (iVar1 != 0) {
      fVar2 = (float10)FUN_005b3cf0(local_c,&DAT_008000ac,0);
      if (fVar2 < (float10)100.0) {
        DAT_00802c60 = (int)*(short *)(DAT_0087b130 + 0x62);
      }
    }
  }
  return;
}

