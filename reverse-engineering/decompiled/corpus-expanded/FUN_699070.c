/* Ghidra pseudocode, not original source.
 * ev_4289758b99e4c7501e635d810a16af61d296f1bd933ef263ce76cab568b7549e
 * Entry: 0x699070; label: FUN_00699070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00699070(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  int unaff_retaddr;
  int *piVar3;
  int *piVar4;
  
  puVar1 = (undefined4 *)(in_ECX + 0x54);
  if (*(int *)(in_ECX + 0x54) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xa0));
    piVar4 = (int *)*puVar1;
    (**(code **)(*piVar4 + 8))();
    *puVar1 = 0;
    *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(unaff_retaddr + 4);
    *(undefined2 *)(in_ECX + 0x1e) = *(undefined2 *)(unaff_retaddr + 2);
    *(undefined2 *)(in_ECX + 0x28) = *(undefined2 *)(unaff_retaddr + 0xc);
    *(undefined2 *)(in_ECX + 0x2a) = *(undefined2 *)(unaff_retaddr + 0xe);
    *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(unaff_retaddr + 8);
    piVar3 = (int *)(in_ECX + 0x30);
    *(undefined4 *)(in_ECX + 0x58) = 4;
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    *(undefined4 *)(in_ECX + 0x40) = 0;
    *(undefined4 *)(in_ECX + 0x44) = 0;
    *(undefined4 *)(in_ECX + 0x48) = 0;
    *(undefined4 *)(in_ECX + 0x4c) = 0;
    *(undefined4 *)(in_ECX + 0x50) = 0;
    *(int *)(in_ECX + 0x38) = *(int *)(in_ECX + 0x58) * *(int *)(in_ECX + 0x24);
    *piVar3 = 0x24;
    *(undefined4 *)(in_ECX + 0x34) = 0x10080;
    *(int *)(in_ECX + 0x40) = in_ECX + 0x1c;
    *puVar1 = 0;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x3fc) + 0xc))
                      (*(int **)(in_ECX + 0x3fc),piVar3,&stack0xfffffff8,0);
    if (-1 < iVar2) {
      iVar2 = (**(code **)*piVar4)(piVar4,&DAT_0078496c,puVar1);
      if (-1 < iVar2) {
        (**(code **)(*(int *)*puVar1 + 0x3c))(*puVar1,*(undefined4 *)(in_ECX + 0x10));
        *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x10);
      }
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xa0));
  }
  return 0;
}

