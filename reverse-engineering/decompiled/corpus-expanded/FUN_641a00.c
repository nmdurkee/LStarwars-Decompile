/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x641a00; label: FUN_00641a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00641a00(void)

{
  int iVar1;
  float10 fVar2;
  
  FUN_005d0a40(1);
  FUN_005d0880(2);
  if (DAT_029139b0 == 0) {
    fVar2 = (float10)_DAT_029134c8;
  }
  else {
    fVar2 = (float10)FUN_005becc0(&DAT_029134a4,DAT_029139ac + 0x30,0);
    fVar2 = fVar2 - (float10)1.0;
  }
  iVar1 = DAT_029139ac;
  *(float *)(DAT_029139ac + 0x48) = (float)fVar2;
  *(undefined4 *)(iVar1 + 0x4c) = _DAT_029134c4;
  FUN_00621140();
  if (DAT_0291397c == 0) {
    FUN_00641980();
    FUN_0063c810();
    FUN_0063d0f0();
    if (DAT_029139a0 != 0) {
      FUN_005d0fe0(DAT_009738b8,_DAT_0080fe00,_DAT_0080fe00);
      FUN_00626b50(DAT_029137ac);
    }
    if (DAT_029139a4 != 0) {
      FUN_00626b50(DAT_029137b0);
      FUN_005d0a70();
      FUN_005d08c0();
      return;
    }
  }
  else if (DAT_0291397c == 2) {
    FUN_0063ced0();
    FUN_0063c810();
    FUN_0063d8b0();
    if (DAT_029139a0 != 0) {
      FUN_00626b50(DAT_0291353c);
      FUN_005d0a70();
      FUN_005d08c0();
      return;
    }
  }
  else if (DAT_0291397c == 1) {
    FUN_0063c810();
    FUN_0063db30();
    FUN_0063cf30();
    if (DAT_02913954 != 0) {
      FUN_00626b50(DAT_02913954);
    }
  }
  FUN_005d0a70();
  FUN_005d08c0();
  return;
}

