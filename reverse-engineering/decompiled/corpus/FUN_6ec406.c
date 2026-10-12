/* Ghidra analysis pseudocode, not original source.
 * ev_0c181eace2d19d4182fe88edb7c380dbd0b0bf6e152acc5799b1564533e0f6fc
 * Entry: 0x6ec406; label: vscan_fn
 */

/* Library Function - Single Match
    _vscan_fn
   
   Library: Visual Studio 2005 Release */

undefined4 __cdecl vscan_fn(code *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char *unaff_ESI;
  
  _strlen(unaff_ESI);
  if ((unaff_ESI == (char *)0x0) || (param_2 == 0)) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = (*param_1)(&stack0xffffffdc,param_2,param_3,param_4);
  }
  return uVar2;
}

