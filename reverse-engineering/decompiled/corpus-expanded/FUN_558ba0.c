/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x558ba0; label: FUN_00558ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00558ba0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (param_2 != 0) {
    iVar5 = 0;
    if (*(ushort *)(param_2 + 0xc) != 0) {
      puVar4 = *(undefined4 **)(param_2 + 4);
      do {
        iVar1 = *(int *)*puVar4;
        if (((((*(uint *)(iVar1 + 0x94) & 2) != 0) && ((*(uint *)(iVar1 + 0x94) & 1) != 0)) &&
            ((*(uint *)(iVar1 + 0x9c) & 0x10) != 0)) &&
           ((-1 < (char)*(uint *)(iVar1 + 0x9c) &&
            (piVar2 = *(int **)(*(int *)(iVar1 + 0x34) + 0x18), piVar2 != (int *)0x0)))) {
          do {
            if (*(short *)(piVar2[9] + 2) == *(short *)(param_3 + 0xfa)) {
              iVar5 = FUN_005806a0(*(undefined1 *)(param_3 + 0x101),param_1);
              if (*(int *)(param_3 + 4) == 0) {
                iVar3 = -1;
              }
              else {
                iVar3 = (int)*(char *)(*(int *)(param_3 + 4) + 0x280);
              }
              FUN_00558a70(param_1,iVar1,param_3 + 0x88,iVar3,*(undefined1 *)(iVar5 + 0x3c));
              return 1;
            }
            piVar2 = (int *)*piVar2;
          } while (piVar2 != (int *)0x0);
        }
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar5 < (int)(uint)*(ushort *)(param_2 + 0xc));
    }
  }
  return 0;
}

