/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x4029e0; label: FUN_004029e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004029e0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x509c)) {
    iVar3 = 0;
    do {
      uVar1 = FUN_0067c4f0(iVar3 + 0x1c + *(int *)(param_1 + 0x5098),4);
      *(undefined2 *)(iVar3 + 0x60 + *(int *)(param_1 + 0x5098)) = uVar1;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x74;
    } while (iVar2 < *(int *)(param_1 + 0x509c));
  }
  return;
}

