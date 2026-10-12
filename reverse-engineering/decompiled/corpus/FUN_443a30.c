/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x443a30; label: FUN_00443a30
 */

float10 FUN_00443a30(void)

{
  int iVar1;
  float10 fVar2;
  int in_stack_00000014;
  
  if (in_stack_00000014 == 0) {
    fVar2 = (float10)0;
  }
  else {
    iVar1 = FUN_0055a1b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),in_stack_00000014,0,1);
    fVar2 = (float10)iVar1;
    if (iVar1 < 0) {
      return fVar2 + (float10)4.2949673e+09;
    }
  }
  return fVar2;
}

