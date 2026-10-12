/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x4415a0; label: FUN_004415a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004415a0(void)

{
  int iVar1;
  int in_stack_00000014;
  
  if (in_stack_00000014 != 0) {
    iVar1 = FUN_00467890(in_stack_00000014);
    if (iVar1 != 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

