/* Ghidra analysis pseudocode, not original source.
 * ev_0c181eace2d19d4182fe88edb7c380dbd0b0bf6e152acc5799b1564533e0f6fc
 * Entry: 0x6ebe42; label: __get_osplatform
 */

/* Library Function - Single Match
    __get_osplatform
   
   Library: Visual Studio 2005 Release */

undefined4 __get_osplatform(int *param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 != (int *)0x0) && (DAT_0297c1b4 != 0)) {
    *param_1 = DAT_0297c1b4;
    return 0;
  }
  puVar1 = (undefined4 *)FUN_006ead5f();
  *puVar1 = 0x16;
  FUN_006e9fc2(0,0,0,0,0);
  return 0x16;
}

