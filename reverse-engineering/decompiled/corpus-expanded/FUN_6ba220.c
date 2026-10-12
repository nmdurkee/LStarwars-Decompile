/* Ghidra pseudocode, not original source.
 * ev_4470474dfe9095336407712c08b1b1234dd43f54b8096ef09bb626cb5952ee3b
 * Entry: 0x6ba220; label: FUN_006ba220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ba220(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076b630;
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x10);
  }
  return;
}

