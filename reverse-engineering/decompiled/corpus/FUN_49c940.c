/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49c940; label: FUN_0049c940
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049c940(void)

{
  float fVar1;
  float *pfVar2;
  int unaff_ESI;
  bool bVar3;
  float10 fVar4;
  
  if (*(char *)(unaff_ESI + 0x7b5) != '?') {
    return;
  }
  fVar1 = *(float *)(unaff_ESI + 0x77c) - _DAT_00925018;
  *(float *)(unaff_ESI + 0x77c) = fVar1;
  if (0.0 < fVar1) {
    pfVar2 = (float *)FUN_0062f150(unaff_ESI + 8,(int)*(short *)(unaff_ESI + 0x7aa),1,0);
    if (pfVar2 == (float *)0x0) {
      return;
    }
    fVar4 = (float10)FUN_0062f1f0(*(undefined4 *)(unaff_ESI + 0x50),
                                  (int)*(short *)(unaff_ESI + 0x7aa),0);
    if ((float)fVar4 < 1.0) {
      return;
    }
    bVar3 = (float)fVar4 <= *pfVar2;
  }
  else {
    bVar3 = (*(byte *)(unaff_ESI + 0x7bc) & 0x40) == 0;
    *(undefined1 *)(unaff_ESI + 0x7b5) = 0xff;
  }
  if (!bVar3) {
    return;
  }
  if (*(int *)(unaff_ESI + 0x790) != 0) {
    FUN_004364e0(*(int *)(unaff_ESI + 0x790),2,0);
  }
  *(uint *)(unaff_ESI + 0xe24) = *(uint *)(unaff_ESI + 0xe24) & 0xfffffffe;
  *(uint *)(unaff_ESI + 0x7bc) = *(uint *)(unaff_ESI + 0x7bc) | 0x40;
  return;
}

