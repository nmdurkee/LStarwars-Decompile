/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x601230; label: FUN_00601230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00601230(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + 0xb4);
  for (iVar2 = 0x82; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  uVar1 = *(uint *)(param_1 + 200);
  *(float *)(param_1 + 0x54) = (float)(uVar1 & 0xff) / 255.0;
  *(float *)(param_1 + 0x58) = (float)((int)uVar1 >> 8 & 0xff) / 255.0;
  *(float *)(param_1 + 0x5c) = (float)((int)uVar1 >> 0x10 & 0xff) / 255.0;
  return;
}

