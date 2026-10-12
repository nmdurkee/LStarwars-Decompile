/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x553500; label: FUN_00553500
 */

float10 FUN_00553500(undefined4 param_1)

{
  uint uVar1;
  float10 fVar2;
  
  FUN_0067a6d0();
  fVar2 = (float10)FUN_00673730(param_1,0,0x40a00000,0x40a00000,0xffffffff);
  if ((float)fVar2 != 2e+06) {
    uVar1 = FUN_0067a600();
    if ((uVar1 < 0x20) && (((&DAT_008034cc)[uVar1 * 0xc] & 2) != 0)) {
      return (float10)(float)fVar2;
    }
  }
  return (float10)2e+06;
}

