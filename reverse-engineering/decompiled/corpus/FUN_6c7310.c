/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c7310; label: FUN_006c7310
 */

void FUN_006c7310(int param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  if (in_ECX + 1 != (undefined4 *)0x0) {
    in_ECX[1] = 0;
    in_ECX[2] = 0;
  }
  in_ECX[3] = param_1;
  *in_ECX = &PTR_FUN_0076f97c;
  uVar1 = FUN_00633440(param_1 << 4,1);
  in_ECX[5] = uVar1;
  return;
}

