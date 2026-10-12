/* Ghidra pseudocode, not original source.
 * ev_bdf1d7790352cc42fa475d7feda1d016092a6193a7278bd37bc81c47b8a4034d
 * Entry: 0x709e45; label: FID_conflict:_ValidateExecute
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

