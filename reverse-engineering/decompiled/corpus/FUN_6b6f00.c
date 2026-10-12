/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b6f00; label: FUN_006b6f00
 */

float10 FUN_006b6f00(float param_1)

{
  int iVar1;
  float fVar2;
  
  fVar2 = param_1 * 64.0 - 32.0;
  iVar1 = (int)ROUND(fVar2 - 0.5);
  return (float10)((fVar2 - (float)iVar1) *
                   (*(float *)(&DAT_0081f6b4 + iVar1 * 4) - *(float *)(&DAT_0081f6b0 + iVar1 * 4)) +
                  *(float *)(&DAT_0081f6b0 + iVar1 * 4));
}

