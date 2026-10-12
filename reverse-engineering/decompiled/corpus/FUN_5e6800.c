/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e6800; label: FUN_005e6800
 */

void FUN_005e6800(void)

{
  undefined4 *in_ECX;
  
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_00765468;
  FUN_006069a0();
  return;
}

