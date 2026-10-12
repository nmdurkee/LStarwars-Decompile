/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x623850; label: FUN_00623850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00623850(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = FUN_006232e0(param_3,param_4);
  if (iVar1 != 0) {
    if (*(code **)(param_2 + 0x60) != (code *)0x0) {
      (**(code **)(param_2 + 0x60))(param_1,param_2,*(undefined4 *)(param_4 + 0x70));
    }
  }
  return 0;
}

