/* Ghidra pseudocode, not original source.
 * ev_a20a6c15d6d7179604e8e4ec89a70d05558de2baba360f8c881a73106e589323
 * Entry: 0x5884d0; label: FUN_005884d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005884d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar2 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_005884ff;
  }
  iVar1 = 1;
LAB_005884ff:
  *(uint *)(DAT_00954404 + 0x94) =
       *(uint *)(DAT_00954404 + 0x94) ^ (iVar1 << 0xf ^ *(uint *)(DAT_00954404 + 0x94)) & 0x8000;
  return;
}

