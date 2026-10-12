/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x5145a0; label: FUN_005145a0
 */

void FUN_005145a0(int param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    if ((*(uint *)(param_1 + 0x50) & 4) == 0) {
      *(undefined2 *)(param_1 + 0xb2) = 0;
    }
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & 0xfffffffb;
    *(int *)(param_1 + 8) = param_2;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0x38) = 1;
    FUN_00514550();
  }
  return;
}

