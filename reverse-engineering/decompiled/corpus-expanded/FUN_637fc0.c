/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x637fc0; label: FUN_00637fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00637fc0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = param_1;
  if (param_1 < (undefined4 *)(DAT_0291389c + 0x4f84)) {
    do {
      if (param_1[5] == 0) break;
      puVar3 = puVar1 + 0x13;
      puVar4 = param_1;
      for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      param_1 = param_1 + 0x13;
      puVar1 = puVar1 + 0x13;
    } while (param_1 < (undefined4 *)(DAT_0291389c + 0x4f84));
  }
  param_1[-0xe] = 0;
  return;
}

