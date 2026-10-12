/* Ghidra pseudocode, not original source.
 * ev_cc6b5d9c9dc19119c5b50c1e1d885dc592b880ad73e24652555bc61e14428cde
 * Entry: 0x6c8a10; label: FUN_006c8a10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c8a10(void)

{
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    in_ECX[3] = &PTR_FUN_0076f7e8;
    *in_ECX = &PTR_FUN_0076b5b4;
    return;
  }
  ppuRam00000000 = &PTR_FUN_0076b5b4;
  return;
}

