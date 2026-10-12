/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x629440; label: FUN_00629440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00629440(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 0xc);
  if (*(int *)(iVar1 + 0x40) == 0) {
    iVar2 = *(int *)(param_1 + 0x3c);
    while (iVar2 != 0) {
      param_1 = *(int *)(param_1 + 0x3c);
      iVar2 = *(int *)(param_1 + 0x3c);
    }
    *(int *)(iVar1 + 0x40) = param_1;
    *(int *)(param_1 + 0x3c) = iVar1;
    FUN_006271a0(iVar1);
  }
  return;
}

