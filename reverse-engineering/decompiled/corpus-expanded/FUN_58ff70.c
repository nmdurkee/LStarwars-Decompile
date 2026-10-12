/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x58ff70; label: FUN_0058ff70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058ff70(undefined4 param_1,int *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  
  if (param_2 != (int *)0x0) {
    iVar3 = 0;
    if ((short)param_2[1] != 0) {
      puVar2 = (ushort *)(*param_2 + 0x7a);
      do {
        if ((*puVar2 & 0x80) != 0) {
          uVar1 = FUN_0056aa40(param_1,(int)(short)puVar2[-1]);
          *puVar2 = *puVar2 & 0xff7f;
          puVar2[-1] = uVar1;
        }
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 0x3e;
      } while (iVar3 < (int)(uint)*(ushort *)(param_2 + 1));
    }
  }
  return;
}

