/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x705826; label: UnDecorator::getECSUDataType
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getECSUDataType(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getECSUDataType(void)

{
  char cVar1;
  DName *pDVar2;
  uint uVar3;
  uint uVar4;
  DName *in_stack_00000004;
  char *pcVar5;
  char local_1c [8];
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  pcVar5 = DAT_0297cb78;
  uVar4 = 1;
  uVar3 = ~(DAT_0297cb88 >> 0xf) & 1;
  if ((uVar3 == 0) || ((DAT_0297cb88 & 0x1000) != 0)) {
    uVar4 = 0;
  }
  cVar1 = *DAT_0297cb78;
  local_c = 0;
  local_8 = local_8 & 0xfffff000;
  DAT_0297cb78 = DAT_0297cb78 + 1;
  if (cVar1 == '\0') {
    DAT_0297cb78 = pcVar5;
    DName::DName(in_stack_00000004,"nknown ecsu\'");
    return in_stack_00000004;
  }
  if (cVar1 == 'T') {
    pcVar5 = "union ";
  }
  else if (cVar1 == 'U') {
    pcVar5 = "struct ";
  }
  else if (cVar1 == 'V') {
    pcVar5 = "class ";
  }
  else {
    if (cVar1 == 'W') {
      getEnumType();
      pDVar2 = (DName *)operator+(local_1c,(DName *)"enum ");
      DName::operator=((DName *)&local_c,pDVar2);
      goto LAB_007058d1;
    }
    if (cVar1 == 'X') {
      pcVar5 = "coclass ";
    }
    else {
      uVar3 = uVar4;
      if (cVar1 != 'Y') goto LAB_007058d1;
      pcVar5 = "cointerface ";
    }
  }
  DName::operator=((DName *)&local_c,pcVar5);
  uVar3 = uVar4;
LAB_007058d1:
  local_14 = 0;
  local_10 = local_10 & 0xfffff000;
  if (uVar3 != 0) {
    DName::operator=((DName *)&local_14,(DName *)&local_c);
  }
  getScopedName();
  DName::operator+=((DName *)&local_14,(DName *)&local_c);
  DName::DName(in_stack_00000004,(DName *)&local_14);
  return in_stack_00000004;
}

