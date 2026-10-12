/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e3c30; label: FUN_004e3c30
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

