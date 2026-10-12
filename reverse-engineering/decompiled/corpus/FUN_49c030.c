/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x49c030; label: FUN_0049c030
 */

void FUN_0049c030(void)

{
  int unaff_ESI;
  
  if ((*(char *)(unaff_ESI + 0x7b5) == '=') &&
     (*(float *)(unaff_ESI + 0x784) + 0.5 < *(float *)(unaff_ESI + 0x77c))) {
    FUN_00437770();
    FUN_004364e0();
  }
  return;
}

