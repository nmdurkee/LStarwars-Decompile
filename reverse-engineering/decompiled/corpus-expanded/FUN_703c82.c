/* Ghidra pseudocode, not original source.
 * ev_26c3496ed2ff1a3c25ba32180c5bf15d0f4b634a854c340dbd1eefc8d9d7aa21
 * Entry: 0x703c82; label: UnDecorator::getCallingConvention
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getCallingConvention(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getCallingConvention(void)

{
  uint uVar1;
  char *pcVar2;
  uint in_ECX;
  DName *in_stack_00000004;
  Tokens TVar3;
  DNameStatus DVar4;
  undefined4 local_c;
  uint local_8;
  
  if (*DAT_0297cb78 == '\0') {
    DVar4 = 2;
  }
  else {
    uVar1 = (int)*DAT_0297cb78 - 0x41;
    DAT_0297cb78 = DAT_0297cb78 + 1;
    if (uVar1 < 0xd) {
      local_c = 0;
      local_8 = in_ECX & 0xfffff000;
      if ((~(DAT_0297cb88 >> 1) & 1) != 0) {
        uVar1 = uVar1 & 0xfffffffe;
        if (uVar1 == 0) {
          TVar3 = 1;
        }
        else if (uVar1 == 2) {
          TVar3 = 2;
        }
        else if (uVar1 == 4) {
          TVar3 = 4;
        }
        else if (uVar1 == 6) {
          TVar3 = 3;
        }
        else if (uVar1 == 8) {
          TVar3 = 5;
        }
        else {
          if (uVar1 != 0xc) goto LAB_00703d07;
          TVar3 = 6;
        }
        pcVar2 = UScore(TVar3);
        DName::operator=((DName *)&local_c,pcVar2);
      }
LAB_00703d07:
      DName::DName(in_stack_00000004,(DName *)&local_c);
      return in_stack_00000004;
    }
    DVar4 = 1;
  }
  DName::DName(in_stack_00000004,DVar4);
  return in_stack_00000004;
}

