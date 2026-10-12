/* Ghidra pseudocode, not original source.
 * ev_385d2e0ae9f698ed8d8344a9eff47b620edc6fea7a522ef369bc7c504a46373d
 * Entry: 0x704837; label: UnDecorator::getStringEncoding
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getStringEncoding(char *,int)
   
   Library: Visual Studio 2005 Release */

char * __cdecl UnDecorator::getStringEncoding(char *param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  DNameStatus DVar3;
  undefined1 local_14 [8];
  DName local_c [8];
  
  DName::DName(local_c,(char *)param_2);
  pcVar1 = DAT_0297cb78;
  cVar2 = *DAT_0297cb78;
  DAT_0297cb78 = DAT_0297cb78 + 1;
  if ((cVar2 == '@') && (cVar2 = *DAT_0297cb78, DAT_0297cb78 = pcVar1 + 2, cVar2 == '_')) {
    DAT_0297cb78 = pcVar1 + 3;
    getDimension(SUB41(local_14,0));
    getDimension(SUB41(local_14,0));
    cVar2 = *DAT_0297cb78;
    if (cVar2 != '\0') {
      do {
        if (cVar2 == '@') break;
        DAT_0297cb78 = DAT_0297cb78 + 1;
        cVar2 = *DAT_0297cb78;
      } while (cVar2 != '\0');
      if (*DAT_0297cb78 != '\0') {
        DAT_0297cb78 = DAT_0297cb78 + 1;
        DName::DName((DName *)param_1,local_c);
        return param_1;
      }
    }
    DAT_0297cb78 = DAT_0297cb78 + -1;
    DVar3 = 2;
  }
  else {
    DVar3 = 1;
  }
  DName::DName((DName *)param_1,DVar3);
  return param_1;
}

