/* Ghidra pseudocode, not original source.
 * ev_679903358dce225aedf8e0cd6850e85c923706fd55f3fc08c48a53cda153f2a5
 * Entry: 0x7132ab; label: __get_dstbias
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __get_dstbias
   
   Library: Visual Studio 2005 Release */

errno_t __cdecl __get_dstbias(long *_Daylight_savings_bias)

{
  undefined4 *puVar1;
  
  if (_Daylight_savings_bias == (long *)0x0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    return 0x16;
  }
  *_Daylight_savings_bias = DAT_0082aa90;
  return 0;
}

