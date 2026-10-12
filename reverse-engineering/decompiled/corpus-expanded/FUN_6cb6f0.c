/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6cb6f0; label: FUN_006cb6f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006cb6f0(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  char *pcStack_10;
  
  pcStack_10 = "FileInfo";
  iVar2 = (**(code **)(*param_1 + 0x18))();
  if (iVar2 != 0) {
    (**(code **)(*param_1 + 8))(in_ECX + 0xa4c,4,1);
    (**(code **)(*param_1 + 0x1c))();
  }
  iVar2 = (**(code **)(*param_1 + 0x18))("Settings");
  if (iVar2 != 0) {
    (**(code **)(*param_1 + 8))(in_ECX + 0x10a0,4,1);
    (**(code **)(*param_1 + 8))(in_ECX + 0x10a4,4,1);
    (**(code **)(*param_1 + 0x1c))();
  }
  iVar2 = (**(code **)(*param_1 + 0x18))("Editors");
  if (iVar2 != 0) {
    iVar2 = 1;
    (**(code **)(*param_1 + 8))(&pcStack_10,4);
    iVar6 = 0;
    if (0 < iVar2) {
      do {
        uVar3 = (**(code **)(*param_1 + 0x18))(0);
        for (piVar1 = *(int **)(in_ECX + 0x93c); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
          uVar4 = (**(code **)(*piVar1 + 8))(uVar3);
          iVar5 = FUN_004f8b10(uVar4);
          if (iVar5 == 0) {
            (**(code **)(*piVar1 + 0x14))(param_1);
            break;
          }
        }
        (**(code **)(*param_1 + 0x1c))();
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar2);
    }
    (**(code **)(*param_1 + 0x1c))();
  }
  return 1;
}

