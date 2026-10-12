/* Ghidra pseudocode, not original source.
 * ev_dafa2233724afb43ee4ce5fb75a2fdf73c0a8c82e75434708f3b2ad0dea6bad5
 * Entry: 0x702875; label: UnDecorator::getNumberOfDimensions
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

