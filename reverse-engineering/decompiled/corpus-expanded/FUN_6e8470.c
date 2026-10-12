/* Ghidra pseudocode, not original source.
 * ev_0b5d44e813c4aa355d260cb866ec5aec765804eee128937753d2ed60240642a2
 * Entry: 0x6e8470; label: _strstr
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _strstr
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2019 */

char * __cdecl _strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (*_SubStr == '\0') {
    return _Str;
  }
  if (_SubStr[1] == '\0') {
    pcVar4 = (char *)FUN_006f47b6();
    return pcVar4;
  }
  do {
    cVar3 = *_Str;
    do {
      while (_Str = _Str + 1, cVar3 != *_SubStr) {
        if (cVar3 == '\0') {
          return (char *)0x0;
        }
        cVar3 = *_Str;
      }
      cVar3 = *_Str;
      pcVar5 = _Str + 1;
      pcVar4 = _SubStr;
    } while (cVar3 != _SubStr[1]);
    do {
      if (pcVar4[2] == '\0') {
LAB_006e84e9:
        return _Str + -1;
      }
      if (*pcVar5 != pcVar4[2]) break;
      pcVar1 = pcVar4 + 3;
      if (*pcVar1 == '\0') goto LAB_006e84e9;
      pcVar2 = pcVar5 + 1;
      pcVar4 = pcVar4 + 2;
      pcVar5 = pcVar5 + 2;
    } while (*pcVar1 == *pcVar2);
  } while( true );
}

