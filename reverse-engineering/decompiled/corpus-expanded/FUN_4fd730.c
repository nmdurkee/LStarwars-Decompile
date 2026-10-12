/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fd730; label: FUN_004fd730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fd730(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_004fd5d0(param_1,*param_2,*param_3 - *param_2);
  *param_2 = *param_2 + iVar1;
  return;
}

