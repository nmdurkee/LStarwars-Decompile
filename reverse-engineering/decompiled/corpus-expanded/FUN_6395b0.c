/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x6395b0; label: FUN_006395b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006395b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = DAT_02913824;
  puVar3 = &DAT_02913558;
  for (iVar1 = 0x23; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00629480();
  return;
}

