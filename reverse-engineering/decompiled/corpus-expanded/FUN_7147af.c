/* Ghidra pseudocode, not original source.
 * ev_679903358dce225aedf8e0cd6850e85c923706fd55f3fc08c48a53cda153f2a5
 * Entry: 0x7147af; label: __strtoui64
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __strtoui64
   
   Library: Visual Studio 2005 Release */

ulonglong __cdecl __strtoui64(char *_String,char **_EndPtr,int _Radix)

{
  __uint64 _Var1;
  undefined **ppuVar2;
  
  if (DAT_0297cb10 == 0) {
    ppuVar2 = &PTR_DAT_0082a680;
  }
  else {
    ppuVar2 = (undefined **)0x0;
  }
  _Var1 = strtoxq((localeinfo_struct *)ppuVar2,_String,_EndPtr,_Radix,1);
  return _Var1;
}

