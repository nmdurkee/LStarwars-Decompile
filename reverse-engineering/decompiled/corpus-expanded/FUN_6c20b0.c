/* Ghidra pseudocode, not original source.
 * ev_8705922c1b0f5911d8582e9aa5172c8d40ef9c41de03e321ff79e08d51867777
 * Entry: 0x6c20b0; label: FUN_006c20b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c20b0(void)

{
  undefined4 *in_ECX;
  
  if (in_ECX + 1 != (undefined4 *)0x0) {
    in_ECX[1] = 0;
    in_ECX[2] = 0;
  }
  *in_ECX = &PTR_FUN_0076f690;
  return;
}

