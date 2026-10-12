/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441660; label: FUN_00441660
 */

float10 FUN_00441660(void)

{
  int iVar1;
  int in_stack_00000014;
  
  if (in_stack_00000014 != 0) {
    iVar1 = FUN_0055a1b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),in_stack_00000014,0,1);
    if (iVar1 != 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

