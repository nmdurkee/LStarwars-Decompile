/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x559e80; label: FUN_00559e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00559e80(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == -1) {
    if (param_3 != 0) {
      param_2 = FUN_00559e20(param_1,param_3);
      if (param_2 != -1) goto LAB_00559ea5;
    }
    return 0;
  }
LAB_00559ea5:
  iVar2 = *(int *)(*param_1 + 8 + param_2 * 0x14);
  iVar1 = *param_1 + param_2 * 0x14;
  *(undefined4 *)(iVar1 + 4) = 0;
  _memset(*(void **)(iVar1 + 0xc),0,iVar2 * 8);
  return 1;
}

