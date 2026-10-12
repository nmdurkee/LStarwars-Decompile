/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c4e50; label: FUN_005c4e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c4e50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_007642a4;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

