/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x559ee0; label: FUN_00559ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_00559ee0(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  if ((DAT_0093b268 != (int *)0x0) && (param_1 != (int *)0x0)) {
    if (param_3 != 0) {
      param_2 = FUN_00559e20(param_1,param_3);
    }
    if ((-1 < param_2) && (param_2 < *DAT_0093b268)) {
      iVar1 = *param_1 + param_2 * 0x14;
      if (*(int *)(iVar1 + 4) < *(int *)(iVar1 + 8)) {
        piVar2 = (int *)(*(int *)(iVar1 + 0xc) + *(int *)(iVar1 + 4) * 8);
        if (piVar2 != (int *)0x0) {
          if (param_4 != 0) {
            *piVar2 = param_4;
          }
          *(undefined2 *)(piVar2 + 1) = 0;
          *(char *)((int)piVar2 + 6) = (char)param_2;
          *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
          return piVar2;
        }
      }
    }
  }
  return (int *)0x0;
}

