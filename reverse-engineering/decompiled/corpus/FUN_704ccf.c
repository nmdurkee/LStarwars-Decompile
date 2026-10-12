/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x704ccf; label: UnDecorator::getTemplateArgumentList
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getTemplateArgumentList(void)
   
   Library: Visual Studio 2005 Release */

void __cdecl UnDecorator::getTemplateArgumentList(void)

{
  DName DVar1;
  char cVar2;
  char *pcVar3;
  DName *pDVar4;
  long lVar5;
  char *pcVar6;
  DName *in_stack_00000004;
  char *pcVar7;
  char local_5c [8];
  DName local_54 [8];
  char local_4c [8];
  char local_44 [8];
  char local_3c [8];
  undefined4 local_34;
  uint local_30;
  DName local_2c [8];
  int local_24;
  undefined4 local_20;
  uint local_1c;
  char local_18 [16];
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)in_stack_00000004 = 0;
  *(uint *)(in_stack_00000004 + 4) = *(uint *)(in_stack_00000004 + 4) & 0xfffff000;
  DAT_0297cb91 = 1;
  DVar1 = in_stack_00000004[4];
  local_24 = 1;
  do {
    if (((((byte)DVar1 & 0xf) != 0) || (*DAT_0297cb78 == '\0')) || (*DAT_0297cb78 == '@')) {
      DAT_0297cb91 = 0;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (local_24 == 0) {
      DName::operator+=(in_stack_00000004,',');
    }
    else {
      local_24 = 0;
    }
    pcVar3 = DAT_0297cb78;
    cVar2 = *DAT_0297cb78;
    if ((int)cVar2 - 0x30U < 10) {
      DAT_0297cb78 = DAT_0297cb78 + 1;
      pDVar4 = Replicator::operator[](DAT_0297cb74,(int)cVar2 - 0x30U);
    }
    else {
      local_20 = 0;
      local_1c = local_1c & 0xfffff000;
      if (cVar2 == 'X') {
        DAT_0297cb78 = DAT_0297cb78 + 1;
        pcVar7 = "void";
LAB_00704d77:
        DName::operator=((DName *)&local_20,pcVar7);
      }
      else {
        if ((cVar2 == '$') && (DAT_0297cb78[1] != '$')) {
          DAT_0297cb78 = DAT_0297cb78 + 1;
          pDVar4 = (DName *)getTemplateConstant();
        }
        else if (cVar2 == '?') {
          getSignedDimension();
          if (((ushort)DAT_0297cb88 & 0x4000) == 0) {
            pcVar7 = local_5c;
            pcVar6 = local_44;
          }
          else {
            DName::getString(local_2c,local_18,0x10);
            lVar5 = _atol(local_18);
            pcVar7 = (char *)(*DAT_0297cb8c)(lVar5);
            if (pcVar7 != (char *)0x0) goto LAB_00704d77;
            pcVar7 = local_3c;
            pcVar6 = local_4c;
          }
          pDVar4 = (DName *)operator+(pcVar6,(DName *)"`template-parameter");
          pDVar4 = (DName *)DName::operator+(pDVar4,pcVar7);
        }
        else {
          local_34 = 0;
          local_30 = local_30 & 0xfffff000;
          pDVar4 = (DName *)getPrimaryDataType(local_54);
        }
        DName::operator=((DName *)&local_20,pDVar4);
      }
      if ((1 < (int)DAT_0297cb78 - (int)pcVar3) && (*(int *)DAT_0297cb74 != 9)) {
        Replicator::operator+=(DAT_0297cb74,(DName *)&local_20);
      }
      pDVar4 = (DName *)&local_20;
    }
    DName::operator+=(in_stack_00000004,pDVar4);
    DVar1 = in_stack_00000004[4];
  } while( true );
}

