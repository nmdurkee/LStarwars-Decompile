/* Ghidra pseudocode, not original source.
 * ev_ebb7262bcf4e9a2f6ce5c4899044ae4c8e0a5d5c0ddeff4eaa1e0a5d9d7a0639
 * Entry: 0x5887f0; label: FUN_005887f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005887f0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar2 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_0058881f;
  }
  iVar1 = 1;
LAB_0058881f:
  *(uint *)(DAT_00954404 + 0x94) =
       *(uint *)(DAT_00954404 + 0x94) ^ (iVar1 << 0x1b ^ *(uint *)(DAT_00954404 + 0x94)) & 0x8000000
  ;
  return;
}

