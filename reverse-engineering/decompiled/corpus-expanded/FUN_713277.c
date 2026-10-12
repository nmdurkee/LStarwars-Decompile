/* Ghidra pseudocode, not original source.
 * ev_679903358dce225aedf8e0cd6850e85c923706fd55f3fc08c48a53cda153f2a5
 * Entry: 0x713277; label: __get_daylight
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __get_daylight
   
   Library: Visual Studio 2005 Release */

errno_t __cdecl __get_daylight(int *_Daylight)

{
  undefined4 *puVar1;
  
  if (_Daylight == (int *)0x0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    return 0x16;
  }
  *_Daylight = DAT_0082aa8c;
  return 0;
}

