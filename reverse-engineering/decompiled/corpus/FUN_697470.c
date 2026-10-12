/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x697470; label: FUN_00697470
 */

uint FUN_00697470(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if ((*(int *)(in_ECX + 0xd18) == 0) || (DAT_00827610 == 0)) {
    return 0xffffffff;
  }
  if ((*(int *)(in_ECX + 0xd0c) != 0) &&
     (iVar6 = param_1 * 0x40c, *(char *)(*(int *)(in_ECX + 0xd0c) + 0x404 + iVar6) != '\0')) {
    if (param_2 == 0) {
      uVar2 = 0;
      uVar4 = 0x20;
    }
    else {
      uVar2 = 0x20;
      uVar4 = 0x40;
    }
    if (uVar2 < uVar4) {
      piVar3 = (int *)(uVar2 * 0x34 + 0xc + in_ECX);
      while (*piVar3 != 0) {
        uVar2 = uVar2 + 1;
        piVar3 = piVar3 + 0xd;
        if ((int)uVar4 <= (int)uVar2) {
          return 0xffffffff;
        }
      }
      iVar5 = -0x7fffbffb;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_02972bcc);
      iVar1 = *(int *)(*(int *)(in_ECX + 0xd0c) + iVar6);
      if (iVar1 != 0) {
        iVar5 = (**(code **)(**(int **)(in_ECX + 0xd18) + 0x14))
                          (*(int **)(in_ECX + 0xd18),iVar1,uVar2 * 0x34 + 0xc + in_ECX);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_02972bcc);
      if (-1 < iVar5) {
        iVar1 = uVar2 * 0x34 + in_ECX;
        *(int *)(iVar1 + 0x1c) = param_1;
        *(int *)(iVar1 + 0x14) = *(int *)(in_ECX + 0xd0c) + iVar6;
        *(int *)(in_ECX + 0xd10) = *(int *)(in_ECX + 0xd10) + 1;
        return uVar2;
      }
      FUN_00696ab0();
    }
    return 0xffffffff;
  }
  return 0xffffffff;
}

