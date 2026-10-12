/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4ea8e0; label: FUN_004ea8e0
 */

float10 FUN_004ea8e0(int param_1)

{
  char cVar1;
  
  if ((param_1 != 0) && ((cVar1 = *(char *)(param_1 + 0x280), cVar1 == '\0' || (cVar1 == '\x01'))))
  {
    if (*(float *)(&DAT_0088a648 + cVar1 * 4) < 0.0) {
      *(undefined4 *)(&DAT_0088a648 + cVar1 * 4) = 0;
    }
    return (float10)((3.0 - *(float *)(&DAT_0088a648 + *(char *)(param_1 + 0x280) * 4)) / 3.0);
  }
  return (float10)1;
}

