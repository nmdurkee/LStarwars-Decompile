/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x706540; label: UnDecorator::getDecoratedName
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getDecoratedName(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getDecoratedName(void)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  DName *pDVar4;
  DName *pDVar5;
  uint extraout_EDX;
  uint uVar6;
  DName *in_stack_00000004;
  DNameStatus DVar7;
  DName local_24 [8];
  DName local_1c [8];
  undefined4 local_14;
  uint local_10;
  DName local_c [4];
  uint local_8;
  
  if ((DAT_0297cb88 & 0x2000) == 0) {
    if (*DAT_0297cb78 != '?') {
      if (*DAT_0297cb78 == '\0') {
        DVar7 = 2;
        goto LAB_00706742;
      }
LAB_007066f0:
      DVar7 = 1;
LAB_00706742:
      DName::DName(in_stack_00000004,DVar7);
      return in_stack_00000004;
    }
    pcVar2 = DAT_0297cb78 + 1;
    if ((*pcVar2 != '?') || (DAT_0297cb78[2] != '?')) {
      DAT_0297cb78 = pcVar2;
      getSymbolName();
      iVar3 = DName::isEmpty(local_c);
      if ((iVar3 == 0) && ((local_8 & 0x20) != 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      uVar6 = local_8 >> 0xb;
      iVar3 = DName::isValid(local_c);
      if (iVar3 != 0) {
        if ((*DAT_0297cb78 != '\0') && (*DAT_0297cb78 != '@')) {
          getScope();
          iVar3 = DName::isEmpty((DName *)&local_14);
          if (iVar3 == 0) {
            if (DAT_0297cb90 == '\0') {
              pDVar4 = local_24;
              pDVar5 = local_1c;
            }
            else {
              DAT_0297cb90 = '\0';
              pDVar4 = (DName *)DName::operator+(local_c,local_1c);
              DName::operator=(local_c,pDVar4);
              if (*DAT_0297cb78 == '@') goto LAB_007066a5;
              pDVar4 = (DName *)getScope();
              DName::operator=((DName *)&local_14,pDVar4);
              pDVar4 = local_1c;
              pDVar5 = local_24;
            }
            pDVar5 = (DName *)DName::operator+((DName *)&local_14,(char *)pDVar5);
            pDVar4 = (DName *)DName::operator+(pDVar5,pDVar4);
            DName::operator=(local_c,pDVar4);
          }
        }
LAB_007066a5:
        if ((bVar1) && (iVar3 = DName::isEmpty(local_c), iVar3 == 0)) {
          local_8 = local_8 | 0x20;
        }
        if ((uVar6 & 1) != 0) {
          local_8 = local_8 | 0x800;
        }
        iVar3 = DName::isEmpty(local_c);
        if ((iVar3 == 0) && ((local_8 & 0x100) == 0)) {
          if (*DAT_0297cb78 != '\0') {
            if (*DAT_0297cb78 != '@') goto LAB_007066f0;
            DAT_0297cb78 = DAT_0297cb78 + 1;
          }
          if ((((DAT_0297cb88 & 0x1000) == 0) || (bVar1)) || ((local_8 & extraout_EDX) != 0)) {
            composeDeclaration(in_stack_00000004);
            return in_stack_00000004;
          }
          local_14 = 0;
          local_10 = local_10 & 0xfffff000;
          composeDeclaration(local_24);
        }
      }
      pDVar4 = local_c;
      goto LAB_00706575;
    }
    DAT_0297cb78 = pcVar2;
    getDecoratedName();
    for (; *DAT_0297cb78 != '\0'; DAT_0297cb78 = DAT_0297cb78 + 1) {
    }
  }
  else {
    DAT_0297cb88 = DAT_0297cb88 & 0xffffdfff;
    getDataType((DName *)&local_14);
    DAT_0297cb88 = DAT_0297cb88 | 0x2000;
  }
  pDVar4 = (DName *)&local_14;
LAB_00706575:
  DName::DName(in_stack_00000004,pDVar4);
  return in_stack_00000004;
}

