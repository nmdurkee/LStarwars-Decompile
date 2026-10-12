/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a14b0; label: FUN_006a14b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006a14b0(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  iVar1 = 0;
  if (in_ECX != 0) {
    for (uVar2 = in_ECX - 1; uVar2 != 0; uVar2 = uVar2 >> 1) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}

