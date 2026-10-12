/* Ghidra pseudocode, not original source.
 * ev_184291d84d57a0e0f71d3c8a05fa8a71135e786a990f62c870cdb26b01607f61
 * Entry: 0x60f190; label: FUN_0060f190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060f190(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  
  if (param_2 != 0) {
    if (param_4 != param_3 && -1 < param_4 - param_3) {
      param_3 = param_3 + -1;
      FUN_004ef660(param_3 + param_2,&param_5,1);
      *(int *)(param_2 + 0x4b0) = *(int *)(param_2 + 0x4b0) + 1;
      FUN_0060e590(param_1,param_2,param_3,param_4,param_5);
      for (piVar1 = *(int **)(DAT_028fec04 + 0x94); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1])
      {
        FUN_0060ee80();
        if (param_2 == 0) {
          FUN_0060f2d0(param_1,0,param_3,param_4,0,0);
        }
        else {
          *(int *)(param_2 + 0x4b0) = *(int *)(param_2 + 0x4b0) + 1;
        }
        (**(code **)(*piVar1 + 0xc))();
      }
    }
    if (param_2 != 0) {
      if (1 < *(uint *)(param_2 + 0x4b0)) {
        *(uint *)(param_2 + 0x4b0) = *(uint *)(param_2 + 0x4b0) - 1;
        return;
      }
      *(undefined4 *)(param_2 + 0x4b0) = 0;
    }
  }
  return;
}

