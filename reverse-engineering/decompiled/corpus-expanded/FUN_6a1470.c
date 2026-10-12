/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a1470; label: FUN_006a1470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a1470(int param_1,int param_2)

{
  if ((**(int **)(param_1 + 0x1c) < 0x41) && (param_2 != 0)) {
    return 0xffffffff;
  }
  (*(int **)(param_1 + 0x1c))[0x392] = (uint)(param_2 != 0);
  return 0;
}

