/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x6394d0; label: FUN_006394d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006394d0(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (DAT_0291365c != 0) {
    DAT_02913814 = (undefined4 *)FUN_00637f90();
    if (DAT_02913814 != (undefined4 *)0x0) {
      puVar3 = &DAT_02913648;
      puVar4 = DAT_02913814;
      for (iVar2 = 0x13; puVar1 = DAT_02913814, iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      DAT_02913814[8] = DAT_029134a4;
      puVar1[9] = DAT_029134a8;
      puVar1[10] = DAT_029134ac;
    }
  }
  return;
}

