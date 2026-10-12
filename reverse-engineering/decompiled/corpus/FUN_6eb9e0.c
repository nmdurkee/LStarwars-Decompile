/* Ghidra analysis pseudocode, not original source.
 * ev_0c181eace2d19d4182fe88edb7c380dbd0b0bf6e152acc5799b1564533e0f6fc
 * Entry: 0x6eb9e0; label: FUN_006eb9e0
 */

void FUN_006eb9e0(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  
  if ((DAT_029a9c44 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_006fc930();
    return;
  }
  FUN_006f6968((double)in_ST0);
  FUN_006eba38();
  return;
}

