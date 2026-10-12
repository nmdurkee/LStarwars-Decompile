/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x639520; label: FUN_00639520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00639520(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (DAT_0291365c != 0) {
    if (DAT_02913814 == (undefined4 *)0x0) {
      FUN_006394d0();
      return;
    }
    uVar1 = DAT_02913814[8];
    uVar2 = DAT_02913814[9];
    uVar3 = DAT_02913814[10];
    puVar6 = &DAT_02913648;
    puVar7 = DAT_02913814;
    for (iVar5 = 0x13; puVar4 = DAT_02913814, iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    DAT_02913814[8] = uVar1;
    puVar4[9] = uVar2;
    puVar4[10] = uVar3;
  }
  return;
}

