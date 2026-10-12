/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x5170c0; label: FUN_005170c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_005170c0(int param_1,byte param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if (*(byte *)(param_1 + 0xb4) <= param_2) {
    iVar1 = FUN_00512fc0(param_4,*(undefined4 *)(param_1 + 4));
    if (iVar1 != 0) {
      *(byte *)(param_1 + 0xb4) = param_2;
      *(undefined4 *)(param_1 + 0xb8) = param_5;
      *(int *)(param_1 + 0xbc) = iVar1;
      *(undefined1 *)(param_1 + 0xb5) = param_3;
      return 1;
    }
  }
  return 0;
}

