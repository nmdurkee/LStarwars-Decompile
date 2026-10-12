/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x621140; label: FUN_00621140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00621140(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_40 [16];
  
  FUN_006210b0(local_40);
  puVar1 = DAT_02912e78;
  puVar3 = local_40;
  puVar4 = DAT_02912e78;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_00603cc0(puVar1);
  return;
}

