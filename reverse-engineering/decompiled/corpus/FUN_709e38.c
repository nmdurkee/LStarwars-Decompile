/* Ghidra analysis pseudocode, not original source.
 * ev_67f98f38a95887d623f2b825230000473143cb3f5ba4a0d09463374d55adf1d2
 * Entry: 0x709e38; label: FID_conflict:_ValidateExecute
 */

/* Library Function - Multiple Matches With Different Base Names
    int __cdecl _ValidateExecute(int (__stdcall*)(void))
    int __cdecl _ValidateRead(void const *,unsigned int)
    int __cdecl _ValidateWrite(void *,unsigned int)
   
   Library: Visual Studio 2005 Release */

bool FID_conflict__ValidateExecute(int param_1)

{
  return param_1 != 0;
}

