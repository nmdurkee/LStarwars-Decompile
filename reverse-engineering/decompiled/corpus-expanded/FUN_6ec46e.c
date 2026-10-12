/* Ghidra pseudocode, not original source.
 * ev_071b5a91353aec3b9b3ca880d0ad8ff1dbba963601d7a5f67d3b8ab6c7f681aa
 * Entry: 0x6ec46e; label: FID_conflict:_sscanf
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Multiple Matches With Different Base Names
    _sscanf
    _sscanf_s
   
   Library: Visual Studio 2005 Release */

int __cdecl FID_conflict__sscanf(char *_Src,char *_Format,...)

{
  int iVar1;
  
  iVar1 = vscan_fn(&DAT_006fd715,_Format,0,&stack0x0000000c);
  return iVar1;
}

