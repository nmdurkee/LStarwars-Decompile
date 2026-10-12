/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d3760; label: FUN_004d3760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004d3760(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_40 [16];
  
  iVar1 = FUN_00571c80(param_1);
  if ((iVar1 != 0) && (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x7be) != '\0')) {
    puVar3 = local_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_005b4b30(local_40,*(float *)(*(int *)(PTR_DAT_00802c54 + 0x5100) + 8) * 4.0);
    FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x7b0,local_40);
  }
  return iVar1;
}

