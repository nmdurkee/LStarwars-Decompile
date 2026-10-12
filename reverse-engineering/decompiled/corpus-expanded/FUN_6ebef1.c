/* Ghidra pseudocode, not original source.
 * ev_071b5a91353aec3b9b3ca880d0ad8ff1dbba963601d7a5f67d3b8ab6c7f681aa
 * Entry: 0x6ebef1; label: __get_winmajor
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __get_winmajor
   
   Library: Visual Studio 2005 Release */

undefined4 __get_winmajor(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (DAT_0297c1b4 != 0)) {
    *param_1 = DAT_0297c1c0;
    return 0;
  }
  puVar1 = (undefined4 *)FUN_006ead5f();
  *puVar1 = 0x16;
  FUN_006e9fc2(0,0,0,0,0);
  return 0x16;
}

