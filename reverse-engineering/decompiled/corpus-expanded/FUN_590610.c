/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x590610; label: FUN_00590610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00590610(undefined4 param_1,int *param_2)

{
  ushort *puVar1;
  int iVar2;
  
  if (param_2 != (int *)0x0) {
    iVar2 = 0;
    if ((short)param_2[1] != 0) {
      puVar1 = (ushort *)(*param_2 + 0x7a);
      do {
        *puVar1 = *puVar1 & 0xfffb;
        *(undefined1 *)(puVar1 + -6) = 0;
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 0x3e;
      } while (iVar2 < (int)(uint)*(ushort *)(param_2 + 1));
    }
  }
  return;
}

