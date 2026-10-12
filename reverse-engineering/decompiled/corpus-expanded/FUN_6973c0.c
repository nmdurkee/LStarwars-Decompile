/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x6973c0; label: FUN_006973c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006973c0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_02972bb0);
  piVar3 = in_ECX + 3;
  iVar2 = 0x40;
  do {
    piVar1 = (int *)*piVar3;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 0xd;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (0 < DAT_02972bfc) {
    iVar4 = 0;
    iVar2 = 0;
    do {
      piVar3 = *(int **)(in_ECX[0x343] + iVar4);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(*(undefined4 *)(in_ECX[0x343] + iVar4));
        *(undefined4 *)(iVar4 + in_ECX[0x343]) = 0;
      }
      *(undefined1 *)(in_ECX[0x343] + 0x404 + iVar4) = 0;
      *(undefined1 *)(in_ECX[0x343] + 0x405 + iVar4) = 0;
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x40c;
    } while (iVar2 < DAT_02972bfc);
  }
  in_ECX[0x344] = 0;
  *in_ECX = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_02972bb0);
  return;
}

