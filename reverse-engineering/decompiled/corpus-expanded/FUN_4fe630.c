/* Ghidra pseudocode, not original source.
 * ev_291f832bd6f6d010a6248a6acee690ff87721c4cdff92148d1e7c4ba042507e6
 * Entry: 0x4fe630; label: _strstr
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

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

