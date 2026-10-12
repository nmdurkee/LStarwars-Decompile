/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x629a30; label: FUN_00629a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00629a30(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_02912e70;
  *(int *)(DAT_02912e70 + 0x14) = *(int *)(param_1 + 0x14) + 10;
  *(int *)(iVar2 + 0x18) = *(int *)(param_1 + 0x18) + 10;
  if (*(int *)(iVar2 + 0x40) == 0) {
    iVar1 = *(int *)(param_1 + 0x3c);
    while (iVar1 != 0) {
      param_1 = *(int *)(param_1 + 0x3c);
      iVar1 = *(int *)(param_1 + 0x3c);
    }
    *(int *)(iVar2 + 0x40) = param_1;
    *(int *)(param_1 + 0x3c) = iVar2;
    FUN_006271a0(iVar2);
  }
  return;
}

