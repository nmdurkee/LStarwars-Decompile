/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x7069dc; label: UnDecorator::getFunctionIndirectType
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getFunctionIndirectType(class DName const &)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getFunctionIndirectType(DName *param_1)

{
  char *pcVar1;
  DName *pDVar2;
  DName *pDVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  DName *in_stack_00000008;
  char cVar8;
  DNameStatus DVar9;
  DName local_34 [8];
  undefined1 local_2c [8];
  DName local_24 [8];
  DName local_1c [8];
  undefined4 local_14;
  uint local_10;
  DName local_c [8];
  
  cVar8 = *DAT_0297cb78;
  if (cVar8 == '\0') {
    operator+((DNameStatus)param_1,(DName *)0x2);
    return param_1;
  }
  if (((cVar8 < '6') || ('9' < cVar8)) && (cVar8 != '_')) {
    DName::DName(param_1,1);
    return param_1;
  }
  uVar5 = (int)cVar8 - 0x36;
  pcVar1 = DAT_0297cb78 + 1;
  if (uVar5 == 0x29) {
    cVar8 = *pcVar1;
    if (cVar8 == '\0') {
      DAT_0297cb78 = pcVar1;
      operator+((DNameStatus)param_1,(DName *)0x2);
      return param_1;
    }
    uVar5 = (int)cVar8 - 0x3d;
    DAT_0297cb78 = DAT_0297cb78 + 2;
    if ((int)uVar5 < 4) goto LAB_00706a6c;
    bVar7 = SBORROW4(uVar5,7);
    iVar4 = cVar8 + -0x44;
    bVar6 = uVar5 == 7;
LAB_00706a6a:
    if (!bVar6 && bVar7 == iVar4 < 0) goto LAB_00706a6c;
  }
  else {
    DAT_0297cb78 = pcVar1;
    if (-1 < (int)uVar5) {
      bVar7 = SBORROW4(uVar5,3);
      iVar4 = cVar8 + -0x39;
      bVar6 = uVar5 == 3;
      goto LAB_00706a6a;
    }
LAB_00706a6c:
    uVar5 = 0xffffffff;
  }
  if (uVar5 == 0xffffffff) {
    DName::DName(param_1,1);
    return param_1;
  }
  local_14 = 0;
  local_10 = local_10 & 0xfffff000;
  DName::DName(local_c,in_stack_00000008);
  if ((uVar5 & 2) != 0) {
    pDVar2 = (DName *)operator+((char *)local_24,(DName *)&DAT_00781014);
    DName::operator=(local_c,pDVar2);
    if (*DAT_0297cb78 == '\0') {
      pDVar2 = (DName *)operator+((DNameStatus)local_34,(DName *)0x2);
    }
    else {
      pDVar2 = local_24;
      getScope();
      pDVar3 = (DName *)operator+((char)local_34,(DName *)0x20);
      pDVar2 = (DName *)DName::operator+(pDVar3,pDVar2);
    }
    DName::operator=(local_c,pDVar2);
    if (*DAT_0297cb78 == '\0') {
      operator+((DNameStatus)param_1,(DName *)0x2);
      return param_1;
    }
    if (*DAT_0297cb78 != '@') {
      DVar9 = 1;
      goto LAB_00706d0d;
    }
    DAT_0297cb78 = DAT_0297cb78 + 1;
    if (((byte)DAT_0297cb88 & 0x60) == 0x60) {
      pDVar2 = (DName *)getThisType();
      DName::operator|=((DName *)&local_14,pDVar2);
    }
    else {
      pDVar2 = (DName *)getThisType();
      DName::operator=((DName *)&local_14,pDVar2);
    }
  }
  if ((uVar5 & 4) != 0) {
    if ((~(DAT_0297cb88 >> 1) & 1) == 0) {
      pDVar2 = (DName *)getBasedType();
      DName::operator|=(local_c,pDVar2);
    }
    else {
      pDVar2 = local_34;
      getBasedType();
      pDVar3 = (DName *)operator+((char)local_24,(DName *)0x20);
      pDVar2 = (DName *)DName::operator+(pDVar3,pDVar2);
      DName::operator=(local_c,pDVar2);
    }
  }
  if ((~(DAT_0297cb88 >> 1) & 1) == 0) {
    pDVar2 = (DName *)getCallingConvention();
    DName::operator|=(local_c,pDVar2);
  }
  else {
    pDVar2 = local_34;
    pDVar3 = (DName *)getCallingConvention();
    pDVar2 = (DName *)DName::operator+(pDVar3,pDVar2);
    DName::operator=(local_c,pDVar2);
  }
  iVar4 = DName::isEmpty(in_stack_00000008);
  if (iVar4 == 0) {
    cVar8 = (char)local_34;
    pDVar2 = (DName *)operator+((char)local_2c,(DName *)0x28);
    pDVar2 = (DName *)DName::operator+(pDVar2,cVar8);
    DName::operator=(local_c,pDVar2);
  }
  pDVar2 = HeapManager::getMemory((HeapManager *)&DAT_0297cb58,8,0);
  if (pDVar2 == (DName *)0x0) {
    pDVar2 = (DName *)0x0;
  }
  else {
    *(undefined4 *)pDVar2 = 0;
    *(uint *)(pDVar2 + 4) = *(uint *)(pDVar2 + 4) & 0xfffff000;
  }
  getReturnType(local_1c);
  cVar8 = (char)local_34;
  getArgumentTypes();
  pDVar3 = (DName *)operator+((char)local_24,(DName *)0x28);
  pDVar3 = (DName *)DName::operator+(pDVar3,cVar8);
  DName::operator+=(local_c,pDVar3);
  if ((((byte)DAT_0297cb88 & 0x60) != 0x60) && ((uVar5 & 2) != 0)) {
    DName::operator+=(local_c,(DName *)&local_14);
  }
  if ((~(DAT_0297cb88 >> 8) & 1) == 0) {
    pDVar3 = (DName *)getThrowTypes();
    DName::operator|=(local_c,pDVar3);
  }
  else {
    pDVar3 = (DName *)getThrowTypes();
    DName::operator+=(local_c,pDVar3);
  }
  if (pDVar2 != (DName *)0x0) {
    DName::operator=(pDVar2,local_c);
    DName::DName(param_1,local_1c);
    return param_1;
  }
  DVar9 = 3;
LAB_00706d0d:
  DName::DName(param_1,DVar9);
  return param_1;
}

