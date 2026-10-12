/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x441070; label: FUN_00441070
 */

float10 FUN_00441070(void)

{
  int iVar1;
  undefined4 in_stack_00000014;
  
  iVar1 = FUN_004678f0(DAT_0093d810,in_stack_00000014);
  if (iVar1 == 0) {
    iVar1 = FUN_004678f0(DAT_0093d814,in_stack_00000014);
    if (iVar1 == 0) {
      return (float10)0;
    }
  }
  return (float10)1;
}

