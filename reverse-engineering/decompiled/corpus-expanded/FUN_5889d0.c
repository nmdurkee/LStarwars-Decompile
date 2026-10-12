/* Ghidra pseudocode, not original source.
 * ev_ebb7262bcf4e9a2f6ce5c4899044ae4c8e0a5d5c0ddeff4eaa1e0a5d9d7a0639
 * Entry: 0x5889d0; label: FUN_005889d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005889d0(int param_1)

{
  int iVar1;
  
  *(uint *)(DAT_00954400 + 4) = *(uint *)(DAT_00954400 + 4) | 0x40000000;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00954400 + 4) = *(uint *)(DAT_00954400 + 4) & 0xbfffffff;
    }
  }
  return;
}

