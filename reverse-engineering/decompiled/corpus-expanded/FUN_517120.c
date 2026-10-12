/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x517120; label: FUN_00517120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00517120(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xbc) != 0) {
    iVar1 = FUN_004f20f0(param_2,*(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x18));
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0xb4) = 0;
      *(undefined4 *)(param_1 + 0xb8) = 0;
      *(undefined1 *)(param_1 + 0xb5) = 0;
      *(undefined4 *)(param_1 + 0xbc) = 0;
    }
  }
  return;
}

