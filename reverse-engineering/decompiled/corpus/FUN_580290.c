/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x580290; label: FUN_00580290
 */

void FUN_00580290(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"level");
    if (iVar1 == 0) {
      DAT_00951cb8 = *(undefined4 *)(DAT_00951cd4 + 0x13c);
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007626f0);
    if (iVar1 == 0) {
      DAT_00951cb8 = DAT_0092489c;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"vehicle");
    if (iVar1 == 0) {
      DAT_00951cb8 = DAT_00924898;
      return;
    }
    DAT_00951cb8 = DAT_00924880;
  }
  return;
}

