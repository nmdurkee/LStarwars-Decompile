/* Ghidra pseudocode, not original source.
 * ev_4c4127be7d58e8981fbef62e7b9304e5f7a8f47caff33366593b2d257bcf3f12
 * Entry: 0x59f2a0; label: FUN_0059f2a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059f2a0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  puVar3 = param_1;
  if ((param_1 != (undefined4 *)0x0) && (piVar1 = param_1 + 1, *piVar1 != 0)) {
    iVar5 = param_1[2];
    param_1 = (undefined4 *)0x0;
    if (0 < *piVar1) {
      do {
        if (*(char *)(iVar5 + 3) == '\0') {
          piVar1 = *(int **)(iVar5 + 0xc);
          iVar6 = 0;
          if (0 < *piVar1) {
            do {
              piVar2 = *(int **)(piVar1[2] + iVar6 * 4);
              if (*piVar2 == 0) {
                uVar4 = FUN_0055a020(*puVar3,0xffffffff,piVar2[1]);
                **(undefined4 **)(piVar1[2] + iVar6 * 4) = uVar4;
                if ((**(int **)(piVar1[2] + iVar6 * 4) != 0) && ((*(byte *)(iVar5 + 10) & 1) == 0))
                {
                  if ((code *)(&PTR_FUN_00805514)[(uint)*(byte *)(iVar5 + 3) * 3] != (code *)0x0) {
                    (*(code *)(&PTR_FUN_00805514)[(uint)*(byte *)(iVar5 + 3) * 3])(puVar3,iVar5);
                  }
                  if ((((*(ushort *)(iVar5 + 10) & 1) == 0) && ((*(ushort *)(iVar5 + 10) & 4) != 0))
                     && (*(char *)(iVar5 + 3) == '\0')) {
                    FUN_0055a2b0(*puVar3,**(undefined4 **)(piVar1[2] + iVar6 * 4),0,1);
                  }
                }
              }
              else {
                piVar2 = *(int **)(piVar1[2] + iVar6 * 4);
                uVar4 = FUN_0055a020(*puVar3,*(undefined1 *)(*piVar2 + 6),piVar2[1]);
                **(undefined4 **)(piVar1[2] + iVar6 * 4) = uVar4;
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < *piVar1);
          }
        }
        param_1 = (undefined4 *)((int)param_1 + 1);
        iVar5 = iVar5 + 0x20;
      } while ((int)param_1 < (int)puVar3[1]);
    }
  }
  return;
}

