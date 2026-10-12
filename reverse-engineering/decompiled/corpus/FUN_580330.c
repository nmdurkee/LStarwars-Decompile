/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x580330; label: FUN_00580330
 */

void FUN_00580330(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004f7fb0(param_1);
  if ((iVar1 != 0) && (DAT_00951cb8 != 0)) {
    iVar2 = FUN_005cf5b0(DAT_00951cb8,DAT_00951cc0 + 0x68,*(undefined4 *)(param_1 + 0x510),1);
    iVar1 = DAT_00951cc0;
    if (iVar2 != 0) {
      *(undefined4 *)(DAT_00951cc0 + 0x80) = *(undefined4 *)(DAT_00951cc0 + 0x68);
      *(undefined4 *)(iVar1 + 0x84) = *(undefined4 *)(iVar1 + 0x6c);
      *(undefined4 *)(iVar1 + 0x88) = *(undefined4 *)(iVar1 + 0x70);
    }
  }
  return;
}

