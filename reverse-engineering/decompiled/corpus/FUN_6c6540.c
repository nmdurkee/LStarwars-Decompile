/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c6540; label: FUN_006c6540
 */

void FUN_006c6540(int *param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int unaff_EBX;
  int iVar6;
  int iVar7;
  int local_10c;
  undefined1 local_108 [256];
  uint uStack_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_10c;
  local_10c = param_2;
  iVar4 = (**(code **)(*param_1 + 0x18))("Object");
  if (iVar4 != 0) {
    if (param_2 != 0) {
      for (piVar1 = *(int **)(in_ECX + 8); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
        uVar2 = piVar1[7];
        if ((param_1[7] & 0x400000U) == 0) {
          uVar3 = uVar2 & 0x10000000;
        }
        else {
          uVar3 = uVar2 & 0x400000;
        }
        if (uVar3 == 0) {
          iVar4 = piVar1[3];
          if ((int)uVar2 < 0) {
            uVar5 = (**(code **)*piVar1)(param_2);
            FUN_006c6540(param_1,uVar5);
          }
          else {
            if ((iVar4 < 0) || (DAT_02973ba4 <= iVar4)) {
              iVar7 = 0;
            }
            else {
              iVar7 = DAT_02973b8c + iVar4 * 0xc;
            }
            iVar6 = piVar1[6];
            if (iVar6 < 1) {
              iVar6 = *(int *)(iVar7 + 4);
            }
            if (param_1[2] == 2) {
              (**(code **)(*piVar1 + 4))(unaff_EBX,iVar4,local_108,0x100);
            }
            (**(code **)(iVar7 + 8))(param_1,local_108,iVar6);
            if (param_1[2] == 1) {
              (**(code **)(*piVar1 + 8))(unaff_EBX,piVar1[3],local_108,0x100,0);
            }
          }
        }
        in_ECX = local_10c;
        param_2 = unaff_EBX;
      }
      if (*(int *)(in_ECX + 0x14) != 0) {
        (**(code **)(**(int **)(in_ECX + 0x14) + 100))(param_1,param_2);
      }
    }
    (**(code **)(*param_1 + 0x1c))();
  }
  __security_check_cookie(uStack_8 ^ (uint)&stack0xfffffef0);
  return;
}

