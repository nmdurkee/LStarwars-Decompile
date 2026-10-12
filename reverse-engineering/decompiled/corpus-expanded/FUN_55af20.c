/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55af20; label: FUN_0055af20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055af20(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *_Dst;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  if ((DAT_0093b268 != (int *)0x0) && (param_1 != (int *)0x0)) {
    iVar5 = 0;
    if (0 < *DAT_0093b268) {
      puVar6 = (undefined4 *)(*param_1 + 0x10);
      puVar3 = (undefined4 *)(DAT_0093b268[2] + 0x30);
      iVar4 = 0;
      do {
        if (iVar5 != -1) {
          iVar1 = *param_1;
          iVar2 = *(int *)(iVar1 + 8 + iVar4);
          _Dst = *(void **)(iVar1 + 0xc + iVar4);
          *(undefined4 *)(iVar1 + iVar4 + 4) = 0;
          _memset(_Dst,0,iVar2 * 8);
        }
        if ((code *)*puVar3 != (code *)0x0) {
          (*(code *)*puVar3)(param_1,iVar5,param_3,*puVar6);
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x14;
        puVar6 = puVar6 + 5;
        puVar3 = puVar3 + 0x27;
      } while (iVar5 < *DAT_0093b268);
    }
  }
  if ((param_2 != 0) && (*(char *)(param_2 + 0xd) != '\0')) {
    FUN_0059f2a0(param_2);
  }
  return;
}

