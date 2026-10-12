/* Ghidra pseudocode, not original source.
 * ev_626d54f17f079edfd1ff8b6caea4a3c32539f18361fa5c980ebe5ce2dfd8aaf4
 * Entry: 0x6fc446; label: __set_osfhnd
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __set_osfhnd
   
   Library: Visual Studio 2005 Release */

int __cdecl __set_osfhnd(int param_1,intptr_t param_2)

{
  undefined4 *puVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if ((-1 < param_1) && ((uint)param_1 < DAT_029a9b2c)) {
    iVar2 = (param_1 & 0x1fU) * 0x38;
    if (*(int *)(iVar2 + (&DAT_029a9b40)[param_1 >> 5]) == -1) {
      if (DAT_00829580 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_006fc4a0;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)param_2);
      }
LAB_006fc4a0:
      *(intptr_t *)(iVar2 + (&DAT_029a9b40)[param_1 >> 5]) = param_2;
      return 0;
    }
  }
  puVar1 = (undefined4 *)FUN_006ead5f();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_006ead72();
  *puVar1 = 0;
  return -1;
}

