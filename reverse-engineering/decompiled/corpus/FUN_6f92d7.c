/* Ghidra analysis pseudocode, not original source.
 * ev_ad38b5b12c7b5b6be74e46159191c12aead9520624245f9f1862d693e1fa9ce5
 * Entry: 0x6f92d7; label: FindHandler
 */

/* Library Function - Single Match
    void __cdecl FindHandler(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,unsigned char,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 2005 Release */

void __cdecl
FindHandler(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
           _s_FuncInfo *param_5,uchar param_6,int param_7,EHRegistrationNode *param_8)

{
  uchar uVar1;
  bool bVar2;
  _ptiddata p_Var3;
  int iVar4;
  _s_TryBlockMapEntry *p_Var5;
  EHRegistrationNode *unaff_EBX;
  int iVar6;
  int *piVar7;
  _s_FuncInfo *p_Var8;
  int unaff_ESI;
  EHExceptionRecord *pEVar9;
  _s_ESTypeList *unaff_EDI;
  EHRegistrationNode *pEVar10;
  undefined4 in_stack_ffffffd0;
  uint local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  char local_5;
  
  p_Var8 = param_5;
  local_5 = '\0';
  if (*(int *)(param_5 + 4) < 0x81) {
    local_c = (int)(char)param_2[8];
  }
  else {
    local_c = *(int *)(param_2 + 8);
  }
  if ((local_c < -1) || (*(int *)(param_5 + 4) <= local_c)) {
    _inconsistency();
  }
  pEVar9 = param_1;
  if (*(int *)param_1 == -0x1f928c9d) {
    if (((*(int *)(param_1 + 0x10) == 3) &&
        (((iVar4 = *(int *)(param_1 + 0x14), iVar4 == 0x19930520 || (iVar4 == 0x19930521)) ||
         (iVar4 == 0x19930522)))) && (*(int *)(param_1 + 0x1c) == 0)) {
      p_Var3 = __getptd();
      if (p_Var3->_curexception == (void *)0x0) {
        return;
      }
      p_Var3 = __getptd();
      pEVar9 = p_Var3->_curexception;
      param_1 = pEVar9;
      p_Var3 = __getptd();
      param_3 = p_Var3->_curcontext;
      iVar4 = _ValidateRead(pEVar9,1);
      if (iVar4 == 0) {
        _inconsistency();
      }
      if ((((*(int *)pEVar9 == -0x1f928c9d) && (*(int *)(pEVar9 + 0x10) == 3)) &&
          ((iVar4 = *(int *)(pEVar9 + 0x14), iVar4 == 0x19930520 ||
           ((iVar4 == 0x19930521 || (iVar4 == 0x19930522)))))) && (*(int *)(pEVar9 + 0x1c) == 0)) {
        _inconsistency();
      }
      p_Var3 = __getptd();
      if (p_Var3->_curexcspec != (void *)0x0) {
        p_Var3 = __getptd();
        piVar7 = p_Var3->_curexcspec;
        p_Var3 = __getptd();
        iVar4 = 0;
        p_Var3->_curexcspec = (void *)0x0;
        uVar1 = IsInExceptionSpec(param_1,unaff_EDI);
        pEVar9 = param_1;
        if (uVar1 == '\0') {
          iVar6 = 0;
          if (0 < *piVar7) {
            do {
              bVar2 = type_info::operator==
                                (*(type_info **)(iVar6 + 4 + piVar7[1]),
                                 (type_info *)&PTR_PTR_00829f14);
              if (bVar2) {
                ___DestructExceptionObject(param_1,1);
                param_1 = (EHExceptionRecord *)s_bad_exception_0077e000;
                std::exception::exception((exception *)&stack0xffffffd0,(char **)&param_1);
                    /* WARNING: Subroutine does not return */
                __CxxThrowException_8(&stack0xffffffd0,&DAT_007ed5ec);
              }
              iVar4 = iVar4 + 1;
              iVar6 = iVar6 + 0x10;
            } while (iVar4 < *piVar7);
          }
          goto LAB_006f9415;
        }
      }
    }
    p_Var8 = param_5;
    if (((*(int *)pEVar9 == -0x1f928c9d) && (*(int *)(pEVar9 + 0x10) == 3)) &&
       ((iVar4 = *(int *)(pEVar9 + 0x14), iVar4 == 0x19930520 ||
        ((iVar4 == 0x19930521 || (iVar4 == 0x19930522)))))) {
      if (*(int *)(param_5 + 0xc) != 0) {
        p_Var5 = _GetRangeOfTrysToCheck(param_5,param_7,local_c,&local_14,&local_20);
        for (; local_14 < local_20; local_14 = local_14 + 1) {
          if ((*(int *)p_Var5 <= local_c) && (local_c <= *(int *)(p_Var5 + 4))) {
            local_10 = *(int *)(p_Var5 + 0x10);
            for (local_1c = *(int *)(p_Var5 + 0xc); 0 < local_1c; local_1c = local_1c + -1) {
              piVar7 = *(int **)(*(int *)(pEVar9 + 0x1c) + 0xc);
              for (local_18 = *piVar7; 0 < local_18; local_18 = local_18 + -1) {
                piVar7 = piVar7 + 1;
                p_Var8 = (_s_FuncInfo *)*piVar7;
                iVar4 = ___TypeMatch(local_10,p_Var8,*(undefined4 *)(pEVar9 + 0x1c));
                if (iVar4 != 0) {
                  local_5 = '\x01';
                  CatchIt(pEVar9,(EHRegistrationNode *)param_3,param_4,param_5,p_Var8,
                          (_s_HandlerType *)param_7,(_s_CatchableType *)param_8,
                          (_s_TryBlockMapEntry *)unaff_EDI,unaff_ESI,unaff_EBX,
                          (uchar)SUB41(in_stack_ffffffd0,0));
                  pEVar9 = param_1;
                  goto LAB_006f953f;
                }
              }
              local_10 = local_10 + 0x10;
            }
          }
LAB_006f953f:
          p_Var5 = p_Var5 + 0x14;
        }
      }
      p_Var8 = param_5;
      if (param_6 != '\0') {
        ___DestructExceptionObject(pEVar9,1);
      }
      if ((((local_5 != '\0') || ((*(uint *)p_Var8 & 0x1fffffff) < 0x19930521)) ||
          (*(int *)(p_Var8 + 0x1c) == 0)) ||
         (uVar1 = IsInExceptionSpec(pEVar9,unaff_EDI), uVar1 != '\0')) goto LAB_006f9615;
      __getptd();
      __getptd();
      p_Var3 = __getptd();
      p_Var3->_curexception = pEVar9;
      p_Var3 = __getptd();
      p_Var3->_curcontext = param_3;
      pEVar10 = param_8;
      if (param_8 == (EHRegistrationNode *)0x0) {
        pEVar10 = param_2;
      }
      _UnwindNestedFrames(pEVar10,pEVar9);
      pEVar9 = (EHExceptionRecord *)param_5;
      ___FrameUnwindToState(param_2,param_4,param_5,0xffffffff);
      CallUnexpected(*(_s_ESTypeList **)(pEVar9 + 0x1c));
      p_Var8 = param_5;
    }
  }
  if (*(int *)(p_Var8 + 0xc) != 0) {
    if (param_6 != '\0') {
LAB_006f9415:
      terminate();
      return;
    }
    FindHandlerForForeignException(pEVar9,param_2,param_3,param_4,p_Var8,local_c,param_7,param_8);
  }
LAB_006f9615:
  p_Var3 = __getptd();
  if (p_Var3->_curexcspec != (void *)0x0) {
    _inconsistency();
  }
  return;
}

