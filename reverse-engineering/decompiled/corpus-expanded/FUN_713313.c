/* Ghidra pseudocode, not original source.
 * ev_679903358dce225aedf8e0cd6850e85c923706fd55f3fc08c48a53cda153f2a5
 * Entry: 0x713313; label: __get_tzname
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __get_tzname
   
   Library: Visual Studio 2005 Release */

errno_t __cdecl __get_tzname(size_t *_ReturnValue,char *_Buffer,size_t _SizeInBytes,int _Index)

{
  undefined4 *puVar1;
  size_t sVar2;
  errno_t eVar3;
  
  if (_Buffer == (char *)0x0) {
    if (_SizeInBytes != 0) goto LAB_00713360;
  }
  else if (_SizeInBytes == 0) {
LAB_00713360:
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    return 0x16;
  }
  if (_Buffer != (char *)0x0) {
    *_Buffer = '\0';
  }
  if ((_ReturnValue == (size_t *)0x0) || ((_Index != 0 && (_Index != 1)))) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    eVar3 = 0x16;
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
  }
  else {
    sVar2 = _strlen((&PTR_DAT_0082ab18)[_Index]);
    *_ReturnValue = sVar2 + 1;
    if (_Buffer == (char *)0x0) {
      eVar3 = 0;
    }
    else if (_SizeInBytes < sVar2 + 1) {
      eVar3 = 0x22;
    }
    else {
      eVar3 = _strcpy_s(_Buffer,_SizeInBytes,(&PTR_DAT_0082ab18)[_Index]);
    }
  }
  return eVar3;
}

