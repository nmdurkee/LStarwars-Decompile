/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b6eb0; label: FUN_006b6eb0
 */

float10 FUN_006b6eb0(float param_1)

{
  int iVar1;
  
  iVar1 = (int)ROUND(param_1 * 40.743668 - 0.5);
  return (float10)((param_1 * 40.743668 - (float)iVar1) *
                   (*(float *)(&DAT_0081f4ac + iVar1 * 4) - *(float *)(&DAT_0081f4a8 + iVar1 * 4)) +
                  *(float *)(&DAT_0081f4a8 + iVar1 * 4));
}

