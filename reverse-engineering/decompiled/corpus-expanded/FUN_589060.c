/* Ghidra pseudocode, not original source.
 * ev_ebb7262bcf4e9a2f6ce5c4899044ae4c8e0a5d5c0ddeff4eaa1e0a5d9d7a0639
 * Entry: 0x589060; label: FUN_00589060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00589060(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_00589093;
    }
  }
  iVar1 = 1;
LAB_00589093:
  *(uint *)(DAT_00954404 + 0x94) =
       *(uint *)(DAT_00954404 + 0x94) ^ (iVar1 * 2 ^ *(uint *)(DAT_00954404 + 0x94)) & 2;
  return;
}

