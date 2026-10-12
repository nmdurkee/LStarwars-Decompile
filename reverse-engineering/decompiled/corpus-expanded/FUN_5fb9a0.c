/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fb9a0; label: FUN_005fb9a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fb9a0(void)

{
  int *piVar1;
  int iVar2;
  int *piStack_2c;
  undefined2 uStack_8;
  undefined2 uStack_4;
  
  iVar2 = 0;
  do {
    piVar1 = *(int **)((int)&DAT_00986a88 + iVar2);
    if (piVar1 != (int *)0x0) {
      if (*piVar1 == 0) {
        piVar1[2] = 0;
      }
      else if (*(int *)(*piVar1 + 0x28) == 0) {
        piStack_2c = piVar1 + 2;
        (**(code **)(**(int **)*piVar1 + 0x48))(*(int **)*piVar1,(short)piVar1[3]);
        piVar1 = *(int **)**(undefined4 **)((int)&DAT_00986a88 + iVar2);
        (**(code **)(*piVar1 + 0x44))
                  (piVar1,*(undefined2 *)(*(undefined4 **)((int)&DAT_00986a88 + iVar2) + 3),
                   &piStack_2c);
        *(undefined2 *)(*(int *)((int)&DAT_00986a88 + iVar2) + 0x14) = uStack_8;
        *(undefined2 *)(*(int *)((int)&DAT_00986a88 + iVar2) + 0x16) = uStack_4;
      }
      else {
        piVar1[2] = *(int *)(*piVar1 + 0x28);
        *(undefined2 *)(*(int **)((int)&DAT_00986a88 + iVar2) + 5) =
             *(undefined2 *)(**(int **)((int)&DAT_00986a88 + iVar2) + 4);
        *(undefined2 *)((int)*(int **)((int)&DAT_00986a88 + iVar2) + 0x16) =
             *(undefined2 *)(**(int **)((int)&DAT_00986a88 + iVar2) + 6);
      }
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 != 0x400);
  return;
}

