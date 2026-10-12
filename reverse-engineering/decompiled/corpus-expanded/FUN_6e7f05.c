/* Ghidra pseudocode, not original source.
 * ev_b64bd83017f0ebae738352c8f5b7965ab01e6ce8652f7cf557bf7c06ee96df94
 * Entry: 0x6e7f05; label: FID_conflict:_vfprintf
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Multiple Matches With Different Base Names
    __vfprintf_p
    _vfprintf
    _vfprintf_s
   
   Library: Visual Studio 2005 Release */

int __cdecl FID_conflict__vfprintf(FILE *_File,char *_Format,va_list _ArgList)

{
  int iVar1;
  
  iVar1 = vfprintf_helper(FUN_006eef05,_File,_Format,0,_ArgList);
  return iVar1;
}

