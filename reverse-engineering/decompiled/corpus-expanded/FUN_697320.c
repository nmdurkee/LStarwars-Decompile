/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x697320; label: FUN_00697320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00697320(int param_1,char param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(param_1 * 0x40c + *(int *)(in_ECX + 0xd0c));
  (**(code **)(*(int *)*puVar1 + 0x30))(*puVar1,0,0,param_2 != '\0');
  return;
}

