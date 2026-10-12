/* Ghidra analysis pseudocode, not original source.
 * ev_75a7d2b24aeb03b7e743c7a0854f91e7fe1db20b8c79637047cd036a94f43c24
 * Entry: 0x707201; label: UnDecorator::operator_char*
 */

/* Library Function - Single Match
    public: __thiscall UnDecorator::operator char *(void)
   
   Library: Visual Studio 2005 Release */

char * __thiscall UnDecorator::operator_char_(UnDecorator *this)

{
  char cVar1;
  DName *pDVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char local_24 [16];
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  local_c = 0;
  local_14 = 0;
  local_8 = local_8 & 0xfffff000;
  local_10 = local_10 & 0xfffff000;
  if (DAT_0297cb7c == (char *)0x0) goto LAB_00707297;
  if (*DAT_0297cb7c == '?') {
    if (DAT_0297cb7c[1] != '@') {
      if (DAT_0297cb7c[1] == '$') {
        pDVar2 = (DName *)getTemplateName(SUB41(local_24,0));
        DName::operator=((DName *)&local_c,pDVar2);
        if (((byte)local_8 & 0xf) != 1) goto LAB_00707297;
        local_8 = local_8 & 0xfffffff0;
        DAT_0297cb78 = DAT_0297cb7c;
      }
      goto LAB_00707284;
    }
    DAT_0297cb78 = DAT_0297cb78 + 2;
    getDecoratedName();
    pDVar2 = (DName *)operator+(local_24,(DName *)&DAT_00781184);
  }
  else {
LAB_00707284:
    pDVar2 = (DName *)getDecoratedName();
  }
  DName::operator=((DName *)&local_c,pDVar2);
LAB_00707297:
  iVar3 = (int)(local_8 << 0x1c) >> 0x1c;
  if (iVar3 == 3) {
    return (char *)0x0;
  }
  if ((iVar3 == 1) || ((((ushort)DAT_0297cb88 & 0x1000) == 0 && (*DAT_0297cb78 != '\0')))) {
    DName::operator=((DName *)&local_14,DAT_0297cb7c);
  }
  else {
    DName::operator=((DName *)&local_14,(DName *)&local_c);
  }
  if (DAT_0297cb80 == (char *)0x0) {
    iVar3 = DName::length((DName *)&local_14);
    DAT_0297cb84 = iVar3 + 1;
    DAT_0297cb80 = (char *)(*DAT_0297cb58)(iVar3 + 8U & 0xfffffff8);
    if (DAT_0297cb80 == (char *)0x0) {
      return (char *)0x0;
    }
  }
  DName::getString((DName *)&local_14,DAT_0297cb80,DAT_0297cb84);
  pcVar4 = DAT_0297cb80;
  pcVar5 = DAT_0297cb80;
  while (cVar1 = *pcVar4, cVar1 != '\0') {
    if (cVar1 == ' ') {
      *pcVar5 = ' ';
      pcVar5 = pcVar5 + 1;
      do {
        pcVar4 = pcVar4 + 1;
      } while (*pcVar4 == ' ');
    }
    else {
      *pcVar5 = cVar1;
      pcVar5 = pcVar5 + 1;
      pcVar4 = pcVar4 + 1;
    }
  }
  *pcVar5 = '\0';
  return DAT_0297cb80;
}

