/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d0e70; label: FUN_006d0e70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d0e70(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int aiStack_108 [66];
  
  iVar2 = (**(code **)(*param_1 + 0x18))("TypeList");
  if (iVar2 != 0) {
    piVar1 = (int *)(in_ECX + 0x1c);
    (**(code **)(*param_1 + 8))(piVar1,4,1);
    iVar2 = 0;
    if (0 < *piVar1) {
      iVar5 = 0;
      do {
        iVar4 = *(int *)(in_ECX + 4) + iVar5;
        iVar3 = (**(code **)(*param_1 + 0x18))(&DAT_00763b1c);
        if (iVar3 != 0) {
          (**(code **)(*param_1 + 0x10))(iVar4);
          (**(code **)(*param_1 + 8))(iVar4 + 4,4,1);
          (**(code **)(*param_1 + 0x1c))();
        }
        iVar5 = iVar5 + 0xc;
        iVar2 = iVar2 + 1;
      } while (iVar2 < *piVar1);
    }
    (**(code **)(*param_1 + 0x1c))();
  }
  iVar2 = (**(code **)(*param_1 + 0x18))("ClassList");
  if (iVar2 != 0) {
    if (param_1[2] == 2) {
      iVar2 = 0;
      FUN_006cd4d0(param_1,aiStack_108,&stack0xfffffef4,0x40);
      (**(code **)(*param_1 + 8))(&stack0xfffffef4,4,1);
      if (0 < *(int *)(in_ECX + 0x24)) {
        do {
          if (aiStack_108[iVar2] != -1) {
            FUN_006cd740(param_1,aiStack_108);
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(in_ECX + 0x24));
      }
    }
    if (param_1[2] == 1) {
      piVar1 = (int *)(in_ECX + 0x24);
      (**(code **)(*param_1 + 8))(piVar1,4,1);
      iVar2 = 0;
      if (0 < *piVar1) {
        do {
          FUN_006cd740(param_1,0);
          iVar2 = iVar2 + 1;
        } while (iVar2 < *piVar1);
      }
    }
    (**(code **)(*param_1 + 0x1c))();
  }
  return;
}

