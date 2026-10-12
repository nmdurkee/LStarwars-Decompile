/* Ghidra pseudocode, not original source.
 * ev_bdf1d7790352cc42fa475d7feda1d016092a6193a7278bd37bc81c47b8a4034d
 * Entry: 0x70879d; label: FID_conflict:__sopen
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Multiple Matches With Different Base Names
    __sopen
    __wsopen
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

int __cdecl FID_conflict___sopen(wchar_t *_Filename,int _OpenFlag,int _ShareFlag,...)

{
  errno_t eVar1;
  int in_stack_00000010;
  int local_8;
  
  local_8 = -1;
  eVar1 = FID_conflict___sopen_helper
                    ((char *)_Filename,_OpenFlag,_ShareFlag,in_stack_00000010,&local_8,0);
  if (eVar1 != 0) {
    return -1;
  }
  return local_8;
}

