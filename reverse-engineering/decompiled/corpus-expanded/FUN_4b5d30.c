/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b5d30; label: FUN_004b5d30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004b5d30(int param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = *(int *)(PTR_DAT_00802c54 + 300);
  if ((iVar1 != 0) && ((iVar1 == DAT_0087af78 || (iVar1 == DAT_0087b01c)))) {
    iVar1 = *(int *)(param_1 + 0xca4);
    FUN_0058d8b0(param_1);
    FUN_00427b40(param_1);
    if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
      fVar2 = (float10)FUN_004aa5a0(param_1,0x41000000,0);
      FUN_004abac0(param_1,0,(float)fVar2);
      FUN_0049c080(param_1);
      FUN_004a6c30(*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_0080227c,
                   *(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_0080227c,0x3e99999a,0);
      if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x400) != 0) {
        FUN_004a71f0(param_1,*(uint *)(iVar1 + 8) & DAT_00802280,0x3f000000);
      }
    }
    return;
  }
  FUN_004b5120();
  return;
}

