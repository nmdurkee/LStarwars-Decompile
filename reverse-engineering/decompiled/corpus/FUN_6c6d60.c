/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c6d60; label: FUN_006c6d60
 */

void FUN_006c6d60(void)

{
  undefined4 *in_ECX;
  undefined4 extraout_EDX;
  
  FUN_006c6ca0();
  if (in_ECX + 0xb != (undefined4 *)0x0) {
    in_ECX[0xb] = 0;
    in_ECX[0xc] = 0;
  }
  *in_ECX = &PTR_FUN_0076fbc4;
  *(undefined2 *)(in_ECX + 1) = (undefined2)DAT_0081fd48;
  in_ECX[9] = 1;
  FUN_006b7df0();
  FUN_006b7df0();
  in_ECX[0x30] = extraout_EDX;
  return;
}

