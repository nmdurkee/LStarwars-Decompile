/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x705549; label: UnDecorator::getZName
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getZName(bool)
   
   Library: Visual Studio 2005 Release */

void __cdecl UnDecorator::getZName(bool param_1)

{
  DName *pDVar1;
  long lVar2;
  DName *pDVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  undefined3 in_stack_00000005;
  char in_stack_00000008;
  DName local_3c [8];
  DName local_34 [8];
  DName *local_2c;
  DName local_28 [8];
  undefined4 local_20;
  uint local_1c;
  char local_18 [16];
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  uVar4 = (int)*DAT_0297cb78 - 0x30;
  local_2c = _param_1;
  if (uVar4 < 10) {
    DAT_0297cb78 = DAT_0297cb78 + 1;
    pDVar1 = Replicator::operator[](DAT_0297cb70,uVar4);
    DName::DName(_param_1,pDVar1);
    goto LAB_00705726;
  }
  local_20 = 0;
  local_1c = local_1c & 0xfffff000;
  if (*DAT_0297cb78 == '?') {
    pDVar1 = (DName *)getTemplateName(SUB41(local_28,0));
    DName::operator=((DName *)&local_20,pDVar1);
    pcVar7 = DAT_0297cb78 + 1;
    if (*DAT_0297cb78 != '@') {
      DName::operator=((DName *)&local_20,(*DAT_0297cb78 == '\0') + 1);
      pcVar7 = DAT_0297cb78;
    }
  }
  else {
    pcVar5 = "template-parameter-";
    pcVar8 = "template-parameter-";
    iVar6 = 0x12;
    pcVar7 = DAT_0297cb78;
    do {
      if ((*pcVar7 == '\0') || (*pcVar7 != *pcVar8)) break;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (*pcVar7 == *pcVar8) {
      DAT_0297cb78 = DAT_0297cb78 + 0x13;
    }
    else {
      pcVar5 = "generic-type-";
      pcVar8 = "generic-type-";
      iVar6 = 0xc;
      pcVar7 = DAT_0297cb78;
      do {
        if ((*pcVar7 == '\0') || (*pcVar7 != *pcVar8)) break;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      if (*pcVar7 != *pcVar8) {
        pDVar1 = (DName *)DName::DName(local_34,&DAT_0297cb78,'@');
        DName::operator=((DName *)&local_20,pDVar1);
        pcVar7 = DAT_0297cb78;
        goto LAB_007056fd;
      }
      DAT_0297cb78 = DAT_0297cb78 + 0xd;
    }
    getSignedDimension();
    if (((ushort)DAT_0297cb88 & 0x4000) == 0) {
      DName::operator=((DName *)&local_20,"`");
      pDVar1 = local_34;
      pDVar3 = local_3c;
    }
    else {
      DName::getString(local_28,local_18,0x10);
      lVar2 = _atol(local_18);
      pcVar7 = (char *)(*DAT_0297cb8c)(lVar2);
      if (pcVar7 != (char *)0x0) {
        DName::operator=((DName *)&local_20,pcVar7);
        pcVar7 = DAT_0297cb78;
        goto LAB_007056fd;
      }
      DName::operator=((DName *)&local_20,"`");
      pDVar1 = local_3c;
      pDVar3 = local_34;
    }
    pDVar3 = (DName *)operator+((char *)pDVar3,(DName *)pcVar5);
    pDVar1 = (DName *)DName::operator+(pDVar3,(char *)pDVar1);
    DName::operator+=((DName *)&local_20,pDVar1);
    pcVar7 = DAT_0297cb78;
  }
LAB_007056fd:
  DAT_0297cb78 = pcVar7;
  if ((in_stack_00000008 != '\0') && (*(int *)DAT_0297cb70 != 9)) {
    Replicator::operator+=(DAT_0297cb70,(DName *)&local_20);
  }
  DName::DName(local_2c,(DName *)&local_20);
LAB_00705726:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

