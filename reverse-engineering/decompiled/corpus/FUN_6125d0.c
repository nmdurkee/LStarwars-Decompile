/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x6125d0; label: FUN_006125d0
 */

void FUN_006125d0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float fStack0000000c;
  int *in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  
  FUN_00617a00();
  if (0 < in_stack_00000018) {
    piVar4 = in_stack_00000010;
    do {
      iVar1 = *piVar4;
      iVar2 = FUN_006e6b90();
      iVar3 = FUN_006e6b90();
      fStack0000000c = (float)(iVar2 - iVar3 & 0xffff);
      if (0x7fff < (uint)fStack0000000c) {
        fStack0000000c = (float)((int)fStack0000000c - 0x10000);
      }
      fStack0000000c =
           (float)((float10)(float)((float10)(int)fStack0000000c * extraout_ST1) * extraout_ST0 +
                  (float10)*(float *)(iVar1 + 8));
      if (((*(ushort *)(in_ECX + 0xe) & 0x10) != 0) && (fStack0000000c <= *(float *)(in_ECX + 0x20))
         ) {
        fStack0000000c = *(float *)(in_ECX + 0x20);
      }
      if (((*(ushort *)(in_ECX + 0xe) & 0x20) != 0) && (*(float *)(in_ECX + 0x24) <= fStack0000000c)
         ) {
        fStack0000000c = *(float *)(in_ECX + 0x24);
      }
      in_stack_00000018 = in_stack_00000018 + -1;
      *(float *)((int)piVar4 + (in_stack_00000014 - (int)in_stack_00000010)) = fStack0000000c;
      piVar4 = piVar4 + 1;
    } while (in_stack_00000018 != 0);
  }
  return;
}

