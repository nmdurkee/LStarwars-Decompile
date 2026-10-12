/* Ghidra pseudocode, not original source.
 * ev_a20a6c15d6d7179604e8e4ec89a70d05558de2baba360f8c881a73106e589323
 * Entry: 0x588110; label: FUN_00588110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00588110(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_00588143;
    }
  }
  iVar1 = 1;
LAB_00588143:
  *(uint *)(DAT_00954404 + 0x98) =
       *(uint *)(DAT_00954404 + 0x98) ^ (iVar1 * 8 ^ *(uint *)(DAT_00954404 + 0x98)) & 8;
  return;
}

