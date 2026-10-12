/* Ghidra analysis pseudocode, not original source.
 * ev_5fe54c2a55e5805f81bff5ddaf4fd9cf0184cfdba0adc5a7ca08f803c24de38d
 * Entry: 0x6ec5ba; label: FID_conflict:_swscanf
 */

/* Library Function - Multiple Matches With Different Base Names
    _swscanf
    _swscanf_s
   
   Library: Visual Studio 2005 Release */

int __cdecl FID_conflict__swscanf(wchar_t *_Src,wchar_t *_Format,...)

{
  int iVar1;
  
  iVar1 = vscan_fn(&DAT_006ff249,_Format,0,&stack0x0000000c);
  return iVar1;
}

