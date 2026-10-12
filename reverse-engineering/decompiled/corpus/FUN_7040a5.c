/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x7040a5; label: UnDecorator::getDimension
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getDimension(bool)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getDimension(bool param_1)

{
  __uint64 _Var1;
  char *pcVar2;
  char cVar3;
  DName *pDVar4;
  longlong lVar5;
  undefined3 in_stack_00000005;
  char in_stack_00000008;
  DNameStatus DVar6;
  DName local_20 [8];
  char local_18 [8];
  DName local_10 [4];
  int local_c;
  DName *local_8;
  
  local_8 = (DName *)0x0;
  if (*DAT_0297cb78 == 'Q') {
    DAT_0297cb78 = DAT_0297cb78 + 1;
    local_8 = (DName *)0x780f10;
  }
  cVar3 = *DAT_0297cb78;
  if (cVar3 == '\0') {
    DName::DName(_param_1,2);
    return _param_1;
  }
  if (('/' < cVar3) && (cVar3 < ':')) {
    cVar3 = *DAT_0297cb78;
    DAT_0297cb78 = DAT_0297cb78 + 1;
    if (local_8 == (DName *)0x0) {
      pDVar4 = (DName *)DName::DName(local_20,(longlong)(cVar3 + -0x2f));
    }
    else {
      DName::DName(local_10,(longlong)(cVar3 + -0x2f));
      pDVar4 = (DName *)operator+(local_18,local_8);
    }
    DName::DName(_param_1,pDVar4);
    return _param_1;
  }
  _Var1 = 0;
  while (pcVar2 = DAT_0297cb78, cVar3 != '@') {
    if (cVar3 == '\0') {
      DVar6 = 2;
      goto LAB_00704196;
    }
    if ((cVar3 < 'A') || ('P' < cVar3)) goto LAB_007041a0;
    local_c = cVar3 + -0x41 >> 0x1f;
    lVar5 = __allmul(_Var1,0x10,0);
    _Var1 = lVar5 + CONCAT44(local_c,cVar3 + -0x41);
    DAT_0297cb78 = pcVar2 + 1;
    cVar3 = *DAT_0297cb78;
  }
  cVar3 = *DAT_0297cb78;
  DAT_0297cb78 = DAT_0297cb78 + 1;
  if (cVar3 != '@') {
LAB_007041a0:
    DVar6 = 1;
LAB_00704196:
    DName::DName(_param_1,DVar6);
    return _param_1;
  }
  if (in_stack_00000008 == '\0') {
    if (local_8 == (DName *)0x0) {
      pDVar4 = (DName *)DName::DName(local_10,_Var1);
      goto LAB_007041d5;
    }
    DName::DName(local_20,_Var1);
  }
  else {
    if (local_8 == (DName *)0x0) {
      pDVar4 = (DName *)FUN_00703a8b(_Var1);
      goto LAB_007041d5;
    }
    FUN_00703a8b(_Var1);
  }
  pDVar4 = (DName *)operator+(local_18,local_8);
LAB_007041d5:
  DName::DName(_param_1,pDVar4);
  return _param_1;
}

