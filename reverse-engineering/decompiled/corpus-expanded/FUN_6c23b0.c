/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c23b0; label: FUN_006c23b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c23b0(void)

{
  undefined4 *in_ECX;
  
  if (in_ECX != (undefined4 *)0x0) {
    *in_ECX = 0;
    in_ECX[1] = 0;
    *(undefined2 *)(in_ECX + 0x11) = DAT_02973aa0;
    return;
  }
  uRam00000044 = DAT_02973aa0;
  return;
}

