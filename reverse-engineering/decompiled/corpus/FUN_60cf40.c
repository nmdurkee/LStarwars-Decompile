/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60cf40; label: FUN_0060cf40
 */

void FUN_0060cf40(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_006e9c07();
  *in_ECX = &PTR_FUN_0076a8cc;
  in_ECX[8] = 0;
  in_ECX[9] = 0xf;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_0060cb30(param_1,0,0xffffffff);
  *in_ECX = &PTR_FUN_0076a8d8;
  return;
}

