/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x5804b0; label: FUN_005804b0
 */

void FUN_005804b0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_0062c3b0(*(undefined4 *)(DAT_00951cd4 + 0x134),*(undefined4 *)(param_1 + 0x510));
    *(undefined2 *)(DAT_00951cc0 + 0x2e) = uVar1;
  }
  return;
}

