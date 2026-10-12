/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x573520; label: FUN_00573520
 */

int FUN_00573520(int param_1,int *param_2)

{
  int iVar1;
  short *psVar2;
  
  if (param_2 != (int *)0x0) {
    *param_2 = -1;
  }
  if (param_1 != 0) {
    iVar1 = 0;
    if (*(byte *)(param_1 + 0x7d) != 0) {
      psVar2 = (short *)(param_1 + 0x60);
      do {
        if ((*(uint *)(DAT_00951b78 + 100 + *psVar2 * 0x130) & 0x400) != 0) {
          if (param_2 != (int *)0x0) {
            *param_2 = (int)*(short *)(param_1 + 0x60 + iVar1 * 2);
          }
          return *(short *)(param_1 + 0x60 + iVar1 * 2) * 0x130 + DAT_00951b78;
        }
        iVar1 = iVar1 + 1;
        psVar2 = psVar2 + 1;
      } while (iVar1 < (int)(uint)*(byte *)(param_1 + 0x7d));
    }
  }
  return 0;
}

