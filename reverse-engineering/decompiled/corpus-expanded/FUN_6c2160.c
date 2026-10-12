/* Ghidra pseudocode, not original source.
 * ev_8705922c1b0f5911d8582e9aa5172c8d40ef9c41de03e321ff79e08d51867777
 * Entry: 0x6c2160; label: FUN_006c2160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c2160(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076f690;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

