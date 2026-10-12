/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x7041e6; label: UnDecorator::getEnumType
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getEnumType(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getEnumType(void)

{
  char cVar1;
  DName *pDVar2;
  DName *in_stack_00000004;
  char *pcVar3;
  DNameStatus DVar4;
  char local_14 [8];
  undefined4 local_c;
  uint local_8;
  
  local_c = 0;
  local_8 = local_8 & 0xfffff000;
  if (*DAT_0297cb78 == '\0') {
    DVar4 = 2;
LAB_0070428b:
    DName::DName(in_stack_00000004,DVar4);
    return in_stack_00000004;
  }
  switch(*DAT_0297cb78) {
  case '0':
  case '1':
    pcVar3 = "char ";
    break;
  case '2':
  case '3':
    pcVar3 = "short ";
    break;
  case '4':
    goto switchD_00704211_caseD_34;
  case '5':
    pcVar3 = "int ";
    break;
  case '6':
  case '7':
    pcVar3 = "long ";
    break;
  default:
    DVar4 = 1;
    goto LAB_0070428b;
  }
  DName::operator=((DName *)&local_c,pcVar3);
switchD_00704211_caseD_34:
  cVar1 = *DAT_0297cb78;
  DAT_0297cb78 = DAT_0297cb78 + 1;
  if ((((cVar1 == '1') || (cVar1 == '3')) || (cVar1 == '5')) || (cVar1 == '7')) {
    pDVar2 = (DName *)operator+(local_14,(DName *)"unsigned ");
    DName::operator=((DName *)&local_c,pDVar2);
  }
  DName::DName(in_stack_00000004,(DName *)&local_c);
  return in_stack_00000004;
}

