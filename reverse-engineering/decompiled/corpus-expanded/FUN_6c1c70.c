/* Ghidra pseudocode, not original source.
 * ev_8705922c1b0f5911d8582e9aa5172c8d40ef9c41de03e321ff79e08d51867777
 * Entry: 0x6c1c70; label: FUN_006c1c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c1c70(void)

{
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    *in_ECX = 0;
    in_ECX[1] = 0;
  }
  return;
}

