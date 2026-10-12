/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52c790; label: FUN_0052c790
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

