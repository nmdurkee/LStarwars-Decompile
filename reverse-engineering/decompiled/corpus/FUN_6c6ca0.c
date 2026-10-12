/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c6ca0; label: FUN_006c6ca0
 */

void FUN_006c6ca0(void)

{
  undefined2 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076fa04;
  *(undefined2 *)(in_ECX + 1) = 0;
  *(undefined2 *)((int)in_ECX + 6) = DAT_02973aa0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  *in_ECX = &PTR_FUN_0076faf4;
  FUN_005d0480(in_ECX + 6);
  *in_ECX = &PTR_FUN_0076fb64;
  uVar1 = (undefined2)DAT_0081fd48;
  in_ECX[9] = 0;
  *(undefined2 *)(in_ECX + 1) = uVar1;
  return;
}

