/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x580470; label: FUN_00580470
 */

void FUN_00580470(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if ((iVar1 != 0) && (DAT_00951cb8 != 0)) {
    FUN_005cf5b0(DAT_00951cb8,DAT_00951cc0 + 0x98,*(undefined4 *)(param_1 + 0x510),1);
  }
  return;
}

