/* Ghidra pseudocode, not original source.
 * ev_26c3496ed2ff1a3c25ba32180c5bf15d0f4b634a854c340dbd1eefc8d9d7aa21
 * Entry: 0x703eb4; label: UnDecorator::getArgumentList
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    private: static class DName __cdecl UnDecorator::getArgumentList(void)
   
   Library: Visual Studio 2005 Release */

DName * __cdecl UnDecorator::getArgumentList(void)

{
  char *pcVar1;
  DName *pDVar2;
  uint uVar3;
  DName *in_stack_00000004;
  DName local_18 [8];
  undefined4 local_10;
  uint local_c;
  int local_8;
  
  *(undefined4 *)in_stack_00000004 = 0;
  *(uint *)(in_stack_00000004 + 4) = *(uint *)(in_stack_00000004 + 4) & 0xfffff000;
  local_8 = 1;
  if ((*(uint *)(in_stack_00000004 + 4) & 0xf) == 0) {
    do {
      if (*DAT_0297cb78 == '@') {
        return in_stack_00000004;
      }
      if (*DAT_0297cb78 == 'Z') {
        return in_stack_00000004;
      }
      if (local_8 == 0) {
        DName::operator+=(in_stack_00000004,',');
      }
      else {
        local_8 = 0;
      }
      pcVar1 = DAT_0297cb78;
      if (*DAT_0297cb78 == '\0') {
        DName::operator+=(in_stack_00000004,2);
        return in_stack_00000004;
      }
      uVar3 = (int)*DAT_0297cb78 - 0x30;
      if (uVar3 < 10) {
        DAT_0297cb78 = DAT_0297cb78 + 1;
        pDVar2 = Replicator::operator[](DAT_0297cb6c,uVar3);
      }
      else {
        local_10 = 0;
        local_c = local_c & 0xfffff000;
        getPrimaryDataType(local_18);
        if ((1 < (int)DAT_0297cb78 - (int)pcVar1) && (*(int *)DAT_0297cb6c != 9)) {
          Replicator::operator+=(DAT_0297cb6c,local_18);
        }
        pDVar2 = local_18;
      }
      DName::operator+=(in_stack_00000004,pDVar2);
    } while (((byte)in_stack_00000004[4] & 0xf) == 0);
  }
  return in_stack_00000004;
}

