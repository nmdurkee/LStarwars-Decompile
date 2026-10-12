/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x617970; label: FUN_00617970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00617970(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076aca0;
  FUN_00617790();
  *in_ECX = &PTR_FUN_0076105c;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

