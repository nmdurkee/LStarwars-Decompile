/* Ghidra pseudocode, not original source.
 * ev_18939eb5636c5080554c34c4c464805d15dff0cc807e45e19880c96644741519
 * Entry: 0x5aee80; label: FUN_005aee80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005aee80(float *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_3 * 8 + 1000;
  FUN_005f35e0(DAT_009738b8,(param_2 + 10) * 0x10,iVar1,0x10,&DAT_00763e3c,(double)*param_1);
  FUN_005f35e0(DAT_009738b8,(param_2 + 0x50) * 0x10,iVar1,0x10,&DAT_00763e3c,(double)param_1[1]);
  FUN_005f35e0(DAT_009738b8,(param_2 + 0x96) * 0x10,iVar1,0x10,&DAT_00763e3c,(double)param_1[2]);
  return;
}

