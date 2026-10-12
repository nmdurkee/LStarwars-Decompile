/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e68e0; label: FUN_005e68e0
 */

void FUN_005e68e0(byte param_1)

{
  undefined4 *in_ECX;
  
  FUN_00606a20();
  *in_ECX = &PTR_LAB_007642a4;
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

