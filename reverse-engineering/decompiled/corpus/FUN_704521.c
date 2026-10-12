/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x704521; label: UnDecorator::getArrayType
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getArrayType(class DName const &)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getArrayType(DName *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  DName *pDVar3;
  undefined4 uVar4;
  DName *pDVar5;
  DName *extraout_ECX;
  int iVar6;
  DName *in_stack_00000008;
  char cVar7;
  DName local_2c [8];
  undefined4 local_24 [2];
  DName local_1c [8];
  DName local_14 [4];
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  if (*DAT_0297cb78 == '\0') {
    iVar6 = DName::isEmpty(in_stack_00000008);
    cVar7 = (char)local_2c;
    puVar2 = local_24;
    if (iVar6 == 0) {
      pDVar3 = local_1c;
      pDVar5 = (DName *)operator+((char)local_14,(DName *)0x28);
      pDVar3 = (DName *)DName::operator+(pDVar5,(char *)pDVar3);
      goto LAB_0070455d;
    }
  }
  else {
    iVar1 = getNumberOfDimensions();
    iVar6 = iVar1;
    if (iVar1 < 0) {
      iVar6 = 0;
    }
    if (0 < iVar1) {
      local_c = 0;
      local_8 = local_8 & 0xfffff000;
      if (((byte)in_stack_00000008[4] & 0x80) != 0) {
        DName::operator+=((DName *)&local_c,"[]");
      }
      do {
        cVar7 = (char)local_1c;
        iVar6 = iVar6 + -1;
        getDimension(SUB41(local_24,0));
        pDVar3 = (DName *)operator+((char)local_2c,(DName *)0x5b);
        pDVar3 = (DName *)DName::operator+(pDVar3,cVar7);
        DName::operator+=((DName *)&local_c,pDVar3);
      } while (iVar6 != 0);
      iVar6 = DName::isEmpty(in_stack_00000008);
      if (iVar6 == 0) {
        pDVar3 = local_2c;
        pDVar5 = extraout_ECX;
        if (((byte)in_stack_00000008[4] & 0x80) == 0) {
          cVar7 = (char)local_24;
          pDVar5 = (DName *)operator+((char)local_1c,(DName *)0x28);
          pDVar5 = (DName *)DName::operator+(pDVar5,cVar7);
        }
        pDVar3 = (DName *)DName::operator+(pDVar5,pDVar3);
        DName::operator=((DName *)&local_c,pDVar3);
      }
      getPrimaryDataType(local_14);
      local_10 = local_10 | 0x80;
      DName::DName(param_1,local_14);
      return param_1;
    }
    cVar7 = (char)local_14;
    puVar2 = &local_c;
  }
  pDVar3 = (DName *)DName::DName(local_1c,'[');
LAB_0070455d:
  pDVar3 = (DName *)DName::operator+(pDVar3,(DNameStatus)puVar2);
  uVar4 = DName::operator+(pDVar3,cVar7);
  FUN_007075fa(param_1,uVar4);
  return param_1;
}

