/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b6eb0; label: FUN_006b6eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006b6eb0(float param_1)

{
  int iVar1;
  
  iVar1 = (int)ROUND(param_1 * 40.743668 - 0.5);
  return (float10)((param_1 * 40.743668 - (float)iVar1) *
                   (*(float *)(&DAT_0081f4ac + iVar1 * 4) - *(float *)(&DAT_0081f4a8 + iVar1 * 4)) +
                  *(float *)(&DAT_0081f4a8 + iVar1 * 4));
}

