/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60e120; label: FUN_0060e120
 */

void FUN_0060e120(undefined4 param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    *in_ECX = 0;
    in_ECX[1] = 0;
  }
  *(undefined1 *)(in_ECX + 3) = param_2;
  puVar1 = (undefined1 *)((int)in_ECX + 0xd);
  in_ECX[2] = param_1;
  FUN_0060df50(puVar1);
  if (param_3 != 0) {
    FUN_004f1f40(puVar1,param_3,0x20);
    return;
  }
  *puVar1 = 0;
  return;
}

