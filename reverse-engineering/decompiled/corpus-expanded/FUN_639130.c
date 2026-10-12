/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x639130; label: FUN_00639130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00639130(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (DAT_02913824 != (undefined4 *)0x0) {
    puVar2 = DAT_02913824;
    puVar3 = &DAT_02913720;
    for (iVar1 = 0x23; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}

