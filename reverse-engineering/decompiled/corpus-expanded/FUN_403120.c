/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x403120; label: FUN_00403120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00403120(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_3 + 0x509c)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f1ff0(*(int *)(param_3 + 0x5098) + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x5098) + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x74;
    } while (iVar2 < *(int *)(param_3 + 0x509c));
  }
  return;
}

