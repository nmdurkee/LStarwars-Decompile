/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a25b0; label: FUN_004a25b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a25b0(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = *(char *)(param_1 + 0x7b5);
  if (cVar2 == '\b') {
    if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
      FUN_0054a3e0(PTR_DAT_008021b4,0x3f800000,0,1);
    }
    FUN_004a1f50(param_1,param_2);
  }
  else {
    if (cVar2 == '\x1b') {
      iVar3 = *(int *)(param_1 + 0x790);
      if (iVar3 != 0) {
        if (*(char *)(iVar3 + 0x7b5) == '\x1c') {
          *(undefined1 *)(iVar3 + 0x7b5) = 0xff;
          *(undefined4 *)(iVar3 + 0x790) = 0;
        }
        *(undefined4 *)(param_1 + 0x790) = 0;
      }
      FUN_004a1f50(param_1,param_2);
      return;
    }
    if (cVar2 == '\x1d') {
      if (*(int *)(param_1 + 0xcb8) != 0) {
        pbVar1 = (byte *)(*(int *)(param_1 + 0xcb8) + 0x206);
        *pbVar1 = *pbVar1 & ~('\x01' << (*(byte *)(param_1 + 0x280) & 0x1f));
        if (*(char *)(*(int *)(param_1 + 0xcb8) + 0x206) == '\0') {
          *(undefined1 *)(*(int *)(param_1 + 0xcb8) + 0x206) = 0xff;
        }
        *(undefined4 *)(*(int *)(param_1 + 0xcb8) + 0xe8) = _DAT_007fb084;
        *(undefined4 *)(param_1 + 0xcb8) = 0;
      }
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      FUN_004a1f50(param_1,param_2);
      return;
    }
  }
  return;
}

