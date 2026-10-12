/* Ghidra pseudocode, not original source.
 * ev_cdff09935bddc4594064dfeb1f42a846ac78fe961445b4150dea7d25416822c1
 * Entry: 0x52c790; label: FUN_0052c790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0052c790(int *param_1,int param_2)

{
  int iVar1;
  
  if (((param_2 != 0) && (param_1 != (int *)0x0)) && (param_1[1] != 0)) {
    iVar1 = FUN_00512fc0(param_2,*param_1);
    if (iVar1 != 0) {
      if (param_1[1] == *param_1) {
        FUN_005145a0(param_1);
        return 1;
      }
      FUN_00514640(0,0,param_1,0,0,0,0,*param_1,iVar1);
      param_1[0x19] = 0;
      return 1;
    }
  }
  return 0;
}

