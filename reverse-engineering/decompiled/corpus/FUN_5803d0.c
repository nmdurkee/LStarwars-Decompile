/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x5803d0; label: FUN_005803d0
 */

void FUN_005803d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004f7fb0(param_1);
  if ((iVar1 != 0) && (DAT_00951cb8 != 0)) {
    iVar2 = FUN_005cf5b0(DAT_00951cb8,DAT_00951cc0 + 0x74,*(undefined4 *)(param_1 + 0x510),1);
    iVar1 = DAT_00951cc0;
    if (iVar2 != 0) {
      *(undefined4 *)(DAT_00951cc0 + 0x8c) = *(undefined4 *)(DAT_00951cc0 + 0x74);
      *(undefined4 *)(iVar1 + 0x90) = *(undefined4 *)(iVar1 + 0x78);
      *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(iVar1 + 0x7c);
    }
  }
  return;
}

