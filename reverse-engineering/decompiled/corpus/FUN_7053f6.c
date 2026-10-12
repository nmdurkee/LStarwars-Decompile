/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x7053f6; label: UnDecorator::getTemplateName
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getTemplateName(bool)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getTemplateName(bool param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  DName *pDVar5;
  int iVar6;
  undefined3 in_stack_00000005;
  char in_stack_00000008;
  Replicator local_d4 [60];
  Replicator local_98 [60];
  Replicator local_5c [60];
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined4 local_10;
  uint local_c;
  char local_5;
  
  uVar3 = DAT_0297cb74;
  uVar2 = DAT_0297cb70;
  uVar1 = DAT_0297cb6c;
  if ((*DAT_0297cb78 == '?') && (DAT_0297cb78[1] == '$')) {
    DAT_0297cb78 = DAT_0297cb78 + 2;
    Replicator::Replicator(local_98);
    Replicator::Replicator(local_5c);
    Replicator::Replicator(local_d4);
    local_10 = 0;
    local_c = local_c & 0xfffff000;
    DAT_0297cb6c = local_98;
    DAT_0297cb70 = local_5c;
    DAT_0297cb74 = local_d4;
    local_5 = '\0';
    if (*DAT_0297cb78 == '?') {
      DAT_0297cb78 = DAT_0297cb78 + 1;
      pDVar5 = (DName *)getOperatorName(SUB41(local_18,0),(bool *)0x1);
    }
    else {
      pDVar5 = (DName *)getZName(SUB41(local_18,0));
    }
    DName::operator=((DName *)&local_10,pDVar5);
    iVar6 = DName::isEmpty((DName *)&local_10);
    if (iVar6 != 0) {
      DAT_0297cb90 = 1;
    }
    if (local_5 == '\0') {
      getTemplateArgumentList();
      pDVar5 = (DName *)operator+((char)local_20,(DName *)0x3c);
      DName::operator+=((DName *)&local_10,pDVar5);
      cVar4 = DName::getLastChar((DName *)&local_10);
      if (cVar4 == '>') {
        DName::operator+=((DName *)&local_10,' ');
      }
      DName::operator+=((DName *)&local_10,'>');
      if (in_stack_00000008 != '\0') {
        DAT_0297cb78 = DAT_0297cb78 + 1;
      }
    }
    DAT_0297cb6c = (Replicator *)uVar1;
    DAT_0297cb70 = (Replicator *)uVar2;
    DAT_0297cb74 = (Replicator *)uVar3;
    DName::DName(_param_1,(DName *)&local_10);
  }
  else {
    DName::DName(_param_1,1);
  }
  return _param_1;
}

