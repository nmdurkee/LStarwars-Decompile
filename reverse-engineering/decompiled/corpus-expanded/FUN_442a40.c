/* Ghidra pseudocode, not original source.
 * ev_6293e9c45219377b80e3d0963b70152e043cc5400ac7177165af43f16814c89d
 * Entry: 0x442a40; label: FUN_00442a40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442a40(void)

{
  int iVar1;
  int in_stack_00000014;
  
  if (in_stack_00000014 != 0) {
    iVar1 = FUN_005764b0(in_stack_00000014);
    if (iVar1 != 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

