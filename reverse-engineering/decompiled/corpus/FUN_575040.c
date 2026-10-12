/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x575040; label: FUN_00575040
 */

void FUN_00575040(int param_1)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 < 0x20) {
      FUN_004f1f10(DAT_00951398 + 0x80,*(undefined4 *)(param_1 + 0x510));
      psVar2 = (short *)FUN_005d0690(*(undefined4 *)(DAT_009513b4 + 0x13c),DAT_00951398 + 0x80);
      iVar1 = DAT_00951398;
      *(short **)(DAT_00951398 + 0xf8) = psVar2;
      if ((psVar2 != (short *)0x0) && (*psVar2 != 2)) {
        *(undefined4 *)(iVar1 + 0xf8) = 0;
        *(undefined1 *)(iVar1 + 0x80) = 0;
      }
    }
  }
  return;
}

