/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x6394b0; label: FUN_006394b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006394b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (DAT_02913814 != (undefined4 *)0x0) {
    puVar2 = DAT_02913814;
    puVar3 = &DAT_02913648;
    for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}

