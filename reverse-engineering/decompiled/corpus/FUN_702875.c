/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x702875; label: UnDecorator::getNumberOfDimensions
 */

/* Library Function - Single Match
    private: static int __cdecl UnDecorator::getNumberOfDimensions(void)
   
   Library: Visual Studio 2005 Release */

int __cdecl UnDecorator::getNumberOfDimensions(void)

{
  int iVar1;
  char cVar2;
  
  cVar2 = *DAT_0297cb78;
  if (cVar2 != '\0') {
    if (('/' < cVar2) && (cVar2 < ':')) {
      DAT_0297cb78 = DAT_0297cb78 + 1;
      return cVar2 + -0x2f;
    }
    iVar1 = 0;
LAB_007028c1:
    if (cVar2 == '@') {
      cVar2 = *DAT_0297cb78;
      DAT_0297cb78 = DAT_0297cb78 + 1;
      if (cVar2 != '@') {
LAB_007028d4:
        iVar1 = -1;
      }
      return iVar1;
    }
    if (cVar2 != '\0') {
      if ((cVar2 < 'A') || ('P' < cVar2)) goto LAB_007028d4;
      DAT_0297cb78 = DAT_0297cb78 + 1;
      iVar1 = iVar1 * 0x10 + -0x41 + (int)cVar2;
      cVar2 = *DAT_0297cb78;
      goto LAB_007028c1;
    }
  }
  return 0;
}

