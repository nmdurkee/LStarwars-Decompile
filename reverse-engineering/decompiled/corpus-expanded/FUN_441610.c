/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x441610; label: FUN_00441610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441610(void)

{
  int *in_stack_00000014;
  
  if (((in_stack_00000014 != (int *)0x0) && (*in_stack_00000014 != 0)) &&
     (*(char *)(*in_stack_00000014 + 0x6d) == '\x02')) {
    return (float10)1;
  }
  return (float10)0;
}

