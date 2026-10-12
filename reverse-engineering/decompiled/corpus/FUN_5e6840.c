/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e6840; label: FUN_005e6840
 */

void FUN_005e6840(void)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = 0;
  in_ECX[0xb7] = 0;
  in_ECX[0xb8] = 0;
  in_ECX[0xb9] = 0;
  in_ECX[0xba] = 0;
  in_ECX[0xbb] = 0;
  in_ECX[0xbc] = 0;
  in_ECX[0x12] = 0x3f000000;
  in_ECX[0xbd] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[3] = 4;
  in_ECX[0x11] = 0;
  *in_ECX = &PTR_LAB_00765494;
  return;
}

