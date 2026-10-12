/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a3e50; label: FUN_006a3e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a3e50(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  puVar3 = _calloc(1,0x24);
  uVar2 = *(undefined4 *)(param_1 + 4);
  *puVar3 = 0xc61c3c00;
  puVar3[2] = iVar1 + 0xb34;
  puVar3[1] = uVar2;
  return;
}

