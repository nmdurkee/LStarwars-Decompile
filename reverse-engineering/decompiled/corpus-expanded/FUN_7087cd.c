/* Ghidra pseudocode, not original source.
 * ev_bdf1d7790352cc42fa475d7feda1d016092a6193a7278bd37bc81c47b8a4034d
 * Entry: 0x7087cd; label: FID_conflict:__sopen_s
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Multiple Matches With Different Base Names
    __sopen_s
    __wsopen_s
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

errno_t __cdecl
FID_conflict___sopen_s
          (int *_FileHandle,char *_Filename,int _OpenFlag,int _ShareFlag,int _PermissionMode)

{
  errno_t eVar1;
  
  eVar1 = FID_conflict___sopen_helper(_Filename,_OpenFlag,_ShareFlag,_PermissionMode,_FileHandle,1);
  return eVar1;
}

