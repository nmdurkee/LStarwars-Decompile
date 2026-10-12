/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59d7a0; label: FUN_0059d7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059d7a0(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  puVar2 = param_1;
  if ((((param_1 != (undefined4 *)0x0) && (param_2 != 0)) && (DAT_0093b268 != (int *)0x0)) &&
     (((int)(uint)*(byte *)(param_2 + 6) < *DAT_0093b268 &&
      (*(int *)((uint)*(byte *)(param_2 + 6) * 0x9c + 0x44 + DAT_0093b268[2]) != 0)))) {
    piVar1 = param_1 + 1;
    iVar5 = param_1[2];
    param_1 = (undefined4 *)0x0;
    if (0 < *piVar1) {
      do {
        piVar1 = *(int **)(iVar5 + 0xc);
        if ((piVar1 != (int *)0x0) && (iVar6 = 0, 0 < *piVar1)) {
          do {
            if (**(int **)(piVar1[2] + iVar6 * 4) == 0) {
              uVar3 = (**(code **)((uint)*(byte *)(param_2 + 6) * 0x9c + 0x44 + DAT_0093b268[2]))
                                (param_2);
              iVar4 = FUN_004f8b10(*(undefined4 *)(*(int *)(piVar1[2] + iVar6 * 4) + 4),uVar3);
              if ((iVar4 == 0) &&
                 (**(int **)(piVar1[2] + iVar6 * 4) = param_2, (*(byte *)(iVar5 + 10) & 1) == 0)) {
                if ((code *)(&PTR_FUN_00805514)[(uint)*(byte *)(iVar5 + 3) * 3] != (code *)0x0) {
                  (*(code *)(&PTR_FUN_00805514)[(uint)*(byte *)(iVar5 + 3) * 3])(puVar2,iVar5);
                }
                if ((((*(ushort *)(iVar5 + 10) & 1) == 0) && ((*(ushort *)(iVar5 + 10) & 4) != 0))
                   && (*(char *)(iVar5 + 3) == '\0')) {
                  FUN_0055a2b0(*puVar2,**(undefined4 **)(piVar1[2] + iVar6 * 4),0,1);
                }
              }
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < *piVar1);
        }
        param_1 = (undefined4 *)((int)param_1 + 1);
        iVar5 = iVar5 + 0x20;
      } while ((int)param_1 < (int)puVar2[1]);
    }
  }
  return;
}

