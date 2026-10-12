/* Ghidra analysis pseudocode, not original source.
 * ev_5fe54c2a55e5805f81bff5ddaf4fd9cf0184cfdba0adc5a7ca08f803c24de38d
 * Entry: 0x6edbe0; label: __except_handler4
 */

/* Library Function - Single Match
    __except_handler4
   
   Library: Visual Studio 2005 Release */

undefined4 __except_handler4(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  BOOL BVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 local_c;
  int *local_8;
  undefined4 local_4;
  
  piVar8 = (int *)(*(uint *)(param_2 + 8) ^ DAT_00829570);
  bVar3 = false;
  local_c = 1;
  iVar1 = param_2 + 0x10;
  if (*piVar8 != -2) {
    __security_check_cookie(piVar8[1] + iVar1 ^ *(uint *)(*piVar8 + iVar1));
  }
  __security_check_cookie(piVar8[3] + iVar1 ^ *(uint *)(piVar8[2] + iVar1));
  if ((*(byte *)(param_1 + 1) & 0x66) == 0) {
    local_8 = param_1;
    local_4 = param_3;
    *(int ***)(param_2 + -4) = &local_8;
    iVar7 = *(int *)(param_2 + 0xc);
    if (*(int *)(param_2 + 0xc) == -2) {
      return 1;
    }
    do {
      iVar2 = piVar8[iVar7 * 3 + 4];
      if (piVar8[iVar7 * 3 + 5] != 0) {
        iVar4 = _EH4_CallFilterFunc(piVar8[iVar7 * 3 + 5],iVar1);
        bVar3 = true;
        if (iVar4 < 0) {
          local_c = 0;
          goto LAB_006edc8b;
        }
        if (0 < iVar4) {
          if ((*param_1 == -0x1f928c9d) &&
             (BVar5 = __IsNonwritableInCurrentImage((PBYTE)&PTR____DestructExceptionObject_0077dff0)
             , BVar5 != 0)) {
            ___DestructExceptionObject(param_1,1);
          }
          _EH4_GlobalUnwind(param_2);
          if (*(int *)(param_2 + 0xc) != iVar7) {
            _EH4_LocalUnwind(param_2,iVar7,iVar1,&DAT_00829570);
          }
          *(int *)(param_2 + 0xc) = iVar2;
          if (*piVar8 != -2) {
            __security_check_cookie(piVar8[1] + iVar1 ^ *(uint *)(*piVar8 + iVar1));
          }
          __security_check_cookie(piVar8[3] + iVar1 ^ *(uint *)(piVar8[2] + iVar1));
          uVar6 = _EH4_TransferToHandler((piVar8 + iVar7 * 3 + 4)[2],iVar1);
          return uVar6;
        }
      }
      iVar7 = iVar2;
    } while (iVar2 != -2);
    if (!bVar3) {
      return 1;
    }
  }
  else {
    if (*(int *)(param_2 + 0xc) == -2) {
      return 1;
    }
    _EH4_LocalUnwind(param_2,0xfffffffe,iVar1,&DAT_00829570);
  }
LAB_006edc8b:
  if (*piVar8 != -2) {
    __security_check_cookie(piVar8[1] + iVar1 ^ *(uint *)(*piVar8 + iVar1));
  }
  __security_check_cookie(piVar8[3] + iVar1 ^ *(uint *)(piVar8[2] + iVar1));
  return local_c;
}

