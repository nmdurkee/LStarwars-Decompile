/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x580570; label: FUN_00580570
 */

void FUN_00580570(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_005719f0(*(undefined4 *)(DAT_00951cd4 + 0x138),*(undefined4 *)(param_1 + 0x510));
    *(undefined2 *)(DAT_00951cc0 + 0x38) = uVar1;
  }
  return;
}

